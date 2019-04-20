#ifndef GAMEBOOK_CREATURE_H
#define GAMEBOOK_CREATURE_H

#include <string>
#include "Display.h"

class CCreature
{
public:
    CCreature(int id, int att, int rew, std::string nam, std::string words)
            : creatureID(id), attack(att), reward(rew), name(nam), text(words)
    {}

    std::string getName() const
    { return name; }

    std::string getText() const
    { return text; }

    int getID() const
    { return creatureID; }

    int getAttack() const
    { return attack; }

    int getReward() const
    { return reward; }

    void print(const CDisplay &display) const
    { display.print(text); }

protected:
    int creatureID;
    int attack;
    int reward;
    std::string name;
    std::string text;
};


#endif //GAMEBOOK_CREATURE_H
