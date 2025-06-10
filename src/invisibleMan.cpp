#include "../include/invisible.hpp"
#include "../include/Monster.hpp"
#include <iostream>
InvisibleMan:: InvisibleMan() : Monster("Invisible Man"){Evidences ={false , false , false , false};}
void InvisibleMan:: Power() {
std :: cout << "InvisibleMan using stalk Unseen !!\n";
}
void InvisibleMan:: Move() {
    std :: cout << "Invisible Man Moves toward nearest hero or villager!!\n";

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