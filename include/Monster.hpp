#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "../include/Item.hpp"
#include <string> 
#include <memory>
#include <vector>

class Monster{
    protected:
    std :: string Name;
    // int FrenzyOrder;
    // bool HasFrenzy;
    public :
    Monster(const std :: string  name) : Name(name){}

    virtual void Power()=0;
    virtual void Move() = 0;
    virtual void Attack() = 0;    
    std :: string GetName();

};


#endif