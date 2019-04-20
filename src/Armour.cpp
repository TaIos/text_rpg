#include "Armour.h"

void CArmour::print(const CDisplay &display) const
{
    display.print("Name:" + name + "[" + std::to_string(itemID) + "]\n" +
                  "Defense:" + std::to_string(defense) + "\n");
}

void CArmour::printForShop(const CDisplay &display) const
{
    display.print("Name:" + name + "[" + std::to_string(itemID) + "]\n" +
                  "Defense:" + std::to_string(defense) + "\n" +
                  "Price:" + std::to_string(price) + "\n");
}
