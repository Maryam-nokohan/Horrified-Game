#include "../include/MonsterCard.hpp"
#include "../include/Monster.hpp"
#include "../include/Card.hpp"
#include "../include/Game.hpp"
#include "../include/Names.hpp"
#include "../include/LocationNames.hpp"
#include "../include/Location.hpp"
#include "../include/Dice.hpp"
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <memory>
using namespace LocationNames;
using namespace Names;


MonsterCard :: MonsterCard(const std :: string &name , int item , const std :: string & event , const MonsterStrike& strike) : Card (name){
    this->item = item;
    this->Event = event;
    this->Strikes = strike;
}
int :: MonsterCard ::GetItem ()const {return item;}
std :: string MonsterCard ::GetOrderSymbold(){return Strikes.MonsterSymbol;}
int MonsterCard ::GetMove() {return Strikes.MoveNum;}
int MonsterCard ::GetDiceRoll() {return Strikes.DiceRoll;}
std :: string MonsterCard::GetEvent(){return Event;}
void MonsterCard ::ApplyEffect(Game & game)
{
    //Put items : 
    game.SetRandomItems(item);
    //apply event

    auto dracula = std::dynamic_pointer_cast<Dracula>(game.Monsters[0]);
    auto invisible = std::dynamic_pointer_cast<InvisibleMan>(game.Monsters[1]);

    if (Name == Sunrise)
    {
        dracula->SetLocation(game.mapPlan.GetLocationptr(Crypt));
    }

    else if (Name == FromTheBat)
    {
        dracula->SetLocation(game.heroPlayer->getLocation());
    }

    else if (Name == Thief)
    {
        std::shared_ptr<Location> bestLoc = nullptr;
        int maxItems = -1;
        for (auto &[name, loc] :game.mapPlan.getLocations())
        {
            if ((int)loc->GetItems().size() > maxItems)
            {
                maxItems = loc->GetItems().size();
                bestLoc = loc;
            }
        }
        if (bestLoc)
        {
            invisible->SetLocation(bestLoc);
            bestLoc->ClearItems();
        }
    }

    else if (Name == TheDelivery)
    {
        auto docks = game.mapPlan.GetLocationptr(Docks);
        for (auto &v : game.villagers)
            if (v->getName() == WilburAndChick)
                v->SetLocation(docks);
    }

    else if (Name == FortuneTeller)
    {
        auto camp = game.mapPlan.GetLocationptr(Camp);
        for (auto &v : game.villagers)
            if (v->getName() == Maleva)
                v->SetLocation(camp);
    }

    else if (Name == FormerEmployer)
    {
        auto lab = game.mapPlan.GetLocationptr(Laboratory);
        for (auto &v : game.villagers)
            if (v->getName() == DrCranley)
                v->SetLocation(lab);
    }

    else if (Name == TheInnocent)
    {
        auto barn = game.mapPlan.GetLocationptr(Barn);
        for (auto &v : game.villagers)
            if (v->getName() == Maria)
                v->SetLocation(barn);
    }

    else if (Name == EgyptianExpert)
    {
        auto cave = game.mapPlan.GetLocationptr(Cave);
        for (auto &v : game.villagers)
            if (v->getName() == ProfPearson)
                v->SetLocation(cave);
    }

    else if (Event == TheIchthyologist)
    {
        auto inst = game.mapPlan.GetLocationptr(Institute);
        for (auto &v : game.villagers)
            if (v->getName() == DrReed)
                v->SetLocation(inst);
    }

    else if (Name == OnTheMove)
    {
        int frenzyIndex = 0;
        for (size_t i = 0; i < game.Monsters.size(); ++i)
            if (game.Monsters[i]->GetFrenzyMarker())
                frenzyIndex = (i + 1) %game. Monsters.size();

        for (auto &m : game.Monsters)
            m->SetFrenzyMarker(false);
        game.Monsters[frenzyIndex]->SetFrenzyMarker(true);

        for (auto &v : game.villagers)
        {
            auto from = v->getCurrentLocation();
            auto to = v->getSafeLocation();

            if (!from || !to || from == to)
                continue;

            std::unordered_map<std::shared_ptr<Location>, std::shared_ptr<Location>> prev;
            std::queue<std::shared_ptr<Location>> q;
            std::unordered_set<std::shared_ptr<Location>> visited;

            q.push(from);
            visited.insert(from);

            while (!q.empty())
            {
                auto curr = q.front();
                q.pop();
                if (curr == to)
                    break;

                for (auto &neighbor : curr->GetNeighbors())
                {
                    if (!visited.count(neighbor))
                    {
                        visited.insert(neighbor);
                        prev[neighbor] = curr;
                        q.push(neighbor);
                    }
                }
            }

            std::vector<std::shared_ptr<Location>> path;
            for (auto step = to; step != from && prev.count(step); step = prev[step])
                path.push_back(step);

            std::reverse(path.begin(), path.end());

            if (!path.empty())
            {
                auto nextStep = path.front();
                from->RemoveVillager(v);
                v->SetLocation(nextStep);
                game.MyTerminal.StylizeTextBoard("Villager " + v->getName() + " moves toward safe house: " + nextStep->GetCityName());
            }
        }
    }

    else if (Name == HypnoticGaze)
    {
        auto monsterLoc = game.Monsters[0]->GetLocation(); 
        std::shared_ptr<Hero> closestHero = nullptr;
        std::shared_ptr<Villager> closestVillager = nullptr;
        int minDist = std::numeric_limits<int>::max();

        std::unordered_map<std::shared_ptr<Location>, int> dist;
        std::queue<std::shared_ptr<Location>> q;
        dist[monsterLoc] = 0;
        q.push(monsterLoc);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int d = dist[curr];

            for (auto &h : game.heroes)
                if (h->getLocation() == curr && d < minDist)
                {
                    closestHero = h;
                    closestVillager = nullptr;
                    minDist = d;
                }

            for (auto &v : game.villagers)
                if (v->getCurrentLocation() == curr && d < minDist)
                {
                    closestVillager = v;
                    closestHero = nullptr;
                    minDist = d;
                }

            for (auto &nei : curr->GetNeighbors())
                if (!dist.count(nei))
                {
                    dist[nei] = d + 1;
                    q.push(nei);
                }
        }

        auto target = closestHero ? closestHero->getLocation()
                                  : (closestVillager ? closestVillager->getCurrentLocation() : nullptr);
        if (!target || target == monsterLoc)
            return;

        std::unordered_map<std::shared_ptr<Location>, std::shared_ptr<Location>> prev;
        std::queue<std::shared_ptr<Location>> q2;
        std::unordered_set<std::shared_ptr<Location>> visited;

        q2.push(target);
        visited.insert(target);

        while (!q2.empty())
        {
            auto curr = q2.front();
            q2.pop();
            if (curr == monsterLoc)
                break;

            for (auto &neighbor : curr->GetNeighbors())
            {
                if (!visited.count(neighbor))
                {
                    visited.insert(neighbor);
                    prev[neighbor] = curr;
                    q2.push(neighbor);
                }
            }
        }

        std::vector<std::shared_ptr<Location>> path;
        for (auto step = monsterLoc; step && prev.count(step); step = prev[step])
            path.push_back(step);
        std::reverse(path.begin(), path.end());

        if (path.size() >= 2)
        {
            auto nextStep = path[1];
            if (closestHero)
            {
                auto loc = closestHero->getLocation();
                loc->RemoveHero(closestHero);
                closestHero->SetLocation(nextStep);
                game.MyTerminal.StylizeTextBoard("Hero " + closestHero->getName() + " moves toward monster.");
            }
            else if (closestVillager)
            {
                auto loc = closestVillager->getCurrentLocation();
                loc->RemoveVillager(closestVillager);
                closestVillager->SetLocation(nextStep);
                game.MyTerminal.StylizeTextBoard("Villager " + closestVillager->getName() + " moves toward monster.");
            }
        }
    }

    //apply strikes : 
    for (const auto ch : Strikes.MonsterSymbol)
    {
        if (ch == 'D')
        {
            ApplyMonsterStrike(game , game.Monsters[0]);
        }
        else if (ch == 'I')
        {
            ApplyMonsterStrike(game , game. Monsters[1]);
        }
        else if (ch == 'F')
        {
            if (game.Monsters[0]->GetFrenzyMarker())
            {
                ApplyMonsterStrike(game , game.Monsters[0]);
            }
            else if (game.Monsters[1]->GetFrenzyMarker())
            {
                ApplyMonsterStrike(game , game.Monsters[1]);
            }
        }
    }
    game.MyTerminal.StylizeTextBoard("Played Card : " + Name);
    game.MyTerminal.ShowPause();
}


void MonsterCard:: ApplyMonsterStrike(Game & game , std ::shared_ptr<Monster> monsterName)
{
    
    if (monsterName->GetLocation()->GetHero().empty() && monsterName->GetLocation()->GetVillager().empty())
    {
        monsterName->Move(monsterName->FindNearestOpponent(game.mapPlan, monsterName->GetLocation(), Strikes.MoveNum));
    }
    for (int i = 0; i < Strikes.DiceRoll; ++i)
    {
        std ::string face = game.GameDice->DiceRoll();
        if (face == "*")
        {
            monsterName->Attack(game);
        }
        else if (face == "!")
        {
            std ::string name = monsterName->GetName();
            if (name == "Dracula")
            {
                std ::shared_ptr<Dracula> dracula = std ::dynamic_pointer_cast<Dracula>(monsterName);
                dracula->DarkCharm(game.heroPlayer);
            }
            else
            {
                std ::shared_ptr<InvisibleMan> invisibleMan = std ::dynamic_pointer_cast<InvisibleMan>(monsterName);
                invisibleMan->StalkUnseen(game, 2);
            }
        }
        else if (face == " ")
        {
            game.MyTerminal.StylizeTextBoard("No action for Dice!\n");
        }
    }
}
