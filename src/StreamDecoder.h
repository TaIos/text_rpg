#ifndef GAMEBOOK_STREAMDECODER_H
#define GAMEBOOK_STREAMDECODER_H

#include <string>
#include <sstream>
#include <vector>
#include <set>
#include "ErrorsList.h"

/**
 * Used to decode data which were previously loaded from file with word definition and word data
 */
class CStreamDecoder
{
public:
    int getStringAsInt(std::istringstream &stream) const;

    std::string getString(std::istringstream &stream) const;

    std::string getText(std::istringstream &stream) const;

    std::vector<int> getNumbers(std::istringstream &stream) const;

    std::vector<int> getNumbers(const std::string &data) const;

    std::string getNumbersAsString(std::istringstream &stream) const;

    error decodePlayerData(const std::string &data, std::string &hero, std::string &storyline) const;

protected:
};


#endif //GAMEBOOK_STREAMDECODER_H
