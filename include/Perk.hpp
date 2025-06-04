#ifndef PERK_HPP
#define PERK_HPP
#include "../include/Card.hpp"
class PerkCard : public Card{
    protected :

    public :
    PerkCard(const std :: string&name , const std :: string info);
    void Apply()override;
    private :
};
#endif