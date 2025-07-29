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
#include "raymath.h"
#include <cmath>
#include <algorithm>

void ShowInTerminal :: LoadAssets(){
    //Heroes
    heroTextures["Mayor"] = LoadTexture("../assets/Heros/Mayor.png");
    heroTextures["Archaeologist"] = LoadTexture("../assets/Heros/Archaeologist.png");
    heroTextures["Courier"] = LoadTexture("../assets/Heros/Courier.png");
    heroTextures["Scientist"] = LoadTexture("../assets/Heros/Scientist.png");

    //Monsters
    monsterTextures["Dracula"] = LoadTexture("../assets/Monsters/Dracula.png");
    monsterTextures["InvisibleMan"] = LoadTexture("../assets/Monsters/InvisibleMan.png");

    //Villagers
    villagerTextures["DrCranley"] = LoadTexture("../assets/Villager/DrCranly.png");
    villagerTextures["DrReed"] = LoadTexture("../assets/Villager/DrReed.png");
    villagerTextures["ProfPearson"] = LoadTexture("../assets/Villager/ProfPearson.png");
    villagerTextures["Maleva"] = LoadTexture("../assets/Villager/Maleva.png");
    villagerTextures["Fritz"] = LoadTexture("../assets/Villager/Fritz.png");
    villagerTextures["WilburAndChick"] = LoadTexture("../assets/Villager/WilburAndChick.png");
    villagerTextures["Maria"] = LoadTexture("../assets/Villager/Maria.png");

    //Items
    //Yellow
    itemTextures["Flower"] = LoadTexture("../assets/Items/Yellow/Flower.png");
    itemTextures["TarotDeck"] = LoadTexture("../assets/Items/Yellow/Tarot.png");
    itemTextures["Garlic"] = LoadTexture("../assets/Items/Yellow/Garlic.png");
    itemTextures["MirroredBox"] = LoadTexture("../assets/Items/Yellow/Mirrored_Box.png");
    itemTextures["Stake"] = LoadTexture("../assets/Items/Yellow/Stake.png");
    itemTextures["ScrollOfThoth"] = LoadTexture("../assets/Items/Yellow/Scroll.png");
    itemTextures["Violin"] = LoadTexture("../assets/Items/Yellow/Violin.png");
    itemTextures["Tablet"] = LoadTexture("../assets/Items/Yellow/Tablet.png");
    itemTextures["Wolfsbane"] = LoadTexture("../assets/Items/Yellow/Wolfsbane.png");
    itemTextures["Charm"] = LoadTexture("../assets/Items/Yellow/Charm.png");
    //Red
    itemTextures["Dart"] = LoadTexture("../assets/Items/Red/Dart.png");
    itemTextures["FirePoker"] = LoadTexture("../assets/Items/Red/FirePoker.png");
    itemTextures["Rapier"] = LoadTexture("../assets/Items/Red/Rapier.png");
    itemTextures["Shovel"] = LoadTexture("../assets/Items/Red/Shovel.png");
    itemTextures["Torch"] = LoadTexture("../assets/Items/Red/Torch.png");
    itemTextures["Pitchfork"] = LoadTexture("../assets/Items/Red/Pitchfork.png");
    itemTextures["Rifle"] = LoadTexture("../assets/Items/Red/Rifle.png");
    itemTextures["SilverCane"] = LoadTexture("../assets/Items/Red/SilverCane.png");
    itemTextures["Knife"] = LoadTexture("../assets/Items/Red/Knife.png");
    itemTextures["Pistol"] = LoadTexture("../assets/Items/Red/Pistol.png");
    itemTextures["BearTrap"] = LoadTexture("../assets/Items/Red/BearTrap.png");
    itemTextures["Speargun"] = LoadTexture("../assets/Items/Red/Speargun.png");
    //Blue
    itemTextures["AnatomyTest"] = LoadTexture("../assets/Items/Blue/AnatomyText.png");
    itemTextures["Contrifuge"] = LoadTexture("../assets/Items/Blue/Centrifuge.png");
    itemTextures["Kite"] = LoadTexture("../assets/Items/Blue/Kite.png");
    itemTextures["Research"] = LoadTexture("../assets/Items/Blue/Research.png");
    itemTextures["Telescope"] = LoadTexture("../assets/Items/Blue/Telescope.png");
    itemTextures["Searchlight"] = LoadTexture("../assets/Items/Blue/Searchlight.png");
    itemTextures["Experiment"] = LoadTexture("../assets/Items/Blue/Experiments.png");
    itemTextures["Analysis"] = LoadTexture("../assets/Items/Blue/Analysis.png");
    itemTextures["Rotenone"] = LoadTexture("../assets/Items/Blue/Rotenone.png");
    itemTextures["CosmicRayDiffuser"] = LoadTexture("../assets/Items/Blue/CosmicRayDiffuser.png");
    itemTextures["Nebularium"] = LoadTexture("../assets/Items/Blue/Nebularium.png");
    itemTextures["MonocaneMixture"] = LoadTexture("../assets/Items/Blue/MonocaneMixture.png");
    itemTextures["Fossil"] = LoadTexture("../assets/Items/Blue/Fossil.png");

    //Perks
    perkTextures["VisitFromDetective"] = LoadTexture("../assets/Perk_Cards/VisitFromTheDetective.png");
    perkTextures["BreakOfDown"] = LoadTexture("../assets/Perk_Cards/BreakOfDawn.png");
    perkTextures["OverStock"] = LoadTexture("../assets/Perk_Cards/Overstock.png");
    perkTextures["LateIntoTheNight"] = LoadTexture("../assets/Perk_Cards/LateIntoTheNight.png");
    perkTextures["Repel"] = LoadTexture("../assets/Perk_Cards/Repel.png");
    perkTextures["Hurry"] = LoadTexture("../assets/Perk_Cards/Hurry.png");

    //MonsterCards
    monsterCardTextures["FromTheBat"] = LoadTexture("../assets/Monster_Cards/FormOfTheBat.png");
    monsterCardTextures["Sunrise"] = LoadTexture("../assets/Monster_Cards/Sunrise.png");
    monsterCardTextures["Thief"] = LoadTexture("../assets/Monster_Cards/Thief.png");
    monsterCardTextures["TheDelivery"] = LoadTexture("../assets/Monster_Cards/TheDelivery.png");
    monsterCardTextures["FortuneTeller"] = LoadTexture("../assets/Monster_Cards/FortuneTeller.png");
    monsterCardTextures["FormerEmployer"] = LoadTexture("../assets/Monster_Cards/FomerEmployer.png");
    monsterCardTextures["HurriedAssistant"] = LoadTexture("../assets/Monster_Cards/HurriedAssistant.png");
    monsterCardTextures["TheInnocent"] = LoadTexture("../assets/Monster_Cards/TheInnocent.png");
    monsterCardTextures["EgyptianExpert"] = LoadTexture("../assets/Monster_Cards/EgyptianExpert.png");
    monsterCardTextures["TheIchthyologist"] = LoadTexture("../assets/Monster_Cards/TheIchtyologist.png");
    monsterCardTextures["OnTheMove"] = LoadTexture("../assets/Monster_Cards/OnTheMove.png");
    monsterCardTextures["HypnoticGaze"] = LoadTexture("../assets/Monster_Cards/HypnoticGaze.png");

    //MonsterMats
    monstermatTextures["Dracula"] = LoadTexture("../assets/Monster_Mat/DraculaMat.png");
    monstermatTextures["InvisibleMan"] = LoadTexture("../assets/Monster_Mat/InvisibleManMat.png");

    //Backgrounds
    backgroundTextures["menu"] = LoadTexture("../assets/Background/Background1.png");
    backgroundTextures["input"] = LoadTexture("../assets/Background/Background2.png");
    backgroundTextures["exit"] = LoadTexture("../assets/Background/Background3.png");
    backgroundTextures["back"] = LoadTexture("../assets/Background/Background4.jpg");

    //Map
    mapTexture = LoadTexture("../assets/map.png");

    //Font
    font = LoadFont("../assets/Fonts/Creepster.ttf");

    //Coffin
    coffinBrokenTexture = LoadTexture("../assets/Items/Coffins/SmashedCoffin.png");
    coffinIntactTexture = LoadTexture("../assets/Items/Coffins/Coffin.png");

    //Location

    locationPositions["Cave"] = {116, 397};
    locationPositions["Camp"] = {377, 391};
    locationPositions["Precinct"] = {653, 262};
    locationPositions["Inn"] = {937, 248};
    locationPositions["Abbey"] = {152, 964};
    locationPositions["Crypt"] = {113, 1262};
    locationPositions["Mansion"] = {444, 851};
    locationPositions["Theater"] = {1052, 590};
    locationPositions["Barn"] = {1245, 284};
    locationPositions["Tower"] = {1391, 557};
    locationPositions["Dungeon"] = {1526, 298};
    locationPositions["Docks"] = {1488, 862};
    locationPositions["Institute"] = {1344, 1482};
    locationPositions["Laboratory"] = {1146, 1226};
    locationPositions["Shop"] = {906, 1030};
    locationPositions["Museum"] = {377, 1237};
    locationPositions["Church"] = {755, 1284};
    locationPositions["Hospital"] = {622, 1501};
    locationPositions["Graveyard"] = {992, 1485};

   float r = 30.0f;

    locationBounds["Cave"] = {116.0f - r, 397.0f - r, r * 2, r * 2};
    locationBounds["Camp"] = {377.0f - r, 391.0f - r, r * 2, r * 2};
    locationBounds["Precinct"] = {653.0f - r, 262.0f - r, r * 2, r * 2};
    locationBounds["Inn"] = {937.0f - r, 248.0f - r, r * 2, r * 2};
    locationBounds["Abbey"] = {152.0f - r, 964.0f - r, r * 2, r * 2};
    locationBounds["Crypt"] = {113.0f - r, 1262.0f - r, r * 2, r * 2};
    locationBounds["Mansion"] = {444.0f - r, 851.0f - r, r * 2, r * 2};
    locationBounds["Theater"] = {1052.0f - r, 590.0f - r, r * 2, r * 2};
    locationBounds["Barn"] = {1245.0f - r, 284.0f - r, r * 2, r * 2};
    locationBounds["Tower"] = {1391.0f - r, 557.0f - r, r * 2, r * 2};
    locationBounds["Dungeon"] = {1526.0f - r, 298.0f - r, r * 2, r * 2};
    locationBounds["Docks"] = {1488.0f - r, 862.0f - r, r * 2, r * 2};
    locationBounds["Institute"] = {1344.0f - r, 1482.0f - r, r * 2, r * 2};
    locationBounds["Laboratory"] = {1146.0f - r, 1226.0f - r, r * 2, r * 2};
    locationBounds["Shop"] = {906.0f - r, 1030.0f - r, r * 2, r * 2};
    locationBounds["Museum"] = {377.0f - r, 1237.0f - r, r * 2, r * 2};
    locationBounds["Church"] = {755.0f - r, 1284.0f - r, r * 2, r * 2};
    locationBounds["Hospital"] = {622.0f - r, 1501.0f - r, r * 2, r * 2};
    locationBounds["Graveyard"] = {992.0f - r, 1485.0f - r, r * 2, r * 2};

} 
void ShowInTerminal :: UnloadAssets(){
    
    for (auto& [_, tex] : heroTextures) UnloadTexture(tex);
    for (auto& [_, tex] : monsterTextures) UnloadTexture(tex);
    for (auto& [_, tex] : villagerTextures) UnloadTexture(tex);
    for (auto& [_, tex] : perkTextures) UnloadTexture(tex);
    for (auto& [_, tex] : itemTextures) UnloadTexture(tex);
    for (auto& [_, tex] : monsterCardTextures) UnloadTexture(tex);
    for (auto& [_, tex] : monstermatTextures) UnloadTexture(tex);
    for (auto& [_, tex] : backgroundTextures) UnloadTexture(tex);
    UnloadTexture(mapTexture);
    UnloadFont(font);
    UnloadTexture(coffinBrokenTexture);
    UnloadTexture(coffinIntactTexture);


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
       // DrawTexture(bg, 0, 0, WHITE);
// float screenW = 800.0f;
// float screenH = 600.0f;
// float texW = (float)bg.width;
// float texH = (float)bg.height;

// float scale = std::min(screenW / texW, screenH / texH);
// float drawW = texW * scale;
// float drawH = texH * scale;

// Rectangle source = {0, 0, texW, texH};
// Rectangle dest = {(screenW - drawW) / 2.0f, (screenH - drawH) / 2.0f, drawW, drawH};

// DrawTexturePro(bg, source, dest, {0, 0}, 0.0f, WHITE);
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
    DrawTextEx(font, label.c_str(), position, 20, 1, WHITE);

    
    float fill = terrorLevel / 7.0f;

    
    Rectangle barBg = { position.x, position.y + 30, 200, 20 };
    DrawRectangleRec(barBg, DARKGRAY);

    Rectangle barFill = { position.x, position.y + 30, 200 * fill, 20 };
    DrawRectangleRec(barFill, RED);


    DrawRectangleLinesEx(barBg, 2, BLACK);
}

// void ShowInTerminal :: DrawDraculaMat(const std::vector<std::pair<bool, std::string>>& coffins, Vector2 startPos) {
//     DrawTexture(monstermatTextures["Dracula"], startPos.x, startPos.y, WHITE);

//     float offsetX = 40;
//     float spacing = 150;

//     for (size_t i = 0; i < coffins.size(); ++i) {
        
//         std::string locationName = coffins[i].second;
//         DrawTextEx(font, locationName.c_str(), { startPos.x + offsetX + i * spacing, startPos.y + 100 }, 18, 1, BLACK);

        
//         Texture2D& tex = coffins[i].first ? coffinBrokenTexture : coffinIntactTexture;
//         DrawTexture(tex, startPos.x + offsetX + i * spacing, startPos.y + 130, WHITE);
//     }
// }
// void ShowInTerminal::DrawDraculaMat(Game& game, Vector2 startPos) {

//     auto dracula = game.GetDracula();
//     if(!dracula || !dracula->GetLocation()) return;
//     if (!dracula) return; // اگه دراکولا مقداردهی نشده، هیچی رسم نکن

//     if (monstermatTextures.find("Dracula") == monstermatTextures.end()) return;

//     // رسم تصویر اصلی مات
//     DrawTexture(monstermatTextures["Dracula"], startPos.x, startPos.y, WHITE);

//     auto coffins = dracula->GetCoffins();

//     float offsetX = 50;
//     float spacing = 70;
//     float textOffsetY = 100;

//     for (size_t i = 0; i < coffins.size(); ++i) {
//         std::string locName = coffins[i].second;
//         bool isBroken = coffins[i].first;

//         // متن نام مکان
//         DrawText(locName.c_str(), startPos.x + offsetX + i * spacing, startPos.y + textOffsetY, 16, BLACK);

//         // رسم عکس تابوت
//         Texture2D* tex = nullptr;
//         if (isBroken && coffinBrokenTexture.id != 0) {
//             tex = &coffinBrokenTexture;
//         } else if (!isBroken && coffinIntactTexture.id != 0) {
//             tex = &coffinIntactTexture;
//         }

//         if (tex) {
//             DrawTexture(*tex, startPos.x + offsetX + i * spacing, startPos.y + textOffsetY + 25, WHITE);
//         } else {
//             // اگر فایل لود نشده باشه، علامت X نشون بده
//             DrawText("❌", startPos.x + offsetX + i * spacing, startPos.y + textOffsetY + 25, 20, RED);
//         }
//     }
// }
void ShowInTerminal::DrawDraculaMat(Game& game, Vector2 startPos) {
    auto dracula = game.GetDracula();
    if (!dracula) return;

    const auto& coffins = dracula->GetCoffins();
    if (coffins.empty()) return;

    // تنظیمات جدید با چیدمان افقی
    const float cellWidth = 170.0f;  // کاهش عرض
    const float cellHeight = 50.0f;  // کاهش شدید ارتفاع
    const float padding = 6.0f;
    const float coffinSize = 35.0f;  // کاهش سایز تابوت
    const float textFontSize = 16.0f;
    const float titleFontSize = 18.0f;
    
    // رنگ‌ها
    const Color tableColor = { 50, 50, 80, 255 };
    const Color borderColor = { 100, 100, 140, 255 };
    const Color textColor = WHITE;

    // عنوان جدول
    const char* title = "Dracula mat";
    Vector2 titleSize = MeasureTextEx(font, title, titleFontSize, 1);
    DrawTextEx(font, title, 
              {startPos.x + (cellWidth - titleSize.x)/2, startPos.y - 25}, 
              titleFontSize, 1, WHITE);

    // محاسبه فضای قابل نمایش
    float availableHeight = GetScreenHeight() - startPos.y - 30;
    int maxVisibleRows = std::floor(availableHeight / cellHeight);
    int rowsToShow = std::min((int)coffins.size(), maxVisibleRows);

    for (int i = 0; i < rowsToShow; i++) {
        float cellY = startPos.y + i * cellHeight;
        
        // رسم سلول جدول
        DrawRectangleRounded(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight}, 
            0.1f, 5, tableColor);
        DrawRectangleRoundedLines(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight}, 
            0.1f, 5, borderColor);

        // متن و تابوت در یک خط
        const auto& locName = coffins[i].second;
        std::string label = locName + ":";
        Vector2 textSize = MeasureTextEx(font, label.c_str(), textFontSize, 1);
        
        // نمایش متن سمت چپ
        DrawTextEx(font, label.c_str(), 
                  {startPos.x + padding, cellY + (cellHeight - textSize.y)/2}, 
                  textFontSize, 1, textColor);

        // نمایش تابوت سمت راست
        float coffinX = startPos.x + cellWidth - coffinSize - padding;
        float coffinY = cellY + (cellHeight - coffinSize)/2;
        
        if (coffins[i].first) { // تابوت شکسته
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
        } else { // تابوت سالم
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

    // نمایش پیام برای موارد اضافی
    if (coffins.size() > maxVisibleRows) {
        const char* moreMsg = TextFormat("+%d more...", (int)coffins.size() - maxVisibleRows);
        DrawTextEx(font, moreMsg, 
                  Vector2{startPos.x + 10, startPos.y + rowsToShow * cellHeight + 5}, 
                  14, 1, GRAY);
    }
}
void ShowInTerminal :: DrawInvisibleManMat(const std::vector<std::pair<bool, std::string>>& evidences, Font font, Vector2 position) {
    float fontSize = 18;
    float spacing = 2;
    float y = position.y;

    DrawTextEx(font, "Invisible Man Mat:", {position.x, y}, fontSize, spacing, GOLD);
    y += fontSize + 6;

    float boxWidth = 250;
    float boxHeight = evidences.size() * (fontSize + 4) + 10;
    DrawRectangle(position.x - 10, y - 6, boxWidth, boxHeight, Fade(BEIGE, 0.7f));
    DrawRectangleLinesEx({position.x - 10, y - 6, boxWidth, boxHeight}, 2, DARKBROWN);

    for (const auto& e : evidences) {
        std::string line = e.second + " : ";
        line += (e.first ? u8"\u2713" : u8"\u2717");
        DrawTextEx(font, line.c_str(), {position.x, y}, fontSize, spacing, VIOLET);
        y += fontSize + 4;
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
    DrawRectangleLinesEx({position.x - 10, position.y - 10, 280, boxHeight}, 2 ,MAROON);
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
// void ShowInTerminal::DrawCharactersOnMap(
//     const std::vector<std::shared_ptr<Hero>>& heroes,
//     const std::vector<std::shared_ptr<Monster>>& monsters,
//     const std::vector<std::shared_ptr<Villager>>& villagers,
//     float scale)
// {
    
//     for (const auto& h : heroes) {
//         auto posIt = locationPositions.find(h->getLocation()->GetCityName());
//         auto iconIt = heroTextures.find(h->getName());
//         if (posIt != locationPositions.end() && iconIt != heroTextures.end()) {
//             Vector2 offset = {0, 0}; // بدون افست
//             DrawTextureEx(iconIt->second, Vector2Add(posIt->second, offset), 0.0f, scale, WHITE);
//         }
//     }

//     for (const auto& m : monsters) {
//         auto posIt = locationPositions.find(m->GetLocation()->GetCityName());
//         auto iconIt = monsterTextures.find(m->GetName());
//         if (posIt != locationPositions.end() && iconIt != monsterTextures.end()) {
//             Vector2 offset = {25, 20}; // یه کم پایین‌تر
//             DrawTextureEx(iconIt->second, Vector2Add(posIt->second, offset), 0.0f, scale, WHITE);
//         }
//     }

//     for (const auto& v : villagers) {
//         if(v->getCurrentLocation()){
//         auto posIt = locationPositions.find(v->getCurrentLocation()->GetCityName());
//         auto iconIt = villagerTextures.find(v->getName());
//         if (posIt != locationPositions.end() && iconIt != villagerTextures.end()) {
//             Vector2 offset = {15, -20}; // بالاتر از بقیه
//             DrawTextureEx(iconIt->second, Vector2Add(posIt->second, offset), 0.0f, scale, WHITE);
//         }}
//     }
// }
// void ShowInTerminal::DrawCharactersOnMap( *****
//     const std::vector<std::shared_ptr<Hero>>& heroes,
//     const std::vector<std::shared_ptr<Monster>>& monsters,
//     const std::vector<std::shared_ptr<Villager>>& villagers,
//     float scale,
//     Vector2 offset)
// {
//     std::map<std::string, int> slotOffset; // برای جلوگیری از هم‌پوشانی

//     auto drawCharacter = [&](std::string location, Texture2D& texture) {
//         if (locationPositions.count(location)) {
//             Vector2 basePos = locationPositions[location];
//             basePos = Vector2Add(Vector2Scale(basePos, scale), offset);

//             int index = slotOffset[location]++;
//             basePos.x += index * 15; // فاصله افقی بین آیتم‌ها
//             basePos.y += index * 10; // فاصله عمودی برای هم‌پوشانی کمتر

//             DrawTextureEx(texture, basePos, 0.0f, scale, WHITE);
//         }
//     };

//     for (const auto& h : heroes)
//         drawCharacter(h->getLocation()->GetCityName(), heroTextures[h->getName()]);

//     for (const auto& m : monsters)
//         drawCharacter(m->GetLocation()->GetCityName(), monsterTextures[m->GetName()]);

//     for (const auto& v : villagers){
//         if (v->getCurrentLocation())
//          drawCharacter(v->getCurrentLocation()->GetCityName(), villagerTextures[v->getName()]);
//     }
       
// }
void ShowInTerminal :: DrawLocationOverview(const std::unordered_map<std::string, std::shared_ptr<Location>>& locations,
                          const std::vector<std::shared_ptr<Monster>>& monsters,
                          const std::vector<std::shared_ptr<Villager>>& villagers,
                          const std::vector<std::shared_ptr<Item>>& items,
                          const std::vector<std::shared_ptr<Hero>>& heroes,
                          Font font, Vector2 startPos) {
    float rowHeight = 24;
    float spacing = 2;
    float y = startPos.y;

    float colWidths[5] = {130, 170, 130, 170, 130};
    const char* headers[] = {"Location", "Items", "Monsters", "Villagers", "Heroes"};


    float x = startPos.x;
    for (int i = 0; i < 5; i++) {
        DrawTextEx(font, headers[i], {x, y}, 18, spacing, GOLD);
        x += colWidths[i];
    }
    y += rowHeight;


    for (const auto& [name, loc] : locations) {
        x = startPos.x;


        DrawTextEx(font, loc->GetCityName().c_str(), {x, y}, 16, spacing, WHITE);
        x += colWidths[0];


        float itemX = x;
        bool hasItem = false;
        for (auto& i : items) {
            if (i->getLocation() == loc) {
                std::string str = i->getName() + "(" + std::to_string(i->getPower()) + ")";
                Color c = (i->getColor() == ItemColor::Red) ? RED :
                          (i->getColor() == ItemColor::Yellow) ? YELLOW : SKYBLUE;
                DrawTextEx(font, str.c_str(), {itemX, y}, 16, spacing, c);
                itemX += MeasureTextEx(font, str.c_str(), 16, spacing).x + 10;
                hasItem = true;
            }
        }
        if (!hasItem)
            DrawTextEx(font, "-", {x, y}, 16, spacing, DARKGRAY);
        x += colWidths[1];

    
        float monsterX = x;
        bool hasMonster = false;
        for (auto& m : monsters) {
            if (m->GetLocation() == loc) {
                std::string name = m->GetName();
                if (m->GetFrenzyMarker()) name += "*";
                DrawTextEx(font, name.c_str(), {monsterX, y}, 16, spacing, RED);
                monsterX += MeasureTextEx(font, name.c_str(), 16, spacing).x + 10;
                hasMonster = true;
            }
        }
        if (!hasMonster)
            DrawTextEx(font, "-", {x, y}, 16, spacing, DARKGRAY);
        x += colWidths[2];

        float villagerX = x;
        bool hasVillager = false;
        for (auto& v : villagers) {
            if (v->getCurrentLocation() == loc) {
                std::string name = v->getName() + "(" + v->getSafeLocation()->GetCityName() + ")";
                DrawTextEx(font, name.c_str(), {villagerX, y}, 16, spacing, LIME);
                villagerX += MeasureTextEx(font, name.c_str(), 16, spacing).x + 10;
                hasVillager = true;
            }
        }
        if (!hasVillager)
            DrawTextEx(font, "-", {x, y}, 16, spacing, DARKGRAY);
        x += colWidths[3];

        float heroX = x;
        bool hasHero = false;
        for (auto& h : heroes) {
            if (h->getLocation() == loc) {
                DrawTextEx(font, h->getName().c_str(), {heroX, y}, 16, spacing, GRAY);
                heroX += MeasureTextEx(font, h->getName().c_str(), 16, spacing).x + 10;
                hasHero = true;
            }
        }
        if (!hasHero)
            DrawTextEx(font, "-", {x, y}, 16, spacing, DARKGRAY);

        
        y += rowHeight;
    }

    DrawRectangleLinesEx({startPos.x - 10, startPos.y - 10, 730, y - startPos.y + 20}, 2, Fade(DARKGRAY, 0.5f));
}

// int ShowInTerminal :: ShowHeroPhase(Game& game, const std::vector<std::string>& options) {
//     int selected = -1;

//     float scaleY = (float)GetScreenHeight() / 772.0f;
//     Vector2 mapPos = {0, 0};

//     Rectangle optionRects[options.size()];
//     float buttonWidth = 180;
//     float buttonHeight = 40;
//     float spacing = 15;
//     float totalHeight = options.size() * (buttonHeight + spacing);
//     float startY = GetScreenHeight() - totalHeight - 20;

//     for (int i = 0; i < options.size(); i++) {
//         float x = (GetScreenWidth() - buttonWidth) / 2;
//         float y = startY + i * (buttonHeight + spacing);
//         optionRects[i] = {x, y, buttonWidth, buttonHeight};
//     }

//     std::shared_ptr<MonsterCard> dummyMonsterCard = std::make_shared<MonsterCard>("Dummy", 0, "", MonsterStrike("", 0, 0));

//     while (!WindowShouldClose()) {
//         Vector2 mouse = GetMousePosition();

//         BeginDrawing();
//         ClearBackground(BLACK);

//         // map
//         DrawTexturePro(mapTexture, {0, 0, (float)mapTexture.width, (float)mapTexture.height},
//                        {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
//                        {0, 0}, 0.0f, WHITE);
//         DrawCharactersOnMap(game.heroes , game.Monsters, game.villagers , 0.6f);

//         DrawTerrorLevel(game.terrorLevel, font, {30, 20});

//         if (game.heroPlayer)
//             DrawHeroInfo(game.heroPlayer, font, {550, 20});

//         if (game.heroPlayer && game.heroPlayer->PeekPerkCard())
//             DrawPerkCard(game.heroPlayer->PeekPerkCard(), font, {550, 200});


//         DrawMonsterCard(dummyMonsterCard, font, {550, 340});

    
//         if (auto dracula = game.GetDracula())
//             DrawDraculaMat(game, {500, 60});

        
//         if (auto invisible = game.GetInvisibleMan())
//             DrawInvisibleManMat(invisible->GetEvidence(), font, {550, 460});

    
//         // DrawItemsList(game.GetItemsInGame(), font, {550, 620});

    
//         DrawLocationOverview(game.getMapPlan().getLocations(), game.Monsters,
//                              game.villagers, game.GetItemsInGame(), game.heroes,
//                              font, {30, 280});

    
//         for (int i = 0; i < options.size(); i++) {
//             bool hover = CheckCollisionPointRec(mouse, optionRects[i]);
//             DrawRectangleRounded(optionRects[i], 0.3f, 10, hover ? GRAY : DARKGRAY);
//             int tw = MeasureText(options[i].c_str(), 20);
//             DrawText(options[i].c_str(), optionRects[i].x + (buttonWidth - tw) / 2,
//                      optionRects[i].y + 10, 20, WHITE);
//         }

//         EndDrawing();

    
//         if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//             for (int i = 0; i < options.size(); i++) {
//                 if (CheckCollisionPointRec(mouse, optionRects[i])) {
//                     selected = i;
//                     return selected;
//                 }
//             }
//         }
//     }

//     return selected;
// }
// int ShowInTerminal::ShowHeroPhase(Game& game, const std::vector<std::string>& options) {
//     int selected = -1;

//     float mapScale = 0.6f;
//     float mapDrawWidth = mapTexture.width * mapScale;
//     float mapDrawHeight = mapTexture.height * mapScale;

//     Vector2 mapPos;
//     mapPos.x = (GetScreenWidth() - mapDrawWidth) / 2;
//     mapPos.y = (GetScreenHeight() - mapDrawHeight) / 2;

//     Rectangle optionRects[options.size()];
//     float buttonWidth = 180;
//     float buttonHeight = 40;
//     float spacing = 15;
//     float totalHeight = options.size() * (buttonHeight + spacing);
//     float startY = GetScreenHeight() - totalHeight - 20;

//     for (int i = 0; i < options.size(); i++) {
//         float x = (GetScreenWidth() - buttonWidth) / 2;
//         float y = startY + i * (buttonHeight + spacing);
//         optionRects[i] = {x, y, buttonWidth, buttonHeight};
//     }

//     std::shared_ptr<MonsterCard> dummyMonsterCard = std::make_shared<MonsterCard>("Dummy", 0, "", MonsterStrike("", 0, 0));

//     while (!WindowShouldClose()) {
//         Vector2 mouse = GetMousePosition();

//         BeginDrawing();
//         ClearBackground(BLACK);

//         // 🗺 Draw scaled & centered map
//         DrawTexturePro(
//             mapTexture,
//             {0, 0, (float)mapTexture.width, (float)mapTexture.height},
//             {mapPos.x, mapPos.y, mapDrawWidth, mapDrawHeight},
//             {0, 0}, 0.0f, WHITE
//         );

//         // 🧍 Characters on map (scaled)
//         DrawCharactersOnMap(game.heroes, game.Monsters, game.villagers, mapScale, mapPos);

//         // 📊 UI Elements around the map
//         DrawTerrorLevel(game.terrorLevel, font, {30, 20});

//         if (game.heroPlayer)
//             DrawHeroInfo(game.heroPlayer, font, {30, 100});

//         if (game.heroPlayer && game.heroPlayer->PeekPerkCard())
//             DrawPerkCard(game.heroPlayer->PeekPerkCard(), font, {30, 280});

//         DrawMonsterCard(dummyMonsterCard, font, {30, 420});

//         if (auto dracula = game.GetDracula())
//             DrawDraculaMat(game, {(float)GetScreenWidth() - 400, 60});

//         if (auto invisible = game.GetInvisibleMan())
//             DrawInvisibleManMat(invisible->GetEvidence(), font, {(float)GetScreenWidth() - 400, 400});

//         // 🔍 Draw Location Overview (optional)
//         // DrawLocationOverview(game.getMapPlan().getLocations(), game.Monsters,
//         //                     game.villagers, game.GetItemsInGame(), game.heroes,
//         //                     font, {30, 600});

//         // 🎮 Options
//         for (int i = 0; i < options.size(); i++) {
//             bool hover = CheckCollisionPointRec(mouse, optionRects[i]);
//             DrawRectangleRounded(optionRects[i], 0.3f, 10, hover ? GRAY : DARKGRAY);
//             int tw = MeasureText(options[i].c_str(), 20);
//             DrawText(options[i].c_str(), optionRects[i].x + (buttonWidth - tw) / 2,
//                      optionRects[i].y + 10, 20, WHITE);
//         }

//         EndDrawing();

//         // 🔘 Click Handling
//         if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//             for (int i = 0; i < options.size(); i++) {
//                 if (CheckCollisionPointRec(mouse, optionRects[i])) {
//                     selected = i;
//                     return selected;
//                 }
//             }
//         }
//     }

//     return selected;
// // }
// int ShowInTerminal::ShowHeroPhase(Game& game, const std::vector<std::string>& options) { ****
//     int selected = -1;

//     // تنظیمات جدید برای نقشه کوچکتر
//     float mapScale = 0.3f;  // مقیاس کوچکتر
//     float mapDrawWidth = mapTexture.width * mapScale;
//     float mapDrawHeight = mapTexture.height * mapScale;

//     // موقعیت نقشه (کاملاً وسط صفحه)
//     Vector2 mapPos;
//     mapPos.x = (GetScreenWidth() - mapDrawWidth) / 2;
//     mapPos.y = (GetScreenHeight() - mapDrawHeight) / 2 - 50; // 50 پیکسل بالاتر از مرکز واقعی

//     // تنظیمات جدید برای دکمه‌ها
//     const int buttonsPerRow = 5;  // پنج دکمه در هر ردیف
//     const float buttonWidth = 130; // عرض کمتر
//     const float buttonHeight = 35; // ارتفاع کمتر
//     const float spacing = 10;     // فاصله بین دکمه‌ها
//     const Color buttonColor = {70, 70, 100, 255}; // رنگ آبی تیره
//     const Color hoverColor = {100, 100, 150, 255}; // رنگ آبی روشن هنگام هاور

//     // محاسبه موقعیت دکمه‌ها (دو ردیف پنجتایی)
//     Rectangle optionRects[options.size()];
//     for (int i = 0; i < options.size(); i++) {
//         int row = i / buttonsPerRow;
//         int col = i % buttonsPerRow;
        
//         float totalWidth = buttonsPerRow * buttonWidth + (buttonsPerRow - 1) * spacing;
//         float x = (GetScreenWidth() - totalWidth) / 2 + col * (buttonWidth + spacing);
//         float y = GetScreenHeight() - 120 + row * (buttonHeight + spacing); // 120 پیکسل از پایین
//         optionRects[i] = {x, y, buttonWidth, buttonHeight};
//     }

//     std::shared_ptr<MonsterCard> dummyMonsterCard = std::make_shared<MonsterCard>("Dummy", 0, "", MonsterStrike("", 0, 0));

//     while (!WindowShouldClose()) {
//         Vector2 mouse = GetMousePosition();

//         BeginDrawing();
//         ClearBackground(BLACK);

//         // 🗺 نقشه با اندازه کوچک و کاملاً وسط
//         DrawTexturePro(
//             mapTexture,
//             {0, 0, (float)mapTexture.width, (float)mapTexture.height},
//             {mapPos.x, mapPos.y, mapDrawWidth, mapDrawHeight},
//             {0, 0}, 0.0f, WHITE
//         );

//         // 🧍 کاراکترها روی نقشه
//         DrawCharactersOnMap(game.heroes, game.Monsters, game.villagers, mapScale, mapPos);

//         // 📊 عناصر UI اطراف نقشه
//         DrawTerrorLevel(game.terrorLevel, font, {30, 20});

//         if (game.heroPlayer)
//             DrawHeroInfo(game.heroPlayer, font, {30, 60});

//         if (game.heroPlayer && game.heroPlayer->PeekPerkCard())
//             DrawPerkCard(game.heroPlayer->PeekPerkCard(), font, {30, 220});

//         DrawMonsterCard(dummyMonsterCard, font, {30, 360});

//       //  if (auto dracula = game.GetDracula())
//          //   DrawDraculaMat(game, {(float)GetScreenWidth() - 350, 60});

//         if (auto invisible = game.GetInvisibleMan())
//             DrawInvisibleManMat(invisible->GetEvidence(), font, {(float)GetScreenWidth() - 350, 300});

//         // 🎮 دکمه‌ها (دو ردیف پنجتایی)
//         for (int i = 0; i < options.size(); i++) {
//             bool hover = CheckCollisionPointRec(mouse, optionRects[i]);
//             DrawRectangleRounded(optionRects[i], 0.3f, 8, hover ? hoverColor : buttonColor);
            
//             // متن وسط‌چین شده در دکمه
//             const char* text = options[i].c_str();
//             int fontSize = 16;
//             int tw = MeasureText(text, fontSize);
            
//             // اگر متن طولانی بود، فونت کوچک شود
//             while (tw > buttonWidth - 10 && fontSize > 12) {
//                 fontSize--;
//                 tw = MeasureText(text, fontSize);
//             }
            
//             DrawText(text, 
//                     optionRects[i].x + (buttonWidth - tw) / 2,
//                     optionRects[i].y + (buttonHeight - fontSize) / 2, 
//                     fontSize, WHITE);
//         }

//         EndDrawing();

//         // 🔘 پردازش کلیک
//         if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//             for (int i = 0; i < options.size(); i++) {
//                 if (CheckCollisionPointRec(mouse, optionRects[i])) {
//                     selected = i;
//                     return selected;
//                 }
//             }
//         }
//     }

//     return selected;
// }
void ShowInTerminal::DrawCharactersOnMap(
    const std::vector<std::shared_ptr<Hero>>& heroes,
    const std::vector<std::shared_ptr<Monster>>& monsters,
    const std::vector<std::shared_ptr<Villager>>& villagers,
    float scale,
    Vector2 offset)
{
    std::map<std::string, int> slotOffset; // برای جلوگیری از هم‌پوشانی

    auto drawCharacter = [&](std::string location, Texture2D& texture) {
        if (locationPositions.count(location)) {
            Vector2 basePos = locationPositions[location];
            // تغییرات اصلی اینجا اعمال شده:
            basePos = Vector2Add(Vector2Scale(basePos, 1.0f/3.0f), offset);

            int index = slotOffset[location]++;
            basePos.x += index * 15 * (1.0f/3.0f); // فاصله افقی با مقیاس جدید
            basePos.y += index * 10 * (1.0f/3.0f); // فاصله عمودی با مقیاس جدید

            DrawTextureEx(texture, basePos, 0.0f, 1.0f, WHITE); // مقیاس بافت 1.0
        }
    };

    for (const auto& h : heroes)
        drawCharacter(h->getLocation()->GetCityName(), heroTextures[h->getName()]);

    for (const auto& m : monsters)
        drawCharacter(m->GetLocation()->GetCityName(), monsterTextures[m->GetName()]);

    for (const auto& v : villagers){
        if (v->getCurrentLocation())
            drawCharacter(v->getCurrentLocation()->GetCityName(), villagerTextures[v->getName()]);
    }
}

int ShowInTerminal::ShowHeroPhase(Game& game, const std::vector<std::string>& options) {
    int selected = -1;

    // تنظیمات جدید برای نقشه کوچکتر
    float mapScale = 4.0f;  // مقیاس 3 برای کوچک کردن نقشه
    float mapDrawWidth = mapTexture.width / mapScale; // تقسیم بر مقیاس
    float mapDrawHeight = mapTexture.height / mapScale; // تقسیم بر مقیاس

    // موقعیت نقشه (کاملاً وسط صفحه)
    Vector2 mapPos;
    mapPos.x = (GetScreenWidth() - mapDrawWidth) / 2;
    mapPos.y = (GetScreenHeight() - mapDrawHeight) / 2 - 50; // 50 پیکسل بالاتر از مرکز واقعی

    // تنظیمات جدید برای دکمه‌ها
    const int buttonsPerRow = 5;  // پنج دکمه در هر ردیف
    const float buttonWidth = 130; // عرض کمتر
    const float buttonHeight = 35; // ارتفاع کمتر
    const float spacing = 10;     // فاصله بین دکمه‌ها
    const Color buttonColor = {70, 70, 100, 255}; // رنگ آبی تیره
    const Color hoverColor = {100, 100, 150, 255}; // رنگ آبی روشن هنگام هاور

    // محاسبه موقعیت دکمه‌ها (دو ردیف پنجتایی)
    Rectangle optionRects[options.size()];
    for (int i = 0; i < options.size(); i++) {
        int row = i / buttonsPerRow;
        int col = i % buttonsPerRow;
        
        float totalWidth = buttonsPerRow * buttonWidth + (buttonsPerRow - 1) * spacing;
        float x = (GetScreenWidth() - totalWidth) / 2 + col * (buttonWidth + spacing);
        float y = GetScreenHeight() - 120 + row * (buttonHeight + spacing); // 120 پیکسل از پایین
        optionRects[i] = {x, y, buttonWidth, buttonHeight};
    }

    std::shared_ptr<MonsterCard> dummyMonsterCard = std::make_shared<MonsterCard>("Dummy", 0, "", MonsterStrike("", 0, 0));

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();

        BeginDrawing();
        ClearBackground(BLACK);

        // 🗺 نقشه با اندازه کوچک و کاملاً وسط
        DrawTexturePro(
            mapTexture,
            {0, 0, (float)mapTexture.width, (float)mapTexture.height},
            {mapPos.x, mapPos.y, mapDrawWidth, mapDrawHeight},
            {0, 0}, 0.0f, WHITE
        );

        // 🧍 کاراکترها روی نقشه (با مقیاس معکوس 1/3)
       // DrawCharactersOnMap(game.heroes, game.Monsters, game.villagers, 1.0f/mapScale, mapPos);

        // 📊 عناصر UI اطراف نقشه
        DrawTerrorLevel(game.terrorLevel, font, {30, 20});
        
         if (auto dracula = game.GetDracula())
             DrawDraculaMat(game, {(float)GetScreenWidth() - 190.0f , 40.0f });

        if (game.heroPlayer)
            DrawHeroInfo(game.heroPlayer, font, {30, 60});

        if (game.heroPlayer && game.heroPlayer->PeekPerkCard())
            DrawPerkCard(game.heroPlayer->PeekPerkCard(), font, {30, 220});

        DrawMonsterCard(dummyMonsterCard, font, {30, 360});if (auto invisible = game.GetInvisibleMan())
            DrawInvisibleManMat(invisible->GetEvidence(), font, {(float)GetScreenWidth() - 350, 300});

        // 🎮 دکمه‌ها (دو ردیف پنجتایی)
        for (int i = 0; i < options.size(); i++) {
            bool hover = CheckCollisionPointRec(mouse, optionRects[i]);
            DrawRectangleRounded(optionRects[i], 0.3f, 8, hover ? hoverColor : buttonColor);
            
            // متن وسط‌چین شده در دکمه
            const char* text = options[i].c_str();
            int fontSize = 16;
            int tw = MeasureText(text, fontSize);
            
            // اگر متن طولانی بود، فونت کوچک شود
            while (tw > buttonWidth - 10 && fontSize > 12) {
                fontSize--;
                tw = MeasureText(text, fontSize);
            }
            
            DrawText(text, 
                    optionRects[i].x + (buttonWidth - tw) / 2,
                    optionRects[i].y + (buttonHeight - fontSize) / 2, 
                    fontSize, WHITE);
        }

        EndDrawing();

        // 🔘 پردازش کلیک
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
void ShowInTerminal :: ShowMonsterPhase(Game& game) {
    if (game.MonsterDeck.empty()) return;

    std::shared_ptr<MonsterCard> monsterCard = game.MonsterDeck.back();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawMonsterCard(monsterCard, font, {40, 40});

        DrawLocationOverview(game.getMapPlan().getLocations(),
                             game.Monsters,
                             game.villagers,
                             game.GetItemsInGame(),
                             game.heroes,
                             font, {40, 220});

        DrawTextEx(font, "Press SPACE to continue...", {260, 550}, 18, 2, WHITE);

        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)) break;
    }
}
    