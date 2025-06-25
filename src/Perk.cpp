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
                int idx = game.MyTerminal.ShowHeroPhase(game ,cities);
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
                bool found = false;
                int times = 2;
                while(times--){
                if(game.Monsters[0]){
                    found = true;
                auto Dneighbor = game.Monsters[0]->GetLocation()->GetNeighbors();
                game.Monsters[0]->Move(Dneighbor[0]);}
                if(game.Monsters[1]){
                    found = true;
                auto Ineighbor = game.Monsters[1]->GetLocation()->GetNeighbors();
                game.Monsters[1]->Move(Ineighbor[1]);
                }
            }
            if(!found)
            {
                game.MyTerminal.StylizeTextBoard("No monster to use repel Card!");
                game.MyTerminal.ShowPause();
            }
           
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