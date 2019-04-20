#ifndef GAMEBOOK_STORYLINE_H
#define GAMEBOOK_STORYLINE_H

#include <vector>
#include <string>

/**
 * Holds event IDs in the order they follow each other
 */
class CStoryline
{
public:
    int getCurrentEvent() const
    { return storyLine.front(); }

    unsigned long getEventCount() const
    { return storyLine.size(); }

    void moveToNextEvent()
    { storyLine.erase(storyLine.begin()); }

    void exportData(std::string &data) const;

    void update(const std::vector<int> &data)
    { storyLine = data; }

protected:
    std::vector<int> storyLine;
};

#endif //GAMEBOOK_STORYLINE_H
