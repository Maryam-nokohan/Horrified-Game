#ifndef DRACULA_HPP
#define DRACULA_HPP
#include "../include/Monster.hpp"
#include <vector> 
#include <memory>
class Dracula : public Monster{
    private :
    std :: vector <bool> Coffins;

    public :
    Dracula();
    void Power() override;
    void Move() override;
    void Attack() override;
    bool IsCoffinDestroyed(const int &index)const;
    void DestroyCoffin(const int &index);
    bool AllCoffinDestroyed()const;
};
#endif