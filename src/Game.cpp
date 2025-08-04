#include "../include/Monster.hpp"
#include "../include/LocationNames.hpp"
#include "../include/MonsterCard.hpp"
#include "../include/Mayor.hpp"
#include "../include/Archaelogist.hpp"
#include "../include/Courier.hpp"
#include "../include/scientist.hpp"
#include "../include/Card.hpp"
#include "../include/Perk.hpp"
#include "../include/Dice.hpp"
#include "../include/Game.hpp"
#include "../include/Location.hpp"
#include "../include/Dracula.hpp"
#include "../include/invisible.hpp"
#include "../include/ErrorHandler.hpp"
#include "../include/Villager.hpp"
#include "../include/Names.hpp"
#include "../include/file.hpp"
#include "../include/Terminal.hpp"
#include <unordered_set>
#include <queue>
#include <iostream>
#include "algorithm"
#include <random>
#include <filesystem>
#include <memory>
namespace ErrorType
{
    inline const std ::string String = "string";
    inline const std ::string Int = "int";
    inline const std ::string Float = "float";
}
using namespace ErrorType;
using namespace LocationNames;
using namespace Names;
// constructor
Game ::Game() : terrorLevel(0), heroPlayer(nullptr), GameOver(false), skipMonsterPhase(false), showMessage(true), message("")
{
    SetUpGame();
}
// destructor
Game ::~Game()
{
    heroes.clear();
    Monsters.clear();
    villagers.clear();
    Items.clear();
    EmptyBackUpItems.clear();
    PerkDeck.clear();
    MonsterDeck.clear();
};
void Game ::InitializeLocations()
{
    mapPlan.addLocation(Cave, 0, 0);
    mapPlan.addLocation(Camp, 1, 0);
    mapPlan.addLocation(Precinct, 2, 0);
    mapPlan.addLocation(Inn, 3, 0);
    mapPlan.addLocation(Barn, 4, 0);
    mapPlan.addLocation(Dungeon, 5, 0);
    mapPlan.addLocation(Tower, 6, 0);
    mapPlan.addLocation(Docks, 7, 0);
    mapPlan.addLocation(Institute, 9, 0);
    mapPlan.addLocation(Laboratory, 10, 0);
    mapPlan.addLocation(Graveyard, 11, 0);
    mapPlan.addLocation(Church, 12, 0);
    mapPlan.addLocation(Shop, 13, 0);
    mapPlan.addLocation(Hospital, 14, 0);
    mapPlan.addLocation(Museum, 15, 0);
    mapPlan.addLocation(Abbey, 16, 0);
    mapPlan.addLocation(Mansion, 17, 0);
    mapPlan.addLocation(Theater, 19, 0);
    mapPlan.addLocation(Crypt, 20, 0);

    mapPlan.addEdge(Cave, Camp);

    mapPlan.addEdge(Camp, Precinct);

    mapPlan.addEdge(Precinct, Inn);

    mapPlan.addEdge(Precinct, Theater);

    mapPlan.addEdge(Mansion, Theater);

    mapPlan.addEdge(Precinct, Mansion);

    mapPlan.addEdge(Inn, Theater);

    mapPlan.addEdge(Inn, Camp);

    mapPlan.addEdge(Inn, Mansion);

    mapPlan.addEdge(Barn, Theater);

    mapPlan.addEdge(Theater, Tower);

    mapPlan.addEdge(Dungeon, Tower);

    mapPlan.addEdge(Tower, Docks);

    mapPlan.addEdge(Institute, Laboratory);

    mapPlan.addEdge(Laboratory, Shop);

    mapPlan.addEdge(Graveyard, Church);

    mapPlan.addEdge(Church, Shop);

    mapPlan.addEdge(Shop, Theater);

    mapPlan.addEdge(Camp, Theater);

    mapPlan.addEdge(Shop, Mansion);

    mapPlan.addEdge(Shop, Museum);

    mapPlan.addEdge(Church, Hospital);

    mapPlan.addEdge(Church, Mansion);

    mapPlan.addEdge(Museum, Mansion);

    mapPlan.addEdge(Museum, Church);

    mapPlan.addEdge(Abbey, Mansion);

    mapPlan.addEdge(Abbey, Crypt);

    mapPlan.addEdge(Mansion, Camp);
}
void Game ::InitializeItem()
{

    for (int i = 0; i < 2; i++)
    {

        Items.push_back(std::make_shared<Item>(ItemColor::Yellow, 2, mapPlan.GetLocationptr(LocationNames::Docks), Flower));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow, 3, mapPlan.GetLocationptr(LocationNames::Camp), TarotDeck));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow, 2, mapPlan.GetLocationptr(LocationNames::Inn), Garlic));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow, 3, mapPlan.GetLocationptr(LocationNames::Mansion), MirroredBox));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow, 3, mapPlan.GetLocationptr(LocationNames::Abbey), Stake));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow, 4, mapPlan.GetLocationptr(LocationNames::Museum), ScrollOfThoth));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow, 3, mapPlan.GetLocationptr(LocationNames::Camp), Violin));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow, 3, mapPlan.GetLocationptr(LocationNames::Museum), Tablet));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow, 4, mapPlan.GetLocationptr(LocationNames::Camp), Wolfsbane));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow, 4, mapPlan.GetLocationptr(LocationNames::Camp), Charm));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 2, mapPlan.GetLocationptr(LocationNames::Inn), Dart));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 3, mapPlan.GetLocationptr(LocationNames::Mansion), FirePoker));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 5, mapPlan.GetLocationptr(LocationNames::Theater), Rapier));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 2, mapPlan.GetLocationptr(LocationNames::Graveyard), Shovel));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 5, mapPlan.GetLocationptr(LocationNames::Barn), Torch));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 4, mapPlan.GetLocationptr(LocationNames::Barn), Pitchfork));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 6, mapPlan.GetLocationptr(LocationNames::Barn), Rifle));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 6, mapPlan.GetLocationptr(LocationNames::Shop), SilverCane));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 3, mapPlan.GetLocationptr(LocationNames::Docks), Knife));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 6, mapPlan.GetLocationptr(LocationNames::Precinct), Pistol));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 4, mapPlan.GetLocationptr(LocationNames::Shop), BearTrap));
        Items.push_back(std::make_shared<Item>(ItemColor::Red, 4, mapPlan.GetLocationptr(LocationNames::Institute), Speargun));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 1, mapPlan.GetLocationptr(LocationNames::Institute), AnatomyTest));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 1, mapPlan.GetLocationptr(LocationNames::Laboratory), Contrifuge));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 1, mapPlan.GetLocationptr(LocationNames::Tower), Kite));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 2, mapPlan.GetLocationptr(LocationNames::Tower), Research));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 2, mapPlan.GetLocationptr(LocationNames::Mansion), Telescope));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 2, mapPlan.GetLocationptr(LocationNames::Precinct), Searchlight));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 2, mapPlan.GetLocationptr(LocationNames::Laboratory), Experiment));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 2, mapPlan.GetLocationptr(LocationNames::Institute), Analysis));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 3, mapPlan.GetLocationptr(LocationNames::Institute), Rotenone));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 3, mapPlan.GetLocationptr(LocationNames::Tower), CosmicRayDiffuser));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 3, mapPlan.GetLocationptr(LocationNames::Tower), Nebularium));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 3, mapPlan.GetLocationptr(LocationNames::Inn), MonocaneMixture));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 3, mapPlan.GetLocationptr(LocationNames::Camp), Fossil));
    }
    std ::shuffle(Items.begin(), Items.end(), std ::mt19937(std ::random_device()()));
    // Randomly put 12 cards in map
    SetRandomItems(12);
}
void Game::SetRandomItems(int numberOfItems)
{
    // if the items ended in the bag put them back to the bag
    if (Items.empty())
    {
        Items = EmptyBackUpItems;
    }
    for (int i = 0; i < numberOfItems; ++i)
    {
        EmptyBackUpItems.push_back(Items.back());
        Items.back()->setLocation(mapPlan.GetLocationptr(Items.back()->GetItemLocationName()->GetCityName()));
        Items.pop_back();
    }
}
std::vector<std::shared_ptr<Item>> Game::GetItemsInGame()
{

    std ::vector<std ::shared_ptr<Item>> ItemsInGame;
    for (const auto &l : mapPlan.getLocations())
    {
        if (!l.second->GetItems().empty())
        {
            auto temp = l.second->GetItems();
            ItemsInGame.insert(ItemsInGame.end(), temp.begin(), temp.end());
        }
    }
    return ItemsInGame;
}
void Game ::InitializeCards()
{
    // Perk Card
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::make_shared<PerkCard>(VisitFromDetective));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::make_shared<PerkCard>(BreakOfDown));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::make_shared<PerkCard>(OverStock));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::make_shared<PerkCard>(LateIntoTheNight));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::make_shared<PerkCard>(Repel));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::make_shared<PerkCard>(Hurry));
    }
    std ::shuffle(PerkDeck.begin(), PerkDeck.end(), std ::mt19937(std ::random_device()()));
    // Monster Card
    for (int i = 0; i < 3; ++i)
    {
        MonsterDeck.push_back(std ::make_shared<MonsterCard>(FromTheBat, 2, "Place Dracula in the hero feild", MonsterStrike("I", 1, 2)));
    }
    for (int i = 0; i < 3; ++i)
    {
        MonsterDeck.push_back(std ::make_shared<MonsterCard>(Sunrise, 0, "Put Dracula in Crypt", MonsterStrike("I", 1, 2)));
    }
    for (int i = 0; i < 2; ++i)
    {
        MonsterDeck.push_back(std ::make_shared<MonsterCard>(Thief, 2, "put Invisible man in a location with the most items and remove all the item from that location", MonsterStrike("ID", 1, 3)));
    }
    MonsterDeck.push_back(std ::make_shared<MonsterCard>(TheDelivery, 3, "Put Chick and Wilbur in Dock", MonsterStrike("F", 1, 3)));
    MonsterDeck.push_back(std ::make_shared<MonsterCard>(FortuneTeller, 3, "put maleva in camp", MonsterStrike("F", 1, 2)));
    MonsterDeck.push_back(std ::make_shared<MonsterCard>(FormerEmployer, 3, "put dr.cranly in Lab", MonsterStrike("IF", 1, 2)));
    MonsterDeck.push_back(std ::make_shared<MonsterCard>(HurriedAssistant, 3, "put Fritz in Tower", MonsterStrike("D", 2, 3)));
    MonsterDeck.push_back(std ::make_shared<MonsterCard>(TheInnocent, 3, "put Maria in Barn", MonsterStrike("FDI", 1, 3)));
    MonsterDeck.push_back(std ::make_shared<MonsterCard>(EgyptianExpert, 3, "put prof.Pearson in cave", MonsterStrike("DF", 2, 2)));
    MonsterDeck.push_back(std ::make_shared<MonsterCard>(TheIchthyologist, 3, "put dr.Read in Institute", MonsterStrike("F", 1, 2)));
    for (int i = 0; i < 2; ++i)
    {
        MonsterDeck.push_back(std ::make_shared<MonsterCard>(OnTheMove, 3, "give Frenzy to the next Monster and take each villager one move closer to their safe house", MonsterStrike("F", 3, 2)));
    }
    for (int i = 0; i < 2; ++i)
    {
        MonsterDeck.push_back(std ::make_shared<MonsterCard>(HypnoticGaze, 2, "Closest Villager or Hero getting one move close to monster", MonsterStrike("I", 1, 2)));
    }
    std ::shuffle(MonsterDeck.begin(), MonsterDeck.end(), std ::mt19937(std ::random_device()()));
}
void Game ::InitializeCharacters()
{

    // villager:
    villagers.push_back(std ::make_shared<Villager>(DrCranley, mapPlan.GetLocationptr(Precinct)));
    villagers.push_back(std ::make_shared<Villager>(DrReed, mapPlan.GetLocationptr(Camp)));
    villagers.push_back(std ::make_shared<Villager>(ProfPearson, mapPlan.GetLocationptr(Museum)));
    villagers.push_back(std ::make_shared<Villager>(Maleva, mapPlan.GetLocationptr(Shop)));
    villagers.push_back(std ::make_shared<Villager>(Fritz, mapPlan.GetLocationptr(Institute)));
    villagers.push_back(std ::make_shared<Villager>(WilburAndChick, mapPlan.GetLocationptr(Dungeon)));
    villagers.push_back(std ::make_shared<Villager>(Maria, mapPlan.GetLocationptr(Camp)));
    // monster
    Monsters.push_back(std ::make_shared<Dracula>());
    Monsters.push_back(std ::make_shared<InvisibleMan>());
    Monsters[0]->SetLocation(mapPlan.GetLocationptr(Crypt));
    Monsters[1]->SetLocation(mapPlan.GetLocationptr(Laboratory));
}
void Game::RemoveVillagerFromGame(std::shared_ptr<Villager> v)
{
    villagers.erase(
        std::remove_if(villagers.begin(), villagers.end(),
                       [&v](const std::shared_ptr<Villager> &vi)
                       {
                           return vi == v;
                       }),
        villagers.end());
}
void Game ::SetUpGame()
{
    InitializeLocations();
    InitializeCards();
    InitializeCharacters();
    InitializeItem();
}
void Game::SwitchPlayer()
{
    if (heroPlayer == heroes[0])
        heroPlayer = heroes[1];
    else
        heroPlayer = heroes[0];
}
void Game::HeroPhase()
{

    int selected = -1;
    while (selected != 8)
    {
        selected = MyTerminal.ShowHeroPhase(*this, {"Move", "Guid", "Pick up", "Advance", "Defeat", "Special Action", "Use Perks", "Help", "Exit Hero Phase", "Exit Game", "Save Game", "load game"});
        // check if actions left :
        if (heroPlayer->getRemainingActions() == 0)
        {
            if (!(selected == 6 || selected == 7 || selected == 8 || selected == 9 || selected == 10 || selected == 11))
            {
                MyTerminal.ShowMessageBox("No more actions choose your perk cards or exit!");
                selected = -1;
            }
        }
        // Move
        if (selected == 0)
        {
            auto neighbors = heroPlayer->getLocation()->GetNeighbors();
            std::vector<std::string> neighborNames;
            for (const auto &loc : neighbors)
                neighborNames.push_back(loc->GetCityName());
            MyTerminal.ShowMessageBox("Choose a neighbor to move :");
            int select = MyTerminal.MenuGenerator(neighborNames);
            if (select >= 0 && select < neighbors.size())
            {
                auto nextLocation = neighbors[select];
                auto villagersInNeighbor = heroPlayer->getLocation()->GetVillager();
                if (!villagersInNeighbor.empty())
                {
                    MyTerminal.ShowMessageBox("Would you like to move all the villagers with you?");
                    int choice = MyTerminal.MenuGenerator({"Yes", "No"});
                    if (choice == 0)
                    {
                        for (auto &v : villagersInNeighbor)
                        {
                            v->SetLocation(nextLocation);

                            if (v->isAlive() == State ::Rescued)
                            {
                                RemoveVillagerFromGame(v);
                                MyTerminal.ShowMessageBox("You rescued " + v->getName());
                                heroPlayer->GetPerkCard(PerkDeck.back());
                                heroPlayer->getLocation()->RemoveVillager(v);
                                PerkDeck.pop_back();
                            }
                        }
                    }
                }

                heroPlayer->getLocation()->RemoveHero(heroPlayer);
                heroPlayer->moveTo(nextLocation);
                heroPlayer->DecreaseAction();
            }
            MyTerminal.ShowMessageBox(heroPlayer->getName() + " moved to " + heroPlayer->getLocation()->GetCityName());
        }

        // Guide
        else if (selected == 1)
        {
            auto currentLoc = heroPlayer->getLocation();
            auto neighbors = currentLoc->GetNeighbors();
            auto VillagerWithYout = currentLoc->GetVillager();
            std::vector<std::string> guideOptions;
            std::vector<std::pair<std::shared_ptr<Villager>, std::shared_ptr<Location>>> guideable;

            for (const auto &neighbor : neighbors)
            {
                auto villagersInNeighbor = neighbor->GetVillager();
                for (const auto &villager : villagersInNeighbor)
                {
                    guideOptions.push_back(villager->getName() + " (at " + neighbor->GetCityName() + ")");
                    guideable.emplace_back(villager, neighbor);
                }
            }
            for (const auto &v : VillagerWithYout)
            {
                guideOptions.push_back(v->getName() + " (at " + currentLoc->GetCityName() + ")");
                guideable.emplace_back(v, currentLoc);
            }

            if (!guideOptions.empty())
            {
                MyTerminal.ShowMessageBox("Select a Villager To Guide :");
                int choice = MyTerminal.MenuGenerator(guideOptions);
                if (choice >= 0 && choice < guideable.size())
                {

                    auto villager = guideable[choice].first;
                    auto from = guideable[choice].second;
                    if (guideable[choice].second != currentLoc)
                    {
                        from->RemoveVillager(villager);
                        villager->SetLocation(currentLoc);
                        MyTerminal.ShowMessageBox("You guided " + villager->getName() + " to " + currentLoc->GetCityName() + ".\n");
                        heroPlayer->DecreaseAction();
                    }
                    else
                    {
                        auto neighborsAround = guideable[choice].second->GetNeighbors();
                        std::vector<std::string> GuidableLocs;
                        for (const auto &l : neighborsAround)
                            GuidableLocs.push_back(l->GetCityName());
                        MyTerminal.ShowMessageBox("choose a place to guid " + villager->getName());
                        int s = MyTerminal.MenuGenerator(GuidableLocs);
                        from->RemoveVillager(villager);
                        villager->SetLocation(neighborsAround[s]);
                        MyTerminal.ShowMessageBox("You guided " + villager->getName() + " to " + neighborsAround[s]->GetCityName() + ".\n");
                        heroPlayer->DecreaseAction();
                    }
                    if (villager->isAlive() == State::Rescued)
                    {
                        RemoveVillagerFromGame(villager);
                        MyTerminal.ShowMessageBox("You rescued " + villager->getName());
                        heroPlayer->GetPerkCard(PerkDeck.back());
                        PerkDeck.pop_back();
                    }
                }
            }
            else
            {
                MyTerminal.ShowMessageBox("No villagers in nearby locations to guide.\n");
            }
        }
        // Pick up
        else if (selected == 2)
        {
            if (!heroPlayer->getLocation()->GetItems().empty())
            {
                auto items = heroPlayer->getLocation()->GetItems();
                for (const auto &i : items)
                {
                    heroPlayer->pickUpItems(i);
                }
                MyTerminal.ShowMessageBox(heroPlayer->getName() + " Pick up all the Items!");
                auto invisible = GetInvisibleMan();
                if (invisible)
                {
                    if (invisible->IsTasksLocation(heroPlayer->getLocation()->GetCityName()))
                    {
                        MyTerminal.ShowMessageBox("You pick up one of the evidences in city " + heroPlayer->getLocation()->GetCityName());
                    }
                }
                heroPlayer->DecreaseAction();
            }
            else
            {
                MyTerminal.ShowMessageBox("Not any Items to pick up");
            }
        }

        // Advance
        else if (selected == 3)
        {

            std::string city = heroPlayer->getLocation()->GetCityName();
            auto &inventory = heroPlayer->getInventory();
            const int requiredPower = 6;
            std::shared_ptr<Dracula> dracula = GetDracula();
            std::shared_ptr<InvisibleMan> invisible = GetInvisibleMan();
            bool actionTaken = false;

            if (dracula && dracula->IsTasksLocation(city))
            {
                if (dracula->IsCoffinDestroyed(city))
                {

                    MyTerminal.ShowMessageBox("You already destroyed the coffin at " + city + ".");
                }
                else
                {

                    // collect red items

                    std::vector<std::shared_ptr<Item>> redItems;
                    std::vector<std::string> redItemNames;
                    for (const auto &item : inventory)
                        if (item->getColor() == ItemColor::Red)
                        {
                            redItems.push_back(item);
                            redItemNames.push_back(item->getName());
                        }

                    std::vector<std::shared_ptr<Item>> usedItems;
                    int total = 0;
                    int selected = -1;
                    redItemNames.push_back("Exit");

                    while (true)
                    {

                        MyTerminal.ShowMessageBox("Choose items:");
                        selected = MyTerminal.MenuGenerator(redItemNames);
                        if (selected == redItems.size()) // Exit option selected

                            break;

                        if (selected < 0 || selected >= redItemNames.size())
                        {
                            MyTerminal.ShowMessageBox("Invalid selection. Try again.");
                            continue;
                        }
                        total += redItems[selected]->getPower();
                        // Scientist logic :
                        if (heroPlayer->getName() == "Scientist")
                        {
                            MyTerminal.ShowMessageBox("Would you like to use your ability on " + redItemNames[selected] + " Scientist?");
                            int s = MyTerminal.MenuGenerator({"yes", "no"});
                            if (s == 0)
                            {
                                total++;
                                MyTerminal.ShowMessageBox("Added 1 power to " + redItemNames[selected]);
                            }
                        }
                        usedItems.push_back(redItems[selected]);
                        redItems.erase(redItems.begin() + selected);
                        // Update the item list
                        redItemNames.clear();
                        for (const auto &i : redItems)
                            redItemNames.push_back(i->getName() + " (" + std::to_string(i->getPower()) + ")");
                        redItemNames.push_back("Exit");
                        if (redItems.empty())
                        {
                            MyTerminal.ShowMessageBox("No more items to choose from.");
                            break;
                        }
                    }
                    if (total >= requiredPower)
                    {
                        dracula->AddDetroyedCoffin(city);
                        for (auto &item : usedItems)
                            heroPlayer->RemoveItem(item);
                        heroPlayer->DecreaseAction();
                        MyTerminal.ShowMessageBox("You smashed a Dracula coffin at " + city + "!");
                    }
                    else
                    {
                        MyTerminal.ShowMessageBox("Not enough red item power.");
                    }
                }
                actionTaken = true;
            }
            if (!actionTaken && invisible && city == Precinct)
            {
                bool found = false;
                for (const auto &item : inventory)
                {
                    if (item->GetItemLocationName())
                    {
                        std::string itemLoc = item->GetItemLocationName()->GetCityName();
                        if (invisible->IsTasksLocation(itemLoc))
                        {
                            found = true;
                            if (invisible->IsEvidenceDestroyed(itemLoc))
                            {
                                MyTerminal.ShowMessageBox("You already collected evidence at " + itemLoc + ".");
                            }
                            else
                            {
                                heroPlayer->RemoveItem(item);
                                invisible->AddDetroyedEvidence(itemLoc);
                                heroPlayer->DecreaseAction();
                                MyTerminal.ShowMessageBox("You collected Invisible Man evidence at " + itemLoc + " and put it into " + Precinct);
                                break;
                            }
                        }
                    }
                }
                if (!found)
                {
                    MyTerminal.ShowMessageBox("You don't have any item to put in " + Precinct);
                }
                actionTaken = true;
            }
            if (!actionTaken)
            {
                MyTerminal.ShowMessageBox("Nothing can be advanced at this location.");
            }
        }

        // Defeat
        else if (selected == 4)
        {
            auto monster = heroPlayer->getLocation()->GetMonsters();
            if (!monster.empty())
            {
                if (monster.size() == 2)
                {
                    MyTerminal.ShowMessageBox("There are two Monsters in Your Location choose one to defeat:");
                    int selection = MyTerminal.MenuGenerator({"Dracula", "Invisible Man"});
                    if (selection == 0)
                    {
                        heroPlayer->DefeatAction(GetDracula(), *this);
                    }
                    else if (selection == 1)
                    {
                        heroPlayer->DefeatAction(GetInvisibleMan(), *this);
                    }
                }
                else
                {
                    heroPlayer->DefeatAction(monster.back(), *this);
                }
            }
            else
                MyTerminal.ShowMessageBox("No monster in your location to defeat!");
        }

        // Special Action
        else if (selected == 5)
        {
            heroPlayer->specialAction(*this);
        }
        // perk card
        else if (selected == 6)
        {
            heroPlayer->UsePerkCard(*this);
        }
        // help button
        else if (selected == 7)
        {

            MyTerminal.ShowHelpScreen();
        }
        // exit button
        else if (selected == 8)
        {
            heroPlayer->resetActions();
            SwitchPlayer();
            MyTerminal.ShowMessageBox("exiting the hero phase...");
            break;
        }
        // exit Game Button
        else if (selected == 9)
        {
            MyTerminal.ShowMessageBox("Logging Out ...");
            MyTerminal.ShowExitScreen();
            exit(0);
        }
        else if (selected == 10)
        {
            int slot = MyTerminal.MenuGenerator({"Slot 1", "Slot 2", "Slot 3", "Slot 4", "Slot 5"});
            GameFileHandler::SaveGame(*this, "file_" + std::to_string(slot + 1));
        }
        else if (selected == 11)
        {
            int slot = MyTerminal.MenuGenerator({"Slot 1", "Slot 2", "Slot 3", "Slot 4", "Slot 5"});
            GameFileHandler::LoadGame(*this, "file_" + std::to_string(slot + 1));
        }

        if (CheckGameEnd())
            return;
    }
    if (CheckGameEnd())
        return;
    heroPlayer->resetActions();
}

void Game::increaseTerrorLevel() { terrorLevel++; }
void Game::MonsterPhase()
{
    if (MonsterDeck.empty())
    {
        MyTerminal.ShowPopupMessages(*this, "No Monster card left in the deck");
        return;
    }
    auto card = MonsterDeck.back();

    MyTerminal.ShowPopupMessages(*this, "Monster Phase Begins!!!!!");

    MyTerminal.ShowMonsterPhase(*this, card);
    card->ApplyEffect(*this);

    MyTerminal.ShowPopupMessages(*this, "Monster phase complete. Press Enter to continue...");
    MonsterDeck.pop_back();
}
std::vector<std::shared_ptr<Villager>> &Game::getVillagers() { return villagers; }
std::shared_ptr<Dracula> Game::GetDracula()
{
    for (auto &m : Monsters)
    {
        if (m->GetName() == "Dracula")
        {
            return std::dynamic_pointer_cast<Dracula>(m);
        }
    }
    return nullptr;
}
std::shared_ptr<InvisibleMan> Game::GetInvisibleMan()
{
    for (auto &m : Monsters)
    {
        if (m->GetName() == "Invisible Man")
        {
            return std::dynamic_pointer_cast<InvisibleMan>(m);
        }
    }
    return nullptr;
}
Map &Game::getMapPlan() { return mapPlan; }
void Game::ChooseHero(std::string player1, std::string player2)
{

    auto startArchloc = mapPlan.GetLocationptr(Docks);
    auto startMayorloc = mapPlan.GetLocationptr(Theater);
    auto startCourierloc = mapPlan.GetLocationptr(Shop);
    auto startScientistloc = mapPlan.GetLocationptr(Institute);

    std::vector<std::shared_ptr<Hero>> availableHeroes = {
        std::make_shared<Mayor>(startMayorloc),
        std::make_shared<Archaeologist>(startArchloc),
        std::make_shared<Courier>(startCourierloc),
        std::make_shared<Scientist>(startScientistloc)};

    std::vector<std::string> heroNames;
    for (const auto &hero : availableHeroes)
        heroNames.push_back(hero->getName());

    MyTerminal.ShowMessageBox(player1 + " , choose your hero:");

    int player1Choice = MyTerminal.MenuGenerator(heroNames);
    auto player1Hero = availableHeroes[player1Choice];
    switch (player1Choice)
    {
    case 0:
        heroes.push_back(std ::make_shared<Mayor>(startMayorloc));
        if (!PerkDeck.empty())
        {
            heroes[0]->GetPerkCard(PerkDeck.back());
            PerkDeck.pop_back();
        }
        break;

    case 1:
        heroes.push_back(std ::make_shared<Archaeologist>(startArchloc));
        if (!PerkDeck.empty())
        {
            heroes[0]->GetPerkCard(PerkDeck.back());
            PerkDeck.pop_back();
        }
        break;
    case 2:
        heroes.push_back(std::make_shared<Courier>(startCourierloc));
        if (!PerkDeck.empty())
        {
            heroes[0]->GetPerkCard(PerkDeck.back());
            PerkDeck.pop_back();
        }
        break;
    case 3:
        heroes.push_back(std::make_shared<Scientist>(startScientistloc));
        if (!PerkDeck.empty())
        {
            heroes[0]->GetPerkCard(PerkDeck.back());
            PerkDeck.pop_back();
        }
        break;
    default:
        break;
    }
    availableHeroes.erase(availableHeroes.begin() + player1Choice);

    heroNames.clear();
    for (const auto &hero : availableHeroes)
        heroNames.push_back(hero->getName());

    MyTerminal.ShowMessageBox(player2 + " , choose your hero:");
    int player2Choice = MyTerminal.MenuGenerator(heroNames);
    auto player2Hero = availableHeroes[player2Choice];

    if (heroNames[player2Choice] == "Mayor")
    {
        heroes.push_back(std ::make_shared<Mayor>(startMayorloc));
        if (!PerkDeck.empty())
        {
            heroes[1]->GetPerkCard(PerkDeck.back());
            PerkDeck.pop_back();
        }
    }
    else if (heroNames[player2Choice] == "Archaeologist")
    {
        heroes.push_back(std ::make_shared<Archaeologist>(startArchloc));
        if (!PerkDeck.empty())
        {
            heroes[1]->GetPerkCard(PerkDeck.back());
            PerkDeck.pop_back();
        }
    }
    else if (heroNames[player2Choice] == "Courier")
    {
        heroes.push_back(std::make_shared<Courier>(startCourierloc));
        if (!PerkDeck.empty())
        {
            heroes[1]->GetPerkCard(PerkDeck.back());
            PerkDeck.pop_back();
        }
    }
    else if (heroNames[player2Choice] == "Scientist")
    {
        heroes.push_back(std::make_shared<Scientist>(startScientistloc));
        if (!PerkDeck.empty())
        {
            heroes[1]->GetPerkCard(PerkDeck.back());
            PerkDeck.pop_back();
        }
    }
    heroPlayer = heroes[0];
}
void Game::GameStart()
{
    const int screenWidth = 900;
    const int screenHeight = 700;
    InitWindow(screenWidth, screenHeight, "Horrified Game");
    SetTargetFPS(60);

    InitAudioDevice();
    MyTerminal.music = LoadMusicStream("../assets/horror.mp3");
    PlayMusicStream(MyTerminal.music);

    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Loading...", 385, 340, 30, WHITE);
    EndDrawing();
    MyTerminal.LoadAssets();
    while (true)
    {
        UpdateMusicStream(MyTerminal.music);
        int StartMenuSelected = MyTerminal.MenuGenerator({"Start", "Load Game", "Exit"});

        if (StartMenuSelected == 2)
        {
            MyTerminal.ShowExitScreen();
            UnloadMusicStream(MyTerminal.music);
            CloseAudioDevice();
            return;
        }

        if (StartMenuSelected == 1)
        {
            while (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                BeginDrawing();
                EndDrawing();
            }

            int selectedSlot = MyTerminal.MenuGenerator({"slot1", "slot2", "slot3", "slot4", "slot5"});
            std::string FileName = "file_" + std::to_string(selectedSlot + 1);
            GameFileHandler::LoadGame(*this, FileName);
            break;
        }
        if (StartMenuSelected == 0)
        {
            std::string name1, name2;
            int days1 = 0, days2 = 0;

            if (!MyTerminal.GetPlayerInfo(name1, days1))
                continue;
            if (!MyTerminal.GetPlayerInfo(name2, days2))
                continue;

            std::string p1, p2;
            if (days1 > days2)
            {
                p1 = name2;
                p2 = name1;
            }
            else
            {
                p1 = name1;
                p2 = name2;
            }

            ChooseHero(p1, p2);
            break;
        }
    }

    while (!CheckGameEnd())
    {
        UpdateMusicStream(MyTerminal.music);

        HeroPhase();
        if (!skipMonsterPhase && !CheckGameEnd())
        {
            MonsterPhase();
        }
        else
        {
            skipMonsterPhase = false;
        }
    }

    MyTerminal.UnloadAssets();
    UnloadMusicStream(MyTerminal.music);
    CloseAudioDevice();
    CloseWindow();
}

bool Game::CheckGameEnd()
{
    if (MonsterDeck.empty() && !Monsters.empty())
    {
        MyTerminal.ShowMessageBox("Darkness Falls... The town is overrun! The monsters have prevailed.\n");
        GameOver = true;
    }
    else if (terrorLevel >= 5)
    {
        MyTerminal.ShowMessageBox("Terror Reigns! The townsfolk have lost all hope... Evil claims victory.\n");
        GameOver = true;
    }
    else if (Monsters.empty())
    {
        MyTerminal.ShowMessageBox("Victory! The Heroes have vanquished all the monsters!\n");
        GameOver = true;
    }
    if (GameOver){
        Reset();
        SetUpGame();
        GameStart();
    }
    return GameOver;
}
void Game::Reset()
{
    terrorLevel = 0;
    heroPlayer = nullptr;
    GameOver = false;
    skipMonsterPhase = false;
    heroes.clear();
    Monsters.clear();
    villagers.clear();
    Items.clear();
    EmptyBackUpItems.clear();
    PerkDeck.clear();
    MonsterDeck.clear();
    mapPlan.Clear();
    SetUpGame();
}