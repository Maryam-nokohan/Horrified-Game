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
    ftxui::Element RenderTerrorLevel(int terrorLevel);
    ftxui::Element RenderDraculaMat(std ::vector<std::pair<bool , std::string>>);
    ftxui::Element RenderInvisibleManMat(std ::vector<std::pair<bool , std::string>>);
    ftxui::Element RenderMap();
    ftxui::Element RenderItems(const std::vector< std::shared_ptr<Item>>& items);
    ftxui::Element RenderHeroInfo(const std::shared_ptr<Hero>& hero);
    ftxui::Element RenderMonsterCard(const std::shared_ptr<MonsterCard>& card);
    ftxui::Element RenderPerkCard(const std::shared_ptr<PerkCard>& card);
    ftxui::Table RenderLocationOverview(
        const std::unordered_map<std::string, std::shared_ptr<Location>>& locations,
        const std::vector<std::shared_ptr<Monster>>& monsters,
        const std::vector<std::shared_ptr<Villager>>& villagers,
        const std::vector<std::shared_ptr<Item>>& items,
        const std::vector<std::shared_ptr<Hero>>&heros
    );

  public :
  ShowInTerminal()= default;
  int MenuGenerator(const std::vector<std::string>& options, std::string& msg, Texture2D bg, Font font);
  void StylizeTextBoard(const std :: string text);
  bool GetPlayerInfo(std::string& name, int& days , Font font , Texture2D bg);
  void ShowExitScreen(Texture2D bg, Font font);
  void DrawTerrorLevel(int terrorLevel, Font font, Vector2 position);
  void DrawHeroInfo(std::shared_ptr<Hero> hero, Font font, Vector2 position);
  void DrawPerkCard(const std::shared_ptr<PerkCard>& card, Font font, Vector2 position);
  void DrawMonsterCard(const std::shared_ptr<MonsterCard>& card, Font font, Vector2 position);
  void DrawDraculaMat(const std::vector<std::pair<bool, std::string>>& coffins, Font font, Vector2 position);
  int ShowHeroPhase( Game & game ,const std :: vector<std :: string> options);
  void ShowMonsterPhase( Game & game);
  void ShowPause();
  void ShowPauseWithRefresh();

};
#endif