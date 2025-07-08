#include "../include/Mayor.hpp"
#include "../include/Game.hpp"
#include <iostream>

Mayor::Mayor(std :: shared_ptr<Location> startLocation)
    : Hero("Mayor", 5, startLocation) {}

void Mayor::specialAction(Game & game) {
    game.MyTerminal.StylizeTextBoard("Mayor has no special ability.\n");
}