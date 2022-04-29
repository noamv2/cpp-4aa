#include "Assassin.hpp"

using namespace coup;

Assassin::Assassin(Game &g, std::string s):Player(s, "Assassin"), game{&g}{
    g.add_Player(*this);
}

void Assassin::coup(Player &p){
    if(coins() < 3){
        throw std::invalid_argument("Insufficient funds");
    }
    game->remove_player(p);
    action_object = &p;
}