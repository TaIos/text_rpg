#ifndef GAMEBOOK_INTERACT_H
#define GAMEBOOK_INTERACT_H

#include "Hero.h"
#include "Storyline.h"
#include "World.h"

class CInteract
{
public:
    void operator()(CHero &hero, CStoryline &storyline, const CWorld &world, const CDisplay &display);

protected:

};


#endif //GAMEBOOK_INTERACT_H
