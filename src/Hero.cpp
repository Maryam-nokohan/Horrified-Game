#include "../include/Hero.hpp"
#include "Location.hpp"
#include <iostream>
#include "../include/Dracula.hpp"
#include "../include/invisible.hpp"
#include "../include/Game.hpp"
#include <vector>
#include <algorithm>
#include <memory>

Hero::Hero(const std::string &Name, int MaxActions, std ::shared_ptr<Location> CurrentLocation)
    : name(Name), maxActions(MaxActions), remainingActions(MaxActions), currentLocation(CurrentLocation) {}

void Hero:: GetPerkCard(std :: shared_ptr<PerkCard> Card){
    PerkCards.push_back(Card);
}

void Hero:: SetAction(int NumOfAction){
    maxActions = NumOfAction;
}
std::shared_ptr<PerkCard> Hero::UsePerkCard() {
    if (!PerkCards.empty()) {
        auto card = PerkCards.back();
        PerkCards.pop_back();
        return card;
    }
    return nullptr;
}
void Hero::DecreaseAction(){--remainingActions;};
void Hero :: PlayerGetHit(Game &game){

    if(!inventory.empty()){
    game.MyTerminal.StylizeTextBoard("Would You Like to use an Items ?");
    int selected =game.MyTerminal.Show(game , std :: vector<std :: string>{"Yes" ,"No"});
    switch (selected)
    {
    case 0:{
    std :: vector <std :: string > ItemNames;
     for(const auto & item : inventory)
    {
        ItemNames.push_back(item->getName());
    }
    game.MyTerminal.StylizeTextBoard( "Choose an Item to discard :");
    int index = game.MyTerminal.Show(game, ItemNames);
    RemoveItem(inventory[index]);
    DecreaseAction();
    break;
    }
    case 1 : {
        currentLocation->RemoveHero(shared_from_this());
        SetLocation(game.mapPlan.GetLocationptr("Hospital"));
        game.terrorLevel++;
        break;}
        default:
        break;
    }
}
else{
   

    game.MyTerminal.StylizeTextBoard("Not enaugth Items !!");
    game.MyTerminal.ShowPause();
    currentLocation->RemoveHero(shared_from_this());
    SetLocation(game.mapPlan.GetLocationptr("Hospital"));
    game.terrorLevel++;
}

}

void Hero::resetActions()
{
    remainingActions = maxActions;
}
bool Hero::DefeatAction(std ::vector< std :: shared_ptr<Monster>> monsters)
{
    std :: shared_ptr<Monster> monster;
    if(monsters.size() == 2)
    {
       std :: vector< std :: shared_ptr<Monster>> m1;
       std :: vector< std :: shared_ptr<Monster>> m2;
        m1.push_back( monsters[1]);
        m2.push_back(monsters[0]);
        DefeatAction(m1);
        DefeatAction(m2);
    }
    else
    {
        monster = monsters[0];
    }
    //Dracula
    if(!monster->CanBeDefeated())
    {
        return false;
    }
    int total = 0;
    int requiredPower = 6;
    std::vector<std :: shared_ptr<Item>> usedItems;
    if(auto dracula = std :: dynamic_pointer_cast<Dracula>(monster))
    {
        if(monster->GetLocation()->GetCityName() == currentLocation->GetCityName())
        {
                 std::vector<std :: shared_ptr<Item>> YellowItems;
                for (const auto& item : inventory)
                    if (item->getColor() == ItemColor::Yellow)
                        YellowItems.push_back(item);

                std::sort(YellowItems.begin(), YellowItems.end(), [](const std :: shared_ptr<Item>& a, const std :: shared_ptr<Item>& b) {
                    return a->getPower() < b->getPower();
                });

                for (const auto& item : YellowItems) {
                    if (total >= requiredPower) break;
                    total += item->getPower();
                    usedItems.push_back(item);
                }

        }

    }
    //Invisible man
    else if(auto invisibleMan = std :: dynamic_pointer_cast<InvisibleMan>(monster))
    {
        if(monster->GetLocation()->GetCityName() == currentLocation->GetCityName())
        {
             requiredPower = 9;
                 std::vector<std :: shared_ptr<Item>> RedItems;
                for (const auto& item : inventory)
                    if (item->getColor() == ItemColor::Red)
                        RedItems.push_back(item);

                std::sort(RedItems.begin(), RedItems.end(), [](const std :: shared_ptr<Item>& a, const std :: shared_ptr<Item>& b) {
                    return a->getPower() < b->getPower();
                });

                int total = 0;
                for (const auto& item : RedItems) {
                    if (total >= requiredPower) break;
                    total += item->getPower();
                    usedItems.push_back(item);
                }

        }
    }
     if (total >= requiredPower ) {
                    for (const auto& item : usedItems)
                        this->RemoveItem(item);
                        return true;
                } else {
                    return false;
                }

}
void Hero::moveTo(std ::shared_ptr<Location> newLocation)
{
    if (remainingActions > 0)
    {
        SetLocation(newLocation);
        --remainingActions;
    }
}
void Hero ::RemoveItem(const std :: shared_ptr< Item> item)
{
    auto it = std ::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end())
        inventory.erase(it);
}
void Hero::pickUpItems()
{
    if (remainingActions > 0)
    {
        auto items = currentLocation->GetItems();
        if (!items.empty())
        {
            inventory.insert(inventory.end(), items.begin(), items.end());
            for (auto &item : items)
            {
               
                currentLocation->RemoveItem(item);
                --remainingActions;
            }
        }
    }
}
void Hero ::SetLocation(std ::shared_ptr<Location> location)
{
    if (currentLocation && currentLocation->GetCityName() == location->GetCityName())
    {
        return;
    }

    if (currentLocation != nullptr)
    {
        currentLocation->RemoveHero(shared_from_this());
    }

    currentLocation = location;

    if (currentLocation != nullptr)
    {
        currentLocation->AddHero(shared_from_this());
    }
}
const std::string &Hero::getName() const
{
    return name;
}
std::shared_ptr<PerkCard> Hero::PeekPerkCard() const {
    if (!PerkCards.empty())
        return PerkCards.back();
    return nullptr;
}
int Hero::getRemainingActions() const
{
    return remainingActions;
}

const std ::shared_ptr<Location> &Hero::getLocation() const
{
    return currentLocation;
}

const std::vector<std :: shared_ptr< Item>> &Hero::getInventory() const
{
    return inventory;
}
