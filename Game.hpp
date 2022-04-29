#pragma once
#include "Player.hpp"
#include <queue>

namespace coup{

    class Game{
        
        private:

        std::queue<Player *> players_q; 
        int players_count;

        public:
        Game();

        std::string turn();
        std::vector<std::string> players();
        std::string winner();
        
        void add_Player(Player &p);
        void remove_player(Player &p);
    };

}