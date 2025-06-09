#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <stdexcept>
enum class ItemColor { Red , Blue , Yellow};
class Item{
 private:
    ItemColor color;
    int power;
    std::string location;

 public:
    Item(ItemColor , int , const std::string&);
    ItemColor getColor() const;
    int getPower() const;
    const std::string& getLocation() const;
    void setLocation(const std::string&) ;
    bool operator==(Item item);




};
#endif