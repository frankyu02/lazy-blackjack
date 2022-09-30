#include "hand.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
Hand::Hand()
{
}

void Hand::addCard(std::shared_ptr<Card> card)
{
    hand.push_back(card);
    if (card->getRank() == ACE)
    {
        hasAces = true;
    }
    calculateScore();
}

bool Hand::getInPlay() const
{
    return inPlay;
}

void Hand::configureAceValues()
{
    if (!hasAces)
    {
        return;
    }
    for (auto &c : hand)
    {
        if (c->getRank() == ACE)
        {
            int result;
            string input;
            while (true)
            {
                cout << "Please pick card value for card either 1 or 11: ";
                c->printCard();
                cout << endl;
                getline(std::cin, input);
                stringstream ss(input);
                while (!(ss >> result))
                {
                    cout << "invalid input, please enter a number: " << endl;
                    getline(std::cin, input);
                    ss.clear();
                    stringstream temp(input);
                    ss.swap(temp);
                    ss << input;
                }
                if (result != 1 && result != 11)
                {
                    cout << "Invalid input" << endl;
                }
                else
                {
                    c->setValue(result);
                    break;
                }
            }
        }
    }
}
int Hand::getsum() const
{
    return sum;
}
void Hand::calculateScore()
{
    sum = 0;
    for (auto &c : hand)
    {
        sum += c->getValue();
    }
}
void Hand::printHand()
{
    const string suites[4] = {"\x05", "\x04", "\x03", "\x06"};
    const string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
    for (int i = 0; i < hand.size(); i++)
    {
        if (i != 0)
        {
            cout << "  ";
        }
        cout << "*------*";
    }
    cout << endl;
    for (int i = 0; i < hand.size(); i++)
    {
        if (i != 0)
        {
            cout << "  ";
        }
        cout << "|      |";
    }
    cout << endl;
    for (int i = 0; i < hand.size(); i++)
    {
        string cardText = hand[i]->getHidden() ? "??" : ranks[hand[i]->getRank()] + suites[hand[i]->getSuit()];
        if (i != 0)
        {
            cout << "  ";
        }
        cout << "|  " << cardText << "  |";
    }
    cout << endl;
    for (int i = 0; i < hand.size(); i++)
    {
        if (i != 0)
        {
            cout << "  ";
        }
        cout << "|      |";
    }
    cout << endl;
    for (int i = 0; i < hand.size(); i++)
    {
        if (i != 0)
        {
            cout << "  ";
        }
        cout << "*------*";
    }
    cout << endl;
}

int main()
{
    // create hand
    Hand hand;
    // create hidden card
    shared_ptr<Card> card1 = make_shared<Card>(Card(Suit::HEARTS, Rank::ACE, true));
    // create visible card
    shared_ptr<Card> card2 = make_shared<Card>(Card(Suit::HEARTS, Rank::ACE, false));
    // create ace of hearts
    shared_ptr<Card> card3 = make_shared<Card>(Card(Suit::HEARTS, Rank::ACE, false));
    // create jack of spades
    shared_ptr<Card> card4 = make_shared<Card>(Card(Suit::SPADES, Rank::JACK, false));
    // add jack of spades
    hand.addCard(card4);
    cout << "added jack" << endl;
    // print sum
    cout << hand.getsum() << endl;
    // configure ace values
    hand.configureAceValues();
    // add ace of hearts
    hand.addCard(card3);
    cout << "Added ace" << endl;
    // print sum
    cout << hand.getsum() << endl;
    // configure ace values
    hand.configureAceValues();
    // add hidden card
    hand.addCard(card1);
    // print hand
    hand.printHand();
    return 0;
}