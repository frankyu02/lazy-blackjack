#ifndef PLAYER_H_
#define PLAYER_H_
#include "cards.h"
#include <vector>
#include <memory>
#include "deck.h"
#include "hand.h"

class Player
{
protected:
    std::vector<std::shared_ptr<Hand>> hands;
    int money;
    int Bet;
    virtual ~Player() = default;
    void split();
    void doubleDown(std::shared_ptr<Deck> deck);
    void hit(std::shared_ptr<Deck> deck, std::vector<std::shared_ptr<Card>> &hand);

public:
    void bet(int);
    Player(int m = 100);
    virtual void play(std::shared_ptr<Deck> deck) = 0;
};
#endif