#ifndef HERO_HPP
#define HERO_HPP
#include <string>
#include <vector>
#include <memory>
class Location;
class Monster;
class Item;
class PerkCard;
class Game;

class Hero : public std :: enable_shared_from_this<Hero>
{
    friend class GameFileHandler;
protected:
    std::string name;
    int maxActions;
    int remainingActions;
    std::vector<std :: shared_ptr< Item>> inventory;
    std :: shared_ptr<Location> currentLocation;
    std ::vector <std :: shared_ptr<PerkCard>> PerkCards;
// test
public:
    Hero() = default;
    Hero(const std::string &, int, std :: shared_ptr<Location>);
    virtual ~Hero() = default;
    void UsePerkCard(Game&);
    void GetPerkCard(std :: shared_ptr<PerkCard>);
    std::vector<std::shared_ptr<PerkCard>> & getPerks();
    void resetActions();
    void moveTo(std :: shared_ptr<Location>);
    bool PlayerGetHit(Game& game);
    void pickUpItems(std::shared_ptr<Item>);
    virtual void specialAction(Game&) = 0;
    virtual void DefeatAction(std :: shared_ptr<Monster> , Game&);
    void SetLocation(std :: shared_ptr<Location>location);
    virtual void SetAction(int);

    const std::string &getName() const;
    int getRemainingActions() const;
    const std :: shared_ptr<Location> & getLocation() const;
    const std::vector<std :: shared_ptr< Item>> &getInventory() const;
    void RemoveItem(const std :: shared_ptr< Item>);
    std::shared_ptr<PerkCard> PeekPerkCard() const ;
    void DecreaseAction();

};

#endif