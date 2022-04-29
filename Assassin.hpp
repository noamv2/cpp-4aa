#pragma once

#include "Game.hpp"
namespace coup{
    class Assassin: public Player
    {
    private:
        Game * game;
    public:
        Assassin(Game & g, std::string name);
        //unique traits
        void coup(Player &p);
    };
}
