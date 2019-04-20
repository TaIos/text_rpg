#include "Sword.h"

void CSword::print(const CDisplay &display) const
{
    display.print("Name:" + name + "[" + std::to_string(itemID) + "]\n" +
                  "Attack:" + std::to_string(attack) + "\n");
}

void CSword::printForShop(const CDisplay &display) const
{
    display.print("Name:" + name + "[" + std::to_string(itemID) + "]\n" +
                  "Attack:" + std::to_string(attack) + "\n" + "Price:" + std::to_string(price) + "\n");
}

