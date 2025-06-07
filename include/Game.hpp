#ifndef GAME_HPP
#define GAME_HPP
#include "../include/Monster.hpp"
#include "../include/Card.hpp"
#include "../include/Perk.hpp"
#include "../include/MonsterCard.hpp"
#include "../include/Hero.hpp"
#include "../include/Map.hpp"
#include "../include/Location.hpp"
#include <vector>
#include <memory>
class Game{
    private :
    Map mapPlan;
    // std :: vector <Hero> heros;
    std :: vector <Monster> Monsters;
    // std :: vector <Villager> villagers;
    // std :: vector < Item> Items;

    std :: vector <std :: unique_ptr<PerkCard>> PerkDeck;
    std :: vector <std :: unique_ptr< MonsterCard>> MonsterDeck;
    int terrorLevel;
    Hero *heroPlayer;
    bool GameOver;
    void SetUpGame();
    void InitializeLocations();
    void InitializeItem();
    void InitializeCards();
    // void InitializeCharacters();
    public :
    void ShowMapRoad()const;
    Game();
    ~Game();
    // void StartGame();
    // void HeroPhase();
    // void MonsterPhase();
    // void CheckGameEnd();
    // void IncreaseTerrorLevel();

};
#endif