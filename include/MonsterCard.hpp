#ifndef MONSTERCARD_HPP
#define MONSTERCARD_HPP
#include <string>
#include "../include/Card.hpp"

struct MonsterStrike
{
    std :: string MonsterSymbol;
    int MoveNum;
    int DiceRoll;
    MonsterStrike() = default;
    MonsterStrike(std :: string s , int m , int d) : MonsterSymbol(s) , MoveNum(m) , DiceRoll(d){}
};


class MonsterCard : public Card{
    private :
    int Item;
    std :: string Event;
    MonsterStrike Strikes;
    public :
    int GetItem()const ;
    void ShowCard()const override;
    MonsterCard(const std :: string &name , int item , const std :: string & event , const MonsterStrike& strike);
    void ApplyEffect() override;
    // void ApplyItemEffect();
    // void ApplyEventEffect();
    // void ApplyStrikeEffect();

};

#endif