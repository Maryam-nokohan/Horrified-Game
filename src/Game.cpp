#include "../include/Monster.hpp"
#include "../include/MonsterCard.hpp"
#include "../include/Card.hpp"
#include "../include/Perk.hpp"
#include "../include/Dice.hpp"
#include "../include/Game.hpp"
#include "../include/Location.hpp"
#include <iostream>
#include "algorithm"
#include <random>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <memory>
using namespace ftxui;
void Game ::SetUpGame()
{
    InitializeCards();
    // InitializeCharacters();
    InitializeItem();
}
Game ::Game() : terrorLevel(0), heroPlayer(nullptr), GameOver(false)
{
    SetUpGame();
}
Game ::~Game() {};

void Game ::InitializeLocations()
{
    mapPlan.addEdge("Cave", "Camp");
    mapPlan.addEdge("Camp", "Precinct");
    mapPlan.addEdge("Precinct", "Inn");
    mapPlan.addEdge("Inn", "Barn");
    mapPlan.addEdge("Barn", "Dungeon");

    mapPlan.addEdge("Dungeon", "Tower");
    mapPlan.addEdge("Tower", "Docks");
    mapPlan.addEdge("Docks", "Waterfront");
    mapPlan.addEdge("Waterfront", "Institute");

    mapPlan.addEdge("Institute", "Laboratory");
    mapPlan.addEdge("Laboratory", "Graveyard");
    mapPlan.addEdge("Graveyard", "Church");
    mapPlan.addEdge("Church", "Shop");
    mapPlan.addEdge("Shop", "Hospital");
    mapPlan.addEdge("Hospital", "Museum");
    mapPlan.addEdge("Museum", "Abbey");
    mapPlan.addEdge("Abbey", "Mansion");
    mapPlan.addEdge("Mansion", "Lagoon");
    mapPlan.addEdge("Lagoon", "Camp");

    mapPlan.addEdge("Theater", "Precinct");
    mapPlan.addEdge("Theater", "Station");
    mapPlan.addEdge("Theater", "Tower");

    mapPlan.addEdge("Shop", "Theater");
    mapPlan.addEdge("Station", "Graveyard");
    mapPlan.addEdge("Station", "Museum");

    mapPlan.addEdge("Church", "Hospital");
}
void Game::ShowMapRoad() const
{
    std::vector<Element> lines;

    for (const auto &[name, loc] : mapPlan.getLocations())
    {
        std::string line = name + " -> ";

        for (const auto &neighbor : loc->GetNeighbors())
        {
            line += neighbor->GetName() + ", ";
        }

        if (!loc->GetNeighbors().empty())
        {
            line.pop_back();
            line.pop_back();
        }

        lines.push_back(text(line));
    }

    auto document = vbox(std::move(lines)) | border | center;

    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(Container::Vertical({Renderer([=]
                                              { return document; })}));
}

void Game ::InitializeItem() {}
void Game ::InitializeCards()
{
    // Perk Card
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::unique_ptr<PerkCard>(new PerkCard("visit from Detective")));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::unique_ptr<PerkCard>(new PerkCard("Break of Down")));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::unique_ptr<PerkCard>(new PerkCard("OverStock")));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::unique_ptr<PerkCard>(new PerkCard("Late into the Night")));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::unique_ptr<PerkCard>(new PerkCard("Repel")));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::unique_ptr<PerkCard>(new PerkCard("Hurry")));
    }
    std ::shuffle(PerkDeck.begin(), PerkDeck.end(), std ::mt19937(std ::random_device()()));
    // Monster Card
    for (int i = 0; i < 3; ++i)
    {
        MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("from the Bat", 2, "Place Dracula in the hero feild", MonsterStrike("I", 1, 2))));
    }
    for (int i = 0; i < 3; ++i)
    {
        MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("Sunrise", 0, "Put Dracula in Crypt", MonsterStrike("I", 1, 2))));
    }
    for (int i = 0; i < 2; ++i)
    {
        MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("Thief", 2, "put Invisible man in a location with the most items and remove all the item from that location", MonsterStrike("ID", 1, 3))));
    }
    MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("The Delivery", 3, "Put Chick and Wilbur in Dock", MonsterStrike("F", 1, 3))));
    MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("Fortune Teller", 3, "put maleva in camp", MonsterStrike("F", 1, 2))));
    MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("Former Employer", 3, "put dr.cranly in Lab", MonsterStrike("IF", 1, 2))));
    MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("Hurried Assistant", 3, "put Fritz in Tower", MonsterStrike("D", 2, 3))));
    MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("The innocent", 3, "put Maria in Barn", MonsterStrike("FDI", 1, 3))));
    MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("Egyptian Ecpert", 3, "put prof.Pearson in cave", MonsterStrike("DF", 2, 2))));
    MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("The ichthyologist", 3, "put dr.Read in Institute", MonsterStrike("F", 1, 2))));
    for (int i = 0; i < 2; ++i)
    {
        MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("On the Move", 3, "give Frenzy to the next Monster and take each villager one move closer to their safe house", MonsterStrike("F", 3, 2))));
    }
    for (int i = 0; i < 2; ++i)
    {
        MonsterDeck.push_back(std ::unique_ptr<MonsterCard>(new MonsterCard("Hypnotic Gaze", 2, "Closest Villager or Hero getting one move close to monster", MonsterStrike("I", 1, 2))));
    }
    std ::shuffle(MonsterDeck.begin(), MonsterDeck.end(), std ::mt19937(std ::random_device()()));
}
