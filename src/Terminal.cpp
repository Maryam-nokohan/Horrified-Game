#include "../include/Monster.hpp"
#include "../include/Location.hpp"
#include "../include/Terminal.hpp"
#include "../include/ErrorHandler.hpp"
#include "../include/Game.hpp"
#include "../include/Dracula.hpp"
#include "../include/invisible.hpp"
#include "ftxui/dom/elements.hpp"
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/dom/table.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace ftxui;
// Action controler
int ShowInTerminal ::MenuGenerator(const std::vector<std::string> Options)
{
    int selected = 0;

     auto screen = ScreenInteractive::FitComponent();
    auto menu = Menu(&Options, &selected) | color(Color::BlueViolet) | bgcolor(Color::Black);
    auto renderer = Renderer(menu, [&] {
        return vbox({
            hbox({ text("selected = "), text(std::to_string(selected)) }) | color(Color::BlueViolet),
            separator(),
            menu->Render() | frame,
        }) | border | bgcolor(Color::Black);
    });
    screen.Loop(renderer);
    return selected;
}
void ShowInTerminal ::StylizeTextBoard(const std ::string txt)
{
    auto element = paragraph(txt) | border | color(Color ::BlueViolet) | bgcolor(Color::Black);
    auto screen = Screen ::Create(Dimension ::Fit(element));
    Render(screen, element);
    std ::cout << screen.ToString() << '\n';
}
std::string ShowInTerminal::GetInput(const std::string outputText, std ::string ErrorType)
{

    std::string content;
    std::string placeholder = "Type here...";

    auto screen = ScreenInteractive::TerminalOutput();

    Component inputBox = Input(&content, placeholder);

    auto layout = Renderer(inputBox, [&]
                           { return vbox({text(outputText) | bold | color(Color::Yellow),
                                          separator(),
                                          inputBox->Render() | border}) |
                                    border; });

    screen.Loop(layout);
    if (ErrorType == "string")
        CheckString(content);
    if (ErrorType == "int")
        CheckInt(content);
    if (ErrorType == "float")
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
void ShowInTerminal::ShowPause()
{
    StylizeTextBoard("Press Enter to continue...");
    std ::cin.get();
}
void ShowInTerminal::ShowPauseWithRefresh()
{
    StylizeTextBoard("Press Enter to continue...");
    Refresh();
    std ::cin.get();
}
//Render function
Element ShowInTerminal ::RenderTerrorLevel(int terrorLevel)
{
    float fill = terrorLevel / 7.0f;
    return vbox({text("Terror Level: " + std::to_string(terrorLevel)) | bold,
                 gauge(fill) | color(Color::Red)}) |
           border;
}
Element ShowInTerminal::RenderMap()
{
    return paragraph(R"(
Cave ─── Camp  Precinct   Inn     Barn    Dungeon
         │      │          │       │         │
         │______│__________│____Theater____Tower___Docks
         │                         │________________
         │                                         │
         │                           ___Graveyard  │
      Mansion__________Church________│             │
         │        │                  │___Hospital  │
         │        │____Museum                      │
Abbey____│        │                                │
  │               │                                │
  Crypt           │                                │
                  Shop_____________________________│
Institute____Lab__│
)") | border | bgcolor(Color::DarkGoldenrod) | color(Color::Black);
}
Element ShowInTerminal::RenderDraculaMat(std ::vector<std::pair<bool , std::string>> coffins)
{
    std::string ShowCoffins = "";
    for (const auto &c : coffins)
    {
        ShowCoffins += c.second;
        ShowCoffins +=" : " ;
        ShowCoffins += (c.first ? u8"\u2713" : u8"\u2717");
        ShowCoffins += "\n";
    }
    return hbox({text("Dracula Mat : ") | bold | color(Color::Red),
                 paragraph(ShowCoffins) | bold | color(Color::Black) | bgcolor(Color::SandyBrown)});
}
Element ShowInTerminal::RenderInvisibleManMat(std::vector<std::pair<bool , std::string>> evidences)
{
    std::string ShowCollected = "";
    for (const auto &e : evidences)
    {
        ShowCollected += e.second;
        ShowCollected +=" : " ;
        ShowCollected += (e .first? u8"\u2713" : u8"\u2717");
        ShowCollected += "\n" ;
    }
    return hbox({text("Invisible Man Mat : ") | bold | color(Color::YellowLight),
                 paragraph(ShowCollected) | bold | color(Color::BlueViolet) | bgcolor(Color::SandyBrown)});
}
Element ShowInTerminal::RenderItems(const std::vector<std::shared_ptr<Item>> &items)
{
    std::vector<Element> lines;
    for (const auto &item : items)
    {
        if (ItemColor ::Red == item->getColor())
            lines.push_back(text("- " + item->getName() + " (" + std::to_string(item->getPower()) + ")") | color(Color ::Red));
        if (ItemColor ::Yellow == item->getColor())
            lines.push_back(text("- " + item->getName() + " (" + std::to_string(item->getPower()) + ")") | color(Color ::Yellow));
        if (ItemColor ::Blue == item->getColor())
            lines.push_back(text("- " + item->getName() + " (" + std::to_string(item->getPower()) + ")") | color(Color ::Blue));
    }
    return vbox(lines) | border | bgcolor(Color::DarkOliveGreen1) | color(Color::White);
}
Element ShowInTerminal::RenderHeroInfo(const std::shared_ptr<Hero> &hero)
{
    std::vector<Element> lines;
    lines.push_back(text("Hero: " + hero->getName()) | bold);
    lines.push_back(text("Location: " + hero->getLocation()->GetCityName()));
    lines.push_back(text("Actions: " + std::to_string(hero->getRemainingActions())));
    lines.push_back(text("Inventory:"));
    for (const auto &item : hero->getInventory())
    {
        if (ItemColor ::Red == item->getColor())
            lines.push_back(text("- " + item->getName() + " (" + std::to_string(item->getPower()) + ")") | color(Color ::Red));
        if (ItemColor ::Yellow == item->getColor())
            lines.push_back(text("- " + item->getName() + " (" + std::to_string(item->getPower()) + ")") | color(Color ::Yellow));
        if (ItemColor ::Blue == item->getColor())
            lines.push_back(text("- " + item->getName() + " (" + std::to_string(item->getPower()) + ")") | color(Color ::Blue));
    }
    return vbox(lines) | border | bgcolor(Color::DarkGreen) | color(Color::White);
}
Element ShowInTerminal::RenderMonsterCard(const std::shared_ptr<MonsterCard> &card)
{
    return vbox({text("Monster Card") | bold | color(Color::Red),
                 separator(),
                 text("Name: " + card->GetName()),
                 text("Event: " + card->GetEvent()),
                 text("Items: " + std::to_string(card->GetItem())),
                 text("Move: " + std::to_string(card->GetMove())),
                 text("Dice: " + std::to_string(card->GetDiceRoll())),
                 text("Order: " + card->GetOrderSymbold())}) |
           border | bgcolor(Color::DarkRed) | color(Color::White);
}
Element ShowInTerminal::RenderPerkCard(const std::shared_ptr<PerkCard> &card){
    return vbox({text("Perk Card") | bold | color(Color::Green),
                 separator(),
                 text("Name: " + (card != nullptr) ? card->GetName(): " " )}) |
           border | bgcolor(Color::GrayLight) | color(Color::Yellow);
}
Table ShowInTerminal::RenderLocationOverview(
    const std::unordered_map<std::string, std::shared_ptr<Location>> &locations,
    const std::vector<std::shared_ptr<Monster>> &monsters,
    const std::vector<std::shared_ptr<Villager>> &villagers,
    const std::vector<std::shared_ptr<Item>> &items,
    const std ::vector<std ::shared_ptr<Hero>> &heros)
{
 std::vector<std::vector<Element>> t;
t.push_back({text("Location"), text("Item"), text("Monsters"), text("Villagers"), text("Heros")});

for (const auto &[name, loc] : locations) {
    std::vector<Element> itemElements;
    std::vector<Element> monsterElements;
    std::vector<Element> villagerElements;
    std::vector<Element> heroElements;

    // Items
    for (auto &i : items) {
        if (i->getLocation() == loc) {
            if (i->getColor() == ItemColor::Red) {
                itemElements.push_back(text(i->getName() + "(" + std ::to_string(i->getPower()) + ")") | color(Color::Red));
                itemElements.push_back(text(","));
            } else if (i->getColor() == ItemColor::Yellow) {
                itemElements.push_back(text(i->getName()+ "(" + std::to_string(i->getPower()) + ")") | color(Color::Yellow));
                itemElements.push_back(text(","));
            } else if (i->getColor() == ItemColor::Blue) {
                itemElements.push_back(text(i->getName() + "(" + std::to_string(i->getPower()) + ")")| color(Color::Blue));
                itemElements.push_back(text(","));
            }
        }
    }

    // Monsters
    for (auto &m : monsters) {
        if (m->GetLocation() == loc) {
            auto monsterName = m->GetFrenzyMarker() ? m->GetName() + "*" : m->GetName();
            monsterElements.push_back(text(monsterName) | color(Color::Red));
        }
    }

    // Villagers
    for (auto &v : villagers) {
        if (v->getCurrentLocation() == loc) {
            villagerElements.push_back(text(v->getName() + "(" + v->getSafeLocation()->GetCityName() + ")") | color(Color::GreenYellow));
        }
    }

    // Heroes
    for (auto &h : heros) {
        if (h->getLocation() == loc) {
            heroElements.push_back(text(h->getName()) | color(Color::GrayLight));
        }
    }

    if (itemElements.empty()) itemElements.push_back(text("-"));
    if (monsterElements.empty()) monsterElements.push_back(text("-"));
    if (villagerElements.empty()) villagerElements.push_back(text("-"));
    if (heroElements.empty()) heroElements.push_back(text("-"));
  
    t.push_back({
        text(loc->GetCityName()),
        hbox(itemElements),
        hbox(monsterElements),
        hbox(villagerElements),
        hbox(heroElements),
    });
}

    auto table = Table(t);
    table.SelectAll().Border(LIGHT);

    // Add border around the columns.
    table.SelectColumn(0).Border(LIGHT);
    table.SelectColumn(1).Border(LIGHT);
    table.SelectColumn(2).Border(LIGHT);
    table.SelectColumn(3).Border(LIGHT);
    table.SelectColumn(4).Border(LIGHT);
    //Rows
    for(int i = 0 ; i < 19 ; ++i)
    table.SelectRow(i).Border(LIGHT);
  
    // Make first row bold with a double border.
    table.SelectRow(0).Decorate(bold);
    table.SelectRow(0).SeparatorVertical(LIGHT);
    table.SelectRow(0).Border(DOUBLE);

    // Select row from the second to the last.
    auto content = table.SelectRows(1, -1);

    return table;
}

int ShowInTerminal::ShowHeroPhase(Game &game, const std::vector<std::string> options)
{
    // Print
    StylizeTextBoard("========================================HeroPhase========================================");
    std::cout << '\n';
    int selectedIndex = -1;
    // Initial Setup

    auto monsterCardView = std::make_shared<MonsterCard>("MonsterCards", 0, "", MonsterStrike("", 0, 0));
    auto mapView = RenderMap();
    auto terrorView = RenderTerrorLevel(game.terrorLevel);

    auto dracula = game.GetDracula();
    Element draculaMat = text("Task Done!");
    if (dracula) {
        draculaMat = RenderDraculaMat(dracula->GetCoffins());
    }

    auto invisibleMan = game.GetInvisibleMan();
    Element invisibleManMat = text("Task Done!");
    if (invisibleMan) {
        invisibleManMat = RenderInvisibleManMat(invisibleMan->GetEvidence());
    }

    Element heroInfo = text("No hero");
    if (game.heroPlayer) {
        heroInfo = RenderHeroInfo(game.heroPlayer);
    }

    Element perkCard = text("No Perk Card");
    if (game.heroPlayer && game.heroPlayer->PeekPerkCard()) {
        perkCard = RenderPerkCard(game.heroPlayer->PeekPerkCard());
    }

    auto monsterCard = RenderMonsterCard(monsterCardView);
    auto locOverview = RenderLocationOverview(
        game.getMapPlan().getLocations(),
        game.Monsters,
        game.villagers,
        game.GetItemsInGame(),
        game.heroes);
    auto doc = locOverview.Render();

    // Menu component
    auto menuComponent = Menu(&options, &selectedIndex);
    auto menuRenderer = Renderer(menuComponent, [&] {
        return vbox({
            hbox({text("selected = "), text(std::to_string(selectedIndex)) | color(Color::BlueViolet)}),
            separator(),
            menuComponent->Render() | frame
        }) | border | bgcolor(Color::Black);
    });
    auto menuContainer = Container::Vertical({menuComponent});

    // Main layout
    auto layout = Renderer([&] {
        return vbox({
            hbox({ftxui::separator(), terrorView, ftxui::separator()}),
            ftxui::separator(),
            hbox({ftxui::separator(), mapView, ftxui::separator(), doc | bgcolor(Color::Black), ftxui::separator()}),
            hbox({ftxui::separator(), heroInfo, ftxui::separator(),
                  perkCard, ftxui::separator(),
                  monsterCard, ftxui::separator(),
                  draculaMat, ftxui::separator(),
                  invisibleManMat, ftxui::separator()}),
            ftxui::separator(),
            text("Choose your action:"),
        });
    });
    auto layoutContainer = Container::Horizontal({});

    // Final combined layout
    auto combined = Container::Vertical({menuContainer});
    auto final_renderer = Renderer(combined, [&] {
        return vbox({
            layout->Render(),
            menuRenderer->Render() | frame | border | bgcolor(Color::Black) | color(Color::BlueViolet)
        });
    });

    // Main Screen
    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(final_renderer);

    return selectedIndex;
}
void ShowInTerminal:: ShowMonsterPhase( Game & game){
    //print
    StylizeTextBoard("===============================================MonsterPhase===============================================");
      // Monster Card
    if (!game.MonsterDeck.empty()) {
        auto monsterCard = RenderMonsterCard(game.MonsterDeck.back());

        auto locOverview = RenderLocationOverview(
            game.getMapPlan().getLocations(),
            game.Monsters,
            game.villagers,
            game.GetItemsInGame(),
            game.heroes);

        auto layout = hbox(monsterCard, locOverview.Render()) | border;
        auto screen = Screen::Create(Dimension::Fit(layout));
        Render(screen, layout); 
        std::cout << screen.ToString() << '\n';
    }
    ShowPause();

  }



    