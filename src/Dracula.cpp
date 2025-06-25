#include "../include/Dracula.hpp"
#include "../include/Monster.hpp"
#include "../include/Game.hpp"
#include "../include/LocationNames.hpp"
#include <stdexcept>
#include <iostream>
using namespace LocationNames;

//Constructor :
Dracula :: Dracula() : Monster("Dracula",1,true){Table ={{false ,Crypt} ,{ false ,Cave} , {false,Dungeon} , {false,Graveyard} };}
//Power:
void Dracula :: DarkCharm(Game &game) {
game.MyTerminal.StylizeTextBoard("Dracula using Dark Charm !!");
if(game.heroPlayer->getLocation()->GetCityName() == CurrentLocation->GetCityName())
{
    game.MyTerminal.StylizeTextBoard( "Hero Already in Dracula's Location.");
    game.MyTerminal.ShowPause();
    return;
}
auto HeroLocation = game.heroPlayer->getLocation();
HeroLocation->RemoveHero(game.heroPlayer);
CurrentLocation->AddHero(game.heroPlayer);
game.MyTerminal.StylizeTextBoard(game.heroPlayer->getName() + " moved to dracula spot!");
game.MyTerminal.ShowPause();
}
//Move :
void Dracula :: Move(std :: shared_ptr<Location> NearestOppenent) {
    if(!CurrentLocation) return;
    CurrentLocation->RemoveMonster(shared_from_this());
    CurrentLocation = NearestOppenent;
    CurrentLocation->AddMonster(shared_from_this());   
}
//coffins :
void Dracula::AddDetroyedCoffin( std :: string LocationName)
{
    if(!IsCoffinDestroyed(LocationName)){
    for(auto & coffin : Table)
    {
        if(coffin.second == LocationName)
        coffin.first = true;

    }
}
}

bool Dracula ::IsCoffinDestroyed(std :: string locName)
{
    for(auto & pair : Table)
    {
        if(pair.second == locName)
        {
                return pair.first;
        }
    }
    throw std :: invalid_argument("Coffin Not found in this Location!\n");
}
bool Dracula :: CanBeDefeated()
{
    for(const auto & c : Table)
    {
        if(!c.first)
        return false;

    }
    return true;
}
bool Dracula::IsTasksLocation(std :: string LocationName)
{
    for(const auto & loc : Table)
    {
        if(loc.second == LocationName)
        return true;
    }
    return false;
}
std :: vector<bool> Dracula::GetCoffinsDestroyed()
{
    std::vector<bool> coffins;
    for(const auto & c : Table)
    {
        coffins.push_back(c.first);
    }
    return coffins;
}


