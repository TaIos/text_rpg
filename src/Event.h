#ifndef GAMEBOOK_EVENT_H
#define GAMEBOOK_EVENT_H

#include <string>
#include <map>
#include "Display.h"
#include "Hero.h"

class CEvent
{
public:

    CEvent(int id, std::string name, std::string words)
            : eventID(id), eventName(name), text(words)
    {}

    virtual ~CEvent() = default;

    virtual void print(const CDisplay &display) const = 0;

    virtual void execute(CHero &hero, const CDisplay &display, const std::map<int, const CEvent *> &events,
                         const std::map<int, const CCreature *> &creatures) const = 0;

protected:
    int eventID;
    std::string eventName, text;
};


#endif //GAMEBOOK_EVENT_H
