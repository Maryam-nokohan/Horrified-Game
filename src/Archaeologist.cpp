#include "../include/Archaelogist.hpp"
#include "../include/Location.hpp"
#include "../include/Item.hpp"
#include "../include/Game.hpp"
Archaeologist::Archaeologist(std::shared_ptr<Location> startLocation)
    : Hero("Archaeologist", 4, startLocation) {
    }

void Archaeologist::specialAction(Game& game) {
    std::vector<std :: shared_ptr<Location>> neighbors = currentLocation->GetNeighbors();
    for(auto loc : neighbors){
    std::vector<std :: shared_ptr<Item>> itemsThere = loc->GetItems();

        if(!itemsThere.empty()){
            std::string output;
        for(auto item : itemsThere){
            inventory.push_back(item);
            item->getLocation()->ClearItems();
            output+= " get " +  item->getName() + " form " + item->getLocation()->GetCityName() + "\n"; 
        }
        itemsThere.clear();
        DecreaseAction();
        game.MyTerminal.StylizeTextBoard(output);
    }
}
    game.MyTerminal.StylizeTextBoard("Not any item in the nearby locations!");
}