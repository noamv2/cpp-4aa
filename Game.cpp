#include "Game.hpp"
using namespace coup;

Game::Game():players_count{0}{

}

std::string Game::turn(){
    return players_q.front()->get_name();
}

std::vector<std::string> Game::players(){
    std::vector<std::string> names;
    std::queue<Player *> cpy = players_q;

    while(!cpy.empty()){

            names.push_back(cpy.front()->get_name());
            cpy.pop();

    }
    
    return names;
}

std::string Game::winner(){return "";}

void Game::add_Player(Player &p){
    if(players_count > 5){
        throw "too many players";
    }
    players_q.push(&p);
    ++players_count;
}

void Game::remove_player(Player &p){

    std::queue<Player *> temp;
    // move all the players from the original queue to 
    while(!players_q.empty()){
        Player * t = players_q.front();
        if(t == &p){
            players_q.pop(); 
            continue; //remove the player we were asked to emit   
        }
        temp.push(t);
        players_q.pop();
    }
    if(temp.size() == players_count){
        throw "Player doesnt exsits, remove failed";
    }

    players_count--;
    // return the remaining players to the original queue
    while(!temp.empty()){
        Player * t = temp.front();
        players_q.push(t);
        temp.pop();
    }
}