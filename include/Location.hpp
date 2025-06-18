#ifndef LOCATION_HPP
#define LOCATION_HPP


#include <memory>
#include <string>
#include <vector>
class Hero; class Monster; class Villager ;class Item;
class Location
{
private:
    int x, y;
    std ::string Name;
    std ::vector<std :: shared_ptr<Location>> neighbors;
    std :: vector <std :: shared_ptr< Item>> itemes ;
    std :: vector <std :: shared_ptr<Hero>> Heros;
    std :: vector <std :: shared_ptr<Villager>> Villagers;
    std ::vector<std :: shared_ptr<Monster>> Monsters;

public:
    Location(const std ::string &name);
    Location(const std ::string &name, int x, int y);
    void AddNeighbor(std :: shared_ptr<Location> neighbor);
    std::vector<std :: shared_ptr<Location> > GetNeighbors() const;
    void AddMonster(std :: shared_ptr<Monster> monsterName);
    void RemoveMonster(const std :: shared_ptr<Monster>monsterName);
    std :: vector<std:: shared_ptr<Monster>> GetMonsters() const ;
    void AddItem(std :: shared_ptr< Item> ItemName);
    void RemoveItem(std :: shared_ptr< Item> ItemName); 
    void ClearItems();
    std :: vector<std :: shared_ptr< Item>>& GetItems();
    void AddVillager(std :: shared_ptr<Villager> villagerName);
    void RemoveVillager(std :: shared_ptr<Villager> villagerName);
    std :: vector <std :: shared_ptr<Villager>> & GetVillager();
    void AddHero(std :: shared_ptr<Hero> HeroName);
    void RemoveHero(std :: shared_ptr<Hero> HeroName);
    std ::vector<std :: shared_ptr<Hero> > GetHero();
    std ::string GetCityName()const;
    int GetX()const ;
    int GetY()const ;
    
    ~Location() {};
};
#endif