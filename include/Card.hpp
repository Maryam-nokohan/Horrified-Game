#ifndef CARD_HPP
#define CARD_HPP
#include <string>
class Game;
class Card{
    protected :
    std :: string Name;
    public :
    Card() = default;
    Card(const std :: string & name );
    virtual void ApplyEffect(Game & )=0;
    void SetName(const std :: string& );
    std :: string GetName();
    virtual ~Card() = default;
};
#endif