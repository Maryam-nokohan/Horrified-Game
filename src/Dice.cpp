#include "../include/Dice.hpp"
#include <ctime>
#include <random>
#include <iostream>
using namespace std;
Dice ::Dice(){SetFaces();}
string Dice ::DiceRoll()
{
    srand(time(0));
    int random = rand() % 6;
    return DiceFaces[random];

}
void Dice::SetFaces()
{
    DiceFaces.push_back("*");
    DiceFaces.push_back("!");
    for(int i = 0 ; i  < 4; ++i)
    DiceFaces.push_back(" ");
}