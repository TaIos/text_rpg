#include "InventoryBrowser.h"

void CInventoryBrowser::operator()(CHero &hero, const CWorld &world, const CDisplay &display)
{
    std::string command;
    int itemID;

    display.printWithDelimiter("Welcome to inventory browser.\nType help to see all commands.\n");

    while (true)
    {
        display.print("Enter your command:");

        while (display.getString(command) != error::no_error)
            display.printWithDelimiter("Invalid input. Enter help to display all commands.\n");

        if (command == "ls")
            printInventory(hero.getInventory(), world, display);
        else if (command == "equip")
        {
            if (display.getNumber(itemID) == error::no_error)
                equip(itemID, hero, world, display);
            else
                display.printWithDelimiter("Invalid input,\n");
        }
        else if (command == "exit")
            break;
        else if (command == "help")
            printHelp(display);
        else
            display.printWithDelimiter("Invalid command. Type help to see all commands\n");

        display.dumpToNewLine();
    }
}

void CInventoryBrowser::equip(int itemID, CHero &hero, const CWorld &world, const CDisplay &display)
{
    if (hero.getInventory().isInInventory(itemID))
    {
        hero.useItem(world.getItem(itemID));
        display.printWithDelimiter("You have equipped " + world.getItemName(itemID) + "\n");
    }
    else
        display.printWithDelimiter("Invalid item id.\n");
}

void CInventoryBrowser::printInventory(const CInventory &inventory, const CWorld &world, const CDisplay &display) const
{
    if (inventory.isEmpty())
        display.printWithDelimiter("Inventory is empty.\n");
    else
    {
        display.print("\n");
        for (const auto &itemID : inventory.getItemsID())
        {
            world.getItem(itemID).print(display);
            display.print("\n");
        }
    }
}

void CInventoryBrowser::printHelp(const CDisplay &display) const
{
    display.printWithDelimiter("'ls' to list inventory\n"
                                       "'equip [id]' to equip armour or sword with id\n"
                                       "'exit' to go back from inventory\n");
}
