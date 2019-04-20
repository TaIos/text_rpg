#include "HeroStats.h"

/**
 * @param data holds all exported data in specific format
 */
void HeroStats::exportData(std::string &data) const
{
    data = "hero_stats ";
    data += (
            race + " " +
            std::to_string(level) + " " +
            std::to_string(xp) + " " +
            std::to_string(health) + " " +
            std::to_string(maxHealth) + " " +
            std::to_string(mana) + " " +
            std::to_string(attack) + " " +
            std::to_string(strength) + " " +
            std::to_string(armour) + " ");
}

void HeroStats::levelUp()
{
    health += 10;
    maxHealth += 10;
    mana += 10;
    attack += 1;
    strength += 1;
    armour += 1;
}
