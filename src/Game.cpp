#include "../include/Monster.hpp"
#include "../include/LocationNames.hpp"
#include "../include/MonsterCard.hpp"
#include "../include/Mayor.hpp"
#include "../include/Archaelogist.hpp"
#include "../include/Courier.hpp"
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
#include <unordered_set>
#include <queue>
#include <iostream>
#include "algorithm"
#include <random>
#include "../include/Terminal.hpp"
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
Game ::Game() : terrorLevel(0), heroPlayer(nullptr), GameOver(false), skipMonsterPhase(false)
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

    mapPlan.addEdge(Graveyard, Hospital);

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
    // Hero and giving the start perk Card :
    auto startArchloc = mapPlan.GetLocationptr(Docks);
    auto startMayorloc = mapPlan.GetLocationptr(Theater);
    auto startCourierloc = mapPlan.GetLocationptr(Shop);
    // Mayor
    heroes.push_back(std ::make_shared<Mayor>(startMayorloc));
    heroes[0]->GetPerkCard(PerkDeck.back());
    PerkDeck.pop_back();
    // Archaeologist
    heroes.push_back(std ::make_shared<Archaeologist>(startArchloc));
    heroes[1]->GetPerkCard(PerkDeck.back());
    PerkDeck.pop_back();
    // Courier
    heroes.push_back(std::make_shared<Courier>(startCourierloc));
    heroes[2]->GetPerkCard(PerkDeck.back());
    PerkDeck.pop_back();
    // 
    

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
        selected = MyTerminal.ShowHeroPhase(*this, {"Move", "Guid", "Pick up", "Advance", "Defeat", "Special Action", "Use Perks", "Help", "Exit Hero Phase", "Exit Game"});
        // check if actions left :
        if (heroPlayer->getRemainingActions() == 0)
        {
            if (!(selected == 6 || selected == 7 || selected == 8 || selected == 9))
            {
                MyTerminal.StylizeTextBoard("No more actions choose your perk cards or exit!");
                MyTerminal.ShowPause();
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
                MyTerminal.StylizeTextBoard("Choose a neighbor to move :");
                int select = MyTerminal.MenuGenerator(neighborNames);
            if (select >= 0 && select < neighbors.size())
            {
                auto nextLocation = neighbors[select];
                auto villagersInNeighbor = heroPlayer->getLocation()->GetVillager();
                if (!villagersInNeighbor.empty())
                {
                    MyTerminal.StylizeTextBoard("Would you like to move all the villagers with you?");
                    int choice = MyTerminal.MenuGenerator({"Yes", "No"});
                    if (choice == 0)
                    {
                        for (auto &v : villagersInNeighbor)
                        {
                            v->SetLocation(nextLocation);

                            if (v->isAlive() == State ::Rescued)
                            {
                                RemoveVillagerFromGame(v);
                                MyTerminal.StylizeTextBoard("You rescued " + v->getName());
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
            MyTerminal.StylizeTextBoard(heroPlayer->getName() + " moved to " + heroPlayer->getLocation()->GetCityName());
            MyTerminal.ShowPause();
        }

        // Guide
        else if (selected == 1)
        {
            auto currentLoc = heroPlayer->getLocation();
            auto neighbors = currentLoc->GetNeighbors();
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

            if (!guideOptions.empty())
            {
                MyTerminal.StylizeTextBoard("Select a Villager To Guide :");
                int choice = MyTerminal.MenuGenerator(guideOptions);
                if (choice >= 0 && choice < guideable.size())
                {
                    auto villager = guideable[choice].first;
                    auto from = guideable[choice].second;
                    from->RemoveVillager(villager);
                    villager->SetLocation(currentLoc);
                    MyTerminal.StylizeTextBoard("You guided " + villager->getName() + " to " + currentLoc->GetCityName() + ".\n");
                    heroPlayer->DecreaseAction();
                    if (villager->isAlive() == State::Rescued)
                    {
                        RemoveVillagerFromGame(villager);
                        MyTerminal.StylizeTextBoard("You rescued " + villager->getName());
                        heroPlayer->GetPerkCard(PerkDeck.back());
                        PerkDeck.pop_back();
                    }
                    MyTerminal.ShowPause();
                }
            }
            else
            {
                MyTerminal.StylizeTextBoard("No villagers in nearby locations to guide.\n");
                MyTerminal.ShowPause();
            }
        }

        // Pick up
        else if (selected == 2)
        {
            if (!heroPlayer->getLocation()->GetItems().empty())
            {
                heroPlayer->pickUpItems();
                MyTerminal.StylizeTextBoard(heroPlayer->getName() + " Pick up all the Items!");
                auto invisible = GetInvisibleMan();
                if (invisible)
                {
                    if (invisible->IsTasksLocation(heroPlayer->getLocation()->GetCityName()))
                    {
                        MyTerminal.StylizeTextBoard("You pick up one of the evidences in city " + heroPlayer->getLocation()->GetCityName());
                    }
                }
                MyTerminal.ShowPause();
            }
            else
            {
                MyTerminal.StylizeTextBoard("Not any Items to pick up");
                MyTerminal.ShowPause();
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
                    MyTerminal.StylizeTextBoard("You already destroyed the coffin at " + city + ".");
                    MyTerminal.ShowPause();
                }
                else
                {
                    // collect red items
                    std::vector<std::shared_ptr<Item>> redItems;
                    for (const auto &item : inventory)
                        if (item->getColor() == ItemColor::Red)
                            redItems.push_back(item);

                    std::sort(redItems.begin(), redItems.end(), [](const auto &a, const auto &b)
                              { return a->getPower() < b->getPower(); });

                    int total = 0;
                    std::vector<std::shared_ptr<Item>> usedItems;
                    // if we have a red item with power 6:
                    if (redItems.back()->getPower() == 6)
                    {
                        total = 6;
                        usedItems.push_back(redItems.back());
                    }
                    // else use greedy
                    else
                    {
                        for (const auto &item : redItems)
                        {
                            if (total >= requiredPower)
                                break;
                            total += item->getPower();
                            usedItems.push_back(item);
                        }
                    }

                    if (total >= requiredPower)
                    {
                        dracula->AddDetroyedCoffin(city);
                        for (auto &item : usedItems)
                            heroPlayer->RemoveItem(item);
                        heroPlayer->DecreaseAction();
                        MyTerminal.StylizeTextBoard("You smashed a Dracula coffin at " + city + "!");
                        MyTerminal.ShowPause();
                    }
                    else
                    {
                        MyTerminal.StylizeTextBoard("Not enough red item power.");
                        MyTerminal.ShowPause();
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
                                MyTerminal.StylizeTextBoard("You already collected evidence at " + itemLoc + ".");
                                MyTerminal.ShowPause();
                            }
                            else
                            {
                                heroPlayer->RemoveItem(item);
                                invisible->AddDetroyedEvidence(itemLoc);
                                heroPlayer->DecreaseAction();
                                MyTerminal.StylizeTextBoard("You collected Invisible Man evidence at " + itemLoc + " and put it into " + Precinct);
                                MyTerminal.ShowPause();
                                break;
                            }
                        }
                    }
                }
                if (!found)
                {
                    MyTerminal.StylizeTextBoard("You don't have any item to put in " + Precinct);
                    MyTerminal.ShowPause();
                }
                actionTaken = true;
            }

            if (!actionTaken)
            {
                MyTerminal.StylizeTextBoard("Nothing can be advanced at this location.");
                MyTerminal.ShowPause();
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
                    MyTerminal.StylizeTextBoard("There are two Monsters in Your Location choose one to defeat:");
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
                MyTerminal.StylizeTextBoard("No monster in your location to defeat!");
            MyTerminal.ShowPause();
        }

        // Special Action
        else if (selected == 5)
        {
            heroPlayer->specialAction(*this);
            MyTerminal.ShowPause();
            
        }
        // perk card
        else if (selected == 6)
        {
            heroPlayer->UsePerkCard(*this);
        }
        // help button
        else if (selected == 7)
        {
            Help();
        }
        // exit button
        else if (selected == 8)
        {
            heroPlayer->resetActions();
            SwitchPlayer();
            MyTerminal.StylizeTextBoard("exiting the hero phase...");
            MyTerminal.ShowPause();
            break;
        }
        // exit Game Button
        else if (selected == 9)
        {
            MyTerminal.StylizeTextBoard("Logging Out ...");
            exit(0);
        }
        if (CheckGameEnd())
            return;
    }
    heroPlayer->resetActions();
}
void Game::increaseTerrorLevel() { terrorLevel++; }
void Game::MonsterPhase()
{
    if (MonsterDeck.empty())
    {
        MyTerminal.StylizeTextBoard("No Monster card left in the deck");
        return;
    }
    MyTerminal.ShowMonsterPhase(*this);
    auto randomCard = MonsterDeck.back();
    randomCard->ApplyEffect(*this);
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
void Game::GameStart()
{
    int StartMenuSelected = -1;
    while (StartMenuSelected != 0)
    {

        // Start menue:
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Horrified Game");
    SetTargetFPS(60);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Loading...", 350, 280, 20, DARKGRAY);
    EndDrawing();

    Font font = LoadFont("assets/Fonts/Bungee-Regular.ttf");
    Texture2D bg1 = LoadTexture("assets/Background.png");
    Texture2D bg2 = LoadTexture("assets/Background2.png");

    std::string message;
        int StartMenuSelected = MyTerminal.MenuGenerator(std::vector<std::string>{"Start", "Help", "Exit"} , message , bg1 , font );
        std::string p1, p2;
        int lastTime1, lastTime2;

        switch (StartMenuSelected)
        {
        case 0:
        {
            // Garlic questions :
            p1 = MyTerminal.GetInput("What's Your Name Player 1? ", String);
            lastTime1 = stoi(MyTerminal.GetInput("When was the last time that you ate garlic " + p1 + "? (Ex: 2 days): ", Int));
            p2 = MyTerminal.GetInput("What's Your Name Player 2? ", String);
            lastTime2 = stoi(MyTerminal.GetInput("When was the last time that you ate garlic " + p2 + "? (Ex: 2 days): ", Int));
            if (lastTime1 >= lastTime2)
                message = p2 + " You can choose a hero." ;
            else
                message = p1 + " You can choose a hero." ;

            int HeroChoose = MyTerminal.MenuGenerator(std::vector<std::string>{"Mayor", "Archaeologist" , "Courier" , "Scientist"} , message , bg2 , font);
            heroPlayer = heroes[HeroChoose];
        }
        case 1:
            Help();
            break;
        case 2:
            MyTerminal.StylizeTextBoard("Logging Out ...");
            exit(0);
            break;
        default:
            MyTerminal.StylizeTextBoard("Not an option!!!");
            break;
        }
        if (StartMenuSelected == 0)
        {
            break;
        }

    }
    while (!CheckGameEnd())
    {
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
}
void Game::Help()
{
    MyTerminal.StylizeTextBoard(
        "======================== HORRIFIED GAME INSTRUCTIONS ========================\n"
        "Welcome to the Horrified Game! Here are the basics you need to know:\n\n"

        "1. Goal:\n"
        "   - Work with the other heroes to defeat the monsters (Dracula, Invisible Man, etc.) by\n"
        "     completing their objectives (destroying coffins, collecting evidence, defeating monsters, etc.).\n"
        "   - Protect the villagers by guiding or moving them to their safe locations.\n"
        "   - Prevent the terror level from reaching its maximum.\n\n"

        "2. Hero Actions:\n"
        "   - Move: Travel between connected locations.\n"
        "   - Guide: Move villagers from adjacent locations to your location.\n"
        "   - Pick Up: Collect available items at your current location.\n"
        "   - Advance: Perform special tasks like destroying Dracula's coffin or collecting evidence for the Invisible Man.\n"
        "   - Defeat: Attempt to defeat a monster when in the same location.\n"
        "   - Use Perks: Play a perk card for special bonuses.\n"
        "   - Special Action: Perform unique character abilities.\n"
        "   - End Turn: Finish your hero phase.\n\n"

        "3. Monsters:\n"
        "   - Each monster has unique abilities and special tasks required to defeat them.\n"
        "   - Monsters move and attack every monster phase, causing terror and defeating heroes and villagers.\n\n"

        "4. Terror Level:\n"
        "   - The terror level increases when monsters kill heroes or villagers.\n"
        "   - If the terror level reaches the maximum, you lose the game.\n\n"

        "5. Win the Game:\n"
        "   - Complete the objectives for all monsters.\n"
        "   - Maintain a low terror level.\n\n"

        "Remember:\n"
        "   - Plan your moves strategically.\n"
        "   - Protect the villagers.\n"
        "   - Use your perk cards wisely.\n"
        "   - Defeat the monsters and save the town!\n\n"

        "Good luck, hero!\n"
        "==========================================================================\n");

    MyTerminal.ShowPauseWithRefresh();
    return;
}
bool Game::CheckGameEnd()
{
    if (MonsterDeck.empty() && !Monsters.empty())
    {
        MyTerminal.StylizeTextBoard("💀 Darkness Falls... The town is overrun! The monsters have prevailed.\n");
        GameOver = true;
    }
    else if (terrorLevel >= 5)
    {
        MyTerminal.StylizeTextBoard("🩸 Terror Reigns! The townsfolk have lost all hope... Evil claims victory.\n");
        GameOver = true;
    }
    else if (Monsters.empty())
    {
        MyTerminal.StylizeTextBoard("🎉 Victory! The Heroes have vanquished all the monsters!\n");
        GameOver = true;
    }
    if (GameOver)
        exit(0);
    return GameOver;
}