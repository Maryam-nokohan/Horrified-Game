#include "../include/Villager.hpp"
#include "../include/Location.hpp"
#include <stdexcept>

Villager :: Villager(const std :: string Name , std :: shared_ptr<Location> SafeLoc): currentLocation(nullptr) , state(State::Alive)
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
State Villager::isAlive() const{
    return state;
}
void Villager::moveTo(std :: shared_ptr<Location> newLocation){

   SetLocation(newLocation);
}
void Villager::kill(){
    state = State::Killed;
    currentLocation->RemoveVillager(shared_from_this());
}
void Villager::rescue(){
   if(currentLocation)
   {
    if(currentLocation -> GetCityName() == safeLocation->GetCityName())
    {
        state = State::Rescued;
        currentLocation->RemoveVillager(shared_from_this());
    }
   }
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
     throw std::invalid_argument("null ptr for villager location!");
}