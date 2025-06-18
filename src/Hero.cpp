#include "../include/Hero.hpp"
#include "Location.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

Hero::Hero(const std::string &name, int maxActions, std ::shared_ptr<Location> currentLocation)
    : name(name), maxActions(maxActions), remainingActions(maxActions), currentLocation(currentLocation) {}

void Hero:: GetPerkCard(std :: shared_ptr<PerkCard> Card){
    PerkCards.push_back(Card);

}
std::shared_ptr<PerkCard> Hero::UsePerkCard() {
    if (!PerkCards.empty()) {
        auto card = PerkCards.back();
        PerkCards.pop_back();
        return card;
    }
    return nullptr;
}

void Hero::resetActions()
{
    remainingActions = maxActions;
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
