#include "Interact.h"

/**
 * Executes events events
 * @param hero is player on which event will be executed
 * @param storyline is used to get current event and after executing this event moving to the next
 * @param world is used for getting events and creatures
 * @param display is used for output
 */
void CInteract::operator()(CHero &hero, CStoryline &storyline, const CWorld &world, const CDisplay &display)
{
    if (storyline.getEventCount() > 0)
    {
        const CEvent &event = world.getEvent(storyline.getCurrentEvent());
        event.execute(hero, display, world.getAllEvents(), world.getAllCreatures());
        storyline.moveToNextEvent();
        display.wait();
    }
}

