#include "./include/Item.hpp"

 Item::Item(ItemColor color, int power, const std::string& location) : 
 color(color) {
    if(power<=0 || power>10){
        throw std::invalid_argument("Power must be between 1 and 10");
    }
    if(location.empty()){
        throw std::invalid_argument("Location can't be empty");
    }
    this->power = power;
    this->location = location ;
 }

ItemColor Item::getColor() const{
    return color;

}
int Item::getPower() const{
    return power;
}
const std::string& Item::getLocation() const{
    return location;

    }
void Item::setLocation(const std::string& newLoc){
    if(newLoc.empty()){
        throw std::invalid_argument("New location can't be empty");
    }
    location = newLoc ;

}
