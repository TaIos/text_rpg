#ifndef GAMEBOOK_IOHANDLE_H
#define GAMEBOOK_IOHANDLE_H

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "ErrorsList.h"

/**
 * Used when reading word definition and word data from the file
 * Can be called only from CWord
 * Returns error if specific data format is not recognized
 */
class IOhandle
{
public:
    error loadEvent(std::ifstream &stream, std::string &dst);

    error loadEventOrder(std::ifstream &stream, std::string &dst);

    error loadCreature(std::ifstream &stream, std::string &dst);

    error loadShopItem(std::ifstream &stream, std::string &dst);

protected:

    void dumpLine(std::ifstream &stream);
};


#endif //GAMEBOOK_IOHANDLE_H
