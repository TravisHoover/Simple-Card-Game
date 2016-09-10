#ifndef PL_H
#define PL_H

#include <iostream>
#include <string>
#include "deck.h"
#include "card.h"

using std::ostream;
using std::string;

class Player
{
public:
    static const int Max_Cards = 3; //Max # of cards a player can have

    // constructor
	Player(string name="unknown");

    // The player removes one card from his hand
    // and return it.
    // You can use whatever stratge you want here such as
    // choose a card randomly, choose the largest card,
    // choose the first card, or other more complicated algorithm
	Card playCard();

    // The player gets one card from the deck
	void drawCard(Deck& dk);

    // Add the point value of the card
    // to the score of the player
	void addScore(Card acard);

    // Return the score the player has earned so far
	int total() const;

    // return the name of the player
    string getName() const; 

    // Return true if no more cards in the player's hands,
    // otherwise false
	bool emptyHand() const;

    // overload the << operator to display all cards in player's hand
    friend std::ostream& operator << (std::ostream&, const Player&);

private:
	string  name;       //player's name
	int     score;      //score the player has earned so far
	Card    hand[Max_Cards];    //the array holding cards 
	bool    played[Max_Cards];  //played[i] indicates if hand[i] has a card or not.
};

#endif
