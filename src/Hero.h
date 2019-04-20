#ifndef GAMEBOOK_HERO_H
#define GAMEBOOK_HERO_H

#include <iostream>
#include <string>
#include <typeinfo>
#include "Creature.h"
#include "Inventory.h"
#include "ErrorsList.h"
#include "Display.h"
#include "Armour.h"
#include "Sword.h"
#include "Item.h"
#include "Equipment.h"
#include "HeroStats.h"
#include "StreamDecoder.h"

class CHero
{
public:

    CHero() = default;

    CHero(std::string newName, std::string newRace);

    void exportData(std::string &data) const;

    void update(const std::string &data, const CStreamDecoder &decoder);

    void fight(const CCreature &creature);

    void useItem(const CItem &item)
    { item.useItem(stats, equipment); }

    void sufferDamage(int dmg)
    { stats.health -= dmg; }

    bool isDead()
    { return stats.health <= 0; }

    int getGold() const
    { return gold; }

    std::string getName() const
    { return name; }

    void payGold(int num)
    { gold -= num; }

    void addGold(int num)
    { gold += num; }

    void addXP(int num, const CDisplay &display);

    int getAttack() const
    { return stats.attack + equipment.getAttack(); }

    int getArmour() const
    { return stats.armour + equipment.getArmour(); }

    CInventory &getInventory()
    { return inventory; }

    void printStats(const CDisplay &display) const;

protected:

    std::string name;
    HeroStats stats;
    CEquipment equipment;
    CInventory inventory;
    int gold;
};


#endif //GAMEBOOK_HERO_H
