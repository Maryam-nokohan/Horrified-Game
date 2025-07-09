#include "../include/Monster.hpp"
#include "../include/Location.hpp"
#include "../include/Terminal.hpp"
#include "../include/ErrorHandler.hpp"
#include "../include/Game.hpp"
#include "../include/Dracula.hpp"
#include "../include/invisible.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Action controler
int MenuGenerator(const std::vector<std::string>& options, std::string& msg, Texture2D bg, Font font) {
    int selected = -1;

    const float buttonWidth = 160;
    const float buttonHeight = 40;
    const float spacing = 20;
    const float totalHeight = options.size() * buttonHeight + (options.size() - 1) * spacing;
    const float startY = (GetScreenHeight() - totalHeight) / 2;

    Rectangle optionRects[options.size()];
    for (int i = 0; i < options.size(); i++) {
        float x = (GetScreenWidth() - buttonWidth) / 2;
        float y = startY + i * (buttonHeight + spacing);
        optionRects[i] = { x, y, buttonWidth, buttonHeight };
    }

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height}, {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, {0, 0}, 0.0f, WHITE);

        for (int i = 0; i < options.size(); i++) {
            bool hovered = CheckCollisionPointRec(mouse, optionRects[i]);
            DrawRectangleRounded(optionRects[i], 0.3f, 10, hovered ? LIGHTGRAY : BEIGE);

            int textWidth = MeasureText(options[i].c_str(), 20);
            DrawText(options[i].c_str(), optionRects[i].x + (buttonWidth - textWidth)/2, optionRects[i].y + 10, 20, BLACK);
        }

        if (!msg.empty()) {
            DrawTextEx(font, msg.c_str(), { 270, 520 }, 20, 1, BLACK);
        }

        EndDrawing();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            for (int i = 0; i < options.size(); i++) {
                if (CheckCollisionPointRec(mouse, optionRects[i])) {
                    return i;
                }
            }
        }
    }

    return -1;
}

std::string GetInput(const std::string& prompt, const std::string& errorType) {
    const int screenWidth = 800;
    const int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "Player Info");
    SetTargetFPS(60);

    Font customFont = LoadFont("assets/Fonts/Bungee-Regular.ttf");

    std::string input;
    std::string errorMessage = "";
    std::string placeholder = "Type here...";
    bool enterPressed = false;

    Rectangle inputBox = { 150, 150, 500, 50 };
    Rectangle okButton = { 350, 250, 100, 40 };

    while (!WindowShouldClose() && !enterPressed) {
        Vector2 mouse = GetMousePosition();
        bool hoverOK = CheckCollisionPointRec(mouse, okButton);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextEx(customFont, prompt.c_str(), (Vector2){ 60, 60 }, 20, 2, BLACK);

        DrawRectangleRounded(inputBox, 0.2f, 10, LIGHTGRAY);
        DrawRectangleRoundedLines(inputBox, 0.2f, 10,DARKGRAY);

        const char* inputText = input.empty() ? placeholder.c_str() : input.c_str();
        DrawTextEx(customFont, inputText, (Vector2){ inputBox.x + 10, inputBox.y + 10 }, 18, 1, input.empty() ? GRAY : BLACK);

        DrawRectangleRounded(okButton, 0.3f, 10, hoverOK ? GRAY : DARKGRAY);
        DrawRectangleRoundedLines(okButton, 0.4f, 25, BLACK);
        DrawTextEx(customFont, "OK", (Vector2){ okButton.x + 30, okButton.y + 10 }, 20, 2, WHITE);

        if (!errorMessage.empty()) {
            DrawTextEx(customFont, errorMessage.c_str(), (Vector2){ 60, 330 }, 16, 1, RED);
        }

        EndDrawing();

        int key = GetCharPressed();
        if (key > 0 && input.length() < 30) {
            input += (char)key;
        }

        if (IsKeyPressed(KEY_BACKSPACE) && !input.empty()) {
            input.pop_back();
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hoverOK) {
            if (errorType == "int" && !CheckInt(input)) {
                errorMessage = "Please enter a valid integer!";
            } else if (errorType == "float" && !CheckFloat(input)) {
                errorMessage = "Please enter a valid float!";
            } else if (errorType == "string" && !CheckString(input)) {
                errorMessage = "Please enter a valid string!";
            }
            else {
                enterPressed = true;
            }
        }
    }

    UnloadFont(customFont);
    CloseWindow();
    return input;
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



    