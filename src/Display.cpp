#include "Display.h"

action CDisplay::multiChoice(const multichoice &choices) const
{
    size_t choice;

    for (size_t i = 0; i < choices.size(); i++)
        outputStr << i + 1 << ") " << choices[i].first << std::endl;

    outputStr << "Your choice: ";

    while (!(inputStr >> choice) || choice < 1 || choice > (choices.size()))
    {
        dumpToNewLine();
        outputStr << "Please enter valid number from range 1-" << choices.size() << std::endl;
        outputStr << "Your choice: ";
    }

    return choices[choice - 1].second;
}

void CDisplay::print(std::string str) const
{
    outputStr << str;
}

void CDisplay::printWithDelimiter(std::string str) const
{
    printDelimiter();
    outputStr << str;
    printDelimiter();
}

void CDisplay::printDelimiter(int cnt) const
{
    for (int i = 0; i < cnt; i++)
        outputStr << "========================" << std::endl;
}

error CDisplay::getString(std::string &text) const
{
    if (inputStr >> text)
        return error::no_error;

    dumpToNewLine();

    return error::invalid_input;
}

error CDisplay::getNumber(int &number) const
{
    if (inputStr >> number)
        return error::no_error;

    dumpToNewLine();

    return error::invalid_input;
}

void CDisplay::wait(std::string text) const
{
    std::string dummy;

    outputStr << text;
    dumpToNewLine();

    std::getline(inputStr, dummy);
}

void CDisplay::dumpToNewLine() const
{
    inputStr.clear();
    while (inputStr.get() != '\n')
        continue;
}

void CDisplay::printError(error err) const
{
    switch (err)
    {
        case error::first_menu :
            printWithDelimiter("Error on first menu screen.\n");
            break;

        case error::save :
            printWithDelimiter("Error while saving the game.\n");
            break;

        case error::load :
            printWithDelimiter("Error while loading the game.\n");
            break;

        case error::exit :
            printWithDelimiter("Error while trying to close the game.\n");
            break;

        case error::no_such_filename :
            printWithDelimiter("No such filename\n");
            break;

        case error::no_write_permission :
            printWithDelimiter("No write permission.\n");
            break;

        case error::error_reading_creature :
            printWithDelimiter("Error while reading creature from file.\n");
            break;

        case error::error_reading_event :
            printWithDelimiter("Error while reading event from file.\n");
            break;

        case error::error_reading_shop_item :
            printWithDelimiter("Error while reading shop_item from file.\n");
            break;

        case error::error_reading_world :
            printWithDelimiter("Error while reading world data from file.\n");
            break;

        case error::cant_open_file :
            printWithDelimiter("Error, can't open file.\n");
            break;

        case error::cant_write_to_file :
            printWithDelimiter("Error, can't write to file.\n");
            break;

        case error::error_while_writing_to_file :
            printWithDelimiter("Error while writing to the file.\n");
            break;

        case error::error_while_decoding_player_data :
            printWithDelimiter("Error while decoding player data.\n");
            break;

        case error::invalid_id :
            printWithDelimiter("Invalid ID assignment in word file.\n");
            break;

        case error::invalid_input :
            printWithDelimiter("Invalid input.\n");
            break;

        case error::unknown :
            printWithDelimiter("Unknown error occurred.\n");
            break;

        case error::no_error:
            break;
    }
}
