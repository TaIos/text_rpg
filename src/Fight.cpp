#include "Fight.h"

void CFight::execute(CHero &hero, const CDisplay &display, const std::map<int, const CEvent *> &events,
                     const std::map<int, const CCreature *> &creatures) const
{

    const CCreature *creature = creatures.at(creatureID);

    display.printWithDelimiter(eventName + "\n" + text + "\n");

    display.print("'" + creature->getName() + "' " +
                  "attack:" + std::to_string(creature->getAttack()) + ", " +
                  "health:" + std::to_string(creature->getAttack() * 2) + "\n");

    action choice = display.multiChoice(enemyEncounterChoice);

    if (choice == action::fight)
    {
        display.print(creature->getName() + ": " + creature->getText() + "\n");

        hero.fight(*creature);

        if (hero.isDead())
            display.printWithDelimiter("You have died in the fight!\n");
        else
        {
            display.printDelimiter();
            display.print("You have won the fight! You get 5 XP and " +
                          std::to_string(creature->getReward()) + " gold.\n");
            hero.addXP(5, display);
            hero.addGold(creature->getReward());
        }
    }
    else if (choice == action::retreat)
        display.printWithDelimiter("You have successfully retreated from the fight!\n");
}