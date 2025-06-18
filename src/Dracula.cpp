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
void Dracula :: DarkCharm(std :: shared_ptr<Hero> CurrentHero) {
std :: cout << "Dracula using Dark Charm !!\n";
if(CurrentHero->getLocation()->GetCityName() == CurrentLocation->GetCityName())
{
    std :: cout << "Hero Already in Dracula's Location.\n";
}
auto HeroLocation = CurrentHero->getLocation();
HeroLocation->RemoveHero(CurrentHero);
CurrentLocation->AddHero(CurrentHero);
}
//Move :
void Dracula :: Move(std :: shared_ptr<Location> NearestOppenent) {
    std :: cout << "Dracula Moves toward nearest hero or villager!!\n";
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

// void Dracula:: ShowDraculaMat(){
//     std :: cout << "Dracula Mat : ";
//     for(const auto & coff : Table)
//     {
//         if(coff)
//         std :: cout << "* " ;
//         else 
//         std :: cout << "-";
//     }
// }
