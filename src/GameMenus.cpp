#include "GameMenus.h"

CGameMenus::CGameMenus()
{
    greetingScreen = "Welcome to FOO game\n";

    firstMenuChoice = {std::make_pair("Play new game", action::play),
                       std::make_pair("Load game", action::load),
                       std::make_pair("Exit", action::exit)};

    standardChoice = {std::make_pair("Go to the next location.", action::go_next),
                      std::make_pair("Show stats", action::print_stats),
                      std::make_pair("Buy", action::shopping),
                      std::make_pair("Inventory", action::go_to_inventory),
                      std::make_pair("Save game", action::save),
                      std::make_pair("Leave to main menu", action::go_to_main_menu),
                      std::make_pair("Exit game", action::exit)};
}
