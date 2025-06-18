#include "../include/Dice.hpp"
#include <ctime>
#include <random>
#include <iostream>
using namespace std;
Dice ::Dice(){
    for(int i = 0 ; i <6 ; i++)
    {
        if(i == 2)
        DiceFaces[i] = "!";
        if(i == 0)
        DiceFaces[i] ="*"; 
        else
        DiceFaces[i] =" ";
    }
}
string Dice ::DiceRoll()
{
    srand(time(0));
    int random = rand() % 6;
    return DiceFaces[random];
}