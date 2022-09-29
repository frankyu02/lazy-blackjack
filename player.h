#ifndef PLAYER_H_
#define PLAYER_H_
#include "cards.h"
#include <vector>
#include <memory>
#include "deck.h"

class Player
{
    std::vector<std::vector<std::shared_ptr<Card>>> hand;
    int score = 0;
    int money;
    int bet = 0;
    int aceValue = 1;
    bool playing = true;
    bool willBustonChange = false;                                            // determin if switching acevalue will cause bust
    virtual void calculateScore(std::vector<std::shared_ptr<Card>> hand) = 0; // should change aceValue to 1 if bust
    void split();

public:
    Player(int m = 100);
    virtual void display_hand(std::vector<std::shared_ptr<Card>> hand) const = 0;
    virtual void play(std::shared_ptr<Deck> deck) = 0;
    virtual void hit(std::shared_ptr<Deck> deck, std::vector<std::shared_ptr<Card>> &hand) = 0;
    virtual void bet(int b);
    virtual void doubleDown(std::shared_ptr<Deck> deck, std::vector<std::shared_ptr<Card>> &hand) = 0;
};
#endif