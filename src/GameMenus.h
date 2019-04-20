#ifndef GAMEBOOK_GAMEMENUS_H
#define GAMEBOOK_GAMEMENUS_H

#include <string>
#include <vector>
#include "ActionsList.h"

typedef std::vector<std::pair<std::string, action >> multichoice;

class CGameMenus
{
public:
    CGameMenus();

    std::string greetingScreen;
    multichoice firstMenuChoice;
    multichoice standardChoice;
};


#endif //GAMEBOOK_GAMEMENUS_H
