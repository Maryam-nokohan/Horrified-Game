#ifndef MAYOR_HPP
#define MAYOR_HPP
#include "../include/Hero.hpp"
#include <memory>

class Mayor : public Hero {
public:
    Mayor(std :: shared_ptr<Location>);
    void specialAction() override;
};

#endif