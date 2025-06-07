#ifndef LOCATION_HPP
#define LOCATION_HPP
#include "../include/Monster.hpp"

#include <string>
#include <vector>
#include <string>
#include <vector>

class Location
{
private:
    int x, y;
    std ::string Name;
    std ::vector<Location *> neighbors;
    // std :: vector <Item>
    // std :: vector <Hero>
    // std :: vector <villager>
    std ::vector<Monster *> Monsters;

public:
    Location(const std ::string &name);
    Location(const std ::string &name, int x, int y);
    void AddNeighbor(Location *neighbor);
    std::vector<Location *> GetNeighbors() const;
    // void AddMonster(Monster* monsterName);
    // void RemoveMonster(Monster *monsterName);
    // void AddVillager(Villager* VillagerName);
    // void RemoveVillager(Villager *VillagerName);
    // void AddItem(Item* ItemName);
    // void RemoveItem(Item *ItemName);
    // void AddHero(Hero* HeroName);
    // void RemoveHero(Hero *HeroName);
    std ::string GetName();
    // std :: vector<Monster*> GetMonsters();
    // std :: vector GetItem();
    // std :: vector GetHeros();
    // std :: vector GetItem();
    // std :: vector GetVillagers();
    ~Location() {};
};
#endif