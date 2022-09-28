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
    // create istream and ostream operators as friends
    friend std::istream &operator>>(std::istream &is, Card &aCard);
    Suit suit;
    Rank rank;

public:
    // create constructor
    Card(Suit s = CLUBS, Rank r = ACE);
    // get suit
    Suit getSuit() const;
    // get rank
    Rank getRank() const;
    void printCards(std::vector<Card>) const;
};
// comparator for suit and rank
bool operator==(const Card &c1, const Card &c2);
std::istream &operator>>(std::istream &in, Card &c);
#endif