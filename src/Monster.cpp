#include "../include/Monster.hpp"
#include "../include/Villager.hpp"
#include "../include/Item.hpp"
#include "../include/Location.hpp"
#include "../include/Map.hpp"
#include "../include/Game.hpp"
#include "../include/ErrorHandler.hpp"
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <queue>
#include <iostream>
#include <memory>
#include <string>
//Constructor
Monster ::Monster(const std :: string  name  , int frenzyOrder ,bool hasFrenzy ) :CurrentLocation(nullptr) {
this->Name = name;
if(frenzyOrder >=0)
this->FrenzyOrder = frenzyOrder;
else 
throw std :: invalid_argument("frenzy order can't be negative!\n");
this->HasFrenzy = hasFrenzy;
}
//Get methods
std :: string Monster ::GetName () {return Name;}
int Monster :: GetFrenzyOrder()const{
    return FrenzyOrder;

}
bool Monster ::  GetFrenzyMarker()const{
return HasFrenzy;}
const std::shared_ptr<Location>& Monster ::  GetLocation()const{
if(CurrentLocation)
return CurrentLocation;
else throw std::invalid_argument("No location Set for Monster " + Name);
}

//Set methods
void Monster ::  SetFrenzyMarker(bool hasMarker){
HasFrenzy = hasMarker;
}
void Monster ::  SetLocation(std :: shared_ptr<Location> currLoc){
if(CurrentLocation)
{
    CurrentLocation->RemoveMonster(shared_from_this());
}
CurrentLocation = currLoc;
if(currLoc)
{
    currLoc->AddMonster(shared_from_this());
}
}
//Find nearest opponent to attack
const std :: shared_ptr< Location> Monster::FindNearestOpponent(Map& plan, std::shared_ptr<Location> monsterLocation, int monsterMoves) {
    std::unordered_map<std :: shared_ptr<Location>, int> distances;
    std::unordered_map<std :: shared_ptr<Location>, std :: shared_ptr<Location>> prev;
    std::queue<std :: shared_ptr<Location>> q;

    // BFS to calculate distances
    distances[monsterLocation] = 0;
    q.push(monsterLocation);

    while (!q.empty()) {
        std :: shared_ptr<Location> curr = q.front();
        q.pop();
        for (auto& neighbor : curr->GetNeighbors()) {
            if (distances.find(neighbor) == distances.end()) {
                distances[neighbor] = distances[curr] + 1;
                prev[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    struct OpponentInfo {
        std :: shared_ptr<Location> loc;
        int dist;
        bool isHero;
    };

    std::vector<OpponentInfo> candidates;
    int minDist = std::numeric_limits<int>::max();

    for (const auto& [name, locPtr] : plan.getLocations()) {
        std :: shared_ptr<Location> loc = locPtr;
        if (distances.find(loc) == distances.end()) continue;

        int dist = distances[loc];
        auto heroes = loc->GetHero();
        auto villagers = loc->GetVillager();

        if (!heroes.empty()) {
            if (dist < minDist) {
                candidates.clear();
                minDist = dist;
            }
            if (dist == minDist) {
                candidates.push_back({loc, dist, true});
            }
        }

        if (!villagers.empty()) {
            if (dist < minDist || (dist == minDist && candidates.empty())) {
                if (dist < minDist) candidates.clear();
                minDist = dist;
                candidates.push_back({loc, dist, false});
            } else if (dist == minDist && !std::any_of(candidates.begin(), candidates.end(), [](const OpponentInfo& o) { return o.isHero; })) {
                candidates.push_back({loc, dist, false});
            }
        }
    }

    if (candidates.empty()) return monsterLocation;

    // Prefer hero if multiple at same minDist
    std::vector<OpponentInfo> best;
    for (const auto& c : candidates) {
        if (c.dist == minDist && c.isHero) best.push_back(c);
    }
    if (best.empty()) best = candidates;

    OpponentInfo chosen = best[rand() % best.size()];

    // Build path back to monster
    std::vector<std :: shared_ptr<Location>> path;
    std :: shared_ptr<Location> step = chosen.loc;
    while (step->GetCityName() != monsterLocation->GetCityName()) {
        path.push_back(step);
        step = prev[step];
    }
    std::reverse(path.begin(), path.end());

    if (path.size() <= static_cast<size_t>(monsterMoves)) {
        return chosen.loc;
    } else {
        return path[monsterMoves - 1];
    }
}
//Attack
bool Monster ::Attack(Game& game)
{
    bool successe = false;
    // game.MyTerminal.ShowPopupMessages(game ,Name + " Attacks!");
    if(Name == "Dracula")
    game.MyTerminal.ShowBackgroundScreen("DraculaAttack" , "Dracula Attacks!");
    if(Name == "Invisible Man")
    game.MyTerminal.ShowBackgroundScreen("InvisibleAttack" , "Invisble Man Attacks!");
    game.MyTerminal.ShowMonsterPhase(game , game.MonsterDeck.back());
    auto  herosNear = CurrentLocation->GetHero();
    auto  VillagersNear = CurrentLocation->GetVillager();
    if(herosNear.empty())
    {
        if(!VillagersNear.empty()){
            game.RemoveVillagerFromGame(VillagersNear.back());
            VillagersNear.back()->kill();
            CurrentLocation->RemoveVillager(VillagersNear.back());
            game.MyTerminal.ShowPopupMessages(game ,Name + " killed " + VillagersNear.back()->getName());
            game.MyTerminal.ShowMonsterPhase(game , game.MonsterDeck.back());
            successe = true;
            game.increaseTerrorLevel();
            return successe;
        }
        else
        {
            game.MyTerminal.ShowPopupMessages(game ,"No opponent nearby to attack");
            return successe;
        }
    }
    else
    {
       auto HeroToAttack = herosNear.back();
       successe = HeroToAttack->PlayerGetHit(game);
       return successe;
    }

}