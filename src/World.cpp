#include "World.h"

CWorld::~CWorld()
{
    for (const auto &creature : creatures)
        delete creature.second;

    for (const auto &item : items)
        delete item.second;

    for (const auto &event : events)
        delete event.second;
}

/**
 * Loads all word data using IOhandle
 * @param worldFile file containing word definition and word data in specific format
 * @return error if specific format is not recognized
 */
error CWorld::loadWorld(std::string worldFile)
{
    error err;
    std::string eventsData, eventOrder, itemsData, creaturesData, tmp;
    std::ifstream file;
    std::vector<int> validateEvent, validateCreature;

    file.open(worldFile);

    if (!file.is_open())
        return error::cant_open_file;

    while (true)
    {
        file >> tmp; // load the key word

        if (tmp == "event")
            err = iOhandle.loadEvent(file, eventsData);
        else if (tmp == "creature")
            err = iOhandle.loadCreature(file, creaturesData);
        else if (tmp == "shop_item")
            err = iOhandle.loadShopItem(file, itemsData);
        else if (tmp == "event_order")
            err = iOhandle.loadEventOrder(file, eventOrder);

        if (err != error::no_error)
        {
            file.close();
            return err;
        }

        file >> tmp;
        if (tmp != "#")
            break;
    }

    if ((err = loadEvents(eventsData, validateEvent, validateCreature)) != error::no_error)
    { file.close(); return err; }

    if ((err = loadItems(itemsData)) != error::no_error)
    { file.close(); return err; }

    if ((err = loadCreatures(creaturesData)) != error::no_error)
    { file.close(); return err; }

    if ((err = loadStoryline(eventOrder)) != error::no_error)
    { file.close() ;return err; }

    file.close();
    return validateIDs(validateEvent, validateCreature);
}

error CWorld::loadEvents(const std::string &data, std::vector<int> &validateEvent, std::vector<int> &validateCreature)
{
    int id, creatureID, damage, optionA, optionB;
    std::string name, text, type, tmp;

    std::istringstream eventStream(data);

    while (eventStream >> tmp) // load first word 'event'
    {
        id = decoder.getStringAsInt(eventStream);
        type = decoder.getString(eventStream);
        name = decoder.getText(eventStream);
        text = decoder.getText(eventStream);

        if (type == "choice")
        {
            optionA = decoder.getStringAsInt(eventStream);
            optionB = decoder.getStringAsInt(eventStream);
            validateEvent.push_back(optionA);
            validateEvent.push_back(optionB);
            events[id] = new CChoice(id, name, text, optionA, optionB);
        }
        else if (type == "dialogue")
            events[id] = new CDialogueNPC(id, name, text);
        else if (type == "fight")
        {
            creatureID = decoder.getStringAsInt(eventStream);
            validateCreature.push_back(creatureID);
            events[id] = new CFight(id, name, text, creatureID);
        }
        else if (type == "trap")
        {
            damage = decoder.getStringAsInt(eventStream);
            events[id] = new CTrap(id, name, text, damage);
        }
    }

    return error::no_error;
}

error CWorld::loadItems(const std::string &data)
{
    std::istringstream stream(data);
    std::string tmp, itemType, text;
    int price, specific, id;

    while (stream >> tmp) // get 'shop_item' word
    {
        id = decoder.getStringAsInt(stream);
        itemType = decoder.getString(stream);
        text = decoder.getText(stream);
        price = decoder.getStringAsInt(stream);

        // get the specific attribute (attack or defense)
        specific = decoder.getStringAsInt(stream);

        if (itemType == "armour")
            items[id] = new CArmour(id, price, specific, text);
        else if (itemType == "sword")
            items[id] = new CSword(id, price, specific, text);
    }

    return error::no_error;
}

error CWorld::loadCreatures(const std::string &data)
{
    int id, attack, reward;
    std::string name, text, tmp;
    std::istringstream creatureStream(data);

    while (creatureStream >> tmp) // load word 'creature'
    {
        id = decoder.getStringAsInt(creatureStream);
        name = decoder.getText(creatureStream);
        text = decoder.getText(creatureStream);
        attack = decoder.getStringAsInt(creatureStream);
        reward = decoder.getStringAsInt(creatureStream);
        creatures[id] = new CCreature(id, attack, reward, name, text);
    }

    return error::no_error;
}

error CWorld::loadStoryline(const std::string &data)
{
    std::istringstream eventOrder(data);
    storyline = decoder.getNumbers(eventOrder);

    return error::no_error;
}

/**
 * Validate all linked id
 * @param validateEvent id of events that needs to ve validated if they exists in database
 * @param validateCreature id of creatures that needs to be validated if they exists in database
 * @return error if corresponding id is not found (eg: fight with creature id which does not exists)
 */
error CWorld::validateIDs(const std::vector<int> &validateEvent, const std::vector<int> &validateCreature) const
{
    // validate events in storyline
    for (auto eventID : storyline)
        if (events.find(eventID) == events.end())
            return error::invalid_id;

    // validate events in choice event
    for (auto eventID : validateEvent)
        if (events.find(eventID) == events.end())
            return error::invalid_id;

    // validate creatures id in fight event
    for (auto creatureID : validateCreature)
        if (creatures.find(creatureID) == creatures.end())
            return error::invalid_id;

    return error::no_error;
}

std::set<int> CWorld::getAllItemID() const
{
    std::set<int> tmp;
    for (const auto &item : items)
        tmp.insert(item.second->getID());
    return tmp;
}
