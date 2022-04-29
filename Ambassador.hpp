#pragma once

#include "Game.hpp"

namespace coup{


    class Ambassador:public Player
    {
    private:
        Game * game;
    public:
        Ambassador(Game & g, std::string name);
        
        //unique traits

        void transfer(Player &from, Player & to);
        void block(Player &p);
        void coup(Player &p);

    };
}