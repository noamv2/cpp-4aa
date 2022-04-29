#include "Game.hpp"
namespace coup{
    
    class Contessa : public Player
    {
    
    private:
        Game* game;
        
    public:
        Contessa(Game &g, std::string name);
        
        void coup(Player &p);
        //unique traits
        void block(Player &p);
    };
    
}