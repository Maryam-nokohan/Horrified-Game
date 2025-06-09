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
#include "../include/Location.hpp"
#include "../include/Terminal.hpp"
#include <vector>
#include <memory>
class Game{
    friend class ShowInTerminal;
    private :
    Map mapPlan;
    std :: vector <std :: unique_ptr<Hero>> heroes;
    std :: vector <std :: unique_ptr <Monster>> Monsters;
    // std :: vector <Villager> villagers;
    std :: vector <Item> Items;

    std :: vector <std :: unique_ptr<PerkCard>> PerkDeck;
    std :: vector <std :: unique_ptr< MonsterCard>> MonsterDeck;
    int terrorLevel;
    std :: unique_ptr <Hero> heroPlayer;
    bool GameOver;
    void SetUpGame();
    void InitializeLocations();
    void InitializeItem();
    void InitializeCards();
    void InitializeCharacters();
    public :
    void GameStart();
    void ShowMapRoad()const;
    Game();
    Game(const Game &) = delete;
    Game & operator=(const Game &) = delete;
    ~Game();
    // void HeroPhase();
    // void MonsterPhase();
    // void CheckGameEnd();
    // void IncreaseTerrorLevel();

};
#endif