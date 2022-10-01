#include "player.h"
#include "deck.h"

using namespace std;
Player::Player(int m) : money{m}
{
    hands.emplace_back(std::make_shared<Hand>());
}

void Player::split()
{
    hands.emplace_back(std::make_shared<Hand>());
    shared_ptr<Card> temp = hands[0]->getback();
    temp->changehidden();
    hands[1]->addCard(temp);
}
void Player::doubleDown(std::shared_ptr<Deck> deck)
{
    shared_ptr<Card> temp = deck->deal();
    temp->changehidden();
    hands[0]->addCard(temp);
}
void Player::bet(int b)
{
    Bet += b;
}
void Player::hit(std::shared_ptr<Deck> deck, std::vector<std::shared_ptr<Card>> &hand)
{
    hand.emplace_back(deck->deal());
}