#include "Trap.h"

void CTrap::execute(CHero &hero, const CDisplay &display, const std::map<int, const CEvent *> &events,
                    const std::map<int, const CCreature *> &creatures) const
{
    display.printWithDelimiter(text + "\n" +
                               "You have suffered " + std::to_string(damage) + " damage.\n");

    hero.sufferDamage(damage);

    if (hero.isDead())
        display.print("You have died.\n");
    else
    {
        display.print("You have survived.\n");
        display.printDelimiter();
    }
}

