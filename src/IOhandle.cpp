#include "IOhandle.h"

error IOhandle::loadEvent(std::ifstream &stream, std::string &dst)
{
    std::string tmp;
    std::string eventType;

    dst += ("event ");

    // read event id
    stream >> tmp;

    dst += (tmp + " ");

    // read event type
    stream >> eventType;


    dst += (eventType + " ");

    // get first line with text
    dumpLine(stream); // discard rest of the line and newline
    std::getline(stream, tmp);
    if (tmp.back() == '\r') // in case of windows end of line
        tmp.pop_back();
    dst += (tmp + " ");


    // get second line with text
    std::getline(stream, tmp);
    if (tmp.back() == '\r') // in case of windows end of line
        tmp.pop_back();
    dst += (tmp + " ");


    // read event specific data
    if (eventType == "fight")
    {
        stream >> tmp; // read word "creature"
        stream >> tmp; // read creature id
        dst += (tmp + " ");
    }
    else if (eventType == "trap")
    {
        stream >> tmp; // read word "trap"
        stream >> tmp; // read trap id
        dst += (tmp + " ");
    }
    else if (eventType == "choice")
    {
        stream >> tmp; // read 'A'
        stream >> tmp; // read first option
        dst += (tmp + " ");

        stream >> tmp; // read 'B'
        stream >> tmp;
        dst += (tmp + " "); // read second option
    }
    else if (eventType != "dialogue") // dialogue doesn't have any other data to read
        return error::error_reading_event;

    return error::no_error;
}

error IOhandle::loadEventOrder(std::ifstream &stream, std::string &dst)
{
    std::string tmp;
    while (stream >> tmp)
    {
        if (tmp == ";")
            break;
        dst += (tmp + " ");
    }
    return error::no_error;
}

error IOhandle::loadCreature(std::ifstream &stream, std::string &dst)
{
    std::string tmp;

    dst += "creature ";

    stream >> tmp; // load creature id
    dst += (tmp + " ");

    dumpLine(stream);

    getline(stream, tmp); // load creature name
    if (tmp.back() == '\r')  // in case of windows end of line
        tmp.pop_back();
    dst += (tmp + " ");

    getline(stream, tmp); // load creature text
    if (tmp.back() == '\r')  // in case of windows end of line
        tmp.pop_back();
    dst += (tmp + " ");

    stream >> tmp; // get word 'attack'
    stream >> tmp; // get attack value
    dst += (tmp + " ");

    stream >> tmp; // get word 'reward'
    stream >> tmp; // get reward value
    dst += (tmp + " ");


    return error::no_error;
}

error IOhandle::loadShopItem(std::ifstream &stream, std::string &dst)
{
    std::string tmp;

    dst += "shop_item ";

    stream >> tmp; // load shop item id
    dst += (tmp + " ");

    stream >> tmp; // load shop item type
    dst += (tmp + " ");

    dumpLine(stream);
    getline(stream, tmp); // load item name
    if (tmp.back() == '\r') // in case of windows end of line
        tmp.pop_back();
    dst += (tmp + " ");

    stream >> tmp; // load word 'price'
    stream >> tmp; // load item price value
    dst += (tmp + " ");

    stream >> tmp; // load second item attribute name
    stream >> tmp; // load second item attribute value
    dst += (tmp + " ");

    return error::no_error;
}

void IOhandle::dumpLine(std::ifstream &stream)
{
    while (stream.get() != '\n')
        continue;
}
