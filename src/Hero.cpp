#include "../include/Hero.hpp"
#include "../include/Location.hpp"
#include "../include/Dracula.hpp"
#include "../include/invisible.hpp"
#include "../include/Game.hpp"
#include "../include/Perk.hpp"
#include "../include/LocationNames.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace LocationNames;
// constructor
Hero::Hero(const std::string &Name, int MaxActions, std ::shared_ptr<Location> CurrentLocation)
    : name(Name), maxActions(MaxActions), remainingActions(MaxActions)
{
    if (CurrentLocation)
    {
        currentLocation = CurrentLocation;
    }
    else
        throw std ::invalid_argument("Location can't be nullptr for hero");
}
// add perkCard to inventory
void Hero::GetPerkCard(std ::shared_ptr<PerkCard> Card)
{
    PerkCards.push_back(Card);
}
// Set max action
void Hero::SetAction(int NumOfAction)
{
    if (NumOfAction >= 0)
    {
        remainingActions = NumOfAction;
    }
    else
        throw std::invalid_argument("Number of actions can't be nagetive!\n");
}
// remove card from inventory
void Hero::UsePerkCard(Game &game)
{
    if (!PerkCards.empty())
    {
        auto card = PerkCards.back();
        card->ApplyEffect(game);
        PerkCards.pop_back();
    }
    else
    {
        game.MyTerminal.StylizeTextBoard("No perks in the inventory!");
        game.MyTerminal.ShowPause();
    }
}
void Hero::DecreaseAction() { --remainingActions; }
bool Hero::PlayerGetHit(Game &game)
{
    bool successe = false;

    if (!inventory.empty())
    {
        game.MyTerminal.StylizeTextBoard("Would You Like to use an Items " + name + " ?");
        int selected = game.MyTerminal.MenuGenerator(std ::vector<std ::string>{"Yes", "No"});
        switch (selected)
        {
        case 0:
        {
            std ::vector<std ::string> ItemNames;
            for (const auto &item : inventory)
            {
                ItemNames.push_back(item->getName());
            }
            game.MyTerminal.StylizeTextBoard("Choose an Item to discard :");
            int index = game.MyTerminal.MenuGenerator(ItemNames);
            RemoveItem(inventory[index]);
            return successe;
        }
        case 1:
        {
            successe = true;
            game.MyTerminal.StylizeTextBoard("monster hits you you'll start from the hospital in the next hero phase");
            game.MyTerminal.ShowPause();
            currentLocation->RemoveHero(shared_from_this());
            SetLocation(game.mapPlan.GetLocationptr(Hospital));
            game.terrorLevel++;
            return successe;
        }
        default:
            return false;
            break;
        }
    }
    else
    {
        game.MyTerminal.StylizeTextBoard("Not enaugth Items !!");
        game.MyTerminal.StylizeTextBoard("monster hits you you'll start from the hospital in the next hero phase");
        successe = true;
        game.MyTerminal.ShowPause();
        currentLocation->RemoveHero(shared_from_this());
        SetLocation(game.mapPlan.GetLocationptr(Hospital));
        game.terrorLevel++;
        return successe;
    }
}
void Hero::resetActions()
{
    remainingActions = maxActions;
}
void Hero::DefeatAction(std::shared_ptr<Monster> monster, Game &game)
{
    if (!monster)
        throw std::invalid_argument("No monster to defeat");

    auto monsterName = monster->GetName();

    if (!monster->CanBeDefeated())
    {
        game.MyTerminal.StylizeTextBoard("You haven't completed the task for " + monsterName + "!");
        game.MyTerminal.ShowPause();
        return;
    }

    if (monster->GetLocation()->GetCityName() != currentLocation->GetCityName())
    {
        game.MyTerminal.StylizeTextBoard("You are not in the same location as the monster!");
        game.MyTerminal.ShowPause();
        return;
    }

    int requiredPower = 0;
    ItemColor requiredColor;

    if (monsterName == "Dracula")
    {
        requiredPower = 6;
        requiredColor = ItemColor::Yellow;
    }
    else if (monsterName == "Invisible Man")
    {
        requiredPower = 9;
        requiredColor = ItemColor::Red;
    }
    else
    {
        game.MyTerminal.StylizeTextBoard("Unknown monster type.");
        game.MyTerminal.ShowPause();
        return;
    }

    // Filter inventory
    std::vector<std::shared_ptr<Item>> filteredItems, usedItems;
    for (const auto &item : inventory)
    {
        if (item->getColor() == requiredColor)
            filteredItems.push_back(item);
    }

    // Check item empty
    if (filteredItems.empty())
    {
        game.MyTerminal.StylizeTextBoard("You don't have any required-color items!");
        game.MyTerminal.ShowPause();
        return;
    }

    // Greedy aproach
    int total = 0;
    std::sort(filteredItems.begin(), filteredItems.end(), [](const auto &a, const auto &b)
              { return a->getPower() < b->getPower(); });

    for (const auto &item : filteredItems)
    {
        if (total >= requiredPower)
            break;
        total += item->getPower();
        usedItems.push_back(item);
    }

    if (total >= requiredPower)
    {
        for (auto &item : usedItems)
            RemoveItem(item);

        DecreaseAction();

        monster->GetLocation()->RemoveMonster(monster);

        auto &monsters = game.Monsters;
        monsters.erase(std::remove(monsters.begin(), monsters.end(), monster), monsters.end());

        game.MyTerminal.StylizeTextBoard("You defeated " + monsterName);
        game.MyTerminal.ShowPause();
    }
    else
    {
        game.MyTerminal.StylizeTextBoard("Total power: " + std::to_string(total) + " , Requierd Power : " + std::to_string(requiredPower)) ;
        game.MyTerminal.StylizeTextBoard("Not enough item power to defeat the monster!");
        game.MyTerminal.ShowPause();
    }
}

void Hero::moveTo(std ::shared_ptr<Location> newLocation)
{
    if (remainingActions > 0)
    {
        SetLocation(newLocation);
    }
}
void Hero::RemoveItem(const std ::shared_ptr<Item> item)
{
    auto it = std ::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end())
        inventory.erase(it);
}
void Hero::pickUpItems()
{
    auto items = currentLocation->GetItems();
    if (!items.empty())
    {
        inventory.insert(inventory.end(), items.begin(), items.end());
        currentLocation->ClearItems();
    }
    DecreaseAction();
}
void Hero::SetLocation(std ::shared_ptr<Location> location)
{
    if (currentLocation && currentLocation->GetCityName() == location->GetCityName())
    {
        return;
    }

    if (currentLocation)
    {
        currentLocation->RemoveHero(shared_from_this());
    }

    currentLocation = location;

    if (currentLocation)
    {
        currentLocation->AddHero(shared_from_this());
    }
    else
        throw std ::invalid_argument("Error! Nullptr location for Hero !\n");
}
const std::string &Hero::getName() const
{
    return name;
}
std::shared_ptr<PerkCard> Hero::PeekPerkCard() const
{
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
    if (currentLocation)
        return currentLocation;
    else
        throw std::invalid_argument("Location is null for hero!\n");
}
const std::vector<std ::shared_ptr<Item>> &Hero::getInventory() const
{
    return inventory;
}
