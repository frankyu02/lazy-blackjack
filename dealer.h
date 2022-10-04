#ifndef DEALER_H
#define DEALER_H
#include "player.h"

class Dealer : public Player
{
public:
    Dealer(int m = 100, std::string n = "Dealer");
    void play(std::shared_ptr<Deck> deck) override;
    void init(std::shared_ptr<Deck> deck) override;
};
#endif
