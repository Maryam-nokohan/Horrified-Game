#ifndef MONSTERCARD_HPP
#define MONSTERCARD_HPP
#include <string>
#include "../include/Card.hpp"
#include <memory>
class Game;
class Monster;
struct MonsterStrike
{
    std :: string MonsterSymbol;
    int MoveNum;
    int DiceRolls;
    MonsterStrike() = default;
    MonsterStrike(std :: string s , int m , int d) : MonsterSymbol(s) , MoveNum(m) , DiceRolls(d){}

};


class MonsterCard : public Card{
    private :
    bool EndStrike;
    int item;
    std :: string Event;
    MonsterStrike Strikes;
    public :
    int GetItem()const ;
    std :: string GetOrderSymbold();
    int GetMove();
    int GetDiceRoll();
    std :: string GetEvent();
    MonsterCard(const std :: string &name , int item , const std :: string & event , const MonsterStrike& strike);
    void ApplyEffect(Game &) override;
    void ApplyMonsterStrike(Game & game , std ::shared_ptr<Monster> monsterName);
};

#endif