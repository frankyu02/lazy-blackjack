#include "player.h"
#include "deck.h"

Player::Player(int m) : money{m} {}
void Player::split()
{
    // create new vector and pop last element of hand[0] into it
    std::vector<std::shared_ptr<Card>> newHand;
    newHand.push_back(hand[0].back());
    hand[0].pop_back();
}