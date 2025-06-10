#include "../include/MonsterCard.hpp"
#include "../include/Monster.hpp"
#include "../include/Card.hpp"
#include <iostream>
using namespace std;

MonsterCard :: MonsterCard(const std :: string &name , int item , const std :: string & event , const MonsterStrike& strike) : Card (name){
    this->Item = item;
    this->Event = event;
    this->Strikes = strike;
}
void :: MonsterCard :: ShowCard()const{
    
    cout << string(10 ,'=') <<"Card Info" <<string(10 , '=') <<'\n';
    cout << string(10 ,'=') << Name <<string(10 , '=') <<'\n';
    cout << "Item Number :" <<Item <<'\n';
    cout <<"Event :"<<Event <<'\n';
    cout <<"Strike : "<< "Symbol : " <<Strikes.MonsterSymbol <<'|' <<"Move : " << Strikes.MoveNum <<'|'<<"Dice : " <<Strikes.DiceRoll<<'\n';    
}
void :: MonsterCard :: ApplyEffect(){}
// void :: MonsterCard :: ApplyItemEffect();
// void :: MonsterCard :: ApplyEventEffect();
// void :: MonsterCard :: ApplyStrikeEffect();
int :: MonsterCard ::GetItem ()const {return Item;}