#include "../include/Card.hpp"
#include "../include/ErrorHandler.hpp"
#include <string>
using namespace std;
Card :: Card(const string & name ){
    SetName(name);
}
void Card :: SetName(const string &name){
    if(CheckString(name)){
        this ->Name = name;
    }
    
}

string Card ::GetName(){return Name;}

