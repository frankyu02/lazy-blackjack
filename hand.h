#ifndef HAND_H
#define HAND_H
#include "cards.h"
#include <vector>
#include <memory>
class Hand
{
    std::vector<std::shared_ptr<Card>> hand;
    int sum = 0;
    bool hasAces = false;
    bool inPlay = true;
    bool isSplitable = false;
    bool doubledDown = false;
    bool bust = false;

public:
    Hand();
    void addCard(std::shared_ptr<Card> card);
    bool getInPlay() const;
    bool getHasAces() const;
    void configureAceValues();
    int getsum() const;
    bool getisSplitable() const;
    void printHand();
    std::shared_ptr<Card> getCard(int i);
    std::shared_ptr<Card> getback();
    void calculateScore();
    bool checkNatural();
    void setInPlay(bool);
    bool getDoubledDown() const;
    void setDoubledDown(bool);
    bool getBust() const;
};
#endif