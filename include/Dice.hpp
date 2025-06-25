#ifndef DICE_HPP
#define DICE_HPP
#include <vector>
#include <string>
class Dice{
private :
std :: vector <std :: string> DiceFaces;
public :
Dice();
std :: string DiceRoll();
void SetFaces();
~Dice()=default;
};
#endif