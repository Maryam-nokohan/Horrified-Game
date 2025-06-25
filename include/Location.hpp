#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <memory>
#include <string>
#include <vector>
class Hero;
class Monster;
class Villager;
class Item;
class Location
{
private:
    int x, y;
    std ::string Name;
    std ::vector<std ::shared_ptr<Location>> neighbors;
    std ::vector<std ::shared_ptr<Item>> itemes;
    std ::vector<std ::shared_ptr<Hero>> Heros;
    std ::vector<std ::shared_ptr<Villager>> Villagers;
    std ::vector<std ::shared_ptr<Monster>> Monsters;

public:
    explicit Location(const std ::string &name);
    Location(const std ::string &name, int x, int y);
    void AddNeighbor(const std ::shared_ptr<Location>& neighbor);
    const std::vector<std ::shared_ptr<Location>> &GetNeighbors() const;
    void AddMonster(const std ::shared_ptr<Monster>& monsterName);
    void RemoveMonster(const std ::shared_ptr<Monster>& monsterName);
    const std ::vector<std::shared_ptr<Monster>> &GetMonsters() const;
    void AddItem(const std ::shared_ptr<Item>& ItemName);
    void RemoveItem( const std ::shared_ptr<Item> &ItemName);
    void ClearItems();
    const std ::vector<std ::shared_ptr<Item>> &GetItems();
    void AddVillager(const std ::shared_ptr<Villager>& villagerName);
    void RemoveVillager( const std ::shared_ptr<Villager> &villagerName);
    const std ::vector<std ::shared_ptr<Villager>> &GetVillager();
    void AddHero(const std ::shared_ptr<Hero>& HeroName);
    void RemoveHero( const std ::shared_ptr<Hero> &HeroName);
    const std ::vector<std ::shared_ptr<Hero>>& GetHero();
    const std ::string& GetCityName() ;
    const int& GetX() ;
    const int& GetY() ;

    ~Location() {};
};
#endif