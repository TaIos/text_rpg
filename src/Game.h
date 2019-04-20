#ifndef GAMEBOOK_GAME_H
#define GAMEBOOK_GAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "World.h"
#include "Shopping.h"
#include "InventoryBrowser.h"
#include "Interact.h"

class CGame
{
public:
    CGame() = delete;

    explicit CGame(std::string worldFile);

    void play();

protected:
    error loadGame();
    error saveGame();
    void reset();
    void exit();

    void mainMenu();
    void tickComponent();
    error createHero();
    void checkHeroStatus();

    error exportPlayerData(std::string filename) const;
    error importPlayerData(std::string filename);

    CWorld world;
    CHero hero;
    CStoryline storyLine;
    CShopping shopping;
    CInventoryBrowser inventoryBrowser;
    CInteract interact;
    CDisplay display;
    CStreamDecoder decoder;

    const CGameMenus menu;
};


#endif //GAMEBOOK_GAME_H
