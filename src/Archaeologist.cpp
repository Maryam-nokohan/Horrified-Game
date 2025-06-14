#include "../include/Archaelogist.hpp"
#include "../include/Location.hpp"
#include "../include/Item.hpp"

Archaeologist::Archaeologist(std::shared_ptr<Location> startLocation)
    : Hero("Archaeologist", 4, startLocation) {}

void Archaeologist::specialAction() {
    if(remainingActions <= 0) return;

    std::vector<std :: shared_ptr<Location>> neighbors = currentLocation->GetNeighbors();
    for(std :: shared_ptr<Location> neighbor : neighbors){
        std::vector<std :: shared_ptr<Item>>& itemsThere = neighbor->GetItems();
        for(auto item : itemsThere){
            inventory.push_back(item);
        }
        itemsThere.clear();
    }
    remainingActions--;
}