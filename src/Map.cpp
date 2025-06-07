#include "../include/Location.hpp"
#include "../include/Map.hpp"
#include "../include/Location.hpp"
#include <memory>
using namespace std;
Map ::Map(){}
void Map ::addLocation(const std::string &name, int x, int y)
{
    if (MapPlan.find(name) == MapPlan.end())
    {
        MapPlan[name] = std::make_unique<Location>(name, x, y);
    }
}
void Map ::addEdge(const std::string &from, const std::string &to)
{
    auto it1 = MapPlan.find(from);
    auto it2 = MapPlan.find(to);

    if (it1 != MapPlan.end() && it2 != MapPlan.end())
    {
        it1->second->AddNeighbor(it2->second.get());
        it2->second->AddNeighbor(it1->second.get());
    }
}

const std::unordered_map<std::string, std::unique_ptr<Location>>&  Map ::getLocations() const
{
    return MapPlan;
}
