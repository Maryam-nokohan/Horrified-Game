#include "../include/invisible.hpp"
#include "../include/Monster.hpp"
#include "../include/Location.hpp"
#include <iostream>
InvisibleMan:: InvisibleMan() : Monster("Invisible Man",6,false){Evidences ={false , false , false , false};}

void InvisibleMan :: Move(std :: shared_ptr<Location> NearestOppenent) {
    std :: cout << "Invisible Man Moves toward nearest hero or villager!!\n";
    if(!CurrentLocation) return;
    CurrentLocation->RemoveMonster(shared_from_this());
    CurrentLocation = NearestOppenent;
    CurrentLocation->AddMonster(shared_from_this());
}
void InvisibleMan:: Attack() {
    std :: cout << "Invisible Man Attacks!!\n";
}
bool InvisibleMan:: IsEvidenceCollected(const int &index)const{
    if(index < 0 || index >=4 ) return false;
    return Evidences[index];
    
}
void InvisibleMan:: DestroyEvidence(const int &index){
    if(index >= 0 && index <4 )
    Evidences[index] = true;


}
bool InvisibleMan:: AllEvidenceCollected()const{
    for(const auto & evidence : Evidences)
    {
        if(!evidence)
        return false;
    }
    return true;

}