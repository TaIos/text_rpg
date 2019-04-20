#include "Shopping.h"

void CShopping::operator()(CHero &hero, const CWorld &world, const CDisplay &display)
{
    std::string command;
    int itemID;

    display.printWithDelimiter("Welcome to the shop. You have " + std::to_string(hero.getGold()) + " gold.\n" +
                               "Type help to see all commands.\n");

    while (true)
    {
        display.print("Enter you command:");

        while (display.getString(command) != error::no_error)
            display.printWithDelimiter("Invalid input. Enter help to display all commands.\n");

        if (command == "ls")
        {
            if (itemsToSell.empty())
                display.print("Shop is empty.\n");
            else
                printItems(display, world);
        }
        else if (command == "buy")
        {
            if (display.getNumber(itemID) == error::no_error)
                buyItem(itemID, hero, world, display);
            else
                display.printWithDelimiter("Invalid input.\n");
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

void CShopping::printHelp(const CDisplay &display) const
{
    display.printWithDelimiter("'ls' to list shop\n"
                                       "'buy [id]' to buy item\n"
                                       "'exit' to leave the shop\n");
}

void CShopping::printItems(const CDisplay &display, const CWorld &world) const
{
    display.print("\n");
    for (const auto &itemID : itemsToSell)
    {
        world.getItem(itemID).printForShop(display);
        display.print("\n");
    }
}

void CShopping::buyItem(int itemID, CHero &hero, const CWorld &world, const CDisplay &display)
{
    if (isInShop(itemID))
    {
        const CItem &itemToBuy = world.getItem(itemID);

        if (itemToBuy.getPrice() <= hero.getGold())
        {
            hero.getInventory().addItem(itemToBuy.getID());
            hero.payGold(itemToBuy.getPrice());
            display.printWithDelimiter("You have bough " + itemToBuy.getName() + "\n");
            eraseItem(itemToBuy.getID());
        }
        else
            display.printWithDelimiter("You don't have enough gold. You have " +
                                       std::to_string(hero.getGold()) + " gold.\n");
    }
    else
        display.printWithDelimiter("Invalid item id\n");
}