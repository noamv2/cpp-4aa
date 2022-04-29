#include "Duke.hpp"
using namespace coup;

Duke::Duke(Game & g, std::string name):Player(name, "Duke"), game{&g}{
    g.add_Player(*this);
}

void Duke::tax(){change_balance(3);}

void Duke::coup(Player &p){
    if(coins() < 7){
        throw std::invalid_argument("Insufficient funds");
    }

    game->remove_player(p);
}

void Duke::block(Player &p){
    if(!p.took_fa){
        throw std::invalid_argument("No foreign add taken");
    }
    p.change_balance(-2);
}