#ifndef GAMEBOOK_DIALOGUENCP_H
#define GAMEBOOK_DIALOGUENCP_H

#include <string>
#include "Event.h"

/**
 * Only prints text, does not interact with hero
 */
class CDialogueNPC : public CEvent
{
public:
    CDialogueNPC(int id, std::string name, std::string text)
            : CEvent(id, name, text)
    {}

    CDialogueNPC() = delete;

    void print(const CDisplay &display) const override
    { display.print(text); }

    void execute(CHero &hero, const CDisplay &display, const std::map<int, const CEvent *> &events,
                 const std::map<int, const CCreature *> &creatures) const override
    { display.printWithDelimiter(eventName + "\n" + text + "\n"); }

protected:
};


#endif //GAMEBOOK_DIALOGUENCP_H
