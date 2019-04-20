#ifndef GAMEBOOK_SHOPPING_H
#define GAMEBOOK_SHOPPING_H

#include <sstream>
#include <vector>
#include <string>
#include <set>
#include "Hero.h"
#include "World.h"

/**
 * Allows user to list and buy items
 */
class CShopping
{
public:

    CShopping() = default;

    void operator()(CHero &hero, const CWorld &world, const CDisplay &display);

    void update(const std::set<int> &data)
    { itemsToSell = data; }

protected:
    std::set<int> itemsToSell;

    void eraseItem(int itemID)
    { itemsToSell.erase(itemID); }

    void buyItem(int itemID, CHero &hero, const CWorld &world, const CDisplay &display);

    void printHelp(const CDisplay &display) const;

    void printItems(const CDisplay &display, const CWorld &world) const;

    bool isInShop(int itemID) const
    { return itemsToSell.find(itemID) != itemsToSell.end(); }
};


#endif //GAMEBOOK_SHOPPING_H
