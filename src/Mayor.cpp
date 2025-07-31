#include "../include/Mayor.hpp"
#include "../include/Game.hpp"

Mayor::Mayor(std :: shared_ptr<Location> startLocation)
    : Hero("Mayor", 5, startLocation) {}

void Mayor::specialAction(Game & game) {
    game.MyTerminal.ShowMessageBox("Mayor has no special ability.\n");
}