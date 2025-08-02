#ifndef GAME_FILE_HANDLER_HPP
#define GAME_FILE_HANDLER_HPP

#include "Game.hpp"

class GameFileHandler {
public:
    static void SaveGame(Game& game, const std::string& filename); 
    static void LoadGame(Game& game, const std::string& filename);
};

#endif
