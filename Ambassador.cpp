#include "Ambassador.hpp"

using namespace coup;

Ambassador::Ambassador(Game & g,std::string name):Player(name, "Ambassador"), game{&g} {
    g.add_Player(*this);
}

//can bloke the steal action performed by a captain
void Ambassador::block(Player &p){
    //Make sure that we are trying to block other captain
    if(p.role() != "Captain" || this == &p){
        throw std::invalid_argument("Captain can block another captain only");
    }
    if(p.action_object == nullptr ){
        throw std::invalid_argument( "No action to block");
    }
    p.change_balance(-2);
    p.action_object->change_balance(2);
}

void Ambassador::transfer(Player &from, Player &to){

    from.change_balance(-1);
    to.change_balance(1);
}

void Ambassador::coup(Player &p){
    if(coins() < 7){
        throw std::invalid_argument( "Insufficient funds");
    }

    game->remove_player(p);
}