#include "../include/Monster.hpp"
#include "../include/Location.hpp"
#include "../include/Terminal.hpp"
#include "../include/ErrorHandler.hpp"
#include "../include/Game.hpp"
#include "../include/Dracula.hpp"
#include "../include/invisible.hpp"
#include "../include/Dice.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstring>
#include "raymath.h"
#include <cmath>
#include <algorithm>
#include "../include/Names.hpp"
#include "../include/LocationNames.hpp"

using namespace Names;
using namespace LocationNames;
void ShowInTerminal ::LoadAssets()
{
    // Heroes
    heroTextures["Mayor"] = LoadTexture("../assets/Heros/Mayor.png");
    heroTextures["Archaeologist"] = LoadTexture("../assets/Heros/Archaeologist.png");
    heroTextures["Courier"] = LoadTexture("../assets/Heros/Courier.png");
    heroTextures["Scientist"] = LoadTexture("../assets/Heros/Scientist.png");

    // Monsters
    monsterTextures["Dracula"] = LoadTexture("../assets/Monsters/Dracula.png");
    monsterTextures["Invisible Man"] = LoadTexture("../assets/Monsters/InvisibleMan.png");

    // Villagers
    villagerTextures[DrCranley] = LoadTexture("../assets/Villager/DrCranly.png");
    villagerTextures[DrReed] = LoadTexture("../assets/Villager/DrReed.png");
    villagerTextures[ProfPearson] = LoadTexture("../assets/Villager/ProfPearson.png");
    villagerTextures[Maleva] = LoadTexture("../assets/Villager/Maleva.png");
    villagerTextures[Fritz] = LoadTexture("../assets/Villager/Fritz.png");
    villagerTextures[WilburAndChick] = LoadTexture("../assets/Villager/WilburAndChick.png");
    villagerTextures[Maria] = LoadTexture("../assets/Villager/Maria.png");

    // Items
    // Yellow
    itemTextures[Flower] = LoadTexture("../assets/Items/Yellow/Flower.png");
    itemTextures[TarotDeck] = LoadTexture("../assets/Items/Yellow/Tarot.png");
    itemTextures[Garlic] = LoadTexture("../assets/Items/Yellow/Garlic.png");
    itemTextures[MirroredBox] = LoadTexture("../assets/Items/Yellow/Mirrored_Box.png");
    itemTextures[Stake] = LoadTexture("../assets/Items/Yellow/Stake.png");
    itemTextures[ScrollOfThoth] = LoadTexture("../assets/Items/Yellow/Scroll.png");
    itemTextures[Violin] = LoadTexture("../assets/Items/Yellow/Violin.png");
    itemTextures[Tablet] = LoadTexture("../assets/Items/Yellow/Tablet.png");
    itemTextures[Wolfsbane] = LoadTexture("../assets/Items/Yellow/Wolfsbane.png");
    itemTextures[Charm] = LoadTexture("../assets/Items/Yellow/Charm.png");
    // Red
    itemTextures[Dart] = LoadTexture("../assets/Items/Red/Dart.png");
    itemTextures[FirePoker] = LoadTexture("../assets/Items/Red/FirePoker.png");
    itemTextures[Rapier] = LoadTexture("../assets/Items/Red/Rapier.png");
    itemTextures[Shovel] = LoadTexture("../assets/Items/Red/Shovel.png");
    itemTextures[Torch] = LoadTexture("../assets/Items/Red/Torch.png");
    itemTextures[Pitchfork] = LoadTexture("../assets/Items/Red/Pitchfork.png");
    itemTextures[Rifle] = LoadTexture("../assets/Items/Red/Rifle.png");
    itemTextures[SilverCane] = LoadTexture("../assets/Items/Red/SilverCane.png");
    itemTextures[Knife] = LoadTexture("../assets/Items/Red/Knife.png");
    itemTextures[Pistol] = LoadTexture("../assets/Items/Red/Pistol.png");
    itemTextures[BearTrap] = LoadTexture("../assets/Items/Red/BearTrap.png");
    itemTextures[Speargun] = LoadTexture("../assets/Items/Red/Speargun.png");
    // Blue
    itemTextures[AnatomyTest] = LoadTexture("../assets/Items/Blue/AnatomyText.png");
    itemTextures[Contrifuge] = LoadTexture("../assets/Items/Blue/Centrifuge.png");
    itemTextures[Kite] = LoadTexture("../assets/Items/Blue/Kite.png");
    itemTextures[Research] = LoadTexture("../assets/Items/Blue/Research.png");
    itemTextures[Telescope] = LoadTexture("../assets/Items/Blue/Telescope.png");
    itemTextures[Searchlight] = LoadTexture("../assets/Items/Blue/Searchlight.png");
    itemTextures[Experiment] = LoadTexture("../assets/Items/Blue/Experiments.png");
    itemTextures[Analysis] = LoadTexture("../assets/Items/Blue/Analysis.png");
    itemTextures[Rotenone] = LoadTexture("../assets/Items/Blue/Rotenone.png");
    itemTextures[CosmicRayDiffuser] = LoadTexture("../assets/Items/Blue/CosmicRayDiffuser.png");
    itemTextures[Nebularium] = LoadTexture("../assets/Items/Blue/Nebularium.png");
    itemTextures[MonocaneMixture] = LoadTexture("../assets/Items/Blue/MonocaneMixture.png");
    itemTextures[Fossil] = LoadTexture("../assets/Items/Blue/Fossil.png");

    // Perks
    perkTextures[VisitFromDetective] = LoadTexture("../assets/Perk_Cards/VisitFromTheDetective.png");
    perkTextures[BreakOfDown] = LoadTexture("../assets/Perk_Cards/BreakOfDawn.png");
    perkTextures[OverStock] = LoadTexture("../assets/Perk_Cards/Overstock.png");
    perkTextures[LateIntoTheNight] = LoadTexture("../assets/Perk_Cards/LateIntoTheNight.png");
    perkTextures[Repel] = LoadTexture("../assets/Perk_Cards/Repel.png");
    perkTextures[Hurry] = LoadTexture("../assets/Perk_Cards/Hurry.png");

    // MonsterCards
    monsterCardTextures[FromTheBat] = LoadTexture("../assets/Monster_Cards/FormOfTheBat.png");
    monsterCardTextures[Sunrise] = LoadTexture("../assets/Monster_Cards/Sunrise.png");
    monsterCardTextures[Thief] = LoadTexture("../assets/Monster_Cards/Thief.png");
    monsterCardTextures[TheDelivery] = LoadTexture("../assets/Monster_Cards/TheDelivery.png");
    monsterCardTextures[FortuneTeller] = LoadTexture("../assets/Monster_Cards/FortuneTeller.png");
    monsterCardTextures[FormerEmployer] = LoadTexture("../assets/Monster_Cards/FomerEmployer.png");
    monsterCardTextures[HurriedAssistant] = LoadTexture("../assets/Monster_Cards/HurriedAssistant.png");
    monsterCardTextures[TheInnocent] = LoadTexture("../assets/Monster_Cards/TheInnocent.png");
    monsterCardTextures[EgyptianExpert] = LoadTexture("../assets/Monster_Cards/EgyptianExpert.png");
    monsterCardTextures[TheIchthyologist] = LoadTexture("../assets/Monster_Cards/TheIchtyologist.png");
    monsterCardTextures[OnTheMove] = LoadTexture("../assets/Monster_Cards/OnTheMove.png");
    monsterCardTextures[HypnoticGaze] = LoadTexture("../assets/Monster_Cards/HypnoticGaze.png");

    // MonsterMats
    monstermatTextures["Dracula"] = LoadTexture("../assets/Monster_Mat/DraculaMat.png");
    monstermatTextures["InvisibleMan"] = LoadTexture("../assets/Monster_Mat/InvisibleManMat.png");

    // Backgrounds
    backgroundTextures["menu"] = LoadTexture("../assets/Background/Background1.png");
    backgroundTextures["input"] = LoadTexture("../assets/Background/Background2.png");
    backgroundTextures["exit"] = LoadTexture("../assets/Background/Background3.png");
    backgroundTextures["back"] = LoadTexture("../assets/Background/Background4.jpg");

    // Map
    mapTexture = LoadTexture("../assets/map.png");

    // Font
    font = LoadFont("../assets/Fonts/Creepster.ttf");

    // Coffin
    coffinBrokenTexture = LoadTexture("../assets/Items/Coffins/SmashedCoffin.png");
    coffinIntactTexture = LoadTexture("../assets/Items/Coffins/Coffin.png");

    // Frenzy Mark
    frenzyMark = LoadTexture("../assets/Monster_Mat/FrenzyMark.png");
    // Location

    locationPositions[Cave] = {43, 133};
    locationPositions[Camp] = {123, 115};
    locationPositions[Precinct] = {219, 104};
    locationPositions[Inn] = {306, 89};
    locationPositions[Abbey] = {58, 319};
    locationPositions[Crypt] = {40, 419};
    locationPositions[Mansion] = {157, 277};
    locationPositions[Theater] = {348, 198};
    locationPositions[Barn] = {415, 101};
    locationPositions[Tower] = {454, 191};
    locationPositions[Dungeon] = {502, 101};
    locationPositions[Docks] = {488, 279};
    locationPositions[Institute] = {443, 495};
    locationPositions[Laboratory] = {377, 405};
    locationPositions[Shop] = {302, 342};
    locationPositions[Museum] = {126, 406};
    locationPositions[Church] = {248, 431};
    locationPositions[Hospital] = {210, 497};
    locationPositions[Graveyard] = {328, 488};

    float r = 30.0f;

    locationBounds[Cave] = {116.0f - r, 397.0f - r, r * 2, r * 2};
    locationBounds[Camp] = {377.0f - r, 391.0f - r, r * 2, r * 2};
    locationBounds[Precinct] = {653.0f - r, 262.0f - r, r * 2, r * 2};
    locationBounds[Inn] = {937.0f - r, 248.0f - r, r * 2, r * 2};
    locationBounds[Abbey] = {152.0f - r, 964.0f - r, r * 2, r * 2};
    locationBounds[Crypt] = {113.0f - r, 1262.0f - r, r * 2, r * 2};
    locationBounds[Mansion] = {444.0f - r, 851.0f - r, r * 2, r * 2};
    locationBounds[Theater] = {1052.0f - r, 590.0f - r, r * 2, r * 2};
    locationBounds[Barn] = {1245.0f - r, 284.0f - r, r * 2, r * 2};
    locationBounds[Tower] = {1391.0f - r, 557.0f - r, r * 2, r * 2};
    locationBounds[Dungeon] = {1526.0f - r, 298.0f - r, r * 2, r * 2};
    locationBounds[Docks] = {1488.0f - r, 862.0f - r, r * 2, r * 2};
    locationBounds[Institute] = {1344.0f - r, 1482.0f - r, r * 2, r * 2};
    locationBounds[Laboratory] = {1146.0f - r, 1226.0f - r, r * 2, r * 2};
    locationBounds[Shop] = {906.0f - r, 1030.0f - r, r * 2, r * 2};
    locationBounds[Museum] = {377.0f - r, 1237.0f - r, r * 2, r * 2};
    locationBounds[Church] = {755.0f - r, 1284.0f - r, r * 2, r * 2};
    locationBounds[Hospital] = {622.0f - r, 1501.0f - r, r * 2, r * 2};
    locationBounds[Graveyard] = {992.0f - r, 1485.0f - r, r * 2, r * 2};
}
void ShowInTerminal ::UnloadAssets()
{

    for (auto &[_, tex] : heroTextures)
        UnloadTexture(tex);
    for (auto &[_, tex] : monsterTextures)
        UnloadTexture(tex);
    for (auto &[_, tex] : villagerTextures)
        UnloadTexture(tex);
    for (auto &[_, tex] : perkTextures)
        UnloadTexture(tex);
    for (auto &[_, tex] : itemTextures)
        UnloadTexture(tex);
    for (auto &[_, tex] : monsterCardTextures)
        UnloadTexture(tex);
    for (auto &[_, tex] : monstermatTextures)
        UnloadTexture(tex);
    for (auto &[_, tex] : backgroundTextures)
        UnloadTexture(tex);
    UnloadTexture(mapTexture);
    UnloadFont(font);
    UnloadTexture(coffinBrokenTexture);
    UnloadTexture(coffinIntactTexture);
    UnloadTexture(frenzyMark);
}
void ShowInTerminal :: DrawMessageBox(const std :: string& message , bool& showMessage)
{
if(showMessage){
    Rectangle box = { 100, 500, 600, 70 };

    DrawRectangleRounded(box, 0.3f, 12, DARKGRAY);
    DrawRectangleRoundedLines(box, 0.3f, 12, RAYWHITE);

    int textWidth = MeasureText(message.c_str(), 20);
    DrawText(message.c_str(), box.x + (box.width - textWidth) / 2, box.y + 25, 20, WHITE);
}}
void ShowInTerminal :: Enter(bool& showMessage){
        
        if (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            showMessage = false;
        }

}
void ShowInTerminal::ShowMessageBox(const std::string& message) {
    Rectangle box = { 100, 500, 600, 70 };

    bool waiting = true;
    while (!WindowShouldClose() && waiting) {
        BeginDrawing();
        ClearBackground(BLANK);

        DrawRectangleRounded(box, 0.3f, 12, DARKGRAY);
        DrawRectangleRoundedLines(box, 0.3f, 12, RAYWHITE);

        int textWidth = MeasureText(message.c_str(), 20);
        DrawText(message.c_str(), box.x + (box.width - textWidth)/2, box.y + 25, 20, WHITE);

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            waiting = false;
    }
}
int ShowInTerminal :: MenuGenerator(const std::vector<std::string>& options) {
    int selected = -1;
    Texture2D bg = backgroundTextures["menu"];
    Font& font = this->font;

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

bool ShowInTerminal :: GetPlayerInfo(std::string& name, int& days) {

    Texture2D bg = backgroundTextures["input"];

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
 

 DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height}, {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, {0, 0}, 0.0f, WHITE);


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
            DrawTextEx(font , errorMsg.c_str(), {200, 400}, 20 , 2 , RED);
        }

        EndDrawing();
    }

    return submitClicked;
}
void ShowInTerminal:: ShowExitScreen() {
    
    Texture2D bg = backgroundTextures["exit"] ;
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

void ShowInTerminal :: DrawTerrorLevel(int terrorLevel, Font font, Vector2 position) {
    
    std::string label = "Terror Level: " + std::to_string(terrorLevel);
    DrawTextEx(font, label.c_str(), position, 20, 1, RED);

    
    float fill = terrorLevel / 7.0f;

    
    Rectangle barBg = { position.x, position.y + 30, 200, 20 };
    DrawRectangleRec(barBg, DARKGRAY);

    Rectangle barFill = { position.x, position.y + 30, 200 * fill, 20 };
    DrawRectangleRec(barFill, RED);


    DrawRectangleLinesEx(barBg, 2, BLACK);
}


void ShowInTerminal::DrawDraculaMat(Game& game, Vector2 startPos) {
    auto dracula = game.GetDracula();
    if (!dracula) return;

    const auto& coffins = dracula->GetCoffins();
    if (coffins.empty()) return;

    const float cellWidth = 148.0f;
    const float cellHeight = 55.0f;
    const float padding = 6.0f;
    const float coffinSize = 35.0f;
    const float textFontSize = 16.0f;
    const float titleFontSize = 18.0f;
    
    
    const Color tableColor = { 50, 50, 80, 255 };
    const Color borderColor = { 100, 100, 140, 255 };
    const Color textColor = WHITE;

    const char* title = "Dracula mat";
    Vector2 titleSize = MeasureTextEx(font, title, titleFontSize, 1);
    DrawTextEx(font, title, 
              {startPos.x + (cellWidth - titleSize.x)/2, startPos.y - 25}, 
              titleFontSize, 1, WHITE);

    float availableHeight = GetScreenHeight() - startPos.y - 30;
    int maxVisibleRows = std::floor(availableHeight / cellHeight);
    int rowsToShow = std::min((int)coffins.size(), maxVisibleRows);

    for (int i = 0; i < rowsToShow; i++) {
        float cellY = startPos.y + i * cellHeight;
        
        
        DrawRectangleRounded(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight}, 
            0.1f, 5, tableColor);
        DrawRectangleRoundedLines(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight}, 
            0.1f, 5, borderColor);

    
        const auto& locName = coffins[i].second;
        std::string label = locName + ":";
        Vector2 textSize = MeasureTextEx(font, label.c_str(), textFontSize, 1);
        
        
        DrawTextEx(font, label.c_str(), 
                  {startPos.x + padding, cellY + (cellHeight - textSize.y)/2}, 
                  textFontSize, 1, textColor);

        
        float coffinX = startPos.x + cellWidth - coffinSize - padding;
        float coffinY = cellY + (cellHeight - coffinSize)/2;
        
        if (coffins[i].first) {
            if (coffinBrokenTexture.id != 0) {
                DrawTexturePro(
                    coffinBrokenTexture,
                    Rectangle{0, 0, (float)coffinBrokenTexture.width, (float)coffinBrokenTexture.height},
                    Rectangle{coffinX, coffinY, coffinSize, coffinSize * (float)coffinBrokenTexture.height/coffinBrokenTexture.width},
                    Vector2{0, 0}, 0.0f, WHITE
                );
            } else {
                DrawTextEx(font, "💀", 
                          Vector2{coffinX + coffinSize/2 - 8, coffinY + 2}, 
                          20, 1, RED);
            }
        } else {
            if (coffinIntactTexture.id != 0) {
                DrawTexturePro(
                    coffinIntactTexture,
                    Rectangle{0, 0, (float)coffinIntactTexture.width, (float)coffinIntactTexture.height},
                    Rectangle{coffinX, coffinY, coffinSize, coffinSize * (float)coffinIntactTexture.height/coffinIntactTexture.width},
                    Vector2{0, 0}, 0.0f, WHITE
                );
            } else {
                DrawTextEx(font, "⚰️", 
                          Vector2{coffinX + coffinSize/2 - 8, coffinY + 2}, 
                          20, 1, GREEN);
            }
        }
    }
    if (coffins.size() > maxVisibleRows) {
        const char* moreMsg = TextFormat("+%d more...", (int)coffins.size() - maxVisibleRows);
        DrawTextEx(font, moreMsg, 
                  Vector2{startPos.x + 10, startPos.y + rowsToShow * cellHeight + 5}, 
                  14, 1, GRAY);
    }
}
void ShowInTerminal::DrawInvisibleManMat(const std::vector<std::pair<bool, std::string>>& evidences, Font font, Vector2 startPos) {
    if (evidences.empty()) return;

    const float cellWidth = 148.0f;
    const float cellHeight = 44.0f;
    const float padding = 6.0f;
    const float iconSize = 20.0f;
    const float textFontSize = 16.0f;
    const float titleFontSize = 18.0f;
    
    const Color tableColor = { 50, 50, 80, 255 };
    const Color borderColor = { 100, 100, 140, 255 };
    const Color textColor = WHITE;

    const char* title = "Invisible Man Mat";
    Vector2 titleSize = MeasureTextEx(font, title, titleFontSize, 1);
    DrawTextEx(font, title, 
              {startPos.x + (cellWidth - titleSize.x)/2, startPos.y - 25}, 
              titleFontSize, 1, GOLD);

    float availableHeight = GetScreenHeight() - startPos.y - 30;
    int maxVisibleRows = std::floor(availableHeight / cellHeight);
    int rowsToShow = std::min((int)evidences.size(), maxVisibleRows);

    for (int i = 0; i < rowsToShow; i++) {
        float cellY = startPos.y + i * cellHeight;
        
        DrawRectangleRounded(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight}, 
            0.1f, 5, tableColor);
        DrawRectangleRoundedLines(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight}, 
            0.1f, 5, borderColor);

        const auto& locName = evidences[i].second;
        std::string label = locName + ":";
        Vector2 textSize = MeasureTextEx(font, label.c_str(), textFontSize, 1);
        
        DrawTextEx(font, label.c_str(), 
                  {startPos.x + padding, cellY + (cellHeight - textSize.y)/2}, 
                  textFontSize, 1, textColor);

        float iconX = startPos.x + cellWidth - iconSize - padding;
        float iconY = cellY + (cellHeight - iconSize)/2;
        
        if (evidences[i].first) {
            
            DrawTextEx(font, "V", 
                      {iconX, iconY}, 
                      iconSize, 1, GREEN);
        } else {
            
            DrawTextEx(font, "X", 
                      {iconX, iconY}, 
                      iconSize, 1, RED);
        }
    }

    if (evidences.size() > maxVisibleRows) {
        const char* moreMsg = TextFormat("+%d more...", (int)evidences.size() - maxVisibleRows);
        DrawTextEx(font, moreMsg, 
                  Vector2{startPos.x + 10, startPos.y + rowsToShow * cellHeight + 5}, 
                  14, 1, GRAY);
    }
}
void ShowInTerminal :: DrawItemsList(const std::vector<std::shared_ptr<Item>>& items, Font font, Vector2 position) {
    float fontSize = 18;
    float spacing = 2;
    float y = position.y;

    float boxWidth = 260;
    float boxHeight = items.size() * (fontSize + 4) + 10;
    DrawRectangle(position.x - 10, position.y - 10, boxWidth, boxHeight, Fade(DARKGREEN, 0.5f));
    DrawRectangleLinesEx({position.x - 10, position.y - 10, boxWidth, boxHeight}, 2, DARKGRAY);

    for (const auto& item : items) {
        std::string line = "- " + item->getName() + " (" + std::to_string(item->getPower()) + ")";
        Color color = WHITE;
        if (item->getColor() == ItemColor::Red) color = RED;
        else if (item->getColor() == ItemColor::Yellow) color = YELLOW;
        else if (item->getColor() == ItemColor::Blue) color = SKYBLUE;

        DrawTextEx(font, line.c_str(), {position.x, y}, fontSize, spacing, color);
        y += fontSize + 4;
    }
}

void ShowInTerminal::DrawHeroInfo(std::shared_ptr<Hero> hero, Font font, Vector2 startPos, Rectangle* outClickZone) {
    if (!hero) return;

    const float cellWidth = 148.0f;
    const float cellHeight = 54.0f;
    const float padding = 6.0f;
    const float textFontSize = 16.0f;
    const float titleFontSize = 18.0f;

    const Color tableColor = { 50, 50, 80, 255 };
    const Color borderColor = { 100, 100, 140, 255 };
    const Color textColor = WHITE;

    const char* title = "Hero Info";
    Vector2 titleSize = MeasureTextEx(font, title, titleFontSize, 1);
    DrawTextEx(font, title,
               {startPos.x + (cellWidth - titleSize.x) / 2, startPos.y - 25},
               titleFontSize, 1, GOLD);

    std::vector<std::string> lines;
    lines.push_back("Hero: " + hero->getName());
    lines.push_back("Location: " + hero->getLocation()->GetCityName());
    lines.push_back("Actions: " + std::to_string(hero->getRemainingActions()));
    lines.push_back("Inventory: Click here");

    for (size_t i = 0; i < lines.size(); i++) {
        float cellY = startPos.y + i * cellHeight;

        DrawRectangleRounded(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight},
            0.1f, 5, tableColor);
        DrawRectangleRoundedLines(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight},
            0.1f, 5, borderColor);

        std::string text = lines[i];

        
        if (text.find("Inventory:") == 0) {
            std::string prefix = "Inventory: ";
            std::string clickablePart = "Click here";

            Vector2 prefixSize = MeasureTextEx(font, prefix.c_str(), textFontSize, 1);
            Vector2 clickableSize = MeasureTextEx(font, clickablePart.c_str(), textFontSize, 1);

            Vector2 prefixPos = {startPos.x + padding, cellY + (cellHeight - prefixSize.y) / 2};
            Vector2 clickablePos = {prefixPos.x + prefixSize.x, cellY + (cellHeight - clickableSize.y) / 2};

            
            DrawTextEx(font, prefix.c_str(), prefixPos, textFontSize, 1, textColor);

            
            DrawTextEx(font, clickablePart.c_str(), clickablePos, textFontSize, 1, textColor);

            
            if (outClickZone) {
                *outClickZone = {clickablePos.x, clickablePos.y, clickableSize.x, clickableSize.y};
            }

        } else {
            Vector2 textSize = MeasureTextEx(font, text.c_str(), textFontSize, 1);
            Vector2 textPos = {startPos.x + padding, cellY + (cellHeight - textSize.y) / 2};
            DrawTextEx(font, text.c_str(), textPos, textFontSize, 1, textColor);
        }
    }
}
void ShowInTerminal::DrawMonsterCard(const std::shared_ptr<MonsterCard> &card, Vector2 position, float scale)
{
    if (!card)
        return;

    std::string nameKey = card->GetName();
    if (monsterCardTextures.find(nameKey) != monsterCardTextures.end())
    {
        Texture2D cardTexture = monsterCardTextures[nameKey];

        float width = cardTexture.width * scale;
        float height = cardTexture.height * scale;

        DrawTextureEx(cardTexture, position, 0.0f, scale, WHITE);
    }
    else
    {
        DrawText(("Card texture missing for: " + nameKey).c_str(), position.x, position.y, 20, RED);
    }
}
float ShowInTerminal::GetBestScaleForCharacters(Texture2D ObjectTexture)
{
    float TargetWidth = 59;
    float TargetHeight = 86;
    float ScaleX = TargetWidth / (float)ObjectTexture.width;
    float ScaleY = TargetHeight / (float)ObjectTexture.height;
    return fmin(ScaleX, ScaleY);
}

void ShowInTerminal::DrawPerkCard(const std::shared_ptr<PerkCard>& card, Font font, Vector2 position) {
    DrawTextEx(font, "Perk Card", {position.x + 35 , position.y}, 20, 2, GREEN);

    if (card) {
        std::string name = card->GetName();


        if (perkTextures.count(name)) {
            Texture2D& texture = perkTextures[name];
            float maxWidth = 150.0f;
            float scale = maxWidth / texture.width ;
            float imgW = texture.width * scale;
            float imgH = texture.height * scale;

            Vector2 imgPos = {position.x, position.y + 30};

            DrawTextureEx(texture, imgPos, 0, scale, WHITE);


            DrawRectangleLines(imgPos.x - 2, imgPos.y - 2, imgW + 4, imgH + 4, DARKGREEN);
        } else {
            DrawTextEx(font, "(Card image missing)", {position.x, position.y + 30}, 18, 2, RED);
        }
    } else {
        DrawTextEx(font, "(No card)", {position.x, position.y + 30}, 18, 2, RED);
    }
}
void ShowInTerminal::DrawCharactersOnMap(
    const std::vector<std::shared_ptr<Hero>> &heroes,
    const std::vector<std::shared_ptr<Monster>> &monsters,
    const std::vector<std::shared_ptr<Villager>> &villagers,
    const std::vector<std::shared_ptr<Item>> Items,
    float scale,
    Vector2 mapDrawPos,
    float mapDrawWidth = 545,
    float mapDrawHeight = 542)
{
    
    // === Draw Items 
    for(const auto i : Items)
    {
        auto posIt = locationPositions.find(i->GetItemLocationName()->GetCityName());
        auto iconIt = itemTextures.find(i->getName());
           if (posIt != locationPositions.end() && iconIt != villagerTextures.end())
            {
                Texture2D ItemTex = iconIt->second;
                Vector2 position = locationPositions[i->GetItemLocationName()->GetCityName()];
                position.y -= 60;
                position.x -= 30;

                float Scale = ShowInTerminal:: GetBestScaleForCharacters(ItemTex);
                DrawTextureEx(ItemTex, position, 0.0f, Scale, WHITE);
            }

    }
    // === Draw Heroes
    for (const auto &h : heroes)
    {
        auto posIt = locationPositions.find(h->getLocation()->GetCityName());
        auto iconIt = heroTextures.find(h->getName());
        if (posIt != locationPositions.end() && iconIt != heroTextures.end())
        {
            Texture2D HeroTex = iconIt->second;
            Vector2 position = locationPositions[h->getLocation()->GetCityName()];
            position.y -= 60;
            position.x -= 30;

            float Scale = ShowInTerminal:: GetBestScaleForCharacters(HeroTex);
            DrawTextureEx(HeroTex, position, 0.0f, Scale, WHITE);
        }
    }

    // === Draw Monsters
    for (const auto &m : monsters)
    {
        auto posIt = locationPositions.find(m->GetLocation()->GetCityName());
        auto iconIt = monsterTextures.find(m->GetName());
        if (posIt != locationPositions.end() && iconIt != monsterTextures.end())
        {
            Texture2D MonsterTex = iconIt->second;
            Vector2 position = locationPositions[m->GetLocation()->GetCityName()];
            position.y -= 80;
            position.x -= 50;

            float Scale = ShowInTerminal:: GetBestScaleForCharacters(MonsterTex);
            DrawTextureEx(MonsterTex, position, 0.0f, Scale, WHITE);
            if(m->GetFrenzyMarker())
            {
                Texture2D frenzyTex = frenzyMark;
                Vector2 pos = {position.x+15 , position.y-20};
                float s = GetBestScaleForCharacters(frenzyTex) / 2;
                DrawTextureEx(frenzyTex , pos , 0.0f , s , WHITE);
            }
        }
    }

    // === Draw Villagers
    for (const auto &v : villagers)
    {
        if (v->getCurrentLocation())
        {
            auto posIt = locationPositions.find(v->getCurrentLocation()->GetCityName());
            auto iconIt = villagerTextures.find(v->getName());
            if (posIt != locationPositions.end() && iconIt != villagerTextures.end())
            {
                Texture2D VillagerTex = iconIt->second;
                Vector2 position = locationPositions[v->getCurrentLocation()->GetCityName()];
                position.y -= 60;
                position.x -= 5;

                float Scale = ShowInTerminal:: GetBestScaleForCharacters(VillagerTex);
                DrawTextureEx(VillagerTex, position, 0.0f, Scale, WHITE);
            }
        }
    }
    
}
std::vector<std::string> ShowInTerminal::ShowDiceRollAnimation(Dice &dice, Font font)
{
    const int numDice = 3;
    const int rollFrames = 20;
    const float boxSize = 100;
    const float spacing = 40;
    const float fontSize = 48;

    std::vector<std::string> resultFaces(numDice);
    Vector2 startPos = {(float)GetScreenWidth() / 2 - (numDice * boxSize + (numDice - 1) * spacing) / 2, (float)GetScreenHeight() / 2 - boxSize / 2};

    // Animation loop
    for (int frame = 0; frame < rollFrames; ++frame)
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        for (int i = 0; i < numDice; ++i)
        {
            std::string face = dice.DiceRoll();
            Rectangle box = {startPos.x + i * (boxSize + spacing), startPos.y, boxSize, boxSize};

            DrawRectangleRounded(box, 0.3f, 12, GRAY);
            DrawRectangleRoundedLines(box, 0.3f, 12, WHITE);

            int faceWidth = MeasureText(face.c_str(), fontSize);
            DrawText(face.c_str(), box.x + (boxSize - faceWidth) / 2, box.y + boxSize / 3, fontSize, BLACK);
        }

        EndDrawing();
        WaitTime(0.09); // delay
    }

    BeginDrawing();
    ClearBackground(DARKBLUE);
    for (int i = 0; i < numDice; ++i)
    {
        resultFaces[i] = dice.DiceRoll();

        Rectangle box = {startPos.x + i * (boxSize + spacing), startPos.y, boxSize, boxSize};
        DrawRectangleRounded(box, 0.3f, 12, SKYBLUE);
        DrawRectangleRoundedLines(box, 0.3f, 12, WHITE);

        int faceWidth = MeasureText(resultFaces[i].c_str(), fontSize);
        DrawText(resultFaces[i].c_str(), box.x + (boxSize - faceWidth) / 2, box.y + boxSize / 3, fontSize, BLACK);
    }
    EndDrawing();
    WaitTime(1.0);

    return resultFaces;
}
void ShowInTerminal::ShowPopupMessages(Game &game , const std::string message)
{
    float screenW = (float)GetScreenWidth();
    float screenH = (float)GetScreenHeight();

    const float boxW = 900;
    const float boxH = 138;
    const float padding = 20;

    Rectangle popupBox = {
        0 , 543,boxW , boxH  
    };

    bool waiting = true;
    while (!WindowShouldClose() && waiting)
    {
        BeginDrawing();


        DrawRectangleRec(popupBox, Fade(DARKBLUE, 0.58f));
        DrawRectangleLinesEx(popupBox, 3, SKYBLUE);

        DrawTextEx(font, message.c_str(),
        {popupBox.x + padding, popupBox.y + padding},
        20, 2, RAYWHITE);
        
        std::string hint = "(Press Enter or click)";
        Vector2 hintSize = MeasureTextEx(font, hint.c_str(), 16, 1);
        DrawTextEx(font, hint.c_str(),
        {popupBox.x + popupBox.width - hintSize.x - 12, popupBox.y + popupBox.height - 24},
        16, 1, GRAY);
        
        EndDrawing();
        
        if (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        waiting = false;
    }
}
void ShowInTerminal::DrawInventoryPopup(std::shared_ptr<Hero> hero) {
    if (!hero) return;

    DrawRectangleRec(inventoryPopupBounds, Fade(BLACK, 0.9f));
    DrawRectangleLinesEx(inventoryPopupBounds, 3, SKYBLUE);

    const float padding = 15.0f;
    const float columnSpacing = 200.0f;
    const float iconSize = 32.0f;
    const float itemSpacing = 40.0f; 
    const int maxItemsPerColumn = (int)((inventoryPopupBounds.height - 2 * padding - 40) / itemSpacing);

    float xStart = inventoryPopupBounds.x + padding;
    float yStart = inventoryPopupBounds.y + padding;

    int fontSize = 20;
    DrawTextEx(font, "Inventory", {xStart, yStart}, fontSize, 1, GOLD);
    yStart += fontSize + 10;

    const auto& items = hero->getInventory();
    if (items.empty()) {
        DrawTextEx(font, "No items found.", {xStart, yStart}, fontSize, 1, LIGHTGRAY);
    } else {
        for (size_t i = 0; i < items.size(); i++) {
            int col = i / maxItemsPerColumn;
            int row = i % maxItemsPerColumn;

            float x = xStart + col * columnSpacing;
            float y = yStart + row * itemSpacing;

            Texture2D icon = itemTextures[items[i]->getName()];
            DrawTexturePro(icon,
                {0, 0, (float)icon.width, (float)icon.height},
                {x, y, iconSize, iconSize},
                {0, 0}, 0.0f, WHITE);

            std::string itemText = items[i]->getName() + "(" + std::to_string(items[i]->getPower()) + ")";
            DrawTextEx(font, itemText.c_str(), {x + iconSize + 10, y + 4}, fontSize, 1, WHITE);
        }
    }

    Rectangle closeBtn = {inventoryPopupBounds.x + inventoryPopupBounds.width - 40, inventoryPopupBounds.y + 10, 30, 30};
    DrawRectangleRounded(closeBtn, 0.2f, 4, RED);
    DrawTextEx(font, "X", {closeBtn.x + 8, closeBtn.y + 4}, 24, 1, WHITE);
}
int ShowInTerminal::ShowHeroPhase(Game& game, const std::vector<std::string>& options) {
    int selected = -1;


    float mapW = 545;
    float mapH = 542;
    Vector2 mapPos = {0, 0};

    
    const int buttonsPerRow = 6 ;
    const float buttonWidth = 130;
    const float buttonHeight = 35;
    const float spacing = 10;
    const Color buttonColor = {100, 140, 255, 255};
    const Color hoverColor = {130, 170, 255, 255};

    Rectangle optionRects[options.size()];
for (int i = 0; i < options.size(); i++) {
    int row = (i < 6) ? 0 : 1;
    int col = (i < 6) ? i : i - 6;

    int colsThisRow = (row == 0) ? 6 : 5;

    float totalWidth = colsThisRow * buttonWidth + (colsThisRow - 1) * spacing;
    float x = (GetScreenWidth() - totalWidth) / 2 + col * (buttonWidth + spacing);
    float y = GetScreenHeight() - 120 + row * (buttonHeight + spacing);

    optionRects[i] = {x, y, buttonWidth, buttonHeight};
}

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();

        BeginDrawing();
        ClearBackground(BLACK);

        
        DrawRectangleLines(mapPos.x - 5, mapPos.y - 5, mapW + 10, mapH + 10, DARKGRAY);
        DrawTexturePro(mapTexture,
                     {0, 0, (float)mapTexture.width, (float)mapTexture.height},
                     {mapPos.x, mapPos.y, mapW, mapH},
                     {0, 0}, 0.0f, WHITE);

        
        DrawCharactersOnMap(game.heroes,
                          game.Monsters,
                          game.villagers,
                          game.GetItemsInGame(),
                          30, {0, 0});

        
        DrawTerrorLevel(game.terrorLevel, font, {8, 484});
        
if (auto dracula = game.GetDracula())
    DrawDraculaMat(game, {(float)GetScreenWidth() - 165.0f , 40.0f });

if (auto invisible = game.GetInvisibleMan()) {
    Vector2 inMatPos = {(float)GetScreenWidth() - 330.0f, 40.0f};
    DrawInvisibleManMat(invisible->GetEvidence(), font, inMatPos);

    Rectangle inventoryClickZone = {0};
    if (game.heroPlayer)
        DrawHeroInfo(game.heroPlayer, font, {inMatPos.x, inMatPos.y + 50.0f * (float)invisible->GetEvidence().size() + 40.0f} , &inventoryClickZone);
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
    CheckCollisionPointRec(GetMousePosition(), inventoryClickZone)) {
    showInventoryPopup = true;
}
}

if (game.heroPlayer && game.heroPlayer->PeekPerkCard()) {
    Vector2 perkCardPos = {(float)GetScreenWidth() - 165.0f, 301.0f};
    DrawPerkCard(game.heroPlayer->PeekPerkCard(), font, perkCardPos);
}

        
        for (int i = 0; i < options.size(); i++) {
            bool hover = CheckCollisionPointRec(mouse, optionRects[i]);
            DrawRectangleRounded(optionRects[i], 0.3f, 8, hover ? hoverColor : buttonColor);
            
            const char* text = options[i].c_str();
            int fontSize = 18;
            int tw = MeasureText(text, fontSize);
            
            while (tw > buttonWidth - 10 && fontSize > 12) {
                fontSize--;
                tw = MeasureText(text, fontSize);
            }
        Vector2 textSize = MeasureTextEx(font, text, fontSize, 1);
            DrawTextEx(font, text, 
           {optionRects[i].x + (buttonWidth - textSize.x) / 2,
            optionRects[i].y + (buttonHeight - textSize.y) / 2},
           fontSize, 1, WHITE);
        }
        if (showInventoryPopup) {
    DrawInventoryPopup(game.heroPlayer);

    Vector2 mouse = GetMousePosition();
    Rectangle closeBtn = {inventoryPopupBounds.x + inventoryPopupBounds.width - 40, inventoryPopupBounds.y + 10, 30, 30};
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mouse, closeBtn)) {
        showInventoryPopup = false;
    }

    if (IsKeyPressed(KEY_ESCAPE)) {
        showInventoryPopup = false;
    }
}

        EndDrawing();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            for (int i = 0; i < options.size(); i++) {
                if (CheckCollisionPointRec(mouse, optionRects[i])) {
                    selected = i;
                    return selected;
                }
            }
        }
    }

    return selected;
}
void ShowInTerminal::ShowMonsterPhase(Game &game, std::shared_ptr<MonsterCard> card)
{
    float screenW = (float)GetScreenWidth();
    float screenH = (float)GetScreenHeight();

    // Map
    float mapW = 545;
    float mapH = 542;
    Vector2 mapPos = {0, 0};

    // Monster Card
    float cardW = 265;
    float cardH = 370;
    Texture2D monsterTexture = monsterCardTextures[card->GetName()];
    float cardScale = cardW / (float)monsterTexture.width;
    Vector2 cardPos = {mapPos.x + mapW + 45, 0};

    BeginDrawing();
    // === Backgound 
     Texture2D bg = backgroundTextures["menu"];
    DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height}, {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, {0, 0}, 0.0f, WHITE);


    // === Map
    DrawRectangleLines(mapPos.x - 5, mapPos.y - 5, mapW + 10, mapH + 10, DARKGRAY);
    DrawTexturePro(
        mapTexture,
        {0, 0, (float)mapTexture.width, (float)mapTexture.height},
        {mapPos.x, mapPos.y, mapW, mapH},
        {0, 0}, 0.0f, WHITE);

    // === Characters on Map
    DrawCharactersOnMap(game.heroes,
                        game.Monsters,
                        game.villagers,
                        game.GetItemsInGame(),
                        30,
                        {0, 0});

    // === Monster Card
    DrawRectangleLines(cardPos.x - 5, cardPos.y - 5, cardW + 10, cardH + 10, DARKGRAY);
    DrawMonsterCard(card, cardPos, cardScale);
    EndDrawing();
}

Font ShowInTerminal::GetFont() { return font; }

