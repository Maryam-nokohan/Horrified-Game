#ifndef TERMINAL_HPP
#define TERMINAL_HPP
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include "../include/Game.hpp"
#include <vector>
#include <string>
#include <memory>
class ShowInTerminal{
  private :
  public :
  ShowInTerminal()= default;
  void Refresh();
  int MenuGenerator(const std :: vector <std :: string> Options);
  void StylizeTextBoard(const std :: string text);
  void ShowTerrorLevel(int);

};
#endif