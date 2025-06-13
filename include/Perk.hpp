#ifndef PERK_HPP
#define PERK_HPP
#include "../include/Card.hpp"
class PerkCard : public Card{
    private:

    public :
    PerkCard(const std :: string & name): Card(name){};
    std :: string ShowCard()const override;
    private :
};
#endif