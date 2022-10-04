#include "human.h"
#include "player.h"
#include "deck.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
Human::Human(int m, string n) : Player(m, n) {}
void Human::play(shared_ptr<Deck> deck)
{
    for (auto &hand : hands)
    {
        while (true)
        {
            if (!hand->getInPlay())
            {
                hand->printHand();
                if (hand->getHasAces())
                {
                    cout << "Looks like you busted but you have an ace in your hand. Would you like to reconfigure the ace value? (y/n)" << endl;
                    char response;
                    cin >> response;
                    if (response == 'y')
                    {
                        hand->configureAceValues();
                        hand->calculateScore();
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    cout << "Looks like its a Bust" << endl;
                }
                break;
            }
            cout << "Current Hand" << endl;
            hand->printHand();
            cout << "Options: " << endl;
            cout << "1. Hit" << endl;
            cout << "2. Stand" << endl;
            cout << "3. Quit" << endl;
            if (hand->getHasAces())
            {
                cout << "4. Configure Ace Value" << endl;
            }
            string input;
            int value;
            getline(cin, input);
            stringstream ss(input);
            while (!(ss >> value))
            {
                cout << "invalid input, please enter a number: " << endl;
                getline(cin, input);
                ss.clear();
                stringstream temp(input);
                ss.swap(temp);
                ss << input;
            }
            switch (value)
            {
            case 1:
                hand->addCard(deck->deal());
            case 2:
                break;
            case 3:
                throw(invalid_argument("Quit"));
                break;
            case 4:
                if (hand->getHasAces())
                {
                    hand->configureAceValues();
                    hand->calculateScore();
                    continue;
                }
                else
                {
                    cout << "invalid input. Please enter a valid number" << endl;
                }
            default:
                cout << "invalid input, please enter a number: " << endl;
                break;
            }
        }
    }
}

void Human::init(shared_ptr<Deck> deck)
{
    hands[0]->addCard(deck->deal());
    hands[0]->addCard(deck->deal());
    cout << "Your hand: " << endl;
    hands[0]->printHand();
    // check natural
    natural = hands[0]->checkNatural();
    if (natural)
    {
        hands[0]->setInPlay(false);
    }
    // check split
    if (hands[0]->getisSplitable())
    {
        cout << "Would you like to split? (y/n)" << endl;
        char response;
        cin >> response;
        if (response == 'y')
        {
            Bet *= 2;
            hands.push_back(make_shared<Hand>());
            hands[1]->addCard(hands[0]->getback());
            hands[0]->addCard(deck->deal());
            hands[1]->addCard(deck->deal());
        }
    }
    // double down
    if (hands[0]->getsum() == 9 || hands[0]->getsum() == 10 || hands[0]->getsum() == 11)
    {
        cout << "Would you like to double down? (y/n)" << endl;
        char response;
        cin >> response;
        if (response == 'y')
        {
            Bet *= 2;
            shared_ptr<Card> card = deck->deal();
            card->changehidden();
            hands[0]->addCard(card);
            hands[0]->setInPlay(false);
            hands[0]->setDoubledDown(true);
        }
    }
}