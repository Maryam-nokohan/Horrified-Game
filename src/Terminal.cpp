#include <iostream>
#include "../include/Monster.hpp"
#include <ftxui/component/screen_interactive.hpp>
#include "../include/Location.hpp"
#include <ftxui/component/component.hpp>
#include "ftxui/dom/elements.hpp"         
#include "../include/Terminal.hpp"
#include "../include/ErrorHandler.hpp"
#include "../include/Game.hpp"
#include <vector>
#include <string>
using namespace ftxui;
//Action controler
int ShowInTerminal ::MenuGenerator(const std::vector<std::string> Options)
{
  int selected = 0;

  auto screen = ScreenInteractive::FitComponent();

  auto menu = ftxui::Menu(Options, &selected) | color(Color :: Blue);
  screen.Loop(menu);
  return selected;
}
void ShowInTerminal ::StylizeTextBoard(const std ::string txt)
{
  auto element = text(txt) | borderHeavy | color(Color ::DarkBlue);
  auto screen = Screen ::Create(Dimension ::Fit(element));
  Render(screen, element);
  std ::cout << screen.ToString() << '\n';}
std::string ShowInTerminal::GetInput(const std::string outputText , std :: string ErrorType) {

    std::string content;
    std::string placeholder = "Type here...";

    auto screen = ScreenInteractive::TerminalOutput();

    Component inputBox = Input(&content, placeholder);

    auto layout = Renderer(inputBox, [&] {
        return vbox({
            text(outputText) | bold | color(Color::Yellow),
            separator(),
            inputBox->Render() | border
        }) | border;
    });

    screen.Loop(layout);
    if(ErrorType == "string")
    CheckString(content);
    if(ErrorType == "int")
    CheckInt(content);
    if(ErrorType == "float")
    CheckFloat(content);
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
/* 
Element ShowInTerminal::RenderMap() {
    return text(R"(
Cave ─── Camp  Prencent   Inn     Barn    Dungeon
         │      |          |       |         |
         |______|__________|____Theater____Tower___Docks
         |                         |______________________               
         |                                                |          
         |                             ___Graveyard       |       
      Mansion___________Church________|                   |
         |         |                  |___Hospital        |
         |         |____Musuem                            |
Abbey____|         |                                      |  
  |                |                                      |
  Crypt            |                                      |
                  Shop____________________________________|
institute____Lab___|
)") | border;
} */
//Render Functions:
Element ShowInTerminal ::RenderTerrorLevel(int terrorLevel )
{
     float fill = terrorLevel / 7.0f;
    return vbox({
        text("Terror Level: " + std::to_string(terrorLevel)) | bold,
        gauge(fill) | color(Color::Red)
    }) | border;

}
Element ShowInTerminal::RenderMap()
{
    return paragraph(R"(
Cave ─── Camp  Precinct   Inn     Barn    Dungeon
         │      │          │       │         │
         │______│__________│____Theater____Tower___Docks
         │                         │____________________               
         │                                                │          
         │                             ___Graveyard       │       
      Mansion___________Church________│                   │
         │         │                  │___Hospital        │
         │         │____Museum                            │
Abbey____│         │                                      │  
  │                │                                      │
  Crypt            │                                      │
                  Shop____________________________________│
Institute____Lab___│
)") | border;
}

Element ShowInTerminal::RenderHeroInfo(const std::shared_ptr<Hero>& hero) {
    std::vector<Element> lines;
    lines.push_back(text("Hero: " + hero->getName()) | bold);
    lines.push_back(text("Location: " + hero->getLocation()->GetCityName()));
    lines.push_back(text("Actions: " + std::to_string(hero->getRemainingActions())));
    lines.push_back(text("Inventory:"));
    for (const auto& item : hero->getInventory()){
        if(ItemColor :: Red == item->getColor())
        lines.push_back(text("- " + item->getName() + " (" + std::to_string(item->getPower()) + ")") | color(Color :: Red));
        if(ItemColor :: Yellow == item->getColor())
        lines.push_back(text("- " + item->getName() + " (" + std::to_string(item->getPower()) + ")") | color(Color :: Yellow));
        if(ItemColor :: Blue == item->getColor())
        lines.push_back(text("- " + item->getName() + " (" + std::to_string(item->getPower()) + ")") | color(Color :: Blue));
    }
    return vbox(lines) | border | bgcolor(Color::DarkBlue) | color(Color::White);
}

Element ShowInTerminal::RenderMonsterCard(const std::shared_ptr<MonsterCard>& card) {
    return vbox({
        text("Monster Card") | bold | color(Color::Red),
        separator(),
        text("Name: " + card->GetName()),
        text("Event: " + card->GetEvent()),
        text("Items: " + std::to_string(card->GetItem())),
        text("Move: " + std::to_string(card->GetMove())),
        text("Dice: " + std::to_string(card->GetDiceRoll())),
        text("Targets: " + card->GetOrderSymbold())
    }) | border | bgcolor(Color::DarkRed) | color(Color::White);
}

Element ShowInTerminal::RenderPerkCard(const std::shared_ptr<PerkCard>& card) {
    return vbox({
        text("Perk Card") | bold | color(Color::Green),
        separator(),
        text("Name: " + card->GetName())
    }) | border | bgcolor(Color::GrayLight) | color(Color::Yellow);
}

Element ShowInTerminal::RenderLocationOverview(
    const std::unordered_map<std::string, std::shared_ptr<Location>>& locations,
    const std::vector<std::shared_ptr<Monster>>& monsters,
    const std::vector<std::shared_ptr<Villager>>& villagers,
    const std::vector<std::shared_ptr<Item>>& items,
    const std :: vector<std :: shared_ptr<Hero>>& heros
) {
    StylizeTextBoard("=============================LocationOverview=============================");
    std::vector<Element> rows;
    rows.push_back(hbox({
        text("Location") | bold,
        filler(),
        text("Items") | bold,
        filler(),
        text("Monsters") | bold,
        filler(),
        text("Villagers") | bold,
        filler(),
        text("Heros") | bold
    }));
    rows.push_back(separator());

    for (const auto& [name, loc] : locations) {
        std::string itemStr, monsterStr, villagerStr , heroStr;

        for (auto& i : items)
            if (i->getLocation() == loc)
                itemStr += i->getName() + " ";

        for (auto& m : monsters)
            if (m->GetLocation() == loc)
                monsterStr += m->GetName() + " ";

        for (auto& v : villagers)
            if (v->getCurrentLocation() == loc)
                villagerStr += v->getName() + " ";

        for (auto& h : heros)
            if (h->getLocation() == loc)
                villagerStr += h->getName() + " ";

        if (itemStr.empty()) itemStr = "-";
        if (monsterStr.empty()) monsterStr = "-";
        if (villagerStr.empty()) villagerStr = "-";

        rows.push_back(hbox({
            text(name),
            filler(),
            text(itemStr),
            filler(),
            text(monsterStr),
            filler(),
            text(villagerStr)
        }));
    }

    return vbox(rows) | border | bgcolor(Color::GrayDark);
}
void ShowInTerminal::ShowPause()
{
    StylizeTextBoard("Press Enter to continue...");
    std :: cin.ignore();
    Refresh();

}

   int ShowInTerminal::Show(Game& game, const std::vector<std::string> options) {
    // Clear terminal
    // Refresh();
    // Print structured game info using your stylized renderer
    StylizeTextBoard("===== Current Game Status =====");
    std::cout << "\n";

    // Terror Level
    auto terrorView = RenderTerrorLevel(game.terrorLevel);
    auto terrorScreen = Screen::Create(Dimension::Fit(terrorView));
    Render(terrorScreen, terrorView);
    std::cout << terrorScreen.ToString() << "\n";

    // Map
    auto mapView = RenderMap();
    auto mapScreen = Screen::Create(Dimension::Fit(mapView));
    Render(mapScreen, mapView);
    std::cout << mapScreen.ToString() << "\n";

    // Hero Info
    if (game.heroPlayer) {
        auto heroInfo = RenderHeroInfo(game.heroPlayer);
        auto heroScreen = Screen::Create(Dimension::Fit(heroInfo));
        Render(heroScreen, heroInfo);
        std::cout << heroScreen.ToString() << "\n";
    }

    // Monster Card
    if (!game.MonsterDeck.empty()) {
        auto monsterCard = RenderMonsterCard(game.MonsterDeck.back());
        auto monsterScreen = Screen::Create(Dimension::Fit(monsterCard));
        Render(monsterScreen, monsterCard);
        std::cout << monsterScreen.ToString() << "\n";
    }

    // Perk Card
    if (game.heroPlayer && game.heroPlayer->PeekPerkCard()) {
        auto perkCard = RenderPerkCard(game.heroPlayer->PeekPerkCard());
        auto perkScreen = Screen::Create(Dimension::Fit(perkCard));
        Render(perkScreen, perkCard);
        std::cout << perkScreen.ToString() << "\n";
    }

    // Location Overview
    auto locOverview = RenderLocationOverview(
        game.getMapPlan().getLocations(),
        game.Monsters,
        game.villagers,
        game.Items,
        game.heroes
    );
    auto locScreen = Screen::Create(Dimension::Fit(locOverview));
    Render(locScreen, locOverview);
    std::cout << locScreen.ToString() << "\n";

    // Now show the menu using menu function
    if(!options.empty())
    {
        StylizeTextBoard("Choose your action:");
        int selectedIndex = MenuGenerator(options);
        return selectedIndex;
    }
    else{ 
        ShowPause();
        return -1;
    }
}
