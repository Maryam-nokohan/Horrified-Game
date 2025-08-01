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
    // test
private:
    std::unordered_map<std::string, std::shared_ptr<Location>> MapPlan;

public:
    Map();
    void addLocation(const std::string &name, int x, int y);
    void addEdge(const std::string &from, const std::string &to);
    const std::unordered_map<std::string, std::shared_ptr<Location>>& getLocations() const;
    std :: string GetRandomLocation()const;
    const std :: shared_ptr<Location>&  GetLocationptr(const std :: string )const ;
    Location & GetLocation(const std :: string &);
    void Clear();
};
#endif
