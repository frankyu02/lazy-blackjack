#ifndef HAND_H_
#define HAND_H_
#include "cards.h"
#include <vector>
#include <memory>
class Hand
{
    std::vector<std::shared_ptr<Card>> hand;
    int sum = 0;
    bool hasAces = false;
    bool inPlay = true;
    void calculateScore();

public:
    Hand();
    void addCard(std::shared_ptr<Card> card);
    bool getInPlay() const;
    void configureAceValues();
    int getsum() const;
    void printHand();
};
#endif