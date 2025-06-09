#include "../include/Location.hpp"
#include <string>
#include <algorithm>
#include "../include/Monster.hpp"
#include "../include/Item.hpp"

// Constructor 
Location :: Location(const std::string& name, int x, int y) : Name(name), x(x), y(y) {}
Location ::Location(const std ::string& name)
{
    this->Name = name;
}
// Neighbor for that location
void Location :: AddNeighbor(Location *neighbor){
    neighbors.push_back(neighbor);
    
}
std::vector<Location*> Location :: GetNeighbors() const{
    return neighbors;
}
// Monsters in that location : 
void Location :: AddMonster(Monster *monsterName) {
    Monsters.push_back(monsterName);
}
void  Location :: RemoveMonster(const Monster* monsterName){
auto it = std :: find(Monsters.begin() , Monsters.end() , monsterName);
if(it != Monsters.end())
Monsters.erase(it);
}
std :: vector<Monster*> Location ::  GetMonsters() const{
    return Monsters;
}
//Item in that location : 
void Location::AddItem(Item ItemName){
    itemes.push_back(ItemName);
}

void Location::RemoveItem(Item ItemName){
auto it = std :: find(itemes.begin() , itemes.end() , ItemName);
if(it != itemes.end())
itemes.erase(it);
}
std::vector<Item>& Location::GetItems(){
    return itemes;
}
//Heros in that location :

void Location :: AddHero  (Hero* HeroName){
    Heros.push_back(HeroName);

}
void Location :: RemoveHero(Hero *HeroName){
auto it = std :: find(Heros.begin() , Heros.end() , HeroName);
if(it != Heros.end())
Heros.erase(it);

}
std :: vector <Hero*> Location :: GetHero(){return Heros;}
//Get City Info 
std ::string Location :: GetCityName() const {return Name;};
int Location :: GetX () const {return x;}
int Location :: GetY () const {return y;}
