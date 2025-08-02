#include "../include/Archaelogist.hpp"
#include "../include/Location.hpp"
#include "../include/Item.hpp"
#include "../include/Game.hpp"
Archaeologist::Archaeologist(std::shared_ptr<Location> startLocation)
    : Hero("Archaeologist", 4, startLocation)
{
}

void Archaeologist::specialAction(Game &game)
{
    std::vector<std ::shared_ptr<Location>> neighbors = currentLocation->GetNeighbors();
    std::vector<std::string> neighborLocations;
    bool taskDone = false;
    for (auto loc : neighbors)
    {
        neighborLocations.push_back(loc->GetCityName());
    }
    game.MyTerminal.ShowMessageBox("choose a location nearby to get item from " + name);
    int select =game.MyTerminal.MenuGenerator(neighborLocations);
    auto loc = game.getMapPlan().GetLocationptr(neighborLocations[select]);

        std::vector<std ::shared_ptr<Item>> itemsThere = loc->GetItems();
        if (!itemsThere.empty())
        {
            std::string output;
            for (auto item : itemsThere)
            {
                inventory.push_back(item);
                output += " get " + item->getName() + " form " + item->getLocation()->GetCityName() + "\n";
            }
            loc->ClearItems();
            itemsThere.clear();
            game.MyTerminal.ShowMessageBox(output);
            taskDone = true;
        }
    
    if (taskDone)
        DecreaseAction();
    else
    game.MyTerminal.ShowMessageBox("Not any item in the nearby locations!");
}