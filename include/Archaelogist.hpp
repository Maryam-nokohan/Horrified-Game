#ifndef ARCHAEOLOGIST_HPP
#define ARCHAEOLOGIST_HPP
#include "../include/Hero.hpp"
#include <memory>
class Game;
class Archaeologist : public Hero {
public:
    Archaeologist() = default;
    Archaeologist(std :: shared_ptr<Location>);
    void specialAction(Game&) override;
};

#endif