#include "cards.h"
#include <string>
#include <vector>
using namespace std;

Card::Card(Suit s, Rank r)
{
    suit = s;
    rank = r;
}

Suit Card::getSuit() const
{
    return suit;
}
Rank Card::getRank() const
{
    return rank;
}
bool operator==(const Card &c1, const Card &c2)
{
    return c1.getSuit() == c2.getSuit() && c1.getRank() == c2.getRank();
}
void Card::printCards(vector<Card> cards) const
{
    string suites[4] = {"\x05", "\x04", "\x03", "\x06"};
    string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
    // this function will likely be moved to the player class instead of the cards class
    for (int i = 0; i < cards.size(); i++)
    {
        if (i != 0)
        {
            cout << "  ";
        }
        cout << "*------*";
    }
    cout << endl;
    for (int i = 0; i < cards.size(); i++)
    {
        if (i != 0)
        {
            cout << "  ";
        }
        cout << "|      |";
    }
    cout << endl;
    for (int i = 0; i < cards.size(); i++)
    {
        if (i != 0)
        {
            cout << "  ";
        }
        cout << "|  " << ranks[cards[i].getRank()] << suites[cards[i].getSuit()] << "  |";
    }
    cout << endl;
    for (int i = 0; i < cards.size(); i++)
    {
        if (i != 0)
        {
            cout << "  ";
        }
        cout << "|      |";
    }
    cout << endl;
    for (int i = 0; i < cards.size(); i++)
    {
        if (i != 0)
        {
            cout << "  ";
        }
        cout << "*------*";
    }
    cout << endl;
};
//*------*
//|      |
//|  7H  |
//|      |
//*------*
int main()
{
    Card c1 = Card(CLUBS, SEVEN);
    Card c2 = Card(DIAMONDS, SIX);
    Card c3 = Card(SPADES, TEN);
    Card c4 = Card(HEARTS, ACE);
    vector<Card> cards;
    cards.push_back(c1);
    cards.push_back(c2);
    cards.push_back(c3);
    cards.push_back(c4);
    c1.printCards(cards);
    return 0;
}