#include "Choice.h"

void CChoice::execute(CHero &hero, const CDisplay &display, const std::map<int, const CEvent *> &events,
                      const std::map<int, const CCreature *> &creatures) const
{
    display.printWithDelimiter(text + "\n");

    action option = display.multiChoice(options);

    if (option == action::choose_option_A)
        events.at(optionA)->execute(hero, display, events, creatures);
    else if (option == action::choose_option_B)
        events.at(optionB)->execute(hero, display, events, creatures);
}
