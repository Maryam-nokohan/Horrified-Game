#ifndef MONSTER_HPP
#define MONSTER_HPP
#include <string> 
class Monster{
    protected:
    std :: string Name;
     
    private :

    public :
    Monster(std :: string & name) : Name(name){}
    virtual void Power()=0;
    virtual void Move() = 0;
    virtual void Attack() = 0;    

};


#endif