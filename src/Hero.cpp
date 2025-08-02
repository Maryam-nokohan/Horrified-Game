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
        game.MyTerminal.ShowMessageBox("No perks in the inventory!");
    }
}
void Hero::DecreaseAction() { --remainingActions; }
bool Hero::PlayerGetHit(Game &game)
{
    bool successe = false;

    if (!inventory.empty())
    {
        game.MyTerminal.ShowMessageBox("Would You Like to use an Items " + name + " ?");
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
            game.MyTerminal.ShowMessageBox("Choose an Item to discard :");
            int index = game.MyTerminal.MenuGenerator(ItemNames);
            RemoveItem(inventory[index]);
            return successe;
        }
        case 1:
        {
            successe = true;
            game.MyTerminal.ShowPopupMessages(game,"monster hits you you'll start from the hospital in the next hero phase");
            currentLocation->RemoveHero(shared_from_this());
            SetLocation(game.mapPlan.GetLocationptr(Hospital));
            game.terrorLevel++;
            game.MyTerminal.ShowMonsterPhase(game , game.MonsterDeck.back());
            return successe;
        }
        default:
        return false;
        break;
    }
}
else
{
    game.MyTerminal.ShowPopupMessages(game,"Not enaugth Items !!");
    game.MyTerminal.ShowPopupMessages(game,"monster hits you you'll start from the hospital in the next hero phase");
    successe = true;
    currentLocation->RemoveHero(shared_from_this());
    SetLocation(game.mapPlan.GetLocationptr(Hospital));
    game.terrorLevel++;
    game.MyTerminal.ShowMonsterPhase(game , game.MonsterDeck.back());
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
        game.MyTerminal.ShowMessageBox("You haven't completed the task for " + monsterName + "!");
        
        return;
    }

    if (monster->GetLocation()->GetCityName() != currentLocation->GetCityName())
    {
        game.MyTerminal.ShowMessageBox("You are not in the same location as the monster!");
        
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
        game.MyTerminal.ShowMessageBox("Unknown monster type.");
        
        return;
    }

    // Filter inventory
    std::vector<std::shared_ptr<Item>> filteredItems, usedItems;
    std::vector<std::string> filtteredNames;
    for (const auto &item : inventory)
    {
        if (item->getColor() == requiredColor)
        {
            filteredItems.push_back(item);
            filtteredNames.push_back(item->getName() + " " + "(" + std::to_string(item->getPower()) + ")");
        }
    }

    // Check item empty
    if (filteredItems.empty())
    {
        game.MyTerminal.ShowMessageBox("You don't have any required-color items!");
        
        return;
    }

    int total = 0;
    int selected = -1;
    filtteredNames.push_back("Exit");
    while (true)
    {
        game.MyTerminal.ShowMessageBox("Choose items:");
        selected = game.MyTerminal.MenuGenerator(filtteredNames);

        if (selected == filteredItems.size()) // Exit option selected
            break;

        if (selected < 0 || selected >= filteredItems.size())
        {
            game.MyTerminal.ShowMessageBox("Invalid selection. Try again.");
            continue;
        }

        total += filteredItems[selected]->getPower();
        if (name == "Scientist")
        {
            game.MyTerminal.ShowMessageBox("Would you like to use your ability on " + filtteredNames[selected] + " Scientist?");
            int s = game.MyTerminal.MenuGenerator({"yes", "no"});
            if (s == 0)
            {
                total++;
               game.MyTerminal.ShowMessageBox("Added 1 power to " + filtteredNames[selected]);
            }
        }
        usedItems.push_back(filteredItems[selected]);
        filteredItems.erase(filteredItems.begin() + selected);

        // Update the item list
        filtteredNames.clear();
        for (const auto &i : filteredItems)
            filtteredNames.push_back(i->getName() + " (" + std::to_string(i->getPower()) + ")");

        filtteredNames.push_back("Exit");

        if (filteredItems.empty())
        {
            game.MyTerminal.ShowMessageBox("No more items to choose from.");
            break;
        }
    }
    if (total >= requiredPower)
    {
        for (auto &item : usedItems)
            RemoveItem(item);

        DecreaseAction();

        monster->GetLocation()->RemoveMonster(monster);

        auto &monsters = game.Monsters;
        monsters.erase(std::remove(monsters.begin(), monsters.end(), monster), monsters.end());

        game.MyTerminal.ShowMessageBox("You defeated " + monsterName);
        
    }
    else
    {
        game.MyTerminal.ShowMessageBox("Total power: " + std::to_string(total) + " , Requierd Power : " + std::to_string(requiredPower));
        game.MyTerminal.ShowMessageBox("Not enough item power to defeat the monster!");
        
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
void Hero::pickUpItems(std::shared_ptr<Item> item)
{
    if (item)
    {
        inventory.push_back(item);
        item->getLocation()->RemoveItem(item);
        return;
    }
    else 
    return;
}
void Hero::addItems(std::shared_ptr<Item> item)
{
    if(item)
    {
        inventory.push_back(item);
    }
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
std::vector<std::shared_ptr<PerkCard>> & Hero::getPerks(){return PerkCards;}
