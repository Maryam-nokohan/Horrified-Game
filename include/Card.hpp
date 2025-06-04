#ifndef CARD_HPP
#define CARD_HPP
#include <string>
class Card{
    protected :
    std :: string Name;
    std :: string Info;
    
    private :
    public :
    Card(const std :: string & name , const std :: string info) : Name(name) , Info(info){}
    virtual ~Card();
    virtual void Apply()=0;

};
#endif