#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include "deck.h"

class Human : public Player
{
public:
    Human(int m = 100);
    void play(std::shared_ptr<Deck> deck) override;
    void init(std::shared_ptr<Deck> deck) override;
};
#endif