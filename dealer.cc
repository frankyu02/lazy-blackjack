#include "dealer.h"

using namespace std;

Dealer::Dealer(int m, string n) : Player(m, n) {}

void setAllAces(shared_ptr<Hand> hand, int i)
{
    vector<shared_ptr<Card>> cards = hand->getCards();
    for (auto &card : cards)
    {
        if (card->getRank() == ACE)
        {
            card->setValue(i);
        }
    }
}
void Dealer::play(shared_ptr<Deck> deck)
{
    for (auto &hand : hands)
    {
        while (true)
        {
            if (hand->getsum() > 21)
            {
                if (hand->getHasAces())
                {
                    setAllAces(hand, 1);
                    hand->calculateScore();
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (hand->getsum() < 17)
            {
                hand->addCard(deck->deal());
                continue;
            }
            else
            {
                break;
            }
        }
    }
}

void Dealer::init(shared_ptr<Deck> deck)
{
    for (auto &hand : hands)
    {
        shared_ptr<Card> card1 = deck->deal();
        card1->changehidden();
        hand->addCard(card1);
        hand->addCard(deck->deal());
        if (hand->getHasAces())
        {
            setAllAces(hand, 11);
        }
    }
}
