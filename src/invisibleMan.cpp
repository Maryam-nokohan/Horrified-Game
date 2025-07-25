#include "../include/invisible.hpp"
#include "../include/Monster.hpp"
#include "../include/Location.hpp"
#include "../include/Hero.hpp"
#include "../include/Game.hpp"
#include "../include/LocationNames.hpp"
#include <algorithm>
#include <queue>
#include <iostream>
#include <limits>
using namespace LocationNames;
InvisibleMan:: InvisibleMan() : Monster("Invisible Man",6,false){Evidences ={ {false , Inn} , {false , Laboratory} , {false ,Barn } , {false ,Mansion } , {false , Institute}};}
//Move method
void InvisibleMan :: Move(std :: shared_ptr<Location> NearestOppenent) {
    if(!CurrentLocation) return;
    CurrentLocation->RemoveMonster(shared_from_this());
    CurrentLocation = NearestOppenent;
    CurrentLocation->AddMonster(shared_from_this());
}
//Check if the location has evidence
bool InvisibleMan::IsTasksLocation(std :: string LocationName)
{
    for(const auto & loc : Evidences)
    {
        if(loc.second == LocationName)
        return true;
    }
return false;
}
//Power
void InvisibleMan::StalkUnseen(Game& game, int moves) {
    game.MyTerminal.ShowMessageBox("Stalk Unseen Activated : ");
    auto& villagers = game.getVillagers();
    auto& map = game.getMapPlan(); 
    if(villagers.empty())
    {
        game.MyTerminal.ShowMessageBox("No villager in the map to use Stalk unseen!");
        return;
    }
    auto locals = CurrentLocation->GetVillager();
    if (!locals.empty()) {
        auto target = locals.back();
        game.MyTerminal.ShowMessageBox("Invisible Man is already in "+target->getCurrentLocation()->GetCityName()+ " uses Stalk Unseen and kills " + target->getName());
        target->kill();
        game.RemoveVillagerFromGame(target);
        return;
    }

    std::unordered_map<std::shared_ptr<Location>, int> dist;
    std::unordered_map<std::shared_ptr<Location>, std::shared_ptr<Location>> prev;
    std::queue<std::shared_ptr<Location>> q;

    dist[CurrentLocation] = 0;
    q.push(CurrentLocation);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (auto& neighbor : curr->GetNeighbors()) {
            if (dist.find(neighbor) == dist.end()) {
                dist[neighbor] = dist[curr] + 1;
                prev[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    std::shared_ptr<Location> targetLoc = nullptr;
    int minDist = std::numeric_limits<int>::max();

    for (auto& v : villagers) {
        auto loc = v->getCurrentLocation();
        if (dist.find(loc) != dist.end() && dist[loc] < minDist) {
            targetLoc = loc;
            minDist = dist[loc];
        }
    }

    if (!targetLoc) {
        game.MyTerminal.ShowMessageBox("No villager found for Stalk Unseen!");
        return;
    }

    std::vector<std::shared_ptr<Location>> path;
    auto step = targetLoc;
    while (step != CurrentLocation) {
        path.push_back(step);
        step = prev[step];
    }
    std::reverse(path.begin(), path.end());

    auto destination = path.size() <= (size_t)moves ? targetLoc : path[moves - 1];
    CurrentLocation->RemoveMonster(shared_from_this());
    CurrentLocation = destination;
    CurrentLocation->AddMonster(shared_from_this());

    auto afterMove = CurrentLocation->GetVillager();
    if (!afterMove.empty()) {
        auto target = afterMove.back();
        game.MyTerminal.ShowMessageBox("Invisible Man moved Toward " + target->getName());
        CurrentLocation->RemoveVillager(target);
    } else {
        game.MyTerminal.ShowMessageBox("Invisible Man moved to " + CurrentLocation->GetCityName());
    }
}
//Check if evidence already destroyed
 bool InvisibleMan:: IsEvidenceDestroyed(std :: string LocationName){
    for(auto & pair : Evidences)
    {
        if(pair.second == LocationName)
        {
                return pair.first;
        }
    }
    throw std :: invalid_argument("Evidence Not found in this Location!\n");

 }
void InvisibleMan :: AddDetroyedEvidence(std :: string LocaitonName){

    if(!IsEvidenceDestroyed(LocaitonName)){
    for(auto & Evidenc : Evidences)
    {
        if(Evidenc.second == LocaitonName)
        Evidenc.first = true;

    }
}

}
bool InvisibleMan ::CanBeDefeated()
{
    for(const auto & collected : Evidences)
    {
        if(!collected.first)
        return false;
    }
    return true;
}
std :: vector<bool> InvisibleMan::GetEvidences()
{
    std :: vector<bool> Evidenc;
    for(const auto & e : Evidences)
    {
        Evidenc.push_back(e.first);
    }
    return Evidenc;
}
std :: vector<std::pair<bool , std::string>> InvisibleMan :: GetEvidence() const{
    return Evidences;
}