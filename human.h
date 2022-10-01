#ifndef HUMAN_H_
#define HUMAN_H_
#include "player.h"
#include "deck.h"

class Human : public Player
{
    Human(int m = 100);
    void display_hand(std::vector<std::shared_ptr<Card>> hand) const override;
    void play(std::shared_ptr<Deck> deck) override;
    void hit(std::shared_ptr<Deck> deck, std::vector<std::shared_ptr<Card>> &hand) override;
    void doubleDown(std::shared_ptr<Deck> deck, std::vector<std::shared_ptr<Card>> &hand) override;
    void dealwithAces(std::vector<std::shared_ptr<Card>> &hand) override;
};
#endif