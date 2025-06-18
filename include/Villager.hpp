#ifndef VILLAGER_HPP
#define VILLAGER_HPP
#include <string>
#include <memory>
class Location;
class Villager :public std :: enable_shared_from_this<Villager>
{

    private:
      std::string name;
      std :: shared_ptr<Location> currentLocation;
      std :: shared_ptr<Location> safeLocation;
      bool alive;

    public:
      Villager(const std::string& , std :: shared_ptr<Location> , std :: shared_ptr<Location>);
       Villager(const std :: string Name , std :: shared_ptr<Location> SafeLoc); 
      const std::string& getName() const;
      void SetLocation(std :: shared_ptr<Location>);
      const std :: shared_ptr<Location>& getCurrentLocation() const;
      const std :: shared_ptr<Location>& getSafeLocation() const;
      const std :: string & getCurrentLocationName() const;
      bool isAlive() const;

      void moveTo(std :: shared_ptr<Location>);
      void kill();
      void rescue();


};
#endif