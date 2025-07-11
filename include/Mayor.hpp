#ifndef MAYOR_HPP
#define MAYOR_HPP
#include "../include/Hero.hpp"
#include <memory>
class Game;
class Mayor : public Hero {
public:
    Mayor() = default;
    Mayor(std :: shared_ptr<Location>);
    void specialAction(Game&) override;
};

#endif