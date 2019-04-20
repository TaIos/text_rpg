#ifndef GAMEBOOK_HEROSTATS_H
#define GAMEBOOK_HEROSTATS_H

#include <string>

struct HeroStats
{
    std::string race;
    int level;
    int xp;
    int health;
    int maxHealth;
    int mana;
    int attack;
    int strength;
    int armour;

    void exportData(std::string &data) const;

    void levelUp();
};


#endif //GAMEBOOK_HEROSTATS_H
