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
    bool isSplitable = false;

public:
    Hand();
    void addCard(std::shared_ptr<Card> card);
    bool getInPlay() const;
    bool getHasAces() const;
    void configureAceValues();
    int getsum() const;
    bool getisSplitable() const;
    void printHand();
    shared_ptr<Card> getCard(int i);
    shared_ptr<Card> getback();
};
#endif