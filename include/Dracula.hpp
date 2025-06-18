#ifndef DRACULA_HPP
#define DRACULA_HPP
#include "../include/Monster.hpp"
#include "../include/Hero.hpp"
#include "../include/Map.hpp"
#include <vector> 
#include <memory>
class Dracula : public Monster{
    private :
    std :: vector <bool> Coffins;

    public :
    Dracula();
    void Move(std :: shared_ptr<Location>) override;
    void Attack() override;
    void DarkCharm(std :: shared_ptr<Hero>);
    void ShowDraculaMat();
    bool IsCoffinDestroyed(const int &index)const;
    void DestroyCoffin(const int &index);
    bool AllCoffinDestroyed()const;
};
#endif