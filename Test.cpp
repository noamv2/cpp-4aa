#include "doctest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"

using namespace coup;
TEST_CASE("Game 1"){

    Game game;
    Duke duke {game,"duke1"};
    Duke duke2 {game,"duke2"};
    Assassin assassin {game, "assassin"};
    Captain cap {game, "captain"};

    //check income
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(duke2.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(cap.income());
    
    CHECK(duke.coins() == 1);
    CHECK(duke2.coins() == 1);
    CHECK(assassin.coins() == 1);
    CHECK(cap.coins() == 1);

    //check foreign_aid
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(duke2.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(cap.foreign_aid());
    
    CHECK(duke.coins() == 3);
    CHECK(duke2.coins() == 3);
    CHECK(assassin.coins() == 3);
    CHECK(cap.coins() == 3);

    //check duke's blocking function
    CHECK_NOTHROW(duke.block(duke2));
    CHECK_NOTHROW(duke.block(assassin));
    CHECK_NOTHROW(duke.block(cap));

    CHECK(duke.coins() == 3);
    CHECK(duke2.coins() == 1);
    CHECK(assassin.coins() == 1);
    CHECK(cap.coins() == 1);

    

    SUBCASE("Turn system tests"){
        //its duke1 turn now
        CHECK_THROWS(cap.foreign_aid());
        CHECK_THROWS(duke2.foreign_aid());
        CHECK(game.turn() == "duke1");

        
    }
    

}