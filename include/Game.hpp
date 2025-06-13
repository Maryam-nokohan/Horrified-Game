#ifndef GAME_HPP
#define GAME_HPP
#include "../include/Dracula.hpp"
#include "../include/invisible.hpp"
#include "../include/Monster.hpp"
#include "../include/Card.hpp"
#include "../include/Perk.hpp"
#include "../include/MonsterCard.hpp"
#include "../include/Hero.hpp"
#include "../include/Map.hpp"
#include "../include/Item.hpp"
#include "../include/Location.hpp"
#include "../include/Terminal.hpp"
#include <vector>
#include <memory>
class Game{
    private :
    ShowInTerminal MyTerminal;
    Map mapPlan;
    std :: vector <std :: shared_ptr<Hero>> heroes;
    std :: vector <std :: shared_ptr <Monster>> Monsters;
    std :: vector <std :: shared_ptr<Villager>> villagers;
    std :: vector <std :: shared_ptr <Item>> Items;
    std :: vector <std :: shared_ptr<PerkCard>> PerkDeck;
    std :: vector <std :: shared_ptr< MonsterCard>> MonsterDeck;
    int terrorLevel;
    std :: shared_ptr <Hero>heroPlayer;
    bool GameOver;
    bool skipMonsterPhase;
    void SetUpGame();
    void InitializeLocations();
    void InitializeItem();
    void InitializeCards();
    void InitializeCharacters();
    public :
    void GameStart();
    void ShowMapRoad()const;
    void LocationOverView();
    void PlayerGetHit();

    Game();
    Game(const Game &) = delete;
    Game & operator=(const Game &) = delete;
    ~Game();
    void HeroPhase();
    void MonsterPhase();
    bool CheckGameEnd();
    // void IncreaseTerrorLevel();

};
#endif