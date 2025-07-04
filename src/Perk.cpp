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
    auto dracula = game.GetDracula();
    auto invisible = game.GetInvisibleMan();
    std::string name = GetName();
            game.MyTerminal.StylizeTextBoard("You used perk: "+ name );
            if (name == VisitFromDetective) {
                if(invisible){
                std::vector<std::string> cities;
                for (const auto& [name, loc] : game.mapPlan.getLocations())
                    cities.push_back(name);
                game.MyTerminal.StylizeTextBoard("Choose a City to put invisible man:");
                int idx = game.MyTerminal.MenuGenerator(cities);
                invisible->SetLocation(game.mapPlan.GetLocationptr(cities[idx]));
                }
                else 
                {
                    game.MyTerminal.StylizeTextBoard("Invisible Man isn't in the Game to apply " + VisitFromDetective+" !");
                }
            }
            else if (name == BreakOfDown) {
                game.skipMonsterPhase = true;
                game.SetRandomItems(2);
                game.MyTerminal.StylizeTextBoard("Next Monster phase is skipped and two items added to the Map");
                
            }
            else if (name == OverStock) {
                game.SetRandomItems(2);
                game.MyTerminal.StylizeTextBoard("Added two item to the map!");

                }
            else if (name == LateIntoTheNight) {
                game.heroPlayer->SetAction(2+ game.heroPlayer->getRemainingActions());
                game.MyTerminal.StylizeTextBoard("Added two action to Hero actions!");
            }
        
            else if (name == Repel) {
                bool found = false;
                int times = 2;
                while(times--){
                if(dracula){
                    found = true;
                auto Dneighbor = dracula->GetLocation()->GetNeighbors();
                dracula->Move(Dneighbor[0]);}
                if(invisible){
                    found = true;
                auto Ineighbor = invisible->GetLocation()->GetNeighbors();
                invisible->Move(Ineighbor[1]);
                }
            }
            if(!found)
            {
                game.MyTerminal.StylizeTextBoard("No monster to use repel Card!");
                game.MyTerminal.ShowPause();
            }
            else {
                game.MyTerminal.StylizeTextBoard("Moved Monsters two step farther");
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
            game.MyTerminal.ShowPause();
        }