#include "../include/Location.hpp"
#include "../include/Villager.hpp"
#include <string>
#include <algorithm>

// Constructor
Location ::Location(const std::string &name, int x, int y) : Name(name), x(x), y(y) {}
Location ::Location(const std ::string &name)
{
    this->Name = name;
}
// Neighbor for that location
void Location ::AddNeighbor(std :: shared_ptr<Location> neighbor)
{
    neighbors.push_back(neighbor);
}
std::vector<std :: shared_ptr<Location>> Location ::GetNeighbors() const
{
    return neighbors;
}
// Monsters in that location :
void Location ::AddMonster(std :: shared_ptr <Monster>monsterName)
{
    Monsters.push_back(monsterName);
}
void Location ::RemoveMonster(const std :: shared_ptr <Monster>monsterName)
{
    auto it = std ::find(Monsters.begin(), Monsters.end(), monsterName);
    if (it != Monsters.end())
        Monsters.erase(it);
}
std ::vector<std :: shared_ptr <Monster>> Location ::GetMonsters() const
{
    return Monsters;
}
// villager in that location :
void Location ::AddVillager(std :: shared_ptr<Villager> villagerName)
{
    Villagers.push_back(villagerName);
}
void Location ::RemoveVillager(std :: shared_ptr<Villager> villagerName)
{
    auto it = std ::find(Villagers.begin(), Villagers.end(), villagerName);
    if (it != Villagers.end())
        Villagers.erase(it);
}
std ::vector<std :: shared_ptr<Villager>> &Location ::GetVillager()
{
    return Villagers;
}

// Item in that location :
void Location::AddItem(std :: shared_ptr< Item> ItemName)
{
    itemes.push_back(ItemName);
}

void Location::RemoveItem(std :: shared_ptr< Item> ItemName)
{
    auto it = std ::find(itemes.begin(), itemes.end(), ItemName);
    if (it != itemes.end())
        itemes.erase(it);
}
std::vector<std :: shared_ptr< Item>> &Location::GetItems()
{
    return itemes;
}
void Location::ClearItems()
{
    for(auto & item : itemes)
    {
        RemoveItem(item);
    }
}
// Heros in that location :

void Location ::AddHero(std :: shared_ptr<Hero> HeroName)
{
    Heros.push_back(HeroName);
}
void Location ::RemoveHero(std :: shared_ptr<Hero> HeroName)
{
    auto it = std ::find(Heros.begin(), Heros.end(), HeroName);
    if (it != Heros.end())
        Heros.erase(it);
}
std ::vector<std :: shared_ptr<Hero> > Location ::GetHero() { return Heros; }
// Get City Info
std ::string Location ::GetCityName() const { return Name; };
int Location ::GetX() const { return x; }
int Location ::GetY() const { return y; }
