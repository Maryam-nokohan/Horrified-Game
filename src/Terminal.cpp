#include <iostream>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include "ftxui/dom/elements.hpp"         
#include "../include/Terminal.hpp"
#include "../include/ErrorHandler.hpp"
#include <vector>
#include <string>
using namespace ftxui;

int ShowInTerminal ::MenuGenerator(const std::vector<std::string> Options)
{
  int selected = 0;

  auto screen = ScreenInteractive::FitComponent();

  auto menu = ftxui::Menu(Options, &selected) | color(Color ::DarkBlue) | bgcolor(Color ::GrayDark);
  screen.Loop(menu);
  return selected;
}
void ShowInTerminal ::StylizeTextBoard(const std ::string txt)
{
  auto element = text(txt) | borderHeavy | color(Color ::DarkBlue);
  auto screen = Screen ::Create(Dimension ::Fit(element));
  Render(screen, element);
  std ::cout << screen.ToString() << '\n';
}
void ShowInTerminal ::ShowTerrorLevel(int TerrorLevel)
{
  std ::string output = "Terror Level :";
  output += std ::to_string(TerrorLevel);
  StylizeTextBoard(output);
  float PlaceToFill = TerrorLevel / 7.0f;
  auto element = (gauge(PlaceToFill)) | color(Color ::DarkBlue);
  auto screen = Screen ::Create(Dimension ::Fixed(7), Dimension ::Fixed(2));
  Render(screen, element);
  std ::cout << screen.ToString() << '\n';
}
std ::string ShowInTerminal ::GetInput(const std ::string output)
{
    auto screen = ScreenInteractive::FitComponent();

    std::string content ;

    std::string placeholder = "Type something...";

    Component input = Input(&content, placeholder);

    auto outputComponent = text(output) | color(Color::DarkBlue);

    auto layout = hbox(
        outputComponent,          
        separator(),              
        input                
    ) | border;

    Component layoutComponent = Renderer(input, [=]() {
        return layout;
    });

    screen.Loop(layoutComponent);
    CheckString(content);
    return content;

 
}

void ShowInTerminal ::Refresh()
{
#ifdef __WIN32
  system("cls");
#else
  system("clear");
#endif
}
