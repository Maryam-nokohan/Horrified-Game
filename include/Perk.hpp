#ifndef PERK_HPP
#define PERK_HPP
#include "../include/Card.hpp"
class Game;
class PerkCard : public Card{

    public :
    PerkCard(const std :: string & name): Card(name){};
    std :: string GetName();
    void ApplyEffect(Game&) override;
    };
#endif