#include "Contessa.hpp"

using namespace coup;

Contessa::Contessa(Game &g, std::string s): Player(s, "Contessa"), game{&g} {
    g.add_Player(*this);
}

void Contessa::coup(Player &p){
    if(coins() < 3){
        throw "Insufficient funds";
    }
    game->remove_player(p);
    action_object = &p;
}

void Contessa::block(Player &p){
    
    if(p.role() != "Contessa"){
        throw "Contessa can block assasins only";
    }
    if(p.action_object == nullptr ){
        throw "No action to block";
    }
    game->add_Player(*p.action_object);
}