#include "cards.h"
#include <string>
#include <vector>
using namespace std;

Card::Card(Suit s, Rank r, bool h) : suit(s), rank(r), hidden(h)
{
    if (r == JACK || r == QUEEN || r == KING)
    {
        value = 10;
    }
    else
    {
        value = r + 1;
    }
}

Suit Card::getSuit() const
{
    return suit;
}
Rank Card::getRank() const
{
    return rank;
}
void Card::changehidden()
{
    hidden = !hidden;
}
int Card::getValue() const
{
    return value;
}
void Card::setValue(int v)
{
    value = v;
}
bool Card::getHidden() const
{
    return hidden;
}

void Card::printCard() const
{
    string suites[4] = {"\x05", "\x04", "\x03", "\x06"};
    string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
    cout << ranks[rank] << suites[suit] << " Current value: " << value;
}