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
#include <limits>
using namespace LocationNames;
using namespace Names;

//Constructor
MonsterCard :: MonsterCard(const std :: string &name , int item , const std :: string & event , const MonsterStrike& strike) : Card (name) , EndStrike(false){
    if(item >= 0)
    this->item = item;
    else 
    throw std::invalid_argument("Monster card item count must be posetive");
    this->Event = event;
    this->Strikes = strike;
}
//Get functions 
int :: MonsterCard ::GetItem ()const {return item;}
std :: string MonsterCard ::GetOrderSymbold(){return Strikes.MonsterSymbol;}
int MonsterCard ::GetMove() {return Strikes.MoveNum;}
int MonsterCard ::GetDiceRoll() {return Strikes.DiceRolls;}
std :: string MonsterCard::GetEvent(){return Event;}
//Effect 
void MonsterCard ::ApplyEffect(Game & game)
{
    //Put items : 
    game.SetRandomItems(item);
    game.MyTerminal.AddLogMessage("Added " + std :: to_string(item) + " items to map");
    
    //apply event
    auto dracula = game.GetDracula();
    auto invisible = game.GetInvisibleMan();

    if (Name == Sunrise)
    {
        if(dracula){
        dracula->SetLocation(game.mapPlan.GetLocationptr(Crypt));
        game.MyTerminal.AddLogMessage(Sunrise + " Card Event Applyed  :"  + Event);
        
        }
        else {
            game.MyTerminal.AddLogMessage("dracula isn't in the game to apply Sunrise card effect!");
            
            return;}
    }

    else if (Name == FromTheBat)
    {
        if(dracula){
        dracula->GetLocation()->RemoveMonster(dracula);
        dracula->SetLocation(game.heroPlayer->getLocation());
        game.MyTerminal.AddLogMessage(FromTheBat+ " Card Event Applyed  :"  + Event);
        
        }
        else {
            game.MyTerminal.AddLogMessage("dracula isn't in the game to apply "+ FromTheBat+" card effect!");
            
            }
    }

    else if (Name == Thief)
    {
        if(invisible){
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
            game.MyTerminal.AddLogMessage(Thief + " Card Event Applyed  :"  + Event);
            
        }
        else 
        {
            game.MyTerminal.AddLogMessage("No items in game to apply " + Thief + " effect!");
        
        }
    }
    else 
    {
        game.MyTerminal.AddLogMessage("Invisible man is not in the game to apply " + Thief + " effect!");
        

    }
    }

    else if (Name == TheDelivery)
    {

        auto docks = game.mapPlan.GetLocationptr(Docks);
        bool found = false;
        for (auto &v : game.villagers){
            if (v->getName() == WilburAndChick){
                found = true;
                v->SetLocation(docks);
            }
        }
        if(found)
        {
            game.MyTerminal.AddLogMessage(TheDelivery + " Card Event Applyed  :"  + Event);
            
        }
        else
        {
            game.MyTerminal.AddLogMessage("Not found " + WilburAndChick + " to apply " + TheDelivery);
            
            return;
        }
    }

    else if (Name == FortuneTeller)
    {
        bool found = false;
        auto camp = game.mapPlan.GetLocationptr(Camp);
         for (auto &v : game.villagers){
            if (v->getName() == Maleva){
                found = true;
                v->SetLocation(camp);
            }
        }
        if(found)
        {
            game.MyTerminal.AddLogMessage(FortuneTeller + " Card Event Applyed  :"  + Event);
            
        }
        else
        {
            game.MyTerminal.AddLogMessage("Not found " +Maleva + " to apply " + FortuneTeller);
            
            return;
        }
    }

    else if (Name == FormerEmployer)
    {
        bool found = false;
        auto lab = game.mapPlan.GetLocationptr(Laboratory);
         for (auto &v : game.villagers){
            if (v->getName() == DrCranley){
                found = true;
                v->SetLocation(lab);
            }
        }
        if(found)
        {
            game.MyTerminal.AddLogMessage(FormerEmployer + " Card Event Applyed  :"  + Event);
            
        }
        else
        {
            game.MyTerminal.AddLogMessage("Not found " + DrCranley + " to apply " + FormerEmployer);
            
            return;
        }
    }

    else if (Name == HurriedAssistant)
    {
        bool found = false;
        auto tower = game.mapPlan.GetLocationptr(Tower);
        for (auto &v : game.villagers){
            if (v->getName() == Fritz){
                found = true;
                v->SetLocation(tower);
            }
        }
        if(found)
        {
            game.MyTerminal.AddLogMessage(HurriedAssistant + " Card Event Applyed  :"  + Event);
        
        }
        else
        {
            game.MyTerminal.AddLogMessage("Not found " + Fritz + " to apply " + HurriedAssistant);
            
            return;
        }
    }

    else if (Name == TheInnocent)
    {
        bool found = false;
        auto barn = game.mapPlan.GetLocationptr(Barn);
        for (auto &v : game.villagers){
            if (v->getName() == Maria){
                found = true;
                v->SetLocation(barn);
            }
        }
        if(found)
        {
            game.MyTerminal.AddLogMessage(TheInnocent + " Card Event Applyed  :"  + Event);
        }
        else
        {
            game.MyTerminal.AddLogMessage("Not found " + Maria + " to apply " + TheInnocent);

            return;
        }
    }

    else if (Name == EgyptianExpert)
    {
        bool found = false;
        auto cave = game.mapPlan.GetLocationptr(Cave);
         for (auto &v : game.villagers){
            if (v->getName() == ProfPearson){
                found = true;
                v->SetLocation(cave);
            }
        }
        if(found)
        {
            game.MyTerminal.AddLogMessage(EgyptianExpert + " Card Event Applyed  :"  + Event);
        }
        else
        {
            game.MyTerminal.AddLogMessage("Not found " + ProfPearson + " to apply " + EgyptianExpert);
            return;
        };
    }

    else if (Name == TheIchthyologist)
    {
        bool found =false;
        auto inst = game.mapPlan.GetLocationptr(Institute);
         for (auto &v : game.villagers){
            if (v->getName() == DrReed){
                found = true;
                v->SetLocation(inst);
            }
        }
        if(found)
        {
            game.MyTerminal.AddLogMessage(TheIchthyologist + " Card Event Applyed  :"  + Event);
        }
        else
        {
            game.MyTerminal.AddLogMessage("Not found " + DrReed + " to apply " + TheIchthyologist);
            return;
        }
    }
   
    else if (Name == OnTheMove)
    {
        int frenzyIndex = 0;
        if(dracula)
        {
            if(dracula->GetFrenzyMarker())
            {
                if(invisible)
                {
                    dracula->SetFrenzyMarker(false);
                    invisible->SetFrenzyMarker(true);
                }
            }
        }
        else if(invisible)
        {
            if(invisible->GetFrenzyMarker())
            {
                if(dracula)
                {
                    invisible->SetFrenzyMarker(false);
                    dracula->SetFrenzyMarker(true);
                }
            }
        }
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
                game.MyTerminal.AddLogMessage("Villager " + v->getName() + " moves toward safe house: " + nextStep->GetCityName());
                 if (v->isAlive() == State ::Rescued)
                            {
                                game.RemoveVillagerFromGame(v);
                                game.MyTerminal.AddLogMessage("You rescued " + v->getName());
                                game.heroPlayer->GetPerkCard(game.PerkDeck.back());
                                game.heroPlayer->getLocation()->RemoveVillager(v);
                                game.PerkDeck.pop_back();
                            }
            }
        }
        game.MyTerminal.AddLogMessage(OnTheMove + " Card Event Applyed  :"  + Event);
    }

    else if (Name == HypnoticGaze)
    {
        if(dracula){
        auto monsterLoc = dracula->GetLocation(); 
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
                game.MyTerminal.AddLogMessage("Hero " + closestHero->getName() + " moves toward dracula.");
            }
            else if (closestVillager)
            {
                auto loc = closestVillager->getCurrentLocation();
                loc->RemoveVillager(closestVillager);
                closestVillager->SetLocation(nextStep);
                game.MyTerminal.AddLogMessage("Villager " + closestVillager->getName() + " moves toward dracula.");
            }
        }
           game.MyTerminal.AddLogMessage(HypnoticGaze + " Card Event Applyed  :"  + Event);
    }
    else
    {
    game.MyTerminal.AddLogMessage("dracula isn't in the game to apply "+ HypnoticGaze +" card effect!");
    
}

}

    //apply strikes : 
    game.MyTerminal.AddLogMessage("Applying Strikes ...");
    for (const auto ch : Strikes.MonsterSymbol)
    {
        if(EndStrike)
        return;
        if (ch == 'D' && dracula)
        {
            ApplyMonsterStrike(game , dracula);
        }
        else if (ch == 'I' && invisible)
        {
            ApplyMonsterStrike(game , invisible);
        }
        else if (ch == 'F')
        {
            if(dracula){
            if (dracula->GetFrenzyMarker())
            {
                ApplyMonsterStrike(game ,dracula);
                return;
            }
        }
            if(invisible){
            if(invisible->GetFrenzyMarker())
            {
                ApplyMonsterStrike(game , invisible);
            }
        }
        }
    }
}
void MonsterCard:: ApplyMonsterStrike(Game & game , std ::shared_ptr<Monster> monsterName)
{
    if (!monsterName) {
    throw std :: invalid_argument( "ERROR: monsterName is nullptr in ApplyMonsterStrike()\n");
}
    auto nearHeros = monsterName->GetLocation()->GetHero();
    auto nearVillagers = monsterName->GetLocation()->GetVillager();
    if (nearHeros.empty() && nearVillagers.empty() )
    {
        auto nearestOp = monsterName->FindNearestOpponent(game.mapPlan , monsterName->GetLocation(),Strikes.MoveNum);
        monsterName->Move(nearestOp);
        game.MyTerminal.AddLogMessage(monsterName->GetName() + " moved toward the nearest opponent at " + nearestOp->GetCityName());

    }
    else
    {
        game.MyTerminal.AddLogMessage(monsterName->GetName() + " already in the opponent location");
    }
    int InvisibleManPowerDices = 0;
    for (int i = 0; i < Strikes.DiceRolls; ++i)
    {
        // Faces
        std::vector<std::string> faces = game.MyTerminal.ShowDiceRollAnimation(game.GameDice, game.MyTerminal.GetFont());
        for(const auto & face : faces){
        if (face == "*")
        {
            if(monsterName->Attack(game))
            {
                EndStrike = true;
                return;
            }     
        }
        else if (face == "!")
        {
            std ::string name = monsterName->GetName();
            if (name == "Dracula")
            {
                auto dracula = game.GetDracula();
                dracula->DarkCharm(game);
            }
            else
            {
                InvisibleManPowerDices++;
             
            }
        }
        else if (face == " ")
        {
            
        }
      
    }
}
  if(InvisibleManPowerDices)
        {
            auto Invisible = game.GetInvisibleMan();
            for(int k = 0 ; k < InvisibleManPowerDices ;++k)
            {
                Invisible->StalkUnseen(game , 2);
            
            }
            
        }

}


