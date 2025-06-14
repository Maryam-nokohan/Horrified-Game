#ifndef LOCATION_NAMES_HPP
#define LOCATION_NAMES_HPP

#include <string>

namespace LocationNames {
    inline const std::string Docks       = "Docks";
    inline const std::string Camp        = "Camp";
    inline const std::string Inn         = "Inn";
    inline const std::string Mansion     = "Mansion";
    inline const std::string Abbey       = "Abbey";
    inline const std::string Museum      = "Museum";
    inline const std::string Shop        = "Shop";
    inline const std::string Institute   = "Institute";
    inline const std::string Laboratory  = "Laboratory";
    inline const std::string Precinct    = "Precinct";
    inline const std::string Theater     = "Theater";  
    inline const std::string Graveyard   = "Graveyard";
    inline const std::string Church      = "Church";
    inline const std::string Hospital    = "Hospital";
    inline const std::string Barn        = "Barn";
    inline const std::string Dungeon     = "Dungeon";
    inline const std::string Crypt       = "Crypt";
    inline const std::string Cave        = "Cave";
    inline const std::string Tower       = "Tower";

    inline bool Exists(const std::string& loc) {
        return loc == Docks || loc == Camp || loc == Inn || loc == Mansion || loc == Abbey ||
               loc == Museum || loc == Shop || loc == Institute || loc == Laboratory ||
               loc == Precinct || loc == Theater || loc == Graveyard || loc == Church ||
               loc == Hospital || loc == Barn || loc == Dungeon || loc == Crypt || 
               loc == Cave || loc == Tower;
    }
}

#endif