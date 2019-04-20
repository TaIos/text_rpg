#ifndef GAMEBOOK_TRAP_H
#define GAMEBOOK_TRAP_H

#include "Event.h"

class CTrap : public CEvent
{
public:

    CTrap(int id, std::string name, std::string text, int dmg)
            : CEvent(id, name, text), damage(dmg)
    {}

    CTrap() = delete;

    void print(const CDisplay &display) const override
    { display.print(text); }

    void execute(CHero &hero, const CDisplay &display, const std::map<int, const CEvent *> &events,
                 const std::map<int, const CCreature *> &creatures) const override;

protected:
    int damage;
};


#endif //GAMEBOOK_TRAP_H
