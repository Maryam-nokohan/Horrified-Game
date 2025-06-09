#ifndef LOCATION_HPP
#define LOCATION_HPP
#include "../include/Monster.hpp"
#include "../include/Hero.hpp"

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
    std :: vector <Item> itemes ;
    std :: vector <Hero*> Heros;
    // std :: vector <villager>
    std ::vector<Monster *> Monsters;

public:
    Location(const std ::string &name);
    Location(const std ::string &name, int x, int y);
    void AddNeighbor(Location *neighbor);
    std::vector<Location *> GetNeighbors() const;
    void AddMonster(Monster* monsterName);
    void RemoveMonster(const Monster *monsterName);
    std :: vector<Monster*> GetMonsters() const ;
    void AddItem(Item ItemName);
    void RemoveItem(Item ItemName); 
    std :: vector<Item>& GetItems();
    void AddHero(Hero* HeroName);
    void RemoveHero(Hero *HeroName);
    std :: vector <Hero*> GetHero();
    std ::string GetCityName()const;
    int GetX()const ;
    int GetY()const ;
    // void AddVillager(Villager* VillagerName);
    // void RemoveVillager(Villager *VillagerName);
    // std :: vector GetVillagers();
    ~Location() {};
};
#endif