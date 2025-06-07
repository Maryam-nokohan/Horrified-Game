#include "../include/Location.hpp"
#include <string>

Location :: Location(const std::string& name, int x, int y) : Name(name), x(x), y(y) {}
Location ::Location(const std ::string& name)
{
    this->Name = name;
}
void Location :: AddNeighbor(Location *neighbor){
    neighbors.push_back(neighbor);
    
}
std::vector<Location*> Location :: GetNeighbors() const{
    return neighbors;
}


void AddMonster(Monster *monsterName) {}
// void RemoveMonster(Monster *monsterName);
// void AddVillager(Villager* VillagerName);
// void RemoveVillager(Villager *VillagerName);
// void AddItem(Item* ItemName);
// void RemoveItem(Item *ItemName);
// void AddHero(Hero* HeroName);
// void RemoveHero(Hero *HeroName);
std ::string Location :: GetName(){return Name;};
// std ::vector<Monster *> GetMonsters();
// std :: vector GetItem();
// std :: vector GetHeros();
// std :: vector GetItem();
// std :: vector GetVillagers();
