#include "../include/Courier.hpp"
#include "../include/Game.hpp"

Courier ::Courier(std::shared_ptr<Location> startLocation) : Hero("Courier", 4, startLocation) {}
std::string Courier ::specialAction(Game &game)
{
    auto heros = game.heroes;
    heros.erase(heros.begin()+2);
    std::vector<std::string> heroNames;
    for (const auto &h : heros)
            heroNames.push_back(h->getName());

   int selectedHero = game.MyTerminal.MenuGenerator(heroNames);
    currentLocation->RemoveHero(shared_from_this());
    auto nextLocation = game.heroes[selectedHero]->getLocation();
                getLocation()->RemoveHero(shared_from_this());
                moveTo(nextLocation);
                DecreaseAction();
}
