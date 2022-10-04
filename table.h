#ifndef TABLE_H
#define TABLE_H
#include "player.h"
#include "deck.h"
#include "human.h"
#include "dealer.h"
#include <vector>
class Table
{
    std::vector<std::shared_ptr<Player>> players;
    std::shared_ptr<Deck> deck;

public:
    Table(std::vector<std::shared_ptr<Player>> p, std::shared_ptr<Deck> d);
    void play();
};
#endif