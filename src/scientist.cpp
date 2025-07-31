#include "../include/scientist.hpp"
#include "../include/Game.hpp"
Scientist :: Scientist(std::shared_ptr<Location> startLoc) : Hero ("Scientist" , 4 , startLoc){}
void Scientist::specialAction(Game& game) {
    game.MyTerminal .ShowMessageBox("Scientist don't have an special action!");
}
void Scientist::Ability(){}