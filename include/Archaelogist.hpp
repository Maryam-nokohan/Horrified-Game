#ifndef ARCHAEOLOGIST_HPP
#define ARCHAEOLOGIST_HPP
#include "../include/Hero.hpp"
#include <memory>
#include <string>

class Archaeologist : public Hero {
public:
    Archaeologist(std :: shared_ptr<Location>);
    std::string specialAction() override;
};

#endif