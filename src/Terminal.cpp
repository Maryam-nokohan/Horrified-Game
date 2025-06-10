#include <iostream>
#include <ftxui/component/screen_interactive.hpp>  
#include <ftxui/component/component.hpp>          
#include <ftxui/dom/elements.hpp>  
#include "../include/Terminal.hpp"
#include "../include/Game.hpp"
#include <vector>
#include <string>
using namespace ftxui;

int ShowInTerminal ::MenuGenerator(const std::vector<std::string> Options) {
  int selected = 0;
  
  auto screen = ScreenInteractive::TerminalOutput();
  
  auto menu = ftxui::Menu(Options, &selected) | color(Color ::DarkBlue) ;
  screen.Loop(menu);
  return selected;
}
void ShowInTerminal :: StylizeTextBoard(const std :: string txt){
  auto element = text(txt) | borderHeavy | color(Color :: DarkBlue);
  auto screen = Screen :: Create (Dimension :: Fit(element));
  Render(screen , element);
  std :: cout << screen.ToString() <<'\n'; 
}
void ShowInTerminal :: ShowTerrorLevel(int TerrorLevel){
  std :: string output = "Terror Level :";
  output+=std :: to_string(TerrorLevel);
  StylizeTextBoard(output); 
  float PlaceToFill = TerrorLevel/7.0f;
  auto element = (gauge(PlaceToFill)) | color(Color :: DarkBlue)  ;
  auto screen = Screen :: Create(Dimension ::Fixed(7) ,Dimension :: Fixed(2) );
  Render(screen , element);
  std :: cout << screen.ToString() <<'\n';

}

void ShowInTerminal :: Refresh(){
  #ifdef __WIN32
    system("cls");
  #else
    system("clear");
  #endif
}


