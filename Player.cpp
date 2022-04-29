#include "Player.hpp"
using namespace coup;

Player::Player(std::string name, std::string role):balance{0}, name{name}, role_name{role},took_fa{false}{

}

void Player::income(){
    reset_actions();
    ++balance;
}

void Player::foreign_aid(){
    reset_actions();
    took_fa = true;
    balance += 2;
}

void Player::coup(Player & p){
    reset_actions();
    if(balance < 7){
        throw "Insufficient funds to coup";
    }

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
        throw("Cant have negetive balance");
    }
}
void Player::reset_actions(){
    action_object = nullptr;
    took_fa = false;
}

