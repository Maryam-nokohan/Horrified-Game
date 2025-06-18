#ifndef ARCHAEOLOGIST_HPP
#define ARCHAEOLOGIST_HPP
#include "../include/Hero.hpp"
#include <memory>

class Archaeologist : public Hero {
public:
    Archaeologist(std :: shared_ptr<Location>);
    void specialAction() override;
};

#endif