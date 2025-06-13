#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "../include/Item.hpp"
#include <string> 
#include <memory>
#include <vector>
class Map;
class Location;
class Monster : public std :: enable_shared_from_this<Monster>
{
    protected:
    std :: string Name;
    std :: shared_ptr<Location> CurrentLocation;
    int FrenzyOrder;
    bool HasFrenzy;
    public :
    Monster(const std :: string  name, int frenzyOrder ,bool hasFrenzy );

    virtual void Move(std :: shared_ptr<Location>)=0;
    virtual void Attack() =0;
      
    Location& FindNearestOpponent(Map& ,std :: shared_ptr<Location>, int );
    std :: string GetName();
    int GetFrenzyOrder()const;
    bool GetFrenzyMarker()const;
    void SetFrenzyMarker(bool hasMarker);
    const std :: shared_ptr<Location>& GetLocation()const;
    void SetLocation(std :: shared_ptr<Location>);

    ~Monster(){}

};


#endif