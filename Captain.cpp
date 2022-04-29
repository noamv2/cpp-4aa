#include "Captain.hpp"

using namespace coup;

Captain::Captain(Game & g, std::string s): Player(s, "Captain"), game{&g} {   
    g.add_Player(*this);
}

void Captain::steal(Player & p){
    //steal 2 coins from another player
    p.change_balance(-2);
    this->change_balance(+2);
    action_object = &p;
}

void Captain::block(Player &p){
    //Make sure that we are trying to block other captain
    if(p.role() != "Captain" || this == &p){
        throw "Captain can block another captain only";
    }
    if(p.action_object == nullptr ){
        throw "No action to block";
    }
    p.change_balance(-2);
    p.action_object->change_balance(2);
}

void Captain::coup(Player &p){
    if(coins() < 7){
        throw "Insufficient funds";
    }

    game->remove_player(p);
}