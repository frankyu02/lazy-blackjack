#include "deck.h"
#include "cards.h"
#include <iostream>
using namespace std;

Deck::Deck()
{
    // make a deck of 312 cards
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                deck.emplace_back(make_shared<Card>(Suit(i), Rank(j)));
            }
        }
    }
}
void Deck::shuffle(unsigned seed)
{
    default_random_engine rng{seed};
    for (int i = 0; i < 1000; i++)
    {
        std::shuffle(deck.begin(), deck.end(), rng);
    }
}
void Deck::printDeck() const
{
    for (int i = 0; i < deck.size(); i++)
    {
        if (i != 0)
        {
            cout << " , ";
        }
        if (i % 13 == 0)
        {
            cout << endl;
        }
        cout << deck[i]->getRank() << " " << deck[i]->getSuit();
    }
    cout << endl;
}
void Deck::reset()
{
    deck.clear();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                deck.emplace_back(make_shared<Card>(Suit(i), Rank(j)));
            }
        }
    }
}
