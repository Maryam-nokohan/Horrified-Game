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
#include "../include/Dice.hpp"
#include <vector>
#include <memory>
class Game{
    friend class Hero;
    friend class ShowInTerminal;
    friend class PerkCard;
    friend class MonsterCard;
    private :
    Map mapPlan;
    std :: vector <std :: shared_ptr<Hero>> heroes;
    std :: vector <std :: shared_ptr <Monster>> Monsters;
    std :: vector <std :: shared_ptr<Villager>> villagers;
    std :: vector <std :: shared_ptr <Item>> Items;
    std :: vector <std :: shared_ptr<PerkCard>> PerkDeck;
    std :: vector <std :: shared_ptr< MonsterCard>> MonsterDeck;
    int terrorLevel;
    std :: shared_ptr<Dice> GameDice;
    std :: shared_ptr <Hero>heroPlayer;
    bool GameOver;
    bool skipMonsterPhase;
    void SetUpGame();
    void InitializeLocations();
    void InitializeItem();
    void InitializeCards();
    void InitializeCharacters();
    public :
    ShowInTerminal MyTerminal;
    void GameStart();
    void LocationOverView();
    Game();
    Game(const Game &) = delete;
    Game & operator=(const Game &) = delete;
    ~Game();
    void HeroPhase();
    void SetRandomItems(int);
    void MonsterPhase();
    bool CheckGameEnd();
    void increaseTerrorLevel();
    std::vector<std::shared_ptr<Villager>>& getVillagers();
    Map& getMapPlan();

    // void IncreaseTerrorLevel();

};
#endif