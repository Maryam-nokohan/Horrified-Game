#include "../include/Dice.hpp"
#include <ctime>
#include <random>
#include <iostream>
using namespace std;
Dice ::Dice(){SetFaces();}
std::string Dice::DiceRoll() {
    static std::random_device rd;
    static std::mt19937 gen(rd()); 
    static std::uniform_int_distribution<> dist(0, 5);  // 6 faces

    return DiceFaces[dist(gen)];
}
void Dice::SetFaces()
{
    DiceFaces.push_back("*");
    DiceFaces.push_back("!");
    for(int i = 0 ; i  < 4; ++i)
    DiceFaces.push_back(" ");
}