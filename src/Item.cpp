#include "../include/Item.hpp"
#include "../include/Location.hpp"
 Item::Item(ItemColor color, int power, std :: shared_ptr<Location>loc , const std::string& name) : 
 color(color) , name(name) {
    if(power<=0 || power>10){
        throw std::invalid_argument("Power must be between 1 and 10");
    }
    this->power = power;
     location=loc;
 }

ItemColor Item::getColor() const{
    return color;

}
int Item::getPower() const{
    return power;
}
const std::shared_ptr<Location>& Item::getLocation() const{
    return location;

    }
const std::string& Item::getName() const{
    return name;
}
void Item::setLocation(const std::shared_ptr<Location>& newLoc){
    location = newLoc;
    location->AddItem(shared_from_this());
}
    bool Item :: operator==(Item item){
        if(item.getColor() == color && item.getLocation() == location  && power == item.getPower())
        return true;
        else
        return false;
    }