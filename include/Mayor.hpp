#ifndef MAYOR_HPP
#define MAYOR_HPP
#include "../include/Hero.hpp"
#include <memory>
#include <string>

class Mayor : public Hero {
public:
    Mayor(std :: shared_ptr<Location>);
    std::string specialAction() override;
};

#endif