#include "../include/Mayor.hpp"
#include <iostream>

Mayor::Mayor(std :: shared_ptr<Location> startLocation)
    : Hero("Mayor", 5, startLocation) {}

std::string Mayor::specialAction() {
    return "Mayor has no special ability.\n";
}