#ifndef PERK_HPP
#define PERK_HPP
#include "../include/Card.hpp"
class PerkCard : public Card{
    private:

    public :
    PerkCard(const std :: string & name): Card(name){};
    void ShowCard()const override;
    void ApplyEffect()override;
    private :
};
#endif