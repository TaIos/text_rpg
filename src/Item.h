#ifndef GAMEBOOK_ITEM_H
#define GAMEBOOK_ITEM_H

#include <iostream>
#include <string>
#include "Display.h"
#include "Equipment.h"
#include "HeroStats.h"

class CItem
{
public:
    CItem() = default;

    CItem(int id, int gold, std::string text)
            : itemID(id), price(gold), name(text)
    {}

    virtual ~CItem() = default;

    virtual void useItem(HeroStats &stats, CEquipment &equipment) const = 0;

    int getID() const
    { return itemID; }

    int getPrice() const
    { return price; }

    std::string getName() const
    { return name; }

    virtual void print(const CDisplay &display) const = 0;

    virtual void printForShop(const CDisplay &display) const = 0;

protected:
    int itemID;
    int price;
    std::string name;
};


#endif //GAMEBOOK_ITEM_H
