#ifndef GAMEBOOK_WORLD_H
#define GAMEBOOK_WORLD_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "IOhandle.h"
#include "StreamDecoder.h"
#include "ErrorsList.h"
#include "Armour.h"
#include "Sword.h"
#include "Event.h"
#include "Choice.h"
#include "DialogueNCP.h"
#include "Fight.h"
#include "Trap.h"

/**
 * Database of events, creatures and items
 * Every event, creature or item is identified with id (integer)
 * Loads them from word file with specific format
 */
class CWorld
{
public:

    ~CWorld();

    error loadWorld(std::string worldFile);

    const CItem &getItem(int id) const
    { return *items.at(id); }

    std::string getItemName(int id) const
    { return items.at(id)->getName(); }

    std::set<int> getAllItemID() const;

    const CEvent &getEvent(int id) const
    { return *events.at(id); }

    const std::map<int, const CEvent *> &getAllEvents() const
    { return events; }

    const CCreature &getCreature(int id) const
    { return *creatures.at(id); }

    const std::map<int, const CCreature *> &getAllCreatures() const
    { return creatures; }

    const std::vector<int> &getStoryline() const
    { return storyline; }


protected:
    IOhandle iOhandle;
    CStreamDecoder decoder;
    CDisplay display;

    error loadEvents(const std::string &data, std::vector<int> &validateEvent, std::vector<int> &validateCreature);

    error loadItems(const std::string &data);

    error loadCreatures(const std::string &data);

    error loadStoryline(const std::string &data);

    error validateIDs(const std::vector<int> &validateEvent, const std::vector<int> &validateCreature) const;

    std::vector<int> storyline;
    std::map<int, const CCreature *> creatures;
    std::map<int, const CItem *> items;
    std::map<int, const CEvent *> events;

};


#endif //GAMEBOOK_WORLD_H
