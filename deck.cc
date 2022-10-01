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
    string suites[4] = {"\x05", "\x04", "\x03", "\x06"};
    string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
    int count = 0;
    for (auto &card : deck)
    {
        cout << ranks[card->getRank()] << suites[card->getSuit()] << " ";
        count++;
        if (count % 13 == 0)
        {
            cout << endl;
        }
    }
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
std::shared_ptr<Card> Deck::deal()
{
    std::shared_ptr<Card> temp = deck.back();
    deck.pop_back();
    return temp;
}
