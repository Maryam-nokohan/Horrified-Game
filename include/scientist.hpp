#ifndef SCIENTIST_HPP
#define SCIENTIST_HPP
#include "../include/Hero.hpp"
#include <memory>
class  Game;
class Scientist : public Hero{

 public :
    Scientist() = default;
    Scientist(std::shared_ptr<Location>);
    void Ability();
    void specialAction(Game& game) override;
};
#endif