#pragma once

#include "Game.hpp"

namespace coup{
    class Captain: public Player
    {
    private:
        Game * game;
    public:
        
        Captain(Game & g, std::string name);
        void coup(Player &p);
        //unique traits
        void steal(Player &p); 
        void block(Player &p);
    };
}
