#include "Storyline.h"

void CStoryline::exportData(std::string &data) const
{
    data = "event_order ";

    for (const auto &i : storyLine)
        data += (std::to_string(i) + " ");
}

