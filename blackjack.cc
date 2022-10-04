#include "cards.h"
#include "deck.h"
#include "player.h"
#include "human.h"
#include "dealer.h"
#include "table.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    // create deck
    shared_ptr<Deck> deck = make_shared<Deck>();
    if (argc == 1)
    {
        deck->shuffle(atoi(argv[1]));
    }
    else
    {
        deck->shuffle();
    }
    // create dealer
    shared_ptr<Dealer> dealer = make_shared<Dealer>(100000);
    // ask for number of players
    cout << "How many players are there?" << endl;
    int numPlayers;
    cin >> numPlayers;
    // create players
    vector<shared_ptr<Player>> players;
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "What is the name of player " << i + 1 << "?" << endl;
        string name;
        cin >> name;
        shared_ptr<Human> player = make_shared<Human>(100, name);
        players.emplace_back(player);
    }
    players.emplace_back(dealer);
    // create table
    Table table(players, deck);
    // play game
    while (true)
    {
        try
        {
            table.play();
            // ask if they want to play again
            cout << "Do you want to play again? (y/n)" << endl;
            string answer;
            cin >> answer;
            if (answer == "n")
            {
                break;
            }
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
            return 0;
        }
    }
}