#include "../include/Monster.hpp"
#include "../include/Villager.hpp"
#include "../include/Item.hpp"
#include "../include/Location.hpp"
#include "../include/Map.hpp"
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <queue>
#include <iostream>
#include <memory>
#include <string>

Monster ::Monster(const std :: string  name  , int frenzyOrder ,bool hasFrenzy ){
this->Name = name;
this->FrenzyOrder = frenzyOrder;
this->HasFrenzy = hasFrenzy;
}


std :: string Monster ::GetName () {return Name;}
int Monster :: GetFrenzyOrder()const{
    return FrenzyOrder;

}
bool Monster ::  GetFrenzyMarker()const{
return HasFrenzy;
}
void Monster ::  SetFrenzyMarker(bool hasMarker){
HasFrenzy = hasMarker;
}
const std::shared_ptr<Location>& Monster ::  GetLocation()const{
return CurrentLocation;
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

Location& Monster::FindNearestOpponent(Map& plan, std::shared_ptr<Location> monsterLocation, int monsterMoves) {
    std::unordered_map<Location*, int> distances;
    std::unordered_map<Location*, Location*> prev;
    std::queue<Location*> q;

    // BFS to calculate distances
    distances[monsterLocation.get()] = 0;
    q.push(monsterLocation.get());

    while (!q.empty()) {
        Location* curr = q.front();
        q.pop();
        for (auto& neighbor : curr->GetNeighbors()) {
            if (distances.find(neighbor.get()) == distances.end()) {
                distances[neighbor.get()] = distances[curr] + 1;
                prev[neighbor.get()] = curr;
                q.push(neighbor.get());
            }
        }
    }

    struct OpponentInfo {
        Location* loc;
        int dist;
        bool isHero;
    };

    std::vector<OpponentInfo> candidates;
    int minDist = std::numeric_limits<int>::max();

    for (const auto& [name, locPtr] : plan.getLocations()) {
        Location* loc = locPtr.get();
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

    if (candidates.empty()) return *monsterLocation;

    // Prefer hero if multiple at same minDist
    std::vector<OpponentInfo> best;
    for (const auto& c : candidates) {
        if (c.dist == minDist && c.isHero) best.push_back(c);
    }
    if (best.empty()) best = candidates;

    OpponentInfo chosen = best[rand() % best.size()];

    // Build path back to monster
    std::vector<Location*> path;
    Location* step = chosen.loc;
    while (step != monsterLocation.get()) {
        path.push_back(step);
        step = prev[step];
    }
    std::reverse(path.begin(), path.end());

    if (path.size() <= static_cast<size_t>(monsterMoves)) {
        return *chosen.loc;
    } else {
        return *path[monsterMoves - 1];
    }
}

