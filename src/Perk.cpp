#include "../include/Perk.hpp"
#include "../include/Card.hpp"
#include <iostream>
#include <string>
using namespace std;
void PerkCard::ShowCard() const{
    cout << string(10 ,'=') <<"Card" <<string(10 , '=') <<'\n';
    cout << string(10 ,'=') << Name <<string(10 , '=') <<'\n'; 
}
void PerkCard ::ApplyEffect(){}