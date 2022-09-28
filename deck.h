#ifndef DECK_H_
#define DECK_H_
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
    void printDeck() const;
};
#endif