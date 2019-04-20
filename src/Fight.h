#ifndef GAMEBOOK_FIGHT_H
#define GAMEBOOK_FIGHT_H

#include "Creature.h"
#include "Event.h"
#include "GameMenus.h"


class CFight : public CEvent
{
public:
    CFight(int id, std::string name, std::string text, int idCreature)
            : CEvent(id, name, text), creatureID(idCreature)
    {}

    CFight() = delete;

    void print(const CDisplay &display) const override
    { display.print(text); }

    void execute(CHero &hero, const CDisplay &display, const std::map<int, const CEvent *> &events,
                 const std::map<int, const CCreature *> &creatures) const override;

protected:
    int creatureID;
    multichoice enemyEncounterChoice = {std::make_pair("Fight", action::fight),
                                        std::make_pair("Retreat", action::retreat)};
};


#endif //GAMEBOOK_FIGHT_H
