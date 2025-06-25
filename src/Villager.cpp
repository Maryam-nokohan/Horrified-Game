#include "../include/Villager.hpp"
#include "../include/Location.hpp"
#include <stdexcept>

Villager :: Villager(const std :: string Name , std :: shared_ptr<Location> SafeLoc): currentLocation(nullptr) , alive(true)
{
    name = Name;
    safeLocation = SafeLoc;
}
const std::string  Villager ::getCurrentLocationName()const {return currentLocation->GetCityName(); }

const std::string& Villager::getName() const{
    return name;
}
const std :: shared_ptr<Location>& Villager::getCurrentLocation() const{
    return currentLocation;
}
const std :: shared_ptr<Location>& Villager ::getSafeLocation() const{
    return safeLocation;
}
bool Villager::isAlive() const{
    return alive;
}
void Villager::moveTo(std :: shared_ptr<Location> newLocation){

   SetLocation(newLocation);
}
void Villager::kill(){
    alive = false;
    currentLocation = nullptr ;
}
void Villager::rescue(){
    if(currentLocation->GetCityName() == safeLocation->GetCityName()){
    alive = false;
    currentLocation = nullptr ;
}
else 
return;

}
void Villager:: SetLocation(std :: shared_ptr <Location> location){
    
    if (currentLocation) {
        currentLocation->RemoveVillager(shared_from_this());
    }

    currentLocation = location;

    if (currentLocation) {
        currentLocation->AddVillager(shared_from_this());
        rescue();
    }
    else 
    currentLocation = nullptr;

}