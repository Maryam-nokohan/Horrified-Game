#include "../include/Monster.hpp"
#include "../include/MonsterCard.hpp"
#include "../include/Mayor.hpp"
#include "../include/Archaelogist.hpp"
#include "../include/Card.hpp"
#include "../include/Perk.hpp"
#include "../include/Dice.hpp"
#include "../include/Game.hpp"
#include "../include/Location.hpp"
#include "../include/Dracula.hpp"
#include "../include/invisible.hpp"
#include "../include/ErrorHandler.hpp"
#include "../include/Villager.hpp"
#include <queue>
#include <iostream>
#include "algorithm"
#include <random>
#include "../include/Terminal.hpp"
#include <memory>

void Game ::InitializeLocations()
{
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
    
    for(int i = 0 ; i < 2 ; i++){
        
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow , 2 , "Docks" , "Flower"));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow , 3 , "Camp" , "Tarot Deck"));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow , 2 , "Inn" , "Garlic"));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow , 3 , "Mansion" , "Mirrored Box"));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow , 3 , "Abbey" , "Stake"));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow , 4 , "Museum" , "Scroll Of Thoth"));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow , 3 , "Camp" , "Violin"));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow , 3 , "Museum" , "Tablet"));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow , 4 , "Camp" , "Wolfsbane"));
        Items.push_back(std::make_shared<Item>(ItemColor::Yellow , 4 , "Camp" , "Charm"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 2 , "Inn" , "Dart"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 3 , "Mansion" , "Fire Poker"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 5 , "Theatre" , "Rapier"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 2 , "Graveyard" , "Shovel"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 5 , "Barn" , "Torch"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 4 , "Barn" , "Pitchfork"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 6 , "Barn" , "Rifle"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 6 , "Shop" , "Silver Cane"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 3 , "Docks" , "Knife"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 6 , "Precinct" , "Pistol"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 4 , "Shop" , "Bear Trap"));
        Items.push_back(std::make_shared<Item>(ItemColor::Red , 4 , "Institute" , "Speargun"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 1 , "Institute" , "Anatomy Test"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 1 , "Laboratory" , "Contrifuge"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 1 , "Tower" , "Kite"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 2 , "Tower" , "Research"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 2 , "Mansion" , "Telescope"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 2 , "Precinct" , "Searchlight"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 2 , "Laboratory" , "Experiment"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 2 , "Institute" , "Analysis"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 3 , "Institute" , "Rotenone"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 3 , "Tower" , "Cosmic Ray Diffuser"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 3 , "Tower" , "Nebularium"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue , 3 , "Inn" , "Monocane Mixture"));
        Items.push_back(std::make_shared<Item>(ItemColor::Blue, 3 , "Camp" , "Fossil"));
        
    }
    std ::shuffle(Items.begin(), Items.end(), std ::mt19937(std ::random_device()()));
    for(int i = 0 ; i < 12 ; ++i)
    {
        std ::shared_ptr<Item> temp = Items.back();
        temp->setLocation(temp->getLocation());
        
        Items.pop_back();
    }
    
}
void Game ::InitializeCards()
{
    // Perk Card
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::shared_ptr<PerkCard>(new PerkCard("visit from Detective")));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::shared_ptr<PerkCard>(new PerkCard("Break of Down")));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::shared_ptr<PerkCard>(new PerkCard("OverStock")));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::shared_ptr<PerkCard>(new PerkCard("Late into the Night")));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::shared_ptr<PerkCard>(new PerkCard("Repel")));
    }
    for (int i = 0; i < 3; ++i)
    {
        PerkDeck.push_back(std ::shared_ptr<PerkCard>(new PerkCard("Hurry")));
    }
    std ::shuffle(PerkDeck.begin(), PerkDeck.end(), std ::mt19937(std ::random_device()()));
    // Monster Card
    for (int i = 0; i < 3; ++i)
    {
        MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("from the Bat", 2, "Place Dracula in the hero feild", MonsterStrike("I", 1, 2))));
    }
    for (int i = 0; i < 3; ++i)
    {
        MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("Sunrise", 0, "Put Dracula in Crypt", MonsterStrike("I", 1, 2))));
    }
    for (int i = 0; i < 2; ++i)
    {
        MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("Thief", 2, "put Invisible man in a location with the most items and remove all the item from that location", MonsterStrike("ID", 1, 3))));
    }
    MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("The Delivery", 3, "Put Chick and Wilbur in Dock", MonsterStrike("F", 1, 3))));
    MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("Fortune Teller", 3, "put maleva in camp", MonsterStrike("F", 1, 2))));
    MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("Former Employer", 3, "put dr.cranly in Lab", MonsterStrike("IF", 1, 2))));
    MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("Hurried Assistant", 3, "put Fritz in Tower", MonsterStrike("D", 2, 3))));
    MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("The innocent", 3, "put Maria in Barn", MonsterStrike("FDI", 1, 3))));
    MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("Egyptian Ecpert", 3, "put prof.Pearson in cave", MonsterStrike("DF", 2, 2))));
    MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("The ichthyologist", 3, "put dr.Read in Institute", MonsterStrike("F", 1, 2))));
    for (int i = 0; i < 2; ++i)
    {
        MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("On the Move", 3, "give Frenzy to the next Monster and take each villager one move closer to their safe house", MonsterStrike("F", 3, 2))));
    }
    for (int i = 0; i < 2; ++i)
    {
        MonsterDeck.push_back(std ::shared_ptr<MonsterCard>(new MonsterCard("Hypnotic Gaze", 2, "Closest Villager or Hero getting one move close to monster", MonsterStrike("I", 1, 2))));
    }
    std ::shuffle(MonsterDeck.begin(), MonsterDeck.end(), std ::mt19937(std ::random_device()()));
}
void Game :: InitializeCharacters()
{
    
    //villager:
    villagers.push_back(std :: make_shared<Villager>("Dr.Cranley" ,mapPlan.GetLocationptr("Precinct")));
    villagers.push_back(std :: make_shared<Villager>("Dr.Reed" ,mapPlan.GetLocationptr("Camp")));
    villagers.push_back(std :: make_shared<Villager>("Prof.Pearson" ,mapPlan.GetLocationptr("Museum")));
    villagers.push_back(std :: make_shared<Villager>("Maleva" ,mapPlan.GetLocationptr("Shop")));
    villagers.push_back(std :: make_shared<Villager>("Fritz" ,mapPlan.GetLocationptr("Institute")));
    villagers.push_back(std :: make_shared<Villager>("Wilbur & Chick" ,mapPlan.GetLocationptr("Dungeon")));
    villagers.push_back(std :: make_shared<Villager>("Maria" ,mapPlan.GetLocationptr("Camp")));
    //Hero and giving the start perk Card :
    //Big Bug :
    auto startArchloc = mapPlan.GetLocationptr("Docks");
    auto startMayorloc = mapPlan.GetLocationptr("Theatre");
    heroes.push_back(std :: make_shared<Mayor>(startMayorloc));
    heroes[0]->GetPerkCard(PerkDeck.back());
    PerkDeck.pop_back();
    heroes.push_back(std :: make_shared<Archaeologist>(startArchloc));
    heroes[1]->GetPerkCard(PerkDeck.back());
    PerkDeck.pop_back();
    std :: cout << "YesHero\n";
    //monster
    Monsters.push_back(std :: make_shared<Dracula>());
    Monsters.push_back(std :: make_shared<InvisibleMan>());
    Monsters[0]->SetLocation(mapPlan.GetLocationptr("Crypt"));
    Monsters[1]->SetLocation(mapPlan.GetLocationptr("Laboratory"));
    std :: cout << "YesMonster\n";
}

void Game::HeroPhase()
{
    MyTerminal.StylizeTextBoard("===========HeroPhase===========");
    
    while (heroPlayer->getRemainingActions()) {
        int selected = MyTerminal.MenuGenerator({"Move", "Guid", "Pick up", "Advance", "Defeat", "Special Action"});

        // Move
        if (selected == 0) {
            std::cout << "Select a location to move:\n";
            auto neighbors = heroPlayer->getLocation()->GetNeighbors();
            std::vector<std::string> neighborNames;
            for (const auto& loc : neighbors)
                neighborNames.push_back(loc->GetCityName());

            int select = MyTerminal.MenuGenerator(neighborNames);
            if (select >= 0 && select < neighbors.size()) {
                auto nextLocation = neighbors[select];
                auto villagers = heroPlayer->getLocation()->GetVillager();

                if (!villagers.empty()) {
                    std::cout << "Would you like to move the villagers with you?\n";
                    int choice = MyTerminal.MenuGenerator({"Yes", "No"});
                    if (choice == 0) {
                        for (auto& v : villagers)
                            v->SetLocation(nextLocation);
                    }
                }

                heroPlayer->getLocation()->RemoveHero(heroPlayer);
                heroPlayer->moveTo(nextLocation);
            }
        }

        // Guide
        else if (selected == 1) {
            auto currentLoc = heroPlayer->getLocation();
            auto neighbors = currentLoc->GetNeighbors();
            std::vector<std::string> guideOptions;
            std::vector<std::pair<std::shared_ptr<Villager>, std::shared_ptr<Location>>> guideable;

            for (const auto& neighbor : neighbors) {
                for (const auto& villager : neighbor->GetVillager()) {
                    guideOptions.push_back(villager->getName() + " (at " + neighbor->GetCityName() + ")");
                    guideable.emplace_back(villager, neighbor);
                }
            }

            if (!guideOptions.empty()) {
                int choice = MyTerminal.MenuGenerator(guideOptions);
                if (choice >= 0 && choice < guideable.size()) {
                    auto villager = guideable[choice].first;
                    auto from = guideable[choice].second;
                    from->RemoveVillager(villager);
                    villager->moveTo(currentLoc);
                    currentLoc->AddVillager(villager);
                    std::cout << "You guided " << villager->getName() << " to " << currentLoc->GetCityName() << ".\n";
                    heroPlayer->resetActions(); // optional: if guiding consumes all actions
                }
            } else {
                std::cout << "No villagers in nearby locations to guide.\n";
            }
        }

        // Pick up
        else if (selected == 2) {
            heroPlayer->pickUpItems();
        }

        // Advance
        else if (selected == 3) {
            auto city = heroPlayer->getLocation()->GetCityName();
            auto& inventory = heroPlayer->getInventory();
            const int requiredPower = 6;

            std::vector<std::string> draculaSpots = {"Cave", "Crypt", "Dungeon", "Graveyard"};
            std::vector<std::string> invisibleSpots = {"Museum", "Laboratory", "Shop", "Inn"};

            auto draculaIt = std::find(draculaSpots.begin(), draculaSpots.end(), city);
            if (draculaIt != draculaSpots.end()) {
                std::vector<std :: shared_ptr<Item>> redItems;
                for (const auto& item : inventory)
                    if (item->getColor() == ItemColor::Red)
                        redItems.push_back(item);

                std::sort(redItems.begin(), redItems.end(), [](const std :: shared_ptr<Item>& a, const std :: shared_ptr<Item>& b) {
                    return a->getPower() < b->getPower();
                });

int total = 0;
                std::vector<std :: shared_ptr<Item>> usedItems;
                for (const auto& item : redItems) {
                    if (total >= requiredPower) break;
                    total += item->getPower();
                    usedItems.push_back(item);
                }

                auto dracula = std::dynamic_pointer_cast<Dracula>(Monsters[0]);
                int coffinIndex = std::distance(draculaSpots.begin(), draculaIt);

                if (total >= requiredPower && !dracula->IsCoffinDestroyed(coffinIndex)) {
                    for (const auto& item : usedItems)
                        heroPlayer->RemoveItem(item);
                    dracula->DestroyCoffin(coffinIndex);
                    std::cout << "You smashed a Dracula coffin at " << city << "!\n";
                } else {
                    std::cout << "Not enough red item power or coffin already destroyed.\n";
                }
            }

            auto invisIt = std::find(invisibleSpots.begin(), invisibleSpots.end(), city);
            if (invisIt != invisibleSpots.end()) {
                std::vector<std :: shared_ptr<Item>> yellowItems;
                for (const auto& item : inventory)
                    if (item->getColor() == ItemColor::Yellow)
                        yellowItems.push_back(item);

                std::sort(yellowItems.begin(), yellowItems.end(), [](const std :: shared_ptr<Item>& a, const std :: shared_ptr<Item>& b) {
                    return a->getPower() < b->getPower();
                });

                int total = 0;
                std::vector<std :: shared_ptr<Item>> usedItems;
                for (const auto& item : yellowItems) {
                    if (total >= requiredPower) break;
                    total += item->getPower();
                    usedItems.push_back(item);
                }

                auto invisible = std::dynamic_pointer_cast<InvisibleMan>(Monsters[1]);
                int evidenceIndex = std::distance(invisibleSpots.begin(), invisIt);

                if (total >= requiredPower && !invisible->IsEvidenceCollected(evidenceIndex)) {
                    for (const auto& item : usedItems)
                        heroPlayer->RemoveItem(item);
                    invisible->DestroyEvidence(evidenceIndex);
                    std::cout << "You collected Invisible Man evidence at " << city << "!\n";
                } else {
                    std::cout << "Not enough yellow item power or evidence already collected.\n";
                }
            }
        }

        // Defeat (not yet implemented)
        else if (selected == 4) {
            std::cout << "Defeat action is not implemented yet.\n";
        }

        // Special Action
        else if (selected == 5) {
            heroPlayer->specialAction();
        }
    }

    heroPlayer->resetActions();

    std::cout << "End of actions.\n";
    std::cout << "Would you like to use a perk card?\n";
    int usePerk = MyTerminal.MenuGenerator({"Yes", "No"});
    if (usePerk == 0) {
        auto perkCard = heroPlayer->UsePerkCard();
        if (perkCard) {
            std::string name = perkCard->GetName();
            std::cout << "You used perk: " << name << "\n";

            if (name == "Visit from Detective") {
                std::vector<std::string> cities;
                for (const auto& [name, loc] : mapPlan.getLocations())
                    cities.push_back(name);
                int idx = MyTerminal.MenuGenerator(cities);
                heroPlayer->SetLocation(mapPlan.GetLocationptr(cities[idx]));
            }
            else if (name == "Break of Down") {
                skipMonsterPhase = true;
            }
            else if (name == "OverStock") {
                for (int i = 0; i < 3 && !Items.empty(); ++i) {
                    Items.back()->setLocation(Items.back()->getLocation());

Items.pop_back();
                }
            }
            else if (name == "Late into the Night") {
                heroPlayer->resetActions();
            }
            else if (name == "Repel") {
                std::vector<std::string> names;
                for (auto& m : Monsters) names.push_back(m->GetName());
                int idx = MyTerminal.MenuGenerator(names);
                auto monster = Monsters[idx];
                auto neighbors = monster->GetLocation()->GetNeighbors();
                std::vector<std::string> opts;
                for (auto& loc : neighbors) opts.push_back(loc->GetCityName());
                int dest = MyTerminal.MenuGenerator(opts);
                monster->SetLocation(mapPlan.GetLocationptr(opts[dest]));
            }
            else if (name == "Hurry") {
                std::vector<std::string> villagerNames;
                for (auto& v : villagers)
                    villagerNames.push_back(v->getName());
                int idx = MyTerminal.MenuGenerator(villagerNames);
                villagers[idx]->SetLocation(mapPlan.GetLocationptr("Hospital"));
            }
        }
    }
}
void Game::MonsterPhase()
{
MyTerminal.StylizeTextBoard("MonsterPhase");
}
void Game::GameStart() {
    //Start Logo:
    MyTerminal.StylizeTextBoard("===========Welcome to HORRIFIED===========");
    //Start menue:
    int StartMenuSelected = MyTerminal.MenuGenerator(std::vector<std::string>{"Start", "Exit"});
    std::string p1, p2;
    std::string last1, last2;

    switch (StartMenuSelected) {
        case 0:{  
        p1 = MyTerminal.GetInput("What's Your Name Player 1? ");
        std::cout << "When was the last time that you ate garlic " << p1 << "? (Ex: 2 days ago, 2 months ago, ...): ";
        std::getline(std::cin, last1);
        CheckFloat(last1);

        std::cout << "What's Your Name Player 2? ";
        std::getline(std::cin, p2);
        CheckString(p2);
        std::cout << "When was the last time that you ate garlic " << p2 << "? (Ex: 2 days ago, 2 months ago, ...): ";
        std::getline(std::cin, last2);
        CheckFloat(last2);

        if (std :: stof(last1) > std :: stof(last2))
            std::cout << p2 << " You can choose a hero: \n"; 
        else
            std::cout << p1 << " You can choose a hero: \n";

        int HeroChoose = MyTerminal.MenuGenerator(std::vector<std::string>{"Mayor", "Archaeologist"});
        switch (HeroChoose) {
        case 0: 
            heroPlayer = heroes[0];  
            break;
        case 1: 
            heroPlayer = heroes[1];  
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
    MyTerminal.Refresh();
    while(!GameOver)
    {
        HeroPhase();
        CheckGameEnd();
        MonsterPhase();
    }
}
void Game :: LocationOverView()
{
    MyTerminal.StylizeTextBoard("===========Location Overview===========");



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
void Game :: PlayerGetHit(){

    bool Defended = false;
    auto inventory = heroPlayer->getInventory();
    if(!inventory.empty()){
    std :: cout << "Would You Like to use an Items ?\n";
    int selected = MyTerminal.MenuGenerator(std :: vector<std :: string>{"Yes" ,"No"});
    switch (selected)
    {
    case 0:{
    Defended = true;
    std :: vector <std :: string > ItemNames;
     for(const auto & item : inventory)
    {
        ItemNames.push_back(item->getName());
    }
    std :: cout << "Choose an Item to discard : \n";
    int index = MyTerminal.MenuGenerator(ItemNames);
    heroPlayer->RemoveItem(inventory[index]);
    return;
    break;
    }
    case 1 : {
        auto CurrLoc = heroPlayer->getLocation();
        CurrLoc->RemoveHero(heroPlayer);
        heroPlayer->SetLocation(mapPlan.GetLocationptr("Hospital"));
        terrorLevel++;
        CheckGameEnd();
        return;
        break;}
        default:
        break;
    }
}
else{
   
    std :: cout << "Not enaugth Items !!\n";
    auto CurrLoc = heroPlayer->getLocation();
    CurrLoc->RemoveHero(heroPlayer);
    heroPlayer->SetLocation(mapPlan.GetLocationptr("Hospital"));
    terrorLevel++;
    CheckGameEnd();
}

}
bool Game::CheckGameEnd()
{}