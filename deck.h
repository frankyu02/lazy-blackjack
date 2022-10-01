#ifndef DECK_H
#define DECK_H
#include "cards.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>
class Deck
{
    std::vector<std::shared_ptr<Card>> deck;

public:
    Deck();
    void reset();
    void shuffle(unsigned seed = std::chrono::system_clock::now().time_since_epoch().count());
    std::shared_ptr<Card> deal();
    void printDeck() const;
};
#endif