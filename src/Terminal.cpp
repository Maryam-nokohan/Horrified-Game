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
#include <cstring>

// Action controler
int ShowInTerminal :: MenuGenerator(const std::vector<std::string>& options, std::string& msg, Texture2D bg, Font font) {
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

bool ShowInTerminal :: GetPlayerInfo(std::string& name, int& days , Font font , Texture2D bg) {

    std :: string nameInput = "";
    std :: string daysInput = "";

    Rectangle nameBox = {200, 180, 400, 40};
    Rectangle daysBox = {200, 260, 400, 40};
    Rectangle submitBtn = {430, 350, 120, 40};
    Rectangle backBtn = {250, 350, 120, 40};

    bool typingName = true;
    bool typingDays = false;
    bool submitClicked = false;
    bool backClicked = false;
    std::string errorMsg = "";

    while (!WindowShouldClose() && !submitClicked && !backClicked) {
        Vector2 mouse = GetMousePosition();


        int key = GetCharPressed();
       if (key > 0 && isprint(key)) {
    if (typingName && nameInput.size() < 30) {
        nameInput.push_back((char)key);
    } else if (typingDays && daysInput.size() < 5 && isdigit(key)) {
        daysInput.push_back((char)key);
    }
}

        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (typingName && !nameInput.empty()) {
                nameInput.pop_back();
            } else if (typingDays && !daysInput.empty()) {
                daysInput.pop_back();
            }
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            typingName = CheckCollisionPointRec(mouse, nameBox);
            typingDays = CheckCollisionPointRec(mouse, daysBox);

            if (CheckCollisionPointRec(mouse, submitBtn)) {
                if (nameInput.empty() || daysInput.empty()) {
                    errorMsg = "Both fields must be filled!";
                } else if(!CheckInt(daysInput)){
                    errorMsg ="Days must be a number!";
                }
                 else {
                    name = nameInput;
                    days = std::stoi(daysInput);
                    submitClicked = true;
                }
            }

            if (CheckCollisionPointRec(mouse, backBtn)) {
                backClicked = true;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(bg, 0, 0, WHITE);

        DrawTextEx(font, "Enter your name:", {nameBox.x, nameBox.y - 30}, 20, 2, WHITE);
        DrawRectangleRec(nameBox, typingName ? LIGHTGRAY : GRAY);
        DrawText(nameInput.empty() ? "Type name..." : nameInput.c_str() , nameBox.x +5 , nameBox.y + 10, 20, BLACK);

        DrawTextEx(font, "Days since last garlic:", {daysBox.x, daysBox.y - 30}, 20, 2, WHITE);
        DrawRectangleRec(daysBox, typingDays ? LIGHTGRAY : GRAY);
        DrawText(daysInput.empty() ? "0" : daysInput.c_str() , daysBox.x +5 , daysBox.y + 10, 20, BLACK);


        DrawRectangleRec(submitBtn, SKYBLUE);
        DrawText("Submit", submitBtn.x + 20, submitBtn.y + 10, 20, BLACK);

        DrawRectangleRec(backBtn, ORANGE); 
        DrawText("Back", backBtn.x + 30, backBtn.y + 10, 20, BLACK);

        if (!errorMsg.empty()) {
            DrawText(errorMsg.c_str(), 200, 420, 18, RED);
        }

        EndDrawing();
    }

    return submitClicked;
}
void ShowInTerminal:: ShowExitScreen(Texture2D bg, Font font) {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    double startTime = GetTime();

    while (!WindowShouldClose()) {
        double elapsed = GetTime() - startTime;

        if (elapsed >= 4.0) break;

        BeginDrawing();
        ClearBackground(BLACK);


        DrawTexturePro(bg,
            {0, 0, (float)bg.width, (float)bg.height},
            {0, 0, (float)screenWidth, (float)screenHeight},
            {0, 0}, 0.0f, WHITE);

    
        std::string msg = "THE DARKNESS AWAITS YOU...";
        Vector2 textSize = MeasureTextEx(font, msg.c_str(), 36, 2);
        Vector2 pos = {
            (screenWidth - textSize.x) / 2,
            (screenHeight - textSize.y) / 2
        };

        
            DrawTextEx(font, msg.c_str(), pos, 36, 2, RED);

        EndDrawing();
    }
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

void ShowInTerminal :: DrawTerrorLevel(int terrorLevel, Font font, Vector2 position) {
    
    std::string label = "Terror Level: " + std::to_string(terrorLevel);
    DrawTextEx(font, label.c_str(), position, 20, 1, WHITE);

    
    float fill = terrorLevel / 7.0f;

    
    Rectangle barBg = { position.x, position.y + 30, 200, 20 };
    DrawRectangleRec(barBg, DARKGRAY);

    Rectangle barFill = { position.x, position.y + 30, 200 * fill, 20 };
    DrawRectangleRec(barFill, RED);


    DrawRectangleLinesEx(barBg, 2, BLACK);
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
void ShowInTerminal :: DrawDraculaMat(const std::vector<std::pair<bool, std::string>>& coffins, Font font, Vector2 position) {
    float fontSize = 18;
    float spacing = 2;
    float y = position.y;

    DrawTextEx(font, "Dracula Mat:", {position.x, y}, fontSize, spacing, RED);
    y += fontSize + 6;

    float boxWidth = 250;
    float boxHeight = coffins.size() * (fontSize + 4) + 10;
    DrawRectangle(position.x - 10, y - 6, boxWidth, boxHeight, Fade(BEIGE, 0.7f));
    DrawRectangleLinesEx({position.x - 10, y - 6, boxWidth, boxHeight}, 2, DARKBROWN);

    for (const auto& c : coffins) {
        std::string line = c.second + " : ";
        line += (c.first ? u8"\u2713" : u8"\u2717");  // ✓ یا ✗
        DrawTextEx(font, line.c_str(), {position.x, y}, fontSize, spacing, BLACK);
        y += fontSize + 4;
    }
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
void ShowInTerminal :: DrawHeroInfo(std::shared_ptr<Hero> hero, Font font, Vector2 position) {
    float fontSize = 18;
    float spacing = 2;
    float y = position.y;

    std::string nameLine = "Hero: " + hero->getName();
    DrawTextEx(font, nameLine.c_str(), {position.x, y}, fontSize, spacing, WHITE);
    y += fontSize + 4;

    std::string locLine = "Location: " + hero->getLocation()->GetCityName();
    DrawTextEx(font, locLine.c_str(), {position.x, y}, fontSize, spacing, WHITE);
    y += fontSize + 4;

    std::string actLine = "Actions: " + std::to_string(hero->getRemainingActions());
    DrawTextEx(font, actLine.c_str(), {position.x, y}, fontSize, spacing, WHITE);
    y += fontSize + 10;

    DrawTextEx(font, "Inventory:", {position.x, y}, fontSize, spacing, WHITE);
    y += fontSize + 4;

    for (const auto& item : hero->getInventory()) {
        std::string itemLine = "- " + item->getName() + " (" + std::to_string(item->getPower()) + ")";
        Color color = WHITE;
        if (item->getColor() == ItemColor::Red) color = RED;
        else if (item->getColor() == ItemColor::Yellow) color = YELLOW;
        else if (item->getColor() == ItemColor::Blue) color = SKYBLUE;

        DrawTextEx(font, itemLine.c_str(), {position.x + 10, y}, fontSize, spacing, color);
        y += fontSize + 2;
    }

    float boxHeight = y - position.y + 10;
    DrawRectangleLinesEx({position.x - 10, position.y - 10, 280, boxHeight}, 2, DARKGREEN);
    DrawRectangle(position.x - 10, position.y - 10, 280, boxHeight, Fade(DARKGREEN, 0.3f));

}
void ShowInTerminal :: DrawMonsterCard(const std::shared_ptr<MonsterCard>& card, Font font, Vector2 position) {
    float fontSize = 18;
    float spacing = 2;
    float y = position.y;

    DrawTextEx(font, "Monster Card", {position.x, y}, fontSize, spacing, RED);
    y += fontSize + 4;

    DrawLine(position.x, y, position.x + 250, y, DARKGRAY);
    y += 6;

    DrawTextEx(font, ("Name: " + card->GetName()).c_str(), {position.x, y}, fontSize, spacing, WHITE); y += fontSize + 4;
    DrawTextEx(font, ("Event: " + card->GetEvent()).c_str(), {position.x, y}, fontSize, spacing, WHITE); y += fontSize + 4;
    DrawTextEx(font, ("Items: " + std::to_string(card->GetItem())).c_str(), {position.x, y}, fontSize, spacing, WHITE); y += fontSize + 4;
    DrawTextEx(font, ("Move: " + std::to_string(card->GetMove())).c_str(), {position.x, y}, fontSize, spacing, WHITE); y += fontSize + 4;
    DrawTextEx(font, ("Dice: " + std::to_string(card->GetDiceRoll())).c_str(), {position.x, y}, fontSize, spacing, WHITE); y += fontSize + 4;
    DrawTextEx(font, ("Order: " + card->GetOrderSymbold()).c_str(), {position.x, y}, fontSize, spacing, WHITE); y += fontSize + 6;

    float boxHeight = y - position.y + 10;
    DrawRectangle(position.x - 10, position.y - 10, 280, boxHeight, Fade(MAROON, 0.5f));
    DrawRectangleLinesEx({position.x - 10, position.y - 10, 280, boxHeight}, 2, DARKRED);
}
void ShowInTerminal :: DrawPerkCard(const std::shared_ptr<PerkCard>& card, Font font, Vector2 position) {
    float fontSize = 18;
    float spacing = 2;
    float y = position.y;

    DrawTextEx(font, "Perk Card", {position.x, y}, fontSize, spacing, GREEN);
    y += fontSize + 4;

    DrawLine(position.x, y, position.x + 200, y, DARKGRAY);
    y += 6;

    std::string nameLine = "Name: ";
    if (card != nullptr)
        nameLine += card->GetName();
    else
        nameLine += "(empty)";
    DrawTextEx(font, nameLine.c_str(), {position.x, y}, fontSize, spacing, YELLOW);
    y += fontSize + 6;

    float boxHeight = y - position.y + 10;
    DrawRectangle(position.x - 10, position.y - 10, 220, boxHeight, Fade(LIGHTGRAY, 0.4f));
    DrawRectangleLinesEx({position.x - 10, position.y - 10, 220, boxHeight}, 2, DARKGRAY);
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



    