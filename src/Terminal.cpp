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

void ShowInTerminal :: LoadAssets(){
    //Heroes
    heroTextures["Mayor"] = LoadTexture("assets/Heros/Mayor.png");
    heroTextures["Archaeologist"] = LoadTexture("assets/Heros/Arshaeologist.png");
    heroTextures["Courier"] = LoadTexture("assets/Heros/Courier.png");
    heroTextures["Scientist"] = LoadTexture("assets/Heros/Scientits.png");

    //Monsters
    monsterTextures["Dracula"] = LoadTexture("assets/Monsters/Dracula.png");
    monsterTextures["InvisibleMan"] = LoadTexture("assets/Monsters/InvisibleMan.png");

    //Villagers
    villagerTextures["DrCranley"] = LoadTexture("assets/Villager/DrCranley.png");
    villagerTextures["DrReed"] = LoadTexture("assets/Villager/DrReed.png");
    villagerTextures["ProfPearson"] = LoadTexture("assets/Villager/ProfPearson.png");
    villagerTextures["Maleva"] = LoadTexture("assets/Villager/Maleva.png");
    villagerTextures["Fritz"] = LoadTexture("assets/Villager/Fritz.png");
    villagerTextures["WilburAndChick"] = LoadTexture("assets/Villager/WilburAndChick.png");
    villagerTextures["Maria"] = LoadTexture("assets/Villager/Maria.png");

    //Items
    //Yellow
    itemTextures["Flower"] = LoadTexture("assets/Items/Yellow/Flower.png");
    itemTextures["TarotDeck"] = LoadTexture("assets/Items/Yellow/Tarot.png");
    itemTextures["Garlic"] = LoadTexture("assets/Items/Yellow/Garlic.png");
    itemTextures["MirroredBox"] = LoadTexture("assets/Items/Yellow/Mirrored_Box.png");
    itemTextures["Stake"] = LoadTexture("assets/Items/Yellow/Stake.png");
    itemTextures["ScrollOfThoth"] = LoadTexture("assets/Items/Yellow/Scroll.png");
    itemTextures["Violin"] = LoadTexture("assets/Items/Yellow/Violin.png");
    itemTextures["Tablet"] = LoadTexture("assets/Items/Yellow/Tablet.png");
    itemTextures["Wolfsbane"] = LoadTexture("assets/Items/Yellow/Wolfsbane.png");
    itemTextures["Charm"] = LoadTexture("assets/Items/Yellow/Charm.png");
    //Red
    itemTextures["Dart"] = LoadTexture("assets/Items/Red/Dart.png");
    itemTextures["FirePoker"] = LoadTexture("assets/Items/Red/FirePoker.png");
    itemTextures["Rapier"] = LoadTexture("assets/Items/Red/Rapier.png");
    itemTextures["Shovel"] = LoadTexture("assets/Items/Red/Shovel.png");
    itemTextures["Torch"] = LoadTexture("assets/Items/Red/Torch.png");
    itemTextures["Pitchfork"] = LoadTexture("assets/Items/Red/Pitchfork.png");
    itemTextures["Rifle"] = LoadTexture("assets/Items/Red/Rifle.png");
    itemTextures["SilverCane"] = LoadTexture("assets/Items/Red/SilverCane.png");
    itemTextures["Knife"] = LoadTexture("assets/Items/Red/Knife.png");
    itemTextures["Pistol"] = LoadTexture("assets/Items/Red/Pistol.png");
    itemTextures["BearTrap"] = LoadTexture("assets/Items/Red/BearTrap.png");
    itemTextures["Speargun"] = LoadTexture("assets/Items/Red/Speargun.png");
    //Blue
    itemTextures["AnatomyTest"] = LoadTexture("assets/Items/Blue/AnatomyTest.png");
    itemTextures["Contrifuge"] = LoadTexture("assets/Items/Blue/Centrifuge.png");
    itemTextures["Kite"] = LoadTexture("assets/Items/Blue/Kite.png");
    itemTextures["Research"] = LoadTexture("assets/Items/Blue/Research.png");
    itemTextures["Telescope"] = LoadTexture("assets/Items/Blue/Telescope.png");
    itemTextures["Searchlight"] = LoadTexture("assets/Items/Blue/Searchlight.png");
    itemTextures["Experiment"] = LoadTexture("assets/Items/Blue/Experiments.png");
    itemTextures["Analysis"] = LoadTexture("assets/Items/Blue/Analysis.png");
    itemTextures["Rotenone"] = LoadTexture("assets/Items/Blue/Rotenone.png");
    itemTextures["CosmicRayDiffuser"] = LoadTexture("assets/Items/Blue/CosmicRayDiffuser.png");
    itemTextures["Nebularium"] = LoadTexture("assets/Items/Blue/Nebularium.png");
    itemTextures["MonocaneMixture"] = LoadTexture("assets/Items/Blue/MonocaneMixture.png");
    itemTextures["Fossil"] = LoadTexture("assets/Items/Blue/Fossil.png");

    //Perks
    perkTextures["VisitFromDetective"] = LoadTexture("assets/Perk_Cards/VisitFromTheDetective.png");
    perkTextures["BreakOfDown"] = LoadTexture("assets/Perk_Cards/BreakOfDown.png");
    perkTextures["OverStock"] = LoadTexture("assets/Perk_Cards/Overstock.png");
    perkTextures["LateIntoTheNight"] = LoadTexture("assets/Perk_Cards/LateIntoTheNight.png");
    perkTextures["Repel"] = LoadTexture("assets/Perk_Cards/Repel.png");
    perkTextures["Hurry"] = LoadTexture("assets/Perk_Cards/Hurry.png");

    //MonsterCards
    monsterCardTextures["FromTheBat"] = LoadTexture("assets/Monster_Cards/FromOfTheBat.png");
    monsterCardTextures["Sunrise"] = LoadTexture("assets/Monster_Cards/Sunrise.png");
    monsterCardTextures["Thief"] = LoadTexture("assets/Monster_Cards/Thief.png");
    monsterCardTextures["TheDelivery"] = LoadTexture("assets/Monster_Cards/TheDelivery.png");
    monsterCardTextures["FortuneTeller"] = LoadTexture("assets/Monster_Cards/FortuneTeller.png");
    monsterCardTextures["FormerEmployer"] = LoadTexture("assets/Monster_Cards/FomerEmployer.png");
    monsterCardTextures["HurriedAssistant"] = LoadTexture("assets/Monster_Cards/HurriedAssistant.png");
    monsterCardTextures["TheInnocent"] = LoadTexture("assets/Monster_Cards/TheInnocent.png");
    monsterCardTextures["EgyptianExpert"] = LoadTexture("assets/Monster_Cards/EgyptianExpert.png");
    monsterCardTextures["TheIchthyologist"] = LoadTexture("assets/Monster_Cards/TheIchtyologist.png");
    monsterCardTextures["OnTheMove"] = LoadTexture("assets/Monster_Cards/OnTheMove.png");
    monsterCardTextures["HypnoticGaze"] = LoadTexture("assets/Monster_Cards/HypnoticGaze.png");

    //MonsterMats
    monstermatTextures["Dracula"] = LoadTexture("assets/Monster_Mat/DraculaMat.png");
    monstermatTextures["InvisibleMan"] = LoadTexture("assets/Monster_Mat/InvisibleManMat.png");

    //Backgrounds
    backgroundTextures["menu"] = LoadTexture("assets/Background/Background1.png");
    backgroundTextures["input"] = LoadTexture("assets/Background/Background2.png");
    backgroundTextures["exit"] = LoadTexture("assets/Background/Background3.png");
    backgroundTextures["back"] = LoadTexture("assets/Background/Background4.png");

    //Map
    mapTexture = LoadTexture("assets/map.png");

    //Font
    font = LoadFont("assets/Fonts/Creepster.ttf");

    //Coffin
    coffinBrokenTexture = LoadTexture("assets/Items/coffins/SmashedCoffin.png");
    coffinIntactTexture = LoadTexture("assets/Items/coffins/Coffin.png");
    

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

void ShowInTerminal :: DrawDraculaMat(const std::vector<std::pair<bool, std::string>>& coffins, Vector2 startPos) {
    DrawTexture(monstermatTextures["Dracula"], startPos.x, startPos.y, WHITE);

    float offsetX = 40;
    float spacing = 150;

    for (size_t i = 0; i < coffins.size(); ++i) {
        
        std::string locationName = coffins[i].second;
        DrawTextEx(font, locationName.c_str(), { startPos.x + offsetX + i * spacing, startPos.y + 100 }, 18, 1, BLACK);

        
        Texture2D& tex = coffins[i].first ? coffinBrokenTexture : coffinIntactTexture;
        DrawTexture(tex, startPos.x + offsetX + i * spacing, startPos.y + 130, WHITE);
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

int ShowInTerminal :: ShowHeroPhase(Game& game, const std::vector<std::string>& options, Texture2D mapTexture, Font font) {
    int selected = -1;

    float scaleY = (float)GetScreenHeight() / 772.0f;
    Vector2 mapPos = {0, 0};

    Rectangle optionRects[options.size()];
    float buttonWidth = 180;
    float buttonHeight = 40;
    float spacing = 15;
    float totalHeight = options.size() * (buttonHeight + spacing);
    float startY = GetScreenHeight() - totalHeight - 20;

    for (int i = 0; i < options.size(); i++) {
        float x = (GetScreenWidth() - buttonWidth) / 2;
        float y = startY + i * (buttonHeight + spacing);
        optionRects[i] = {x, y, buttonWidth, buttonHeight};
    }

    std::shared_ptr<MonsterCard> dummyMonsterCard = std::make_shared<MonsterCard>("Dummy", 0, "", MonsterStrike("", 0, 0));

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();

        BeginDrawing();
        ClearBackground(BLACK);

        // map
        DrawTexturePro(mapTexture, {0, 0, (float)mapTexture.width, (float)mapTexture.height},
                       {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                       {0, 0}, 0.0f, WHITE);

        DrawTerrorLevel(game.terrorLevel, font, {30, 20});

        if (game.heroPlayer)
            DrawHeroInfo(game.heroPlayer, font, {550, 20});

        if (game.heroPlayer && game.heroPlayer->PeekPerkCard())
            DrawPerkCard(game.heroPlayer->PeekPerkCard(), font, {550, 200});


        DrawMonsterCard(dummyMonsterCard, font, {550, 340});

    
        if (auto dracula = game.GetDracula())
            DrawDraculaMat(dracula->GetCoffins(), font, {30, 460});

        
        if (auto invisible = game.GetInvisibleMan())
            DrawInvisibleManMat(invisible->GetEvidence(), font, {550, 460});

    
        // DrawItemsList(game.GetItemsInGame(), font, {550, 620});

    
        DrawLocationOverview(game.getMapPlan().getLocations(), game.Monsters,
                             game.villagers, game.GetItemsInGame(), game.heroes,
                             font, {30, 280});

    
        for (int i = 0; i < options.size(); i++) {
            bool hover = CheckCollisionPointRec(mouse, optionRects[i]);
            DrawRectangleRounded(optionRects[i], 0.3f, 10, hover ? GRAY : DARKGRAY);
            int tw = MeasureText(options[i].c_str(), 20);
            DrawText(options[i].c_str(), optionRects[i].x + (buttonWidth - tw) / 2,
                     optionRects[i].y + 10, 20, WHITE);
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
void ShowInTerminal :: ShowMonsterPhase(Game& game, Font font) {
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
    