#include <../include/ErrorHandler.hpp>
#include <string>
#include <cctype>
#include <stdexcept>
bool CheckString(const std ::string& test)
{
    return !(test.empty());
}
bool CheckFloat(std ::string& test)
{
      bool dot = false;
    if (test.empty()) return false;
    for (char c : test) {
        if (c == '.') {
            if (dot) return false;
            dot = true;
        } else if (!isdigit(c)) return false;
    }
    return true;
}
bool CheckInt(std ::string& test)
{
  if (test.empty()) return false;
    for (char c : test) if (!isdigit(c)) return false;
    return true;
}
