#ifndef GAMEBOOK_DISPLAY_H
#define GAMEBOOK_DISPLAY_H

#include <vector>
#include <string>
#include <iostream>
#include "ActionsList.h"
#include "ErrorsList.h"
#include "GameMenus.h"

/**
 * Handles displaying text and getting response from the user
 */
class CDisplay
{
public:

    CDisplay()
            : outputStr(std::cout), inputStr(std::cin)
    {}

    action multiChoice(const multichoice &choices) const;

    error getString(std::string &text) const;

    error getNumber(int &number) const;

    void wait(std::string = "Press ENTER to continue ...") const;

    void print(std::string str) const;

    void printDelimiter(int cnt = 1) const;

    void printWithDelimiter(std::string str) const;

    void printError(error err) const;

    void dumpToNewLine() const;

protected:
    std::ostream &outputStr;
    std::istream &inputStr;

};

#endif //GAMEBOOK_DISPLAY_H
