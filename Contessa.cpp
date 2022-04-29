#include "Contessa.hpp"

using namespace coup;

Contessa::Contessa(Game &g, std::string s): Player(s, "Contessa"), game{&g} {
    g.add_Player(*this);
}

void Contessa::coup(Player &p){
    if(coins() < 3){
        throw std::invalid_argument("Insufficient funds");
    }
    game->remove_player(p);
    action_object = &p;
}

void Contessa::block(Player &p){
    
    if(p.role() != "Assassin"){
        throw std::invalid_argument("Contessa can block assasins only");
    }
    if(p.action_object == nullptr ){
        throw std::invalid_argument("No action to block");
    }
    game->add_Player(*p.action_object);
}