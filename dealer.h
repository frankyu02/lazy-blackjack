#include "player.h"

class Dealer : public Player
{
public:
    Dealer(int m = 100, string n = "Dealer");
    void play(std::shared_ptr<Deck> deck) override;
    void init(std::shared_ptr<Deck> deck) override;
};
