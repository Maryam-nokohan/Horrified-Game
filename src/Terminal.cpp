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
#include <sstream>
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

    DiceBack = LoadTexture("../assets/Items/dice/diceBack.jpg");
    diceFaces[" "] = LoadTexture("../assets/Items/dice/diceEmpty.jpg");
    diceFaces["*"] = LoadTexture("../assets/Items/dice/diceStar.jpg");
    diceFaces["!"] = LoadTexture("../assets/Items/dice/dicePower.jpg");
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
    backgroundTextures["msg"] = LoadTexture("../assets/Background/Background4.png");
    backgroundTextures["phase"] = LoadTexture("../assets/Background/phase1.jpg");
    backgroundTextures["DraculaAttack"] = LoadTexture("../assets/Background/Draculabg.jpg");
    backgroundTextures["InvisibleAttack"] = LoadTexture("../assets/Background/Invisiblebg.jpg");
    backgroundTextures["win"] = LoadTexture("../assets/Background/win.png");
    backgroundTextures["lose"] = LoadTexture("../assets/Background/lose.png");
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

    float r = 20.0f;

    locationBounds[Cave] = {43.0f - r, 133.0f - r, 2 * r, 2 * r};
    locationBounds[Camp] = {123.0f - r, 115.0f - r, 2 * r, 2 * r};
    locationBounds[Precinct] = {219.0f - r, 104.0f - r, 2 * r, 2 * r};
    locationBounds[Inn] = {306.0f - r, 89.0f - r, 2 * r, 2 * r};
    locationBounds[Abbey] = {58.0f - r, 319.0f - r, 2 * r, 2 * r};
    locationBounds[Crypt] = {40.0f - r, 419.0f - r, 2 * r, 2 * r};
    locationBounds[Mansion] = {157.0f - r, 277.0f - r, 2 * r, 2 * r};
    locationBounds[Theater] = {348.0f - r, 198.0f - r, 2 * r, 2 * r};
    locationBounds[Barn] = {415.0f - r, 101.0f - r, 2 * r, 2 * r};
    locationBounds[Tower] = {454.0f - r, 191.0f - r, 2 * r, 2 * r};
    locationBounds[Dungeon] = {502.0f - r, 101.0f - r, 2 * r, 2 * r};
    locationBounds[Docks] = {488.0f - r, 279.0f - r, 2 * r, 2 * r};
    locationBounds[Institute] = {443.0f - r, 495.0f - r, 2 * r, 2 * r};
    locationBounds[Laboratory] = {377.0f - r, 405.0f - r, 2 * r, 2 * r};
    locationBounds[Shop] = {302.0f - r, 342.0f - r, 2 * r, 2 * r};
    locationBounds[Museum] = {126.0f - r, 406.0f - r, 2 * r, 2 * r};
    locationBounds[Church] = {248.0f - r, 431.0f - r, 2 * r, 2 * r};
    locationBounds[Hospital] = {210.0f - r, 497.0f - r, 2 * r, 2 * r};
    locationBounds[Graveyard] = {328.0f - r, 488.0f - r, 2 * r, 2 * r};
}
void ShowInTerminal ::UnloadAssets()
{

    for (auto &[_, tex] : heroTextures)
        UnloadTexture(tex);
    std::cout << "Unloaded heros\n";
    for (auto &[_, tex] : monsterTextures)
        UnloadTexture(tex);
    std::cout << "Unloaded monsters\n";
    for (auto &[_, tex] : villagerTextures)
        UnloadTexture(tex);
    std::cout << "Unloaded villagers\n";
    for (auto &[_, tex] : perkTextures)
        UnloadTexture(tex);
    std::cout << "Unloaded perks\n";
    for (auto &[_, tex] : itemTextures)
        UnloadTexture(tex);
    std::cout << "Unloaded items\n";
    for (auto &[_, tex] : monsterCardTextures)
        UnloadTexture(tex);
    std::cout << "Unloaded monsterdeck\n";
    for (auto &[_, tex] : monstermatTextures)
        UnloadTexture(tex);
    std::cout << "Unloaded monster mat\n";
    for (auto &[_, tex] : backgroundTextures)
        UnloadTexture(tex);
    std::cout << "Unloaded backgrounds\n";
    for (auto &[_, tex] : diceFaces)
        UnloadTexture(tex);
    std::cout << "Unloaded dice faces\n";
    UnloadTexture(mapTexture);
    std::cout << "Unloaded map\n";
    UnloadFont(font);
    std::cout << "Unloaded font\n";
    UnloadTexture(coffinBrokenTexture);
    std::cout << "Unloaded coffin broken\n";
    UnloadTexture(coffinIntactTexture);
    std::cout << "Unloaded coffin intact\n";
    UnloadTexture(frenzyMark);
    std::cout << "Unloaded frenzy mark\n";
    UnloadTexture(DiceBack);
    std::cout << "Unloaded frenzy dice Background\n";
}

void ShowInTerminal::ShowMessageBox(const std::string &message)
{
    const int windowWidth = 900;
    const int windowHeight = 700;

    const float boxWidth = 600;
    const float boxHeight = 150;
    const float boxX = (windowWidth - boxWidth) / 2;
    const float boxY = (windowHeight - boxHeight) / 2 - 30;

    Rectangle box = {boxX, boxY, boxWidth, boxHeight};
    float boxScale = 0.9f;
    float targetScale = 1.0f;

    const float buttonWidth = 200;
    const float buttonHeight = 50;
    const float buttonX = boxX + (boxWidth - buttonWidth) / 2;
    const float buttonY = boxY + boxHeight + 20;
    Rectangle continueButton = {buttonX, buttonY, buttonWidth, buttonHeight};

    Color boxColor = {15, 25, 40, 200};
    Color borderColor = {0, 220, 255, 255};
    Color textColor = {220, 240, 255, 255};
    const Color BUTTON_COLOR = {70, 85, 105, 255};
    const Color BUTTON_BORDER_COLOR = {100, 120, 140, 255};
    const Color HOVER_COLOR = {120, 145, 175, 255};
    const Color TEXT_COLOR_BUTTON = {230, 230, 230, 255};

    bool waiting = true;
    bool buttonPressed = false;

    while (!WindowShouldClose() && waiting)
    {
        UpdateMusicStream(music);
        boxScale += (targetScale - boxScale) * 0.1f;
        Vector2 mousePos = GetMousePosition();
        bool mouseOverButton = CheckCollisionPointRec(mousePos, continueButton);

        if (boxScale > 0.98f && mouseOverButton)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                buttonPressed = true;
            }
            if (buttonPressed && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            {
                waiting = false;
            }
        }

        if (buttonPressed && !mouseOverButton)
        {
            buttonPressed = false;
        }

        BeginDrawing();

        if (backgroundTextures["msg"].id != 0)
        {
            DrawTexturePro(backgroundTextures["msg"],
                           Rectangle{0, 0, (float)backgroundTextures["msg"].width, (float)backgroundTextures["msg"].height},
                           Rectangle{0, 0, (float)windowWidth, (float)windowHeight},
                           Vector2{0, 0}, 0.0f, WHITE);
        }
        else
        {
            DrawRectangleGradientV(0, 0, windowWidth, windowHeight,
                                   Color{240, 240, 250, 255},
                                   Color{200, 200, 220, 255});
        }

        Rectangle scaledBox = {
            box.x + (box.width * (1 - boxScale)) / 2,
            box.y + (box.height * (1 - boxScale)) / 2,
            box.width * boxScale,
            box.height * boxScale};
        DrawRectangleRounded(scaledBox, 0.2f, 16, Fade(boxColor, boxScale));
        DrawRectangleRoundedLines(scaledBox, 0.2f, 16, Fade(borderColor, boxScale));

        int fontSize = 24;
        const float maxTextWidth = boxWidth - 40;
        Vector2 textSize = MeasureTextEx(font, message.c_str(), fontSize, 1.0f);

        if (textSize.x > maxTextWidth)
        {
            std::string wrappedText;
            std::string currentLine;
            std::istringstream iss(message);
            std::string word;
            while (iss >> word)
            {
                if (MeasureTextEx(font, (currentLine + word).c_str(), fontSize, 1.0f).x < maxTextWidth)
                {
                    currentLine += word + " ";
                }
                else
                {
                    wrappedText += currentLine + "\n";
                    currentLine = word + " ";
                }
            }
            wrappedText += currentLine;
            DrawTextEx(font, wrappedText.c_str(),
                       Vector2{scaledBox.x + 20,
                               scaledBox.y + (scaledBox.height - fontSize * (1 + std::count(wrappedText.begin(), wrappedText.end(), '\n'))) / 2},
                       fontSize, 1.0f, Fade(textColor, boxScale));
        }
        else
        {
            DrawTextEx(font, message.c_str(),
                       Vector2{scaledBox.x + (scaledBox.width - textSize.x) / 2,
                               scaledBox.y + (scaledBox.height - textSize.y) / 2},
                       fontSize, 1.0f, Fade(textColor, boxScale));
        }

        if (boxScale > 0.98f)
        {

            Color currentButtonColor = mouseOverButton && buttonPressed ? HOVER_COLOR : (mouseOverButton ? HOVER_COLOR : BUTTON_COLOR);
            DrawRectangleRounded(continueButton, 0.2f, 10, currentButtonColor);
            DrawRectangleRoundedLines(continueButton, 0.2f, 10, mouseOverButton ? SKYBLUE : BUTTON_BORDER_COLOR);

            const char *buttonText = "Continue";
            float buttonFontSize = 20.0f;
            Vector2 buttonTextSize = MeasureTextEx(font, buttonText, buttonFontSize, 1);
            float textX = continueButton.x + (continueButton.width - buttonTextSize.x) / 2;
            float textY = continueButton.y + (continueButton.height - buttonTextSize.y) / 2;
            DrawTextEx(font, buttonText, {textX, textY}, buttonFontSize, 1, TEXT_COLOR_BUTTON);
        }

        EndDrawing();
    }
}
void ShowInTerminal::ShowHelpScreen()
{
    Texture2D bg = backgroundTextures["msg"];
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    Color panelColor = {25, 30, 45, 235};
    Color borderColor = {70, 130, 220, 255};
    Color titleColor = {220, 220, 220, 255};
    Color textColor = {200, 200, 200, 255};
    Color buttonColor = {80, 85, 100, 255};
    Color buttonHoverColor = {100, 110, 130, 255};

    const char *instructionsText =
        "Welcome to the Horrified Game! Here are the basics you need to know:\n\n"
        "1. Goal:\n"
        "   - Work with the other heroes to defeat the monsters (Dracula, Invisible Man, etc.) by\n"
        "     completing their objectives (destroying coffins, collecting evidence, etc.).\n"
        "   - Protect the villagers by guiding them to their safe locations.\n"
        "   - Prevent the terror level from reaching its maximum.\n\n"
        "2. Hero Actions:\n"
        "   - Move: Travel between connected locations.\n"
        "   - Guide: Move villagers from adjacent locations to your location.\n"
        "   - Pick Up: Collect available items at your current location.\n"
        "   - Advance: Perform special tasks like destroying Dracula's coffin.\n"
        "   - Defeat: Attempt to defeat a monster when in the same location.\n"
        "   - Use Perks: Play a perk card for special bonuses.\n"
        "   - Special Action: Perform unique character abilities.\n\n"
        "3. Monsters:\n"
        "   - Each monster has unique abilities and special tasks required to defeat them.\n"
        "   - Monsters move and attack every monster phase.\n\n"
        "4. Terror Level:\n"
        "   - The terror level increases when monsters kill heroes or villagers.\n"
        "   - If the terror level reaches the maximum, you lose the game.\n\n"
        "5. Win the Game:\n"
        "   - Complete the objectives for all monsters.\n\n"
        "Remember:\n"
        "   - Plan your moves strategically.\n"
        "   - Protect the villagers.\n"
        "   - Use your perk cards wisely.\n"
        "   - Defeat the monsters and save the town!\n\n"
        "Good luck, hero!";

    std::vector<std::string> lines;
    std::stringstream ss(instructionsText);
    std::string line;
    while (std::getline(ss, line, '\n'))
    {
        lines.push_back(line);
    }

    float padding = 50.0f;
    Rectangle panelRec = {padding, padding, screenWidth - (padding * 2), screenHeight - (padding * 2)};
    Rectangle backButtonRec = {screenWidth / 2.0f - 100, panelRec.y + panelRec.height - 60, 200, 45};

    float scrollY = 0.0f;
    float textFontSize = 18.0f;
    float textLineSpacing = 10.0f;
    float totalTextHeight = lines.size() * (textFontSize + textLineSpacing);
    Rectangle viewArea = {panelRec.x + 30, panelRec.y + 80, panelRec.width - 60, panelRec.height - 150};

    bool backClicked = false;
    while (!WindowShouldClose() && !backClicked)
    {
        UpdateMusicStream(music);

        Vector2 mousePos = GetMousePosition();
        bool isMouseOverButton = CheckCollisionPointRec(mousePos, backButtonRec);

        if (isMouseOverButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            backClicked = true;
        }

        float wheelMove = GetMouseWheelMove();
        if (wheelMove != 0)
        {
            scrollY += wheelMove * 20;
            if (scrollY > 0)
                scrollY = 0;
            if (scrollY < viewArea.height - totalTextHeight)
                scrollY = viewArea.height - totalTextHeight;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height}, {0, 0, (float)screenWidth, (float)screenHeight}, {0, 0}, 0.0f, DARKGRAY);
        DrawRectangleRec(panelRec, panelColor);
        DrawRectangleLinesEx(panelRec, 3.0f, borderColor);

        const char *titleText = "INSTRUCTIONS";
        float titleFontSize = 32.0f;
        Vector2 titleSize = MeasureTextEx(font, titleText, titleFontSize, 2);
        DrawTextEx(font, titleText, {screenWidth / 2.0f - titleSize.x / 2, panelRec.y + 25}, titleFontSize, 2, titleColor);

        BeginScissorMode(viewArea.x, viewArea.y, viewArea.width, viewArea.height);

        float currentY = viewArea.y + scrollY;
        for (const auto &textLine : lines)
        {
            DrawTextEx(font, textLine.c_str(), {viewArea.x, currentY}, textFontSize, 2.0f, textColor);
            currentY += textFontSize + textLineSpacing;
        }

        EndScissorMode();

        DrawRectangleRec(backButtonRec, isMouseOverButton ? buttonHoverColor : buttonColor);
        const char *backText = "Back to Game";
        float backTextFontSize = 20.0f;
        Vector2 backTextSize = MeasureTextEx(font, backText, backTextFontSize, 2);
        DrawTextEx(font, backText, {backButtonRec.x + (backButtonRec.width - backTextSize.x) / 2, backButtonRec.y + (backButtonRec.height - backTextSize.y) / 2}, backTextFontSize, 2, titleColor);

        EndDrawing();
    }
}
int ShowInTerminal::MenuGenerator(const std::vector<std::string> &options)
{

    const Color BG_COLOR = {21, 30, 39, 255};
    const Color BUTTON_COLOR = {70, 85, 105, 255};
    const Color BUTTON_BORDER_COLOR = {100, 120, 140, 255};
    const Color HOVER_COLOR = {120, 145, 175, 255};
    const Color TEXT_COLOR = {230, 230, 230, 255};

    Texture2D bg = backgroundTextures["menu"];
    Font &font = this->font;

    const float buttonWidth = 200;
    const float buttonHeight = 50;
    const float spacing = 20;
    const int maxButtonsPerColumn = 10;

    int numColumns = 1;
    if (options.size() > maxButtonsPerColumn)
    {
        numColumns = 2;
    }

    int numRows = (numColumns == 1) ? options.size() : static_cast<int>(ceil(options.size() / 2.0));

    const float totalHeight = numRows * buttonHeight + (numRows > 1 ? (numRows - 1) * spacing : 0);
    const float startY = (GetScreenHeight() - totalHeight) / 2;

    std::vector<Rectangle> optionRects(options.size());

    for (int i = 0; i < options.size(); i++)
    {
        float x, y;
        if (numColumns == 1)
        {
            x = (GetScreenWidth() - buttonWidth) / 2.0f;
            y = startY + i * (buttonHeight + spacing);
        }
        else
        {
            int column = i / numRows;
            int row = i % numRows;

            float column1_x = (GetScreenWidth() / 2.0f) - buttonWidth - (spacing / 2.0f);
            float column2_x = (GetScreenWidth() / 2.0f) + (spacing / 2.0f);

            x = (column == 0) ? column1_x : column2_x;
            y = startY + row * (buttonHeight + spacing);
        }
        optionRects[i] = {x, y, buttonWidth, buttonHeight};
    }

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            for (int i = 0; i < options.size(); i++)
            {
                if (CheckCollisionPointRec(mouse, optionRects[i]))
                {
                    return i;
                }
            }
        }

        BeginDrawing();
        ClearBackground(BG_COLOR);

        DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height}, {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, {0, 0}, 0.0f, WHITE);

        for (int i = 0; i < options.size(); i++)
        {
            bool hovered = CheckCollisionPointRec(mouse, optionRects[i]);

            DrawRectangleRounded(optionRects[i], 0.2f, 10, hovered ? HOVER_COLOR : BUTTON_COLOR);
            DrawRectangleRoundedLines(optionRects[i], 0.2f, 10, hovered ? SKYBLUE : BUTTON_BORDER_COLOR);

            float fontSize = 20.0f;
            const float textPadding = 15.0f;
            Vector2 textSize;

            do
            {
                textSize = MeasureTextEx(font, options[i].c_str(), fontSize, 1);
                if (textSize.x > buttonWidth - textPadding)
                {
                    fontSize -= 1.0f;
                }
            } while (textSize.x > buttonWidth - textPadding && fontSize > 8);

            float textX = optionRects[i].x + (optionRects[i].width - textSize.x) / 2;
            float textY = optionRects[i].y + (optionRects[i].height - textSize.y) / 2;

            DrawTextEx(font, options[i].c_str(), {textX, textY}, fontSize, 1, TEXT_COLOR);
        }

        EndDrawing();
    }

    return -1;
}

bool ShowInTerminal::GetPlayerInfo(std::string &name, int &days)
{

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    Texture2D bg = backgroundTextures["input"];

    std::string nameInput = "";
    std::string daysInput = "";
    std::string errorMsg = "";

    Color bgColor = (Color){23, 28, 41, 255};
    Color textColor = (Color){220, 220, 220, 255};
    Color boxColor = (Color){40, 45, 60, 255};
    Color boxActiveBorderColor = (Color){70, 130, 220, 255};
    Color btnBackColor = (Color){80, 85, 100, 255};
    Color btnSubmitColor = (Color){60, 140, 90, 255};
    Color placeholderColor = (Color){150, 150, 150, 255};

    float formWidth = 450;
    float formX = (screenWidth - formWidth) / 2.0f;

    Rectangle nameBox = {formX, 240, formWidth, 50};
    Rectangle daysBox = {formX, 350, formWidth, 50};
    Rectangle backBtn = {formX, 450, 150, 50};
    Rectangle submitBtn = {formX + formWidth - 150, 450, 150, 50};

    bool typingName = true;
    bool typingDays = false;
    bool submitClicked = false;
    bool backClicked = false;

    while (!WindowShouldClose() && !submitClicked && !backClicked)
    {
        UpdateMusicStream(music);

        Vector2 mouse = GetMousePosition();
        int key = GetCharPressed();
        if (key > 0 && isprint(key))
        {
            if (typingName && nameInput.size() < 30)
            {
                nameInput.push_back((char)key);
            }
            else if (typingDays && daysInput.size() < 5 && isdigit(key))
            {
                daysInput.push_back((char)key);
            }
        }
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (typingName && !nameInput.empty())
                nameInput.pop_back();
            else if (typingDays && !daysInput.empty())
                daysInput.pop_back();
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            typingName = CheckCollisionPointRec(mouse, nameBox);
            typingDays = CheckCollisionPointRec(mouse, daysBox);

            if (CheckCollisionPointRec(mouse, submitBtn))
            {
                if (nameInput.empty() || daysInput.empty())
                {
                    errorMsg = "Both fields must be filled!";
                }
                else if (!CheckInt(daysInput))
                {
                    errorMsg = "Days must be a number!";
                }
                else
                {
                    name = nameInput;
                    days = std::stoi(daysInput);
                    submitClicked = true;
                }
            }
            if (CheckCollisionPointRec(mouse, backBtn))
            {
                backClicked = true;
            }
        }

        BeginDrawing();
        ClearBackground(bgColor);

        DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height}, {0, 0, (float)screenWidth, (float)screenHeight}, {0, 0}, 0.0f, WHITE);

        float fontSize = 22.0f;
        float spacing = 2.0f;

        DrawTextEx(font, "Enter your name:", {nameBox.x, nameBox.y - 30}, fontSize, spacing, textColor);
        DrawRectangleRec(nameBox, boxColor);
        if (typingName)
            DrawRectangleLinesEx(nameBox, 2, boxActiveBorderColor);                                                                                                                      // حاشیه برای کادر فعال
        DrawTextEx(font, nameInput.empty() ? "Type name..." : nameInput.c_str(), {nameBox.x + 15, nameBox.y + 15}, fontSize, spacing, nameInput.empty() ? placeholderColor : textColor); // لیبل و کادر روزها
        DrawTextEx(font, "Days since last garlic:", {daysBox.x, daysBox.y - 30}, fontSize, spacing, textColor);
        DrawRectangleRec(daysBox, boxColor);
        if (typingDays)
            DrawRectangleLinesEx(daysBox, 2, boxActiveBorderColor); // حاشیه برای کادر فعال
        DrawTextEx(font, daysInput.empty() ? "0" : daysInput.c_str(), {daysBox.x + 15, daysBox.y + 15}, fontSize, spacing, daysInput.empty() ? placeholderColor : textColor);

        const char *backText = "Back";
        const char *submitText = "Submit";
        Vector2 backTextSize = MeasureTextEx(font, backText, fontSize, spacing);
        Vector2 submitTextSize = MeasureTextEx(font, submitText, fontSize, spacing);

        DrawRectangleRec(backBtn, btnBackColor);
        DrawTextEx(font, backText, {backBtn.x + (backBtn.width - backTextSize.x) / 2, backBtn.y + (backBtn.height - backTextSize.y) / 2}, fontSize, spacing, textColor);

        DrawRectangleRec(submitBtn, btnSubmitColor);
        DrawTextEx(font, submitText, {submitBtn.x + (submitBtn.width - submitTextSize.x) / 2, submitBtn.y + (submitBtn.height - submitTextSize.y) / 2}, fontSize, spacing, textColor);

        if (!errorMsg.empty())
        {
            DrawTextEx(font, errorMsg.c_str(), {formX, 520}, 20, spacing, RED);
        }

        EndDrawing();
    }

    return submitClicked;
}

void ShowInTerminal::ShowBackgroundScreen(std::string name, std::string message)
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    Texture2D bg = backgroundTextures[name];

    float boxScale = 0.9f;
    float targetScale = 1.0f;

    Color boxColor = {15, 25, 40, 160};
    Color borderColor = {0, 220, 255, 200};
    Color textColor = {220, 240, 255, 255};
    int fontSize = 28;

    double startTime = GetTime();
    const float totalDuration = 3.0f;

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        double elapsed = GetTime() - startTime;
        if (elapsed >= totalDuration)
            break;

        float remaining = (float)(totalDuration - elapsed);
        float volume = Clamp(remaining / totalDuration, 0.0f, 1.0f);
        SetMusicVolume(music, volume);

        boxScale += (targetScale - boxScale) * 0.1f;

        BeginDrawing();

        ClearBackground(BLACK);

        if (bg.id != 0)
        {
            DrawTexturePro(bg,
                           Rectangle{0, 0, (float)bg.width, (float)bg.height},
                           Rectangle{0, 0, (float)screenWidth, (float)screenHeight},
                           Vector2{0, 0}, 0.0f, WHITE);
        }

        Vector2 textSize = MeasureTextEx(font, message.c_str(), fontSize, 1.0f);
        float padding = 40;

        Rectangle textBox = {
            (screenWidth - textSize.x - padding) / 2,
            screenHeight - textSize.y - 80,
            textSize.x + padding,
            textSize.y + 30};

        Rectangle scaledBox = {
            textBox.x + (textBox.width * (1 - boxScale)) / 2,
            textBox.y + (textBox.height * (1 - boxScale)) / 2,
            textBox.width * boxScale,
            textBox.height * boxScale};

        DrawRectangleRounded(scaledBox, 0.2f, 16, Fade(boxColor, boxScale));
        DrawRectangleRoundedLines(scaledBox, 0.2f, 16, Fade(borderColor, boxScale));

        Vector2 textPos = {
            scaledBox.x + (scaledBox.width - textSize.x) / 2,
            scaledBox.y + (scaledBox.height - textSize.y) / 2};

        if (boxScale > 0.98f)
        {
            float shake = sin(GetTime() * 20) * 2.0f;
            textPos.x += shake;
        }

        DrawTextEx(font, message.c_str(), textPos, fontSize, 1.0f, Fade(textColor, boxScale));

        EndDrawing();
    }
    SetMusicVolume(music, 1.0f);
}

void ShowInTerminal ::DrawTerrorLevel(int terrorLevel, Font font, Vector2 position)
{

    std::string label = "Terror Level: " + std::to_string(terrorLevel);
    DrawTextEx(font, label.c_str(), position, 20, 1, RED);

    float fill = terrorLevel / 7.0f;

    Rectangle barBg = {position.x, position.y + 30, 200, 20};
    DrawRectangleRec(barBg, DARKGRAY);

    Rectangle barFill = {position.x, position.y + 30, 200 * fill, 20};
    DrawRectangleRec(barFill, RED);

    DrawRectangleLinesEx(barBg, 2, BLACK);
}
void ShowInTerminal::DrawDraculaMat(Game &game, Vector2 startPos)
{
    auto dracula = game.GetDracula();
    if (!dracula)
        return;

    const auto &coffins = dracula->GetCoffins();
    if (coffins.empty())
        return;

    const float cellWidth = 148.0f;
    const float cellHeight = 55.0f;
    const float padding = 6.0f;
    const float coffinSize = 35.0f;
    const float textFontSize = 16.0f;
    const float titleFontSize = 18.0f;

    const Color tableColor = {50, 50, 80, 255};
    const Color borderColor = {100, 100, 140, 255};
    const Color textColor = WHITE;

    const char *title = "Dracula mat";
    Vector2 titleSize = MeasureTextEx(font, title, titleFontSize, 1);
    DrawTextEx(font, title,
               {startPos.x + (cellWidth - titleSize.x) / 2, startPos.y - 25},
               titleFontSize, 1, WHITE);

    float availableHeight = GetScreenHeight() - startPos.y - 30;
    int maxVisibleRows = std::floor(availableHeight / cellHeight);
    int rowsToShow = std::min((int)coffins.size(), maxVisibleRows);

    for (int i = 0; i < rowsToShow; i++)
    {
        float cellY = startPos.y + i * cellHeight;

        DrawRectangleRounded(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight},
            0.1f, 5, tableColor);
        DrawRectangleRoundedLines(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight},
            0.1f, 5, borderColor);

        const auto &locName = coffins[i].second;
        std::string label = locName + ":";
        Vector2 textSize = MeasureTextEx(font, label.c_str(), textFontSize, 1);

        DrawTextEx(font, label.c_str(),
                   {startPos.x + padding, cellY + (cellHeight - textSize.y) / 2},
                   textFontSize, 1, textColor);

        float coffinX = startPos.x + cellWidth - coffinSize - padding;
        float coffinY = cellY + (cellHeight - coffinSize) / 2;

        if (coffins[i].first)
        {
            if (coffinBrokenTexture.id != 0)
            {
                DrawTexturePro(
                    coffinBrokenTexture,
                    Rectangle{0, 0, (float)coffinBrokenTexture.width, (float)coffinBrokenTexture.height},
                    Rectangle{coffinX, coffinY, coffinSize, coffinSize * (float)coffinBrokenTexture.height / coffinBrokenTexture.width},
                    Vector2{0, 0}, 0.0f, WHITE);
            }
            else
            {
                DrawTextEx(font, "💀",
                           Vector2{coffinX + coffinSize / 2 - 8, coffinY + 2},
                           20, 1, RED);
            }
        }
        else
        {
            if (coffinIntactTexture.id != 0)
            {
                DrawTexturePro(
                    coffinIntactTexture,
                    Rectangle{0, 0, (float)coffinIntactTexture.width, (float)coffinIntactTexture.height},
                    Rectangle{coffinX, coffinY, coffinSize, coffinSize * (float)coffinIntactTexture.height / coffinIntactTexture.width},
                    Vector2{0, 0}, 0.0f, WHITE);
            }
            else
            {
                DrawTextEx(font, "⚰️",
                           Vector2{coffinX + coffinSize / 2 - 8, coffinY + 2},
                           20, 1, GREEN);
            }
        }
    }
    if (coffins.size() > maxVisibleRows)
    {
        const char *moreMsg = TextFormat("+%d more...", (int)coffins.size() - maxVisibleRows);
        DrawTextEx(font, moreMsg,
                   Vector2{startPos.x + 10, startPos.y + rowsToShow * cellHeight + 5},
                   14, 1, GRAY);
    }
}
void ShowInTerminal::DrawInvisibleManMat(const std::vector<std::pair<bool, std::string>> &evidences, Font font, Vector2 startPos)
{
    if (evidences.empty())
        return;

    const float cellWidth = 148.0f;
    const float cellHeight = 44.0f;
    const float padding = 6.0f;
    const float iconSize = 20.0f;
    const float textFontSize = 16.0f;
    const float titleFontSize = 18.0f;

    const Color tableColor = {50, 50, 80, 255};
    const Color borderColor = {100, 100, 140, 255};
    const Color textColor = WHITE;

    const char *title = "Invisible Man Mat";
    Vector2 titleSize = MeasureTextEx(font, title, titleFontSize, 1);
    DrawTextEx(font, title,
               {startPos.x + (cellWidth - titleSize.x) / 2, startPos.y - 25},
               titleFontSize, 1, BLUE);

    float availableHeight = GetScreenHeight() - startPos.y - 30;
    int maxVisibleRows = std::floor(availableHeight / cellHeight);
    int rowsToShow = std::min((int)evidences.size(), maxVisibleRows);

    for (int i = 0; i < rowsToShow; i++)
    {
        float cellY = startPos.y + i * cellHeight;

        DrawRectangleRounded(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight},
            0.1f, 5, tableColor);
        DrawRectangleRoundedLines(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight},
            0.1f, 5, borderColor);

        const auto &locName = evidences[i].second;
        std::string label = locName + ":";
        Vector2 textSize = MeasureTextEx(font, label.c_str(), textFontSize, 1);

        DrawTextEx(font, label.c_str(),
                   {startPos.x + padding, cellY + (cellHeight - textSize.y) / 2},
                   textFontSize, 1, textColor);

        float iconX = startPos.x + cellWidth - iconSize - padding;
        float iconY = cellY + (cellHeight - iconSize) / 2;

        if (evidences[i].first)
        {

            DrawTextEx(font, "V",
                       {iconX, iconY},
                       iconSize, 1, GREEN);
        }
        else
        {

            DrawTextEx(font, "X",
                       {iconX, iconY},
                       iconSize, 1, RED);
        }
    }

    if (evidences.size() > maxVisibleRows)
    {
        const char *moreMsg = TextFormat("+%d more...", (int)evidences.size() - maxVisibleRows);
        DrawTextEx(font, moreMsg,
                   Vector2{startPos.x + 10, startPos.y + rowsToShow * cellHeight + 5},
                   14, 1, GRAY);
    }
}

void ShowInTerminal ::DrawItemsList(const std::vector<std::shared_ptr<Item>> &items, Font font, Vector2 position)
{
    float fontSize = 18;
    float spacing = 2;
    float y = position.y;

    float boxWidth = 260;
    float boxHeight = items.size() * (fontSize + 4) + 10;
    DrawRectangle(position.x - 10, position.y - 10, boxWidth, boxHeight, Fade(DARKGREEN, 0.5f));
    DrawRectangleLinesEx({position.x - 10, position.y - 10, boxWidth, boxHeight}, 2, DARKGRAY);

    for (const auto &item : items)
    {
        std::string line = "- " + item->getName() + " (" + std::to_string(item->getPower()) + ")";
        Color color = WHITE;
        if (item->getColor() == ItemColor::Red)
            color = RED;
        else if (item->getColor() == ItemColor::Yellow)
            color = YELLOW;
        else if (item->getColor() == ItemColor::Blue)
            color = SKYBLUE;

        DrawTextEx(font, line.c_str(), {position.x, y}, fontSize, spacing, color);
        y += fontSize + 4;
    }
}

void ShowInTerminal::DrawHeroInfo(std::shared_ptr<Hero> hero, Font font, Vector2 startPos, Rectangle *outClickZone)
{
    if (!hero)
        return;

    const float cellWidth = 148.0f;
    const float cellHeight = 54.0f;
    const float padding = 6.0f;
    const float textFontSize = 16.0f;
    const float titleFontSize = 18.0f;

    const Color tableColor = {50, 50, 80, 255};
    const Color borderColor = {100, 100, 140, 255};
    const Color textColor = WHITE;

    const char *title = "Hero Info";
    Vector2 titleSize = MeasureTextEx(font, title, titleFontSize, 1);
    DrawTextEx(font, title,
               {startPos.x + (cellWidth - titleSize.x) / 2, startPos.y - 25},
               titleFontSize, 1, GOLD);

    std::vector<std::string> lines;
    lines.push_back("Hero: " + hero->getName());
    lines.push_back("Location: " + hero->getLocation()->GetCityName());
    lines.push_back("Actions: " + std::to_string(hero->getRemainingActions()));
    lines.push_back("Inventory: Click here");

    for (size_t i = 0; i < lines.size(); i++)
    {
        float cellY = startPos.y + i * cellHeight;

        DrawRectangleRounded(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight},
            0.1f, 5, tableColor);
        DrawRectangleRoundedLines(
            Rectangle{startPos.x, cellY, cellWidth, cellHeight},
            0.1f, 5, borderColor);

        std::string text = lines[i];

        if (text.find("Inventory:") == 0)
        {
            std::string prefix = "Inventory: ";
            std::string clickablePart = "Click here";

            Vector2 prefixSize = MeasureTextEx(font, prefix.c_str(), textFontSize, 1);
            Vector2 clickableSize = MeasureTextEx(font, clickablePart.c_str(), textFontSize, 1);

            Vector2 prefixPos = {startPos.x + padding, cellY + (cellHeight - prefixSize.y) / 2};
            Vector2 clickablePos = {prefixPos.x + prefixSize.x, cellY + (cellHeight - clickableSize.y) / 2};

            DrawTextEx(font, prefix.c_str(), prefixPos, textFontSize, 1, textColor);

            DrawTextEx(font, clickablePart.c_str(), clickablePos, textFontSize, 1, textColor);

            if (outClickZone)
            {
                *outClickZone = {clickablePos.x, clickablePos.y, clickableSize.x, clickableSize.y};
            }
        }
        else
        {
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

void ShowInTerminal::DrawDiceMat()
{
    const float diceW = 265;
    const float diceH = 172;
    const float boxSize = 60;
    const float spacing = 10;

    Vector2 matPos = {590, 370};

    int numDice = currentFaces.size();
    Vector2 startPos = {
        matPos.x + (diceW - (numDice * boxSize + (numDice - 1) * spacing)) / 2,
        matPos.y + (diceH - boxSize) / 2};
    DrawTexturePro(DiceBack,
                   {0, 0, (float)DiceBack.width, (float)DiceBack.height},
                   {matPos.x, matPos.y, diceW, diceH},
                   {0, 0}, 0.0f, WHITE);

    for (int i = 0; i < numDice; ++i)
    {
        Rectangle box = {startPos.x + i * (boxSize + spacing), startPos.y, boxSize, boxSize};
        DrawRectangleRounded(box, 0.3f, 12, SKYBLUE);
        DrawRectangleRoundedLines(box, 0.3f, 12, WHITE);

        if (diceFaces.find(currentFaces[i]) != diceFaces.end())
        {
            DrawTexturePro(diceFaces[currentFaces[i]],
                           {0, 0, (float)diceFaces[currentFaces[i]].width, (float)diceFaces[currentFaces[i]].height},
                           {box.x, box.y, boxSize, boxSize},
                           {0, 0}, 0.0f, WHITE);
        }
        else
        {
            DrawText("?", box.x + boxSize / 2 - MeasureText("?", 32) / 2,
                     box.y + boxSize / 3, 32, BLACK);
        }
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

void ShowInTerminal::DrawPerkCard(const std::shared_ptr<PerkCard> &card, Font font, Vector2 position)
{
    DrawTextEx(font, "Perk Card", {position.x + 35, position.y}, 20, 2, GREEN);

    if (card)
    {
        std::string name = card->GetName();

        if (perkTextures.count(name))
        {
            Texture2D &texture = perkTextures[name];
            float maxWidth = 150.0f;
            float scale = maxWidth / texture.width;
            float imgW = texture.width * scale;
            float imgH = texture.height * scale;

            Vector2 imgPos = {position.x, position.y + 30};

            DrawTextureEx(texture, imgPos, 0, scale, WHITE);

            DrawRectangleLines(imgPos.x - 2, imgPos.y - 2, imgW + 4, imgH + 4, DARKGREEN);
        }
        else
        {
            DrawTextEx(font, "(Card image missing)", {position.x, position.y + 30}, 18, 2, RED);
        }
    }
    else
    {
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

    for (const auto i : Items)
    {
        auto posIt = locationPositions.find(i->GetItemLocationName()->GetCityName());
        auto iconIt = itemTextures.find(i->getName());
        if (posIt != locationPositions.end() && iconIt != villagerTextures.end())
        {
            Texture2D ItemTex = iconIt->second;
            Vector2 position = locationPositions[i->GetItemLocationName()->GetCityName()];
            position.y -= 60;
            position.x -= 30;

            float Scale = ShowInTerminal::GetBestScaleForCharacters(ItemTex);
            DrawTextureEx(ItemTex, position, 0.0f, Scale, WHITE);
        }
    }

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

            float Scale = ShowInTerminal::GetBestScaleForCharacters(HeroTex);
            DrawTextureEx(HeroTex, position, 0.0f, Scale, WHITE);
        }
    }

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

            float Scale = ShowInTerminal::GetBestScaleForCharacters(MonsterTex);
            DrawTextureEx(MonsterTex, position, 0.0f, Scale, WHITE);
            if (m->GetFrenzyMarker())
            {
                Texture2D frenzyTex = frenzyMark;
                Vector2 pos = {position.x + 15, position.y - 20};
                float s = GetBestScaleForCharacters(frenzyTex) / 2;
                DrawTextureEx(frenzyTex, pos, 0.0f, s, WHITE);
            }
        }
    }

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

                float Scale = ShowInTerminal::GetBestScaleForCharacters(VillagerTex);
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
    const float spacing = 20;
    const float fontSize = 32;
    std::vector<std::string> resultFaces(numDice);
    Vector2 startPos = {
        (float)GetScreenWidth() / 2 - (numDice * boxSize + (numDice - 1) * spacing) / 2,
        (float)GetScreenHeight() / 2 - boxSize / 2};

    for (int frame = 0; frame < rollFrames; ++frame)
    {
        UpdateMusicStream(music);
        BeginDrawing();

        DrawTexturePro(DiceBack,
                       {0, 0, (float)DiceBack.width, (float)DiceBack.height},
                       {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                       {0, 0}, 0.0f, WHITE);

        for (int i = 0; i < numDice; ++i)
        {
            std::string face = dice.DiceRoll();
            Rectangle box = {startPos.x + i * (boxSize + spacing), startPos.y, boxSize, boxSize};

            DrawRectangleRounded(box, 0.3f, 12, GRAY);
            DrawRectangleRoundedLines(box, 0.3f, 12, WHITE);

            DrawTexturePro(diceFaces[face],
                           {0, 0, (float)diceFaces[face].width, (float)diceFaces[face].height},
                           {box.x, box.y, boxSize, boxSize},
                           {0, 0}, 0.0f, WHITE);
        }

        EndDrawing();

        float delay = 0.09f;
        float elapsed = 0.0f;
        while (elapsed < delay)
        {
            float delta = GetFrameTime();
            elapsed += delta;
            UpdateMusicStream(music);
        }
    }

    BeginDrawing();

    DrawTexturePro(DiceBack,
                   {0, 0, (float)DiceBack.width, (float)DiceBack.height},
                   {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                   {0, 0}, 0.0f, WHITE);

    for (int i = 0; i < numDice; ++i)
    {
        resultFaces[i] = dice.DiceRoll();
        Rectangle box = {startPos.x + i * (boxSize + spacing), startPos.y, boxSize, boxSize};
        DrawRectangleRounded(box, 0.3f, 12, SKYBLUE);
        DrawRectangleRoundedLines(box, 0.3f, 12, WHITE);

        DrawTexturePro(diceFaces[resultFaces[i]],
                       {0, 0, (float)diceFaces[resultFaces[i]].width, (float)diceFaces[resultFaces[i]].height},
                       {box.x, box.y, boxSize, boxSize},
                       {0, 0}, 0.0f, WHITE);
    }
    EndDrawing();

    float finalDelay = 1.0f;
    float finalElapsed = 0.0f;
    while (finalElapsed < finalDelay)
    {
        float delta = GetFrameTime();
        finalElapsed += delta;
        UpdateMusicStream(music);
    }
    currentFaces.clear();
    currentFaces = resultFaces;
    return resultFaces;
}
void ShowInTerminal::ShowPopupMessages(Game &game, const std::string message)
{
    float screenW = (float)GetScreenWidth();
    float screenH = (float)GetScreenHeight();

    const float boxW = 900;
    const float boxH = 138;
    const float padding = 20;

    Rectangle popupBox = {
        0, 543, boxW, boxH};

    Color boxColor = {15, 25, 40, 200};
    Color borderColor = {0, 220, 255, 255};

    bool waiting = true;
    while (!WindowShouldClose() && waiting)
    {
        UpdateMusicStream(music);
        BeginDrawing();

        DrawRectangleRec(popupBox, Fade(boxColor, 0.4f));
        DrawRectangleLinesEx(popupBox, 3, borderColor);

        DrawTextEx(font, message.c_str(),
                   {popupBox.x + padding, popupBox.y + padding},
                   20, 2, RED);

        std::string hint = "(Press Enter or click)";
        Vector2 hintSize = MeasureTextEx(font, hint.c_str(), 16, 1);
        DrawTextEx(font, hint.c_str(),
                   {popupBox.x + popupBox.width - hintSize.x - 12, popupBox.y + popupBox.height - 24},
                   16, 1, RED);

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            waiting = false;
    }
}
void ShowInTerminal::DrawInventoryPopup(std::shared_ptr<Hero> hero, float &scrollY)
{
    if (!hero)
        return;

    Rectangle popupBounds = {
        (GetScreenWidth() - 300.0f) / 2,
        (GetScreenHeight() - 450.0f) / 2,
        300.0f,
        450.0f};

    DrawRectangleRec(popupBounds, Fade(BLACK, 0.9f));
    DrawRectangleLinesEx(popupBounds, 3, SKYBLUE);

    const float padding = 20.0f;
    const float iconSize = 32.0f;
    const float itemSpacing = 40.0f;
    const int titleFontSize = 24;
    const float titleSectionHeight = titleFontSize + 30;
    const int itemFontSize = 18;
    const auto &items = hero->getInventory();

    float totalContentHeight = items.empty() ? itemSpacing : items.size() * itemSpacing;

    DrawTextEx(font, "Inventory", {popupBounds.x + padding, popupBounds.y + 15}, titleFontSize, 1, GOLD);

    Rectangle closeBtn = {popupBounds.x + popupBounds.width - 40, popupBounds.y + 10, 30, 30};
    DrawRectangleRounded(closeBtn, 0.2f, 4, RED);
    DrawTextEx(font, "X", {closeBtn.x + 8, closeBtn.y + 4}, 24, 1, WHITE);

    Rectangle viewArea = {
        popupBounds.x,
        popupBounds.y + titleSectionHeight,
        popupBounds.width,
        popupBounds.height - titleSectionHeight - padding};

    if (CheckCollisionPointRec(GetMousePosition(), popupBounds))
    {
        float wheelMove = GetMouseWheelMove();
        if (wheelMove != 0)
        {
            scrollY += wheelMove * 20;
        }
    }

    if (scrollY > 0)
        scrollY = 0;
    float minScrollY = viewArea.height - totalContentHeight;
    if (minScrollY > 0)
        minScrollY = 0;
    if (scrollY < minScrollY)
        scrollY = minScrollY;

    BeginScissorMode(viewArea.x, viewArea.y, viewArea.width, viewArea.height);

    float currentX = viewArea.x + padding;
    float currentY = viewArea.y + scrollY + 10;

    if (items.empty())
    {
        DrawTextEx(font, "No items found.", {currentX, currentY}, itemFontSize, 1, LIGHTGRAY);
    }
    else
    {

        for (const auto &item : items)
        {
            if (itemTextures.count(item->getName()))
            {
                DrawTexturePro(itemTextures[item->getName()],
                               {0, 0, (float)itemTextures[item->getName()].width, (float)itemTextures[item->getName()].height},
                               {currentX, currentY, iconSize, iconSize},
                               {0, 0}, 0.0f, WHITE);
            }
            std::string itemText = item->getName() + " (" + std::to_string(item->getPower()) + ")";
            DrawTextEx(font, itemText.c_str(), {currentX + iconSize + 15, currentY + 4}, itemFontSize, 1, WHITE);
            currentY += itemSpacing;
        }
    }

    EndScissorMode();
}
void ShowInTerminal::DrawLocationInfoPopup(std::shared_ptr<Location> location, float &scrollY)
{
    if (!location)
        return;

    const float padding = 20.0f;
    const float itemSpacing = 40.0f;
    const int titleFontSize = 24;
    const float titleSectionHeight = titleFontSize + 35;
    const int headerFontSize = 20;
    const float headerSpacing = headerFontSize + 15;
    const int itemFontSize = 18;
    const float iconSize = 32.0f;

    const auto &HeroInGame = location->GetHero();
    const auto &monsters = location->GetMonsters();
    const auto &villagers = location->GetVillager();
    const auto &items = location->GetItems();

    float totalContentHeight = 0;
    totalContentHeight += headerSpacing + (HeroInGame.empty() ? itemSpacing : HeroInGame.size() * itemSpacing);
    totalContentHeight += headerSpacing + (monsters.empty() ? itemSpacing : monsters.size() * itemSpacing);
    totalContentHeight += headerSpacing + (villagers.empty() ? itemSpacing : villagers.size() * itemSpacing);
    totalContentHeight += headerSpacing + (items.empty() ? itemSpacing : items.size() * itemSpacing);

    DrawRectangleRec(locationPopupBounds, Fade(BLACK, 0.9f));
    DrawRectangleLinesEx(locationPopupBounds, 3, SKYBLUE);

    std::string title = "Info for " + location->GetCityName();
    DrawTextEx(font, title.c_str(), {locationPopupBounds.x + padding, locationPopupBounds.y + 15}, titleFontSize, 1, GOLD);

    Rectangle closeBtn = {locationPopupBounds.x + locationPopupBounds.width - 40, locationPopupBounds.y + 10, 30, 30};
    DrawRectangleRounded(closeBtn, 0.2f, 4, RED);
    DrawTextEx(font, "X", {closeBtn.x + 8, closeBtn.y + 4}, 24, 1, WHITE);

    Rectangle viewArea = {
        locationPopupBounds.x,
        locationPopupBounds.y + titleSectionHeight,
        locationPopupBounds.width,
        locationPopupBounds.height - titleSectionHeight - padding};

    if (CheckCollisionPointRec(GetMousePosition(), locationPopupBounds))
    {
        float wheelMove = GetMouseWheelMove();
        if (wheelMove != 0)
        {
            scrollY += wheelMove * 20;
        }
    }

    if (scrollY > 0)
        scrollY = 0;
    float minScrollY = viewArea.height - totalContentHeight;
    if (minScrollY > 0)
        minScrollY = 0;
    if (scrollY < minScrollY)
        scrollY = minScrollY;

    BeginScissorMode(viewArea.x, viewArea.y, viewArea.width, viewArea.height);

    float currentX = viewArea.x + padding;
    float currentY = viewArea.y + scrollY + 10;

    DrawTextEx(font, "Heros:", {currentX, currentY}, headerFontSize, 1, YELLOW);
    currentY += headerSpacing;
    if (HeroInGame.empty())
    {
        DrawTextEx(font, "  (None)", {currentX, currentY}, itemFontSize, 1, LIGHTGRAY);
        currentY += itemSpacing;
    }
    else
    {
        for (const auto &hero : HeroInGame)
        {
            if (heroTextures.count(hero->getName()))
            {
                DrawTexturePro(heroTextures[hero->getName()], {0, 0, (float)heroTextures[hero->getName()].width, (float)heroTextures[hero->getName()].height}, {currentX + 5, currentY, iconSize, iconSize}, {0, 0}, 0.0f, WHITE);
            }
            DrawTextEx(font, hero->getName().c_str(), {currentX + iconSize + 15, currentY + 4}, itemFontSize, 1, WHITE);
            currentY += itemSpacing;
        }
    }

    DrawTextEx(font, "Monsters:", {currentX, currentY}, headerFontSize, 1, RED);
    currentY += headerSpacing;
    if (monsters.empty())
    {
        DrawTextEx(font, "  (None)", {currentX, currentY}, itemFontSize, 1, LIGHTGRAY);
        currentY += itemSpacing;
    }
    else
    {
        for (const auto &monster : monsters)
        {
            if (monsterTextures.count(monster->GetName()))
            {
                DrawTexturePro(monsterTextures[monster->GetName()], {0, 0, (float)monsterTextures[monster->GetName()].width, (float)monsterTextures[monster->GetName()].height}, {currentX + 5, currentY, iconSize, iconSize}, {0, 0}, 0.0f, WHITE);
            }
            DrawTextEx(font, monster->GetName().c_str(), {currentX + iconSize + 15, currentY + 4}, itemFontSize, 1, WHITE);
            currentY += itemSpacing;
        }
    }

    DrawTextEx(font, "Villagers:", {currentX, currentY}, headerFontSize, 1, GREEN);
    currentY += headerSpacing;
    if (villagers.empty())
    {
        DrawTextEx(font, "  (None)", {currentX, currentY}, itemFontSize, 1, LIGHTGRAY);
        currentY += itemSpacing;
    }
    else
    {
        for (const auto &villager : villagers)
        {
            if (villagerTextures.count(villager->getName()))
            {
                DrawTexturePro(villagerTextures[villager->getName()], {0, 0, (float)villagerTextures[villager->getName()].width, (float)villagerTextures[villager->getName()].height}, {currentX + 5, currentY, iconSize, iconSize}, {0, 0}, 0.0f, WHITE);
            }
            std :: string villagerInfo = villager->getName() + " (" + villager->getSafeLocation()->GetCityName() + ")" ;
            DrawTextEx(font, villagerInfo.c_str() , {currentX + iconSize + 15, currentY + 4}, itemFontSize, 1, WHITE);
            currentY += itemSpacing;
        }
    }

    DrawTextEx(font, "Items:", {currentX, currentY}, headerFontSize, 1, SKYBLUE);
    currentY += headerSpacing;
    if (items.empty())
    {
        DrawTextEx(font, "  (None)", {currentX, currentY}, itemFontSize, 1, LIGHTGRAY);
        currentY += itemSpacing;
    }
    else
    {
        for (const auto &item : items)
        {
            if (itemTextures.count(item->getName()))
            {
                DrawTexturePro(itemTextures[item->getName()], {0, 0, (float)itemTextures[item->getName()].width, (float)itemTextures[item->getName()].height}, {currentX + 5, currentY, iconSize, iconSize}, {0, 0}, 0.0f, WHITE);
            }
            std::string itemText = item->getName() + " (" + std::to_string(item->getPower()) + ")";
            DrawTextEx(font, itemText.c_str(), {currentX + iconSize + 15, currentY + 4}, itemFontSize, 1, WHITE);
            currentY += itemSpacing;
        }
    }

    EndScissorMode();
}
int ShowInTerminal::ShowHeroPhase(Game &game, const std::vector<std::string> &options)
{
    int selected = -1;

    float mapW = 545;
    float mapH = 542;
    Vector2 mapPos = {0, 0};

    const int buttonsPerRow = 6;
    const float buttonWidth = 130;
    const float buttonHeight = 35;
    const float spacing = 10;
    const Color buttonColor = {100, 140, 255, 255};
    const Color hoverColor = {130, 170, 255, 255};

    Rectangle optionRects[options.size()];
    for (int i = 0; i < options.size(); i++)
    {
        int row = i / 6;
        int col = i % 6;
        float totalWidth = 6 * buttonWidth + (6 - 1) * spacing;
        float x = (GetScreenWidth() - totalWidth) / 2 + col * (buttonWidth + spacing);
        float y = GetScreenHeight() - 120 + row * (buttonHeight + spacing);
        optionRects[i] = {x, y, buttonWidth, buttonHeight};
    }
    float locationScrolly = 0.0f;
    float inventoryScrolly = 0.0f;

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {

            if (showLocationItemsPopup)
            {
                Rectangle closeBtn = {locationPopupBounds.x + locationPopupBounds.width - 40, locationPopupBounds.y + 10, 30, 30};
                if (CheckCollisionPointRec(mouse, closeBtn))
                {
                    showLocationItemsPopup = false;
                    clickedLocation = nullptr;
                }
            }

            else if (showInventoryPopup)
            {
                Rectangle popupBounds = {(GetScreenWidth() - 300.0f) / 2, (GetScreenHeight() - 450.0f) / 2, 300.0f, 450.0f};
                Rectangle closeBtn = {popupBounds.x + popupBounds.width - 40, popupBounds.y + 10, 30, 30};
                if (CheckCollisionPointRec(mouse, closeBtn))
                {
                    showInventoryPopup = false;
                }
            }

            else
            {
                bool buttonClicked = false;
                for (int i = 0; i < options.size(); i++)
                {
                    if (CheckCollisionPointRec(mouse, optionRects[i]))
                    {
                        selected = i;
                        buttonClicked = true;
                        break;
                    }
                }

                if (buttonClicked)
                {
                    return selected;
                }

                for (auto const &[name, bounds] : locationBounds)
                {
                    if (CheckCollisionPointRec(mouse, bounds))
                    {
                        clickedLocation = game.getMapPlan().GetLocationptr(name);
                        showLocationItemsPopup = true;
                        locationScrolly = 0.0f;
                        break;
                    }
                }
            }
        }

        if (IsKeyPressed(KEY_ESCAPE))
        {
            showInventoryPopup = false;
            showLocationItemsPopup = false;
            clickedLocation = nullptr;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        Texture2D bg = backgroundTextures["menu"];
        DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height}, {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, {0, 0}, 0.0f, WHITE);

        DrawRectangleLines(mapPos.x - 5, mapPos.y - 5, mapW + 10, mapH + 10, DARKGRAY);
        DrawTexturePro(mapTexture,
                       {0, 0, (float)mapTexture.width, (float)mapTexture.height},
                       {mapPos.x, mapPos.y, mapW, mapH},
                       {0, 0}, 0.0f, WHITE);

        DrawCharactersOnMap(game.heroes, game.Monsters, game.villagers, game.GetItemsInGame(), 30, {0, 0});
        DrawTerrorLevel(game.terrorLevel, font, {8, 484});

        Vector2 draculaMatPos = {(float)GetScreenWidth() - 165.0f, 40.0f};
        if (auto dracula = game.GetDracula())
        {
            DrawDraculaMat(game, draculaMatPos);
        }
        else
        {

            const char *defeatedMsg = "Dracula is Defeated";
            float fontSize = 18.0f;
            Vector2 textSize = MeasureTextEx(font, defeatedMsg, fontSize, 1);
            DrawTextEx(font, defeatedMsg, {draculaMatPos.x + (148.0f - textSize.x) / 2, draculaMatPos.y + 20}, fontSize, 1, RED);
        }

        Vector2 inMatPos = {(float)GetScreenWidth() - 330.0f, 40.0f};
        if (auto invisible = game.GetInvisibleMan())
        {
            DrawInvisibleManMat(invisible->GetEvidence(), font, inMatPos);
        }
        else
        {

            const char *defeatedMsg = "Invisible Man is Defeated";
            float fontSize = 18.0f;
            Vector2 textSize = MeasureTextEx(font, defeatedMsg, fontSize, 1);
            DrawTextEx(font, defeatedMsg, {inMatPos.x + (148.0f - textSize.x) / 2, inMatPos.y + 20}, fontSize, 1, SKYBLUE);
        }

        Rectangle inventoryClickZone = {0};
        if (game.heroPlayer)
        {

            Vector2 heroInfoPos = {inMatPos.x, inMatPos.y + 290.0f};
            DrawHeroInfo(game.heroPlayer, font, heroInfoPos, &inventoryClickZone);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), inventoryClickZone))
            {
                showInventoryPopup = true;
                inventoryScrolly = 0.0f;
            }
        }

        if (game.heroPlayer && game.heroPlayer->PeekPerkCard())
        {
            Vector2 perkCardPos = {(float)GetScreenWidth() - 165.0f, 301.0f};
            DrawPerkCard(game.heroPlayer->PeekPerkCard(), font, perkCardPos);
        }

        if (!showInventoryPopup && !showLocationItemsPopup)
        {
            for (int i = 0; i < options.size(); i++)
            {
                bool hover = CheckCollisionPointRec(mouse, optionRects[i]);
                DrawRectangleRounded(optionRects[i], 0.3f, 8, hover ? hoverColor : buttonColor);

                const char *text = options[i].c_str();
                int fontSize = 18;
                int tw = MeasureText(text, fontSize);
                while (tw > buttonWidth - 10 && fontSize > 12)
                {
                    fontSize--;
                    tw = MeasureText(text, fontSize);
                }
                Vector2 textSize = MeasureTextEx(font, text, fontSize, 1);
                DrawTextEx(font, text,
                           {optionRects[i].x + (buttonWidth - textSize.x) / 2,
                            optionRects[i].y + (buttonHeight - textSize.y) / 2},
                           fontSize, 1, WHITE);
            }
        }

        if (showInventoryPopup)
        {
            DrawInventoryPopup(game.heroPlayer, inventoryScrolly);
        }

        if (showLocationItemsPopup)
        {
            DrawLocationInfoPopup(clickedLocation, locationScrolly);
        }

        EndDrawing();
    }

    return selected;
}
void ShowInTerminal::ShowMonsterPhase(Game &game, std::shared_ptr<MonsterCard> card)
{
    float screenW = (float)GetScreenWidth();
    float screenH = (float)GetScreenHeight();

    float mapW = 545;
    float mapH = 542;
    Vector2 mapPos = {0, 0};

    float cardW = 265;
    float cardH = 370;
    Texture2D monsterTexture = monsterCardTextures[card->GetName()];
    float cardScale = cardW / (float)monsterTexture.width;
    Vector2 cardPos = {mapPos.x + mapW + 45, 0};

    BeginDrawing();

    Texture2D bg = backgroundTextures["menu"];
    DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height}, {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, {0, 0}, 0.0f, WHITE);

    DrawRectangleLines(mapPos.x - 5, mapPos.y - 5, mapW + 10, mapH + 10, DARKGRAY);
    DrawTexturePro(
        mapTexture,
        {0, 0, (float)mapTexture.width, (float)mapTexture.height},
        {mapPos.x, mapPos.y, mapW, mapH},
        {0, 0}, 0.0f, WHITE);

    DrawCharactersOnMap(game.heroes,
                        game.Monsters,
                        game.villagers,
                        game.GetItemsInGame(),
                        30,
                        {0, 0});

    DrawRectangleLines(cardPos.x - 5, cardPos.y - 5, cardW + 10, cardH + 10, DARKGRAY);
    DrawMonsterCard(card, cardPos, cardScale);

    DrawDiceMat();

    EndDrawing();
}

Font ShowInTerminal::GetFont() { return font; }
