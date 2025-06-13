#ifndef CARD_HPP
#define CARD_HPP
#include <string>
class Card{
    protected :
    std :: string Name;
    public :
    Card() = default;
    Card(const std :: string & name );
    void SetName(const std :: string& );
    std :: string GetName();
    virtual ~Card() = default;
    virtual std :: string ShowCard() const = 0;

};
#endif