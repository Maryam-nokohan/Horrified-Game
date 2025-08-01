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
  Texture2D frenzyMark;
  Texture2D mapTexture;
  Texture2D coffinBrokenTexture;
  Texture2D coffinIntactTexture;
  Font font;
  std::vector<std::string> logMessages;
  const int maxLogLines = 5;
  bool showInventoryPopup = false;
  Rectangle inventoryPopupBounds = {0 , 0 , 400 , 300};
   
  public :
  ShowInTerminal()= default;
  void ShowMessageBox(const std :: string&);
  void LoadAssets();
  void UnloadAssets();
  void DrawInventoryPopup(std::shared_ptr<Hero> hero);
  std::vector<std::string> ShowDiceRollAnimation(Dice &dice, Font font);
  void DrawMessageBox(const std :: string& message , bool&);
  void Enter(bool&);
  int MenuGenerator(const std::vector<std::string>& options);
  bool GetPlayerInfo(std::string& name, int& days);
  void ShowExitScreen();
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
  void ShowPopupMessages(Game & game ,const std::string lines);
  Font GetFont();

};
#endif