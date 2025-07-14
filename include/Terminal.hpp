#ifndef TERMINAL_HPP
#define TERMINAL_HPP
#include "../include/MonsterCard.hpp"
#include "../include/Perk.hpp"
#include "../include/Hero.hpp"
#include "../include/Villager.hpp"
#include "../include/Item.hpp"
#include <map>
#include <string>
#include <memory>
#include "raylib.h"
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
  Texture2D mapTexture;
  Texture2D coffinBrokenTexture;
  Texture2D coffinIntactTexture;
  Font font;
   

  public :
  ShowInTerminal()= default;
  void LoadAssets();
  void UnloadAssets();
  int MenuGenerator(const std::vector<std::string>& options, std::string& msg, Texture2D bg, Font font);
  bool GetPlayerInfo(std::string& name, int& days , Font font , Texture2D bg);
  void ShowExitScreen(Texture2D bg, Font font);
  void DrawTerrorLevel(int terrorLevel, Font font, Vector2 position);
  void DrawHeroInfo(std::shared_ptr<Hero> hero, Font font, Vector2 position);
  void DrawPerkCard(const std::shared_ptr<PerkCard>& card, Font font, Vector2 position);
  void DrawMonsterCard(const std::shared_ptr<MonsterCard>& card, Font font, Vector2 position);
  void DrawDraculaMat(const std::vector<std::pair<bool, std::string>>& coffins,Vector2 position);
  void DrawInvisibleManMat(const std::vector<std::pair<bool, std::string>>& evidences, Font font, Vector2 position);
  void DrawItemsList(const std::vector<std::shared_ptr<Item>>& items, Font font, Vector2 position);
  void DrawLocationOverview(const std::unordered_map<std::string, std::shared_ptr<Location>>& locations,
                          const std::vector<std::shared_ptr<Monster>>& monsters,
                          const std::vector<std::shared_ptr<Villager>>& villagers,
                          const std::vector<std::shared_ptr<Item>>& items,
                          const std::vector<std::shared_ptr<Hero>>& heroes,
                          Font font, Vector2 startPos);
  int ShowHeroPhase( Game& game, const std::vector<std::string>& options, Texture2D mapTexture, Font font);
  void ShowMonsterPhase( Game & game , Font font);

};
#endif