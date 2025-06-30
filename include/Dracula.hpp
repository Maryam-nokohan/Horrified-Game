#ifndef DRACULA_HPP
#define DRACULA_HPP
#include "../include/Monster.hpp"
#include "../include/Hero.hpp"
#include "../include/Map.hpp"
#include <vector> 
#include <memory>
class Game;
class Dracula : public Monster{
    private :
    std :: vector<std:: pair<bool , std :: string>>Table;

    public :
    Dracula();
    void Move(std :: shared_ptr<Location>) override;
    void DarkCharm(Game & game);
    bool IsCoffinDestroyed(std :: string LocationName);
    void AddDetroyedCoffin(std :: string LocaitonName);
    bool CanBeDefeated() override;
    bool IsTasksLocation(std :: string);
    std :: vector<bool> GetCoffinsDestroyed();    
    std :: vector<std:: pair<bool , std :: string>> GetCoffins() const;
};
#endif