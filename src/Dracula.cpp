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
game.MyTerminal.ShowPopupMessages(game,"Dracula using Dark Charm !!");
game.MyTerminal.ShowMonsterPhase(game , game.MonsterDeck.back());
auto HerosInGame = game.heroes;
for(const auto & h : HerosInGame){
if(h->getLocation()->GetCityName() == CurrentLocation->GetCityName())
{
    game.MyTerminal.ShowPopupMessages(game,h->getName() + " Already in Dracula's Location.");
    game.MyTerminal.ShowMonsterPhase(game , game.MonsterDeck.back());
    return;
}
}
auto HeroLocation = game.heroPlayer->getLocation();
HeroLocation->RemoveHero(game.heroPlayer);
game.heroPlayer->moveTo(CurrentLocation);
game.MyTerminal.ShowPopupMessages(game,game.heroPlayer->getName() + " moved to dracula spot!");
game.MyTerminal.ShowMonsterPhase(game , game.MonsterDeck.back());
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
std :: vector<std:: pair<bool , std::string>> Dracula::GetCoffins() const
{
    return Table;
}


