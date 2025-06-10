#include "../include/Dracula.hpp"
#include "../include/Monster.hpp"
#include <stdexcept>
#include <iostream>
Dracula :: Dracula() : Monster("Dracula"){Coffins ={false , false , false , false};}
void Dracula :: Power() {
std :: cout << "Dracula using Dark Charm !!\n";
}
void Dracula :: Move() {
    std :: cout << "Dracula Moves toward nearest hero or villager!!\n";

}
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