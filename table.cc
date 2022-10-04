#include "table.h"

using namespace std;

Table::Table(vector<shared_ptr<Player>> p, shared_ptr<Deck> d) : players(p), deck(d) {}

void Table::play()
{
    int dealerIndex = players.size() - 1;
    for (auto &player : players)
    {
        player->reset();
        if (player->getName() != "Dealer")
        {
            cout << "Hello " << player->getName() << ", how much do you want to bet?" << endl;
            int bet;
            cin >> bet;
            player->bet(bet);
        }
    }
    for (auto &player : players)
    {
        player->init(deck);
    }
    if (players[dealerIndex]->getHands()[0]->getsum() == 21)
    {
        for (auto &player : players)
        {
            if (!player->getNatural())
            {
                player->subMoney(player->getBet());
            }
            else
            {
                player->addMoney(player->getBet() * 2);
            }
        }
        return;
    }
    for (auto &player : players)
    {
        player->play(deck);
    }
    if (players[dealerIndex]->getHands()[0]->getBust())
    {
        for (auto &player : players)
        {
            for (auto &hand : player->getHands())
            {
                if (!hand->getBust())
                {
                    player->addMoney(player->getBet());
                }
                else
                {
                    player->subMoney(player->getBet());
                }
            }
        }
        return;
    }
    else
    {
        int dealerSum = players[dealerIndex]->getHands()[0]->getsum();
        for (auto &player : players)
        {
            for (auto &hand : player->getHands())
            {
                if (hand->getsum() > dealerSum && !hand->getBust())
                {
                    player->addMoney(player->getBet());
                }
                else
                {
                    player->subMoney(player->getBet());
                }
            }
        }
        return;
    }
}