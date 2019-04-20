#ifndef GAMEBOOK_INVENTORYBROWSER_H
#define GAMEBOOK_INVENTORYBROWSER_H

#include <string>
#include "World.h"
#include "Hero.h"

/**
 * Allows user to list his inventory and use items in his inventory
 */
class CInventoryBrowser
{
public:
    void operator()(CHero &hero, const CWorld &CWorld, const CDisplay &display);

protected:

    void equip(int itemID, CHero &hero, const CWorld &world, const CDisplay &display);

    void printInventory(const CInventory &inventory, const CWorld &world, const CDisplay &display) const;

    void printHelp(const CDisplay &display) const;
};


#endif //GAMEBOOK_INVENTORYBROWSER_H
