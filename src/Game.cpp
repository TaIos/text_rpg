#include "Game.h"

void CGame::play()
{
    display.printWithDelimiter(menu.greetingScreen);
    mainMenu();
    tickComponent();
}

void CGame::mainMenu()
{
    error err;

    do
    {
        action choice = display.multiChoice(menu.firstMenuChoice);

        switch (choice)
        {
            case action::play:
                err = createHero();
                break;
            case action::load :
                err = loadGame();
                break;
            case action::exit :
                exit();
                break;
            default:
                err = error::first_menu;
        }
        display.printError(err);

    } while (err != error::no_error);
}

/**
 * Basic guidepost, allows user to choose from variety of actions
 * Can be called only when hero is created
 */
void CGame::tickComponent()
{
    action choice;

    while (true)
    {
        choice = display.multiChoice(menu.standardChoice);

        switch (choice)
        {
            case action::go_next :
                interact(hero, storyLine, world, display);
                checkHeroStatus();
                break;

            case action::print_stats :
                hero.printStats(display);
                break;

            case action::shopping :
                shopping(hero, world, display);
                break;

            case action::go_to_inventory :
                inventoryBrowser(hero, world, display);
                break;

            case action::save :
                saveGame();
                break;

            case action::go_to_main_menu  :
                reset();
                mainMenu();
                break;

            default:
                return;
        }
    }
}

error CGame::createHero()
{
    std::string name, race;

    display.print("Hero, enter your name: ");
    while (display.getString(name) != error::no_error)
        display.print("Please try it again.\n");

    display.print("Enter you race: ");
    while (display.getString(race) != error::no_error)
        display.print("Please try it again.\n");

    hero = CHero(name, race);

    display.printWithDelimiter("You have successfully created a hero.\n");

    return error::no_error;
}

/**
 * Checks whether hero is dead or game is won, if some of these conditions is met game is restarted
 */
void CGame::checkHeroStatus()
{
    if (hero.isDead() || storyLine.getEventCount() == 0)
    {
        if (storyLine.getEventCount() == 0)
        {
            display.print("\n\n\n\n\n\n\n\n" + hero.getName() + ", you have won the game!!!!\n" +
                          "CONGRATULATION\n\n\n\n\n\n\n\n");
        }

        reset();
        play();
    }
}

error CGame::loadGame()
{
    std::string fileName;
    error err;

    display.printDelimiter();
    display.print("Load game from file:");

    while (display.getString(fileName) != error::no_error)
        display.printWithDelimiter("Please, enter valid file name.\n");

    err = importPlayerData(fileName);

    if (err == error::no_error)
        display.printWithDelimiter("Game loaded successfully.\n");

    return err;
}

error CGame::saveGame()
{
    std::string fileName;
    error err;

    display.printDelimiter();
    display.print("Save game to file:");

    while (display.getString(fileName) != error::no_error)
        display.print("Please, enter valid file filename.\n");

    err = exportPlayerData(fileName);

    if (err == error::no_error)
        display.printWithDelimiter("Game saved successfully.\n");
    else
        display.printError(err);

    return err;
}

void CGame::reset()
{
    display.print("\n");
    storyLine.update(world.getStoryline());
    shopping.update(world.getAllItemID());
}

void CGame::exit()
{
    display.print("\nExiting game ...\n");
    throw std::exception();
}

/**
 * Calls CWord to load word definition and word data
 * @param file is name of the file which contains word definition and word data
 */
CGame::CGame(std::string file)
{
    error err;

    if ((err = world.loadWorld(file)) != error::no_error)
    {
        display.printError(err);
        exit();
    }

    reset();
}

/**
 * Exports player data and his/her current storyline into the file in specific format
 */
error CGame::exportPlayerData(std::string filename) const
{
    std::string playerData, storylineData;
    std::ofstream file(filename);

    if (!file.is_open())
        return error::cant_write_to_file;

    hero.exportData(playerData);
    storyLine.exportData(storylineData);

    if (!(file << playerData) || !(file << storylineData))
    {
        file.close();
        return error::error_while_writing_to_file;
    }

    file.close();
    return error::no_error;
}

/**
 * Imports player data from file with specific format
 */
error CGame::importPlayerData(std::string filename)
{
    std::string playerData, storylineData;
    std::stringstream buffer;
    error err;
    std::ifstream file(filename);

    if (!file.is_open())
        return error::cant_open_file;

    buffer << file.rdbuf(); // read file

    err = decoder.decodePlayerData(buffer.str(), playerData, storylineData);

    if (err != error::no_error)
    {
        file.close();
        return err;
    }

    hero.update(playerData, decoder);
    storyLine.update(decoder.getNumbers(storylineData));

    file.close();
    return error::no_error;
}



