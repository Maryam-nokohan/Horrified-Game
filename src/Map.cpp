#include "../include/Location.hpp"
#include "../include/Map.hpp"
#include <stdexcept>
#include <iostream>
#include <memory>
#include <random>
using namespace std;
Map ::Map(){}
void Map ::addLocation(const std::string &name, int x, int y)
{
    if (MapPlan.find(name) == MapPlan.end())
    {
        MapPlan[name] = std::make_shared<Location>(name, x, y);
    }
}
void Map ::addEdge(const std::string &from, const std::string &to)
{
    auto it1 = MapPlan.find(from);
    auto it2 = MapPlan.find(to);

    if (it1 != MapPlan.end() && it2 != MapPlan.end())
    {
        it1->second->AddNeighbor(it2->second);
        it2->second->AddNeighbor(it1->second);
    }
}

const std::unordered_map<std::string, std::shared_ptr<Location>>&  Map ::getLocations() const
{
    return MapPlan;
}


std :: string Map :: GetRandomLocation()const{
    if(MapPlan.empty()) throw std :: runtime_error("Map is empty \n");
    std :: vector <std :: string > keys;
    for(const auto & pair : MapPlan)
    {
        keys.push_back(pair.first);
    }
    std :: random_device rd;
    std :: mt19937 gen ( rd());
    std :: uniform_int_distribution<>dist(0 , keys.size()-1);
    return keys[dist(gen)];

}
  const std :: shared_ptr <Location>& Map :: GetLocationptr(const std :: string & name)const {
    auto it = MapPlan.find(name);
    if(it != MapPlan.end())
    return it->second;
    else
     throw std::out_of_range("Location not found!");
}
Location & Map :: GetLocation(const std :: string & name){
    return *MapPlan.at(name);

}