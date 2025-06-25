#include "../include/Location.hpp"
#include "../include/Villager.hpp"
#include "../include/Item.hpp"
#include <string>
#include <algorithm>

// Constructor
Location ::Location(const std::string &name, int x, int y) : Name(name), x(x), y(y) {}
Location ::Location(const std ::string &name)
{
    this->Name = name;
}
// Neighbor for that location
void Location ::AddNeighbor(const std ::shared_ptr<Location>& neighbor)
{
    neighbors.push_back(neighbor);
}
const std::vector<std ::shared_ptr<Location>> &Location ::GetNeighbors() const
{
    return neighbors;
}
// Monsters in that location :
void Location ::AddMonster(const std ::shared_ptr<Monster>& monsterName)
{
    Monsters.push_back(monsterName);
}
void Location ::RemoveMonster(const std ::shared_ptr<Monster>& monsterName)
{
    auto it = std ::find(Monsters.begin(), Monsters.end(), monsterName);
    if (it != Monsters.end())
        Monsters.erase(it);
}
const std ::vector<std ::shared_ptr<Monster>> &Location ::GetMonsters() const
{
    return Monsters;
}
// villager in that location :
void Location ::AddVillager(const std ::shared_ptr<Villager>& villagerName)
{
    Villagers.push_back(villagerName);
}
void Location ::RemoveVillager( const std ::shared_ptr<Villager> &villagerName)
{
    auto it = std ::remove(Villagers.begin(), Villagers.end(), villagerName);
    if (it != Villagers.end())
    {
        Villagers.erase(it , Villagers.end());
    }
}
const std ::vector<std ::shared_ptr<Villager>> &Location ::GetVillager()
{
    return Villagers;
}

// Item in that location :
void Location::AddItem(const std ::shared_ptr<Item>& ItemName)
{
    itemes.push_back(ItemName);
}

void Location::RemoveItem( const std ::shared_ptr<Item> &ItemName)
{
    auto it = std ::find(itemes.begin(), itemes.end(), ItemName);
    if (it != itemes.end())
    {
        itemes.erase(it);
    }
}
const std::vector<std ::shared_ptr<Item>> &Location::GetItems()
{
    return itemes;
}
// Heros in that location :

void Location ::AddHero(const std ::shared_ptr<Hero>& HeroName)
{
    Heros.push_back(HeroName);
}
void Location ::RemoveHero( const std ::shared_ptr<Hero> &HeroName)
{
    auto it = std ::find(Heros.begin(), Heros.end(), HeroName);
    if (it != Heros.end())
    Heros.erase(it);
}
void Location::ClearItems()
{
    for(int i = 0 ;i <itemes.size() ; ++i)
    {
        RemoveItem(itemes[i]);
    }
    this->itemes.clear();
    this->itemes.resize(0);
}
const std ::vector<std ::shared_ptr<Hero>> &Location ::GetHero() { return Heros; }
// Get City Info
const std ::string& Location ::GetCityName(){ return Name; };
const int& Location ::GetX() { return x; }
const int& Location ::GetY() { return y; }
