#ifndef MAP_HPP
#define MAP_HPP
#include <unordered_map>
#include <string>
#include <list>
#include "../include/Location.hpp"
#include <memory>
#include "Location.hpp"
#include <unordered_map>
#include <memory>
#include <vector>

class Map
{
private:
    std::unordered_map<std::string, std::unique_ptr<Location>> MapPlan;

public:
    Map();
    void addLocation(const std::string &name, int x, int y);
    void addEdge(const std::string &from, const std::string &to);
    const std::unordered_map<std::string, std::unique_ptr<Location>>& getLocations() const;
};
#endif