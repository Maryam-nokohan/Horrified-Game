#include "../include/Villager.hpp"
#include "../include/Location.hpp"

Villager :: Villager(const std :: string Name , std :: shared_ptr<Location> SafeLoc)
{
    name = Name;
    safeLocation = SafeLoc;

}
Villager::Villager(const std::string& name, std :: shared_ptr<Location> startLocation, std :: shared_ptr<Location> safeLocation) : 
name(name) , currentLocation(std :: move (startLocation)) , safeLocation(std :: move (safeLocation)), alive(true){}

const std::string & Villager ::getCurrentLocationName()const {return currentLocation->GetCityName(); }

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
    currentLocation =std :: move (newLocation) ;
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
      if (currentLocation && currentLocation->GetCityName() == location->GetCityName()) {
        return;
    }

    if (currentLocation != nullptr) {
        currentLocation->RemoveVillager(shared_from_this());
    }

    currentLocation = location;

    if (currentLocation != nullptr) {
        currentLocation->AddVillager(shared_from_this());
    }
    rescue();

}