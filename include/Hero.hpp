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

enum class ActionType
{
    Move,
    Guide,
    PickUp,
    Advance,
    Defeat,
    Special
};

class Hero : public std :: enable_shared_from_this<Hero>
{
protected:
    std::string name;
    int maxActions;
    int remainingActions;
    std::vector<std :: shared_ptr< Item>> inventory;
    std :: shared_ptr<Location> currentLocation;
    std ::vector <std :: shared_ptr<PerkCard>> PerkCards;

public:
    Hero() = default;
    Hero(const std::string &, int, std :: shared_ptr<Location>);
    virtual ~Hero() = default;
    std::shared_ptr<PerkCard> UsePerkCard();
    void GetPerkCard(std :: shared_ptr<PerkCard>);
    void resetActions();
    void moveTo(std :: shared_ptr<Location>);
    void PlayerGetHit(Game& game);
    void pickUpItems();
    virtual void specialAction() = 0;
    virtual bool DefeatAction(std ::vector< std :: shared_ptr<Monster>>);
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