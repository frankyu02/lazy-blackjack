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
void Player::bet(int b)
{
    Bet += b;
}

bool Player::getNatural() const
{
    return natural;
}
void Player::reset()
{
    Bet = 0;
    natural = false;
    hands.clear();
    hands.emplace_back(std::make_shared<Hand>());
}
std::vector<std::shared_ptr<Hand>> Player::getHands() const
{
    return hands;
}
void Player::subMoney(int m)
{
    money -= m;
}
void Player::addMoney(int m)
{
    money += m;
}
int Player::getMoney() const
{
    return money;
}
int Player::gethandsize() const
{
    return hands.size();
}