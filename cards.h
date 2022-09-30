#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <vector>
enum Suit
{
    CLUBS = 0,
    DIAMONDS,
    HEARTS,
    SPADES
};
enum Rank
{
    ACE = 0,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};
class Card
{
    Suit suit;
    Rank rank;
    int value;
    bool hidden;

public:
    // create constructor
    Card(Suit s = CLUBS, Rank r = ACE, bool h = false);
    // get suit
    Suit getSuit() const;
    // get rank
    Rank getRank() const;
    void printCards(std::vector<Card>) const;
    void changehidden();
    int getValue() const;
    void setValue(int);
    bool getHidden() const;
    void printCard() const;
};
#endif