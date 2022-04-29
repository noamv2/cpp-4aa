#pragma once

#include "Game.hpp"

namespace coup{
    class Duke : public Player
    {
    private:
        Game * game;
    public:
        Duke(Game &g, std::string name);
        
        void coup(Player &p);
        //unique traits
        void tax();
        void block(Player &p);

    };

}
