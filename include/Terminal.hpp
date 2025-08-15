#ifndef TERMINAL_HPP
#define TERMINAL_HPP
#include "../include/MonsterCard.hpp"
#include "../include/Perk.hpp"
#include "../include/Hero.hpp"
#include "../include/Villager.hpp"
#include "../include/Item.hpp"
#include "../include/Dice.hpp"
#include <map>
#include <string>
#include <memory>
#include "raylib.h"
#include <unordered_map>
class Game;
class ShowInTerminal{
  private :
  std :: unordered_map<std :: string , Texture2D> heroTextures;
  std :: unordered_map<std :: string , Texture2D> monsterTextures;
  std :: unordered_map<std :: string , Texture2D> itemTextures;
  std :: unordered_map<std :: string , Texture2D> perkTextures;
  std :: unordered_map<std :: string , Texture2D> monstermatTextures;
  std :: unordered_map<std :: string , Texture2D> backgroundTextures;
  std :: unordered_map<std :: string , Texture2D> monsterCardTextures;
  std :: unordered_map<std :: string , Texture2D> villagerTextures;
  std :: map<std :: string, Vector2> locationPositions;
  std :: map<std :: string, Rectangle> locationBounds;
  std :: unordered_map<std :: string , Texture2D> diceFaces;
  std :: vector <std :: string> currentFaces;
  Texture2D frenzyMark;
  Texture2D mapTexture;
  Texture2D coffinBrokenTexture;
  Texture2D coffinIntactTexture;
  Texture2D DiceBack;
  Font font;
  std::vector<std::string> logMessages;
  const int maxLogLines = 5;
  bool showInventoryPopup = false;
  Rectangle inventoryPopupBounds = {0 , 0 , 545 , 450};
bool showLocationItemsPopup = false;
std::shared_ptr<Location> clickedLocation = nullptr;
Rectangle locationPopupBounds = { 200, 100, 400, 500 };
   
  public :
  Music music;
  void DrawLocationInfoPopup(std::shared_ptr<Location> location, float& scrollY);
  ShowInTerminal()= default;
  void ShowMessageBox(const std :: string&);
  void LoadAssets();
  void UnloadAssets();
  void DrawInventoryPopup(std::shared_ptr<Hero> hero);
  std::vector<std::string> ShowDiceRollAnimation(Dice &dice, Font font);
  void DrawDiceMat();
  int MenuGenerator(const std::vector<std::string>& options);
  bool GetPlayerInfo(std::string& name, int& days);
  void ShowBackgroundScreen(std::string title , std::string text);
  void DrawTerrorLevel(int terrorLevel, Font font, Vector2 position);
  void DrawHeroInfo(std::shared_ptr<Hero> hero, Font font, Vector2 position , Rectangle* );
  void DrawPerkCard(const std::shared_ptr<PerkCard>& card, Font font, Vector2 position);
  void DrawMonsterCard(const std::shared_ptr<MonsterCard>& card, Vector2 position , float);
  float GetBestScaleForCharacters(Texture2D ObjectTexture);
  void DrawDraculaMat(Game& , Vector2);
  void DrawInvisibleManMat(const std::vector<std::pair<bool, std::string>>& evidences, Font font, Vector2 position);
  void DrawItemsList(const std::vector<std::shared_ptr<Item>>& items, Font font, Vector2 position);
  void DrawCharactersOnMap(
       const std::vector<std::shared_ptr<Hero>> &heroes,
    const std::vector<std::shared_ptr<Monster>> &monsters,
    const std::vector<std::shared_ptr<Villager>> &villagers,
    const std::vector<std::shared_ptr<Item>> Items,
    float scale,
    Vector2 mapDrawPos,
    float mapDrawWidth ,
    float mapDrawHeight );
   // std::vector<std::string> ShowDiceRollAnimation(Dice &dice, Font font);
  int ShowHeroPhase( Game& game, const std::vector<std::string>& options);
  void ShowMonsterPhase( Game & game , std :: shared_ptr<MonsterCard>);
  void DrawLocationItemsPopup(std :: shared_ptr<Location> location);
  void ShowPopupMessages(Game & game ,const std::string lines);
  void ShowHelpScreen();
  Font GetFont();

};
#endif