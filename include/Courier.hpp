#ifndef COURIER_HPP
#define COURIER_HPP
#include "../include/Hero.hpp"
#include <memory>
class Game;
class Courier : public Hero
{
public:
    Courier() = default;
    Courier(std::shared_ptr<Location>);
    void specialAction(Game &);
};

#endif