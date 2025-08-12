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
#include "../include/Courier.hpp"
#include <vector>
#include <memory>
class Game{
    friend class Hero;
    friend class Monster;
    friend class ShowInTerminal;
    friend class PerkCard;
    friend class MonsterCard;
    friend class Dracula;
    friend class Courier;
    friend class InvisibleMan;
    friend class GameFileHandler;
    private :
    Map mapPlan;
    int terrorLevel;
    std :: shared_ptr <Hero>heroPlayer;
    std :: shared_ptr <Hero>heroPlayer2;
    bool GameOver;
    bool skipMonsterPhase;
    bool showMessage;
    std :: string message;
    Dice GameDice;
    std :: vector <std :: shared_ptr<Hero>> heroes;
    std :: vector <std :: shared_ptr <Monster>> Monsters;
    std :: vector <std :: shared_ptr<Villager>> villagers;
    std :: vector <std :: shared_ptr <Item>> Items;
    std :: vector <std :: shared_ptr <Item>> EmptyBackUpItems;
    std :: vector <std :: shared_ptr<PerkCard>> PerkDeck;
    std :: vector <std :: shared_ptr< MonsterCard>> MonsterDeck;
    void SetUpGame();
    void InitializeLocations();
    void InitializeItem();
    void InitializeCards();
    void InitializeCharacters();
    public :
    ShowInTerminal MyTerminal;
    void GameStart();
    Game();
    Game(const Game &) = delete;
    Game & operator=(const Game &) = delete;
    ~Game();
    void ChooseHero(std::string , std::string);
    bool HeroPhase();
    void SetRandomItems(int);
    void MonsterPhase();
    void SwitchPlayer();
    //void Help();
    bool CheckGameEnd();
    void increaseTerrorLevel();
    void RemoveVillagerFromGame(std::shared_ptr<Villager>);
    std::vector<std::shared_ptr<Villager>>& getVillagers();
    Map& getMapPlan();
    std::vector<std::shared_ptr<Item>> GetItemsInGame();
    std::shared_ptr<Dracula> GetDracula();
    std::shared_ptr<InvisibleMan> GetInvisibleMan();
    void Reset();
    Game& GetGame(){return *this;};
    // test
};
#endif