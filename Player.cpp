#include "Game.hpp"
using namespace coup;

Player::Player(std::string name, std::string role):balance{0}, name{name}, role_name{role},took_fa{false}{

}

Player::Player(Game * g, std::string name, std::string role):game{g},balance{0}, name{name}, role_name{role},took_fa{false}{
}

void Player::income(){
    game->play(*this);
    reset_actions();
    ++balance;
}

void Player::foreign_aid(){
    game->play(*this);
    reset_actions();
    took_fa = true;
    balance += 2;
}

void Player::coup(Player & p){
    game->play(*this);
    reset_actions();
    if(balance < 7){
        throw std::invalid_argument("Insufficient funds to coup");
    }
    game->remove_player(p);
}

std::string Player::role(){

    return role_name;
}
int Player::coins(){
    return balance; 
}


void Player::change_balance(int sum){
    balance += sum;
    if(balance < 0){
        balance = 0;
    }
}
void Player::reset_actions(){
    action_object = nullptr;
    took_fa = false;
}

