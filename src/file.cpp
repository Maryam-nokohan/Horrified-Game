#include "../include/file.hpp"
#include "../include/Mayor.hpp"
#include "../include/Archaelogist.hpp"
#include "../include/Courier.hpp"
#include "../include/scientist.hpp"
#include "../include/Monster.hpp"
#include "../include/Dracula.hpp"
#include "../include/invisible.hpp"

#include <stdexcept>
#include <fstream>
#include <filesystem>
#include <iostream>

void GameFileHandler::SaveGame(Game &game, const std::string &filename)
{
    std::filesystem::path filePath = filename;

    if (std::filesystem::exists(filePath) && std::filesystem::file_size(filePath) != 0)
    {
        std::cout << "File is not empty, we overwrite the file!\n";
    }

    std::ofstream out(filename);
    if (!out.is_open())
    {
        throw std::invalid_argument("Failed to open file: " + filename + "\n");
    }

    out << "terrorLevel " << game.terrorLevel << "\n";

    int currentPlayerIndex = (game.heroPlayer == game.heroes[1]) ? 1 : 0;
    out << "currentPlayerIndex " << currentPlayerIndex << "\n";

    // Save heroes
    out << "heroCount " << game.heroes.size() << "\n";
    for (const auto &hero : game.heroes)
    {
        out << "heroName " << hero->getName() << "\n";
        if (!hero->getLocation())
            throw std::runtime_error("Hero " + hero->getName() + " has null location!");
        out << "location " << hero->getLocation()->GetCityName() << "\n";
        out << "actions " << hero->getRemainingActions() << "\n";

        auto inventory = hero->getInventory();
        out << "inventorySize " << inventory.size() << "\n";
        for (const auto &item : inventory)
        {
            if (!item)
                continue;
            out << "item " << item->getPower() << " " << static_cast<int>(item->getColor()) << " " << item->getName() << "\n";
        }

        const auto &perkStack = hero->getPerks();
        out << "heroPerks " << perkStack.size() << "\n";
        for (const auto &perk : perkStack)
        {
            out << "perk " << perk->GetName() << "\n";
        }
    }

    // Save Perk Deck
    out << "perkDeckSize " << game.PerkDeck.size() << "\n";
    for (const auto &card : game.PerkDeck)
    {
        out << "perk " << card->GetName() << "\n";
    }

    // Save Monster Deck
    out << "monsterDeckSize " << game.MonsterDeck.size() << "\n";
    for (const auto &card : game.MonsterDeck)
    {
        out << "monsterCard\n";
        out << "name " << card->GetName() << "\n";
        out << "item " << card->GetItem() << "\n";
        out << "event " << card->GetEvent() << "\n";
        out << "order " << card->GetOrderSymbold() << "\n";
        out << "move " << card->GetMove() << "\n";
        out << "dice " << card->GetDiceRoll() << "\n";
    }

    // Location status
    out << "locationCount " << game.mapPlan.getLocations().size() << "\n";

    for (const auto &[name, loc] : game.mapPlan.getLocations())
    {
        out << "location " << name << "\n";

        // Items at this location
        const auto &items = loc->GetItems();
        out << "items " << items.size() << "\n";
        for (const auto &item : items)
        {
            out << "item " << item->getPower() << " " << static_cast<int>(item->getColor()) << " " << item->getName() << "\n";
        }

        // Villagers
        const auto &villagers = loc->GetVillager();
        out << "villagers " << villagers.size() << "\n";
        for (const auto &v : villagers)
        {
            out << "villager " << v->getName() << "\n";
        }

        // Heroes
        const auto &heroes = loc->GetHero();
        out << "heroes " << heroes.size() << "\n";
        for (const auto &h : heroes)
        {
            out << "hero " << h->getName() << "\n";
        }

        // Monsters
        const auto &monsters = loc->GetMonsters();
        out << "monsters " << monsters.size() << "\n";
        for (const auto &m : monsters)
        {
            out << "monster " << m->GetName() << "\n";
        }
    }
    // Dracula's destroyed coffins
    auto dracula = game.GetDracula();
    if (dracula)
    {
        const auto &coffins = dracula->GetCoffins();
        out << "draculaCoffins " << coffins.size() << "\n";
        for (const auto &[destroyed, name] : coffins)
        {
            out << destroyed << " " << name << "\n";
        }
    }

    // InvisibleMan collected evidence
    auto invisible = game.GetInvisibleMan();
    if (invisible)
    {
        const auto &evidences = invisible->GetEvidence();
        out << "invisibleEvidence " << evidences.size() << "\n";
        for (const auto &[destroyed, name] : evidences)
        {
            out << destroyed << " " << name << "\n";
        }
    }
    // Save Villagers
    out << "villagerCount " << game.villagers.size() << '\n';
    for (const auto &village : game.villagers)
    {
        out << "villagerName " << village->getName() << '\n';
        out << "currentLocation " << village->getCurrentLocationName() << '\n';
        out << "safeHouse " << village->getSafeLocation()->GetCityName() << '\n';
        out << "villagerState " << static_cast<int>(village->isAlive()) << '\n';
    }

    out.close();
    std::cout << "✅ Game saved to " << filename << "\n";
}

void GameFileHandler::LoadGame(Game &game, const std::string &filename)
{
    std::ifstream in(filename);
    if (!in.is_open())
    {
        throw std::invalid_argument("Failed to open save file: " + filename);
    }

    // reset
    game.Reset();

    std::string token;
    in >> token >> game.terrorLevel;
    in >> token;
    int currentPlayerIndex;
    in >> currentPlayerIndex;

    // heros
    int heroCount;
    in >> token >> heroCount;

    for (int i = 0; i < heroCount; ++i)
    {
        in >> token;
        std::string heroName;
        in.ignore();
        std::getline(in, heroName);

        in >> token;
        std::string locName;
        in >> locName;

        in >> token;
        int actions;
        in >> actions;

        std::shared_ptr<Hero> hero;
        auto loc = game.mapPlan.GetLocationptr(locName);
        if (!loc)
            throw std::runtime_error("Invalid location name from save file: " + locName);
        if (heroName == "Mayor")
            hero = std::make_shared<Mayor>(loc);
        else if (heroName == "Archaeologist")
            hero = std::make_shared<Archaeologist>(loc);
        else if (heroName == "Courier")
            hero = std::make_shared<Courier>(loc);
        else if (heroName == "Scientist")
            hero = std::make_shared<Scientist>(loc);
        else
            throw std::runtime_error("Unknown hero name: " + heroName);

        hero->resetActions();
        for (int j = 0; j < (4 - actions); ++j)
            hero->DecreaseAction();

        // Inventory
        int invSize;
        in >> token >> invSize;
        for (int j = 0; j < invSize; ++j)
        {

            in >> token;
            int power, color;
            std::string ItemName;
            in >> power >> color >> std::ws;
            std::getline(in, ItemName);

            auto item = std::make_shared<Item>((ItemColor)color, power, loc, ItemName);
            hero->addItems(item);
        }

        // Perk cards
        int perkSize;
        in >> token >> perkSize;
        for (int j = 0; j < perkSize; ++j)
        {
            in >> token >> std::ws;
            std::string perkName;
            std::getline(in, perkName);
            hero->GetPerkCard(std::make_shared<PerkCard>(perkName));
        }

        game.heroes.push_back(hero);
    }

    // current player
    game.heroPlayer = game.heroes[currentPlayerIndex];

    // Perk Deck
    int perkDeckSize;
    in >> token >> perkDeckSize;
    for (int i = 0; i < perkDeckSize; ++i)
    {
        in >> token >> std::ws;
        std::string perkName;
        std::getline(in, perkName);
        game.PerkDeck.push_back(std::make_shared<PerkCard>(perkName));
    }

    // Monster Deck
    int monsterDeckSize;
    in >> token >> monsterDeckSize;
    for (int i = 0; i < monsterDeckSize; ++i)
    {
        in >> token >> std::ws;
        std::string name, event, order;
        int item, move, dice;

        in >> token >> std::ws;
        std::getline(in, name);
        in >> token >> item;
        in >> token >> std::ws;
        std::getline(in, event);
        in >> token >> order;
        in >> token >> move;
        in >> token >> dice;

        game.MonsterDeck.push_back(std::make_shared<MonsterCard>(name, item, event, MonsterStrike(order, move, dice)));
    }

    std::vector<std::pair<std::string, std::string>> villagerLocationPairs;

    // Locs
    int locCount;
    in >> token >> locCount;

    for (int i = 0; i < locCount; ++i)
    {
        in >> token;
        std::string locName;
        in >> locName;
        auto loc = game.mapPlan.GetLocationptr(locName);
        if (!loc)
            throw std::runtime_error("Invalid location name Item from save file: " + locName);

        int count;

        // Items
        in >> token >> count;
        for (int j = 0; j < count; ++j)
        {
            in >> token;
            int power, color;
            std::string ItemName;
            in >> power >> color >> std::ws;
            std::getline(in, ItemName);

            auto item = std::make_shared<Item>((ItemColor)color, power, loc,loc, ItemName);
            loc->AddItem(item);
        }

        // Villagers
        in >> token >> count;

        for (int j = 0; j < count; ++j)
        {
            in >> token >> std::ws;
            std::string name;
            std::getline(in, name);
            villagerLocationPairs.emplace_back(name, loc->GetCityName());
        }

        // Heroes
        in >> token >> count;
        for (int j = 0; j < count; ++j)
        {
            in >> token;
            std::string name;
            in.ignore();
            std::getline(in, name);
            for (auto &h : game.heroes)
            {
                if (h->getName() == name)
                {
                    loc->AddHero(h);
                    h->moveTo(loc);
                }
            }
        }

        // Monsters
        in >> token >> count;
        for (int j = 0; j < count; ++j)
        {
            in >> token;
            std::string name;
            in.ignore();
            std::getline(in, name);
            for (auto &m : game.Monsters)
            {
                if (m->GetName() == name)
                {
                    m->Move(loc);
                }
            }
        }
    }
    // Dracula coffins
    in >> token;
    if (token == "draculaCoffins")
    {
        int coffinCount;
        in >> coffinCount;
        auto dracula = game.GetDracula();
     for (int i = 0; i < coffinCount; ++i)
        {
            bool destroyed;
            std::string name;
            in >> destroyed >> name;
            if (destroyed)
                dracula->AddDetroyedCoffin(name);
        }
    }

    // InvisibleMan evidence
    in >> token;
    if (token == "invisibleEvidence")
    {
        int evCount;
        in >> evCount;
        auto invisible = game.GetInvisibleMan();
        for (int i = 0; i < evCount; ++i)
        {
            bool destroyed;
            std::string name;
            in >> destroyed >> name;
            if (destroyed)
                invisible->AddDetroyedEvidence(name);
        }
    }
    // Villagers
    int villageCount;
    in >> token >> villageCount;
    for (int i = 0; i < villageCount; ++i)
    {
        in >> token >> std::ws;
        std::string villagerName;
        std::getline(in, villagerName);

        in >> token >> std::ws;
        std::string currentLocStr;
        in >> currentLocStr;

        in >> token >> std::ws;
        std::string safeLoc;
        in >> safeLoc;

        in >> token;
        int stateInt;
        in >> stateInt;

        auto safeLocation = game.mapPlan.GetLocationptr(safeLoc);
        auto currentLoc = (currentLocStr == "NO_LOCATION") ? nullptr : game.mapPlan.GetLocationptr(currentLocStr);

        auto villager = std::make_shared<Villager>(villagerName, safeLocation);
        villager->SetState(static_cast<State>(stateInt));

        if (currentLoc)
            villager->SetLocation(currentLoc);

        game.villagers.push_back(villager);
    }

    in.close();
    std::cout << "✅ Game loaded from " << filename << "\n";
}
