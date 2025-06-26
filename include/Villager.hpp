#ifndef VILLAGER_HPP
#define VILLAGER_HPP
#include <string>
#include <memory>
class Location;
enum class State{
    Alive ,
    Rescued,
    Killed
};
class Villager :public std :: enable_shared_from_this<Villager>
{

    private:
      std::string name;
      State state;
      std :: shared_ptr<Location> currentLocation;
      std :: shared_ptr<Location> safeLocation;
    public:
       Villager(const std :: string Name , std :: shared_ptr<Location> SafeLoc); 
      const std::string& getName() const;
      void SetLocation(std :: shared_ptr<Location>);
      const std :: shared_ptr<Location>& getCurrentLocation() const;
      const std :: shared_ptr<Location>& getSafeLocation() const;
      const std :: string  getCurrentLocationName() const;
      State isAlive() const;
      void moveTo(std :: shared_ptr<Location>);
      void kill();
      void rescue();


};
#endif