#include "../include/Monster.hpp"
#include "../include/MonsterCard.hpp"
#include "../include/Card.hpp"
#include "../include/Perk.hpp"
#include "../include/Dice.hpp"
#include "../include/Game.hpp"
#include "../include/Location.hpp"
#include "../include/Dracula.hpp"
#include "../include/invisible.hpp"
#include "../include/ErrorHandler.hpp"
#include <iostream>
#include "algorithm"
#include <random>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include "../include/Terminal.hpp"
#include <memory>

void Game ::InitializeLocations()
{
    //fix
    mapPlan.addLocation("Cave", 0, 0);
    mapPlan.addLocation("Camp", 1, 0);
    mapPlan.addLocation("Precinct", 2, 0);
    mapPlan.addLocation("Inn", 3, 0);
    mapPlan.addLocation("Barn", 4, 0);
    mapPlan.addLocation("Dungeon", 5, 0);
    mapPlan.addLocation("Tower", 6, 0);
    mapPlan.addLocation("Docks", 7, 0);
    mapPlan.addLocation("Institute", 9, 0);
    mapPlan.addLocation("Laboratory", 10, 0);
    mapPlan.addLocation("Graveyard", 11, 0);
    mapPlan.addLocation("Church", 12, 0);
    mapPlan.addLocation("Shop", 13, 0);
    mapPlan.addLocation("Hospital", 14, 0);
    mapPlan.addLocation("Museum", 15, 0);
    mapPlan.addLocation("Abbey", 16, 0);
    mapPlan.addLocation("Mansion", 17, 0);
    mapPlan.addLocation("Theater", 19, 0);
    mapPlan.addLocation("Crypt", 20, 0);
    
    
    
    mapPlan.addEdge("Cave", "Camp");
    
    mapPlan.addEdge("Camp", "Precinct");
    
    mapPlan.addEdge("Precinct", "Inn");
    
    mapPlan.addEdge("Precinct", "Theater");
    
    mapPlan.addEdge("Precinct", "Mansion");
    
    mapPlan.addEdge("Inn", "Theater");
    
    mapPlan.addEdge("Inn", "Camp");
    
    mapPlan.addEdge("Inn", "Mansion");
    
    mapPlan.addEdge("Barn", "Theater");
    
    mapPlan.addEdge("Theater", "Tower");
    
    mapPlan.addEdge("Dungeon", "Tower");
    
    mapPlan.addEdge("Tower", "Docks");
    
    mapPlan.addEdge("Institute", "Laboratory");
    
    mapPlan.addEdge("Laboratory", "Shop");
    
    mapPlan.addEdge("Graveyard", "Church");
    
    mapPlan.addEdge("Church", "Shop");
    
    mapPlan.addEdge("Shop" , "Theater");
    
    mapPlan.addEdge("Shop" ,"Mansion");
    
    mapPlan.addEdge("Shop" , "Museum");
    
    mapPlan.addEdge("Church" , "Hospital");
    
    mapPlan.addEdge("Church" , "Mansion");
    
    mapPlan.addEdge("Museum" , "Mansion");
    
    mapPlan.addEdge("Museum" , "Church");
    
    mapPlan.addEdge("Abbey", "Mansion");
    
    mapPlan.addEdge("Abbey" , "Crypt");
    
    mapPlan.addEdge("Mansion" , "Camp");
    
    
}
void Game::ShowMapRoad() const
{
    using namespace ftxui;
    
    std::cout << "Map Plan:\n";
    for(auto & c : mapPlan.getLocations())
    {
        std :: cout <<"City : " << c.first <<"\n";
        std :: cout << "is connected to : ";
        for(auto & nei : c.second->GetNeighbors())
        {
            std :: cout << nei->GetCityName()<< " and , ";
        }
       std ::  cout << '\n';
    }
    
}
void Game ::InitializeItem() {

    //Add all item like this :
    Items.push_back(Item(ItemColor::Yellow , 2 , "Docks"));


}
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
void Game :: InitializeCharacters()
{
    //villager
    //Hero :
    heroes.push_back(std :: make_unique<Mayor>());
    heroes.push_back(std :: make_unique<Archaeologist>());
    //monster
    Monsters.push_back(std :: make_unique<Dracula>());
    Monsters.push_back(std :: make_unique<InvisibleMan>());
}
void Game::GameStart() {
    ShowInTerminal MyTerminal;

    int StartMenuSelected = MyTerminal.MenuGenerator(std::vector<std::string>{"Start", "Exit"});
    std::string p1, p2;
    std::string last1, last2;

    switch (StartMenuSelected) {
    case 0:{  
        std::cout << "========== Welcome to HORRIFIED ==========\n";
        std::cout << "What's Your Name Player 1? ";
        std::getline(std::cin, p1);
        CheckString(p1);
        std::cout << "When was the last time that you ate garlic " << p1 << "? (Ex: 2 days ago, 2 months ago, ...): ";
        std::getline(std::cin, last1);
        CheckFloat(last1);

        std::cout << "What's Your Name Player 2? ";
        std::getline(std::cin, p2);
        CheckString(p2);
        std::cout << "When was the last time that you ate garlic " << p2 << "? (Ex: 2 days ago, 2 months ago, ...): ";
        std::getline(std::cin, last2);
        CheckFloat(last2);

        if (last1 > last2)
            std::cout << p2 << " You can choose a hero: \n"; 
        else
            std::cout << p1 << " You can choose a hero: \n";

        int HeroChoose = MyTerminal.MenuGenerator(std::vector<std::string>{"Mayor", "Archaeologist"});
        switch (HeroChoose) {
        case 0: 
            heroPlayer = std::make_unique<Mayor>();  
            break;
        case 1: 
            heroPlayer = std::make_unique<Archaeologist>();  
            break;
        default:
            break;
        }
        break;  
    }
    case 1:  
        std::cout << "Logging Out ...\n";
        exit(0);  
        break;

    default:
        break;
    }
}

void Game ::SetUpGame()
{
    InitializeLocations();
    InitializeCards();
    InitializeCharacters();
    InitializeItem();
}
Game ::Game() : terrorLevel(0), heroPlayer(nullptr), GameOver(false)
{
    SetUpGame();
}
Game ::~Game() {};