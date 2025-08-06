#include "../include/Courier.hpp"
#include "../include/Game.hpp"

Courier ::Courier(std::shared_ptr<Location> startLocation) : Hero("Courier", 4, startLocation) {}
void Courier ::specialAction(Game &game)
{
    auto heros = game.heroes;
    int index = -1;
    for (int i = 0 ; i < heros.size() ; ++i){
        if(heros[i]->getName() != "Courier")
        index = i;
    }
    currentLocation->RemoveHero(shared_from_this());
    auto nextLocation = game.heroes[index]->getLocation();
                getLocation()->RemoveHero(shared_from_this());
                moveTo(nextLocation);
                DecreaseAction();
    game.MyTerminal.ShowMessageBox("Courier moved to " + game.heroes[index] ->getName());
}
