#include "../include/Dracula.hpp"
#include "../include/Monster.hpp"
#include <stdexcept>
#include <iostream>
//Constructor :
Dracula :: Dracula() : Monster("Dracula",1,true){Coffins ={false , false , false , false};}
//Power:
void Dracula :: DarkCharm(std :: shared_ptr<Hero> CurrentHero) {
std :: cout << "Dracula using Dark Charm !!\n";
if(CurrentHero->getLocation()->GetCityName() == CurrentLocation->GetCityName())
{
    std :: cout << "Hero Already in Dracula's Location.\n";
}
auto HeroLocation = CurrentHero->getLocation();
HeroLocation->RemoveHero(CurrentHero);
CurrentLocation->AddHero(CurrentHero);
}
//Move :
void Dracula :: Move(std :: shared_ptr<Location> NearestOppenent) {
    std :: cout << "Dracula Moves toward nearest hero or villager!!\n";
    if(!CurrentLocation) return;
    CurrentLocation->RemoveMonster(shared_from_this());
    CurrentLocation = NearestOppenent;
    CurrentLocation->AddMonster(shared_from_this());   
}
//Attack :

void Dracula :: Attack() {
    std :: cout << "Dracula Attacks!!\n";
}
bool Dracula :: IsCoffinDestroyed(const int &index)const{
    if(index < 0 || index >=4 ) return false;
    return Coffins[index];
    
}
void Dracula :: DestroyCoffin(const int &index){
    if(index >= 0 && index <4 )
    Coffins[index] = true;


}
bool Dracula :: AllCoffinDestroyed()const{
    for(const auto & conffin : Coffins)
    {
        if(!conffin)
        return false;
    }
    return true;

}
void Dracula:: ShowDraculaMat(){
    std :: cout << "Dracula Mat : ";
    for(const auto & coff : Coffins)
    {
        if(coff)
        std :: cout << "* " ;
        else 
        std :: cout << "-";
    }
}
