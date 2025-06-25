#include <../include/ErrorHandler.hpp>
#include <string>
#include <cctype>
#include <stdexcept>
void CheckString(std ::string test)
{
    if (test.empty())
    {
        throw std ::invalid_argument("Error : empty string is invalid input !!\n");
    }
}
void CheckFloat(std ::string test)
{
    if (test.empty())
    {
        throw std ::invalid_argument("Error : empty string is invalid input !!\n");
    }
    try
    {
        stod(test);
    }
    catch (std ::invalid_argument &e)
    {
        std ::cerr << e.what(); //"Invalid floating point!"
    }
    catch (std ::out_of_range &e)
    {
        std ::cerr << e.what();
    }
    if (stod(test) < 0)
    {
        throw std ::invalid_argument("negative input is unavailiable!!\n");
    }
}
void CheckInt(std ::string test)
{
    if (test.empty())
    {
        throw std ::invalid_argument("Error : empty string is invalid input !!\n");
    }
    try
    {
        stoi(test);
    }
    catch (std ::invalid_argument &e)
    {
        std ::cerr << e.what(); //"Invalid int!"
    }
    catch (std ::out_of_range &e)
    {
        std ::cerr << e.what();
    }
    if (stoi(test) < 0)
    {
        throw std ::invalid_argument("negative input is unavailiable!!\n");
    }
}
