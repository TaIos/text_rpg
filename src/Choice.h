#ifndef GAMEBOOK_CHOICE_H
#define GAMEBOOK_CHOICE_H

#include <string>
#include "Event.h"
#include "GameMenus.h"

/**
 * Let's user choose from two options
 * optionA and optionB are id's of events that can follow this Event
 */
class CChoice : public CEvent
{
public:
    CChoice(int id, std::string name, std::string text, int optA, int optB)
            : CEvent(id, name, text), optionA(optA), optionB(optB)
    {}

    CChoice() = delete;

    void print(const CDisplay &display) const override
    { display.print(text); }

    void execute(CHero &hero, const CDisplay &display, const std::map<int, const CEvent *> &events,
                 const std::map<int, const CCreature *> &creatures) const override;

protected:
    int optionA, optionB;
    multichoice options = {std::make_pair("A", action::choose_option_A),
                           std::make_pair("B", action::choose_option_B)};
};


#endif //GAMEBOOK_CHOICE_H
