#include "../include/Perk.hpp"
#include "../include/Game.hpp"
#include "../include/Card.hpp"
#include "../include/Hero.hpp"
#include "../include/Names.hpp"
#include <iostream>
#include <string>
using namespace Names;
using namespace std;
std :: string PerkCard ::GetName(){return Name;}
void PerkCard ::ApplyEffect(Game & game)
{
    std::string name = GetName();
            game.MyTerminal.StylizeTextBoard("You used perk: "+ name );
            game.MyTerminal.ShowPause();
            if (name == VisitFromDetective) {
                std::vector<std::string> cities;
                for (const auto& [name, loc] : game.mapPlan.getLocations())
                    cities.push_back(name);
                game.MyTerminal.StylizeTextBoard("Choose a City to put invisible man:");
                int idx = game.MyTerminal.Show(game ,cities);
                game.Monsters[1]->SetLocation(game.mapPlan.GetLocationptr(cities[idx]));
            }
            else if (name == BreakOfDown) {
                game.skipMonsterPhase = true;
                game.SetRandomItems(2);
                
            }
            else if (name == OverStock) {
                game.SetRandomItems(2);
      
                }
            else if (name == LateIntoTheNight) {
                game.heroPlayer->SetAction(2+ game.heroPlayer->getRemainingActions());
            }
            else if (name == Repel) {
                int times = 2;
                while(times--){
                for(auto & m : game.Monsters)
                {
                    auto neighbor = m->GetLocation()->GetNeighbors();
                    m->Move(neighbor[0]);
                }}
               /*  std::vector<std::string> names;
                for (auto& m : game.Monsters) names.push_back(m->GetName());
                int idx = game.MyTerminal.Show(*this ,names);
                auto monster = Monsters[idx];
                auto neighbors = monster->GetLocation()->GetNeighbors();
                std::vector<std::string> opts;
                for (auto& loc : neighbors) opts.push_back(loc->GetCityName());
                int dest = game.MyTerminal.Show(*this ,opts);
                monster->SetLocation(mapPlan.GetLocationptr(opts[dest])); */
            }
            else if (name == Hurry) {
                   int times = 2;
                while(times--){
                for(auto & h: game.heroes)
                {
                    auto neighbor = h->getLocation()->GetNeighbors();
                    h->moveTo(neighbor[0]);
                }}
               
            }
        }