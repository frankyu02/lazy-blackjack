#ifndef PLAYER_H
#define PLAYER_H
#include "cards.h"
#include <vector>
#include <memory>
#include "deck.h"
#include "hand.h"
#include <string>

class Player
{
protected:
    std::vector<std::shared_ptr<Hand>> hands;
    int money;
    int Bet = 0;
    bool natural = false;
    virtual ~Player() = default;
    void split();
    string name;

public:
    bool getNatural() const;
    void bet(int);
    Player(int m = 100, string n = "Player");
    // normal play function
    virtual void play(std::shared_ptr<Deck> deck) = 0;
    // run once at start of each game.
    virtual void init(std::shared_ptr<Deck> deck) = 0;
    void reset();
    std::vector<std::shared_ptr<hand>> getHands() const;
    void subMoney(int);
    void addMoney(int);
    int getMoney() const;
    int gethandsize() const;
    string getName() const;
};
#endif