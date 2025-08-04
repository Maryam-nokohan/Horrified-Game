#include "../include/Item.hpp"
#include "../include/Location.hpp"
 Item::Item(ItemColor color, int power, std :: shared_ptr<Location>loc , const std::string& name) : 
 color(color) , name(name) , CurrentLocation(nullptr){
    if(power<=0 || power>10){
        throw std::invalid_argument("Power must be between 1 and 10");
    }
    this->power = power;
     ItemLocation=loc;
 }
 Item::Item(ItemColor color, int power, std::shared_ptr<Location> itemLoc , std::shared_ptr<Location> CurrLoc , const std::string& name) :
 color(color) , name(name) , CurrentLocation(CurrLoc) , ItemLocation(itemLoc) , power(power){}


ItemColor Item::getColor() const{
    return color;

}
int Item::getPower() const{
    return power;
}
const std::shared_ptr<Location> Item::getLocation() const{
    if(CurrentLocation)
    return CurrentLocation;
    else
    return nullptr;
    }
const std::shared_ptr<Location>& Item::GetItemLocationName()const{return ItemLocation;}
const std::string& Item::getName() const{
    return name;
}
void Item::setLocation(const std::shared_ptr<Location>& newLoc){
    if(CurrentLocation != nullptr)
    {
        CurrentLocation->RemoveItem(shared_from_this());
    }
    CurrentLocation = newLoc;
    if(newLoc){
    CurrentLocation->AddItem(shared_from_this());
    }
    else
    {
        CurrentLocation = nullptr;
    }
}
    bool Item :: operator==(Item item){
        if(item.getColor() == color && item.GetItemLocationName() == ItemLocation  && power == item.getPower())
        return true;
        else
        return false;
    }