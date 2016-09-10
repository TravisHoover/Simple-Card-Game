#ifndef CARD_H
#define CARD_H

#include <iostream>
using std::ostream;

enum suite {clubs, hearts, spades, diamonds};

class Card
{
public:
    //default constructor. It is required since another class
    //may declare an array of Card objects.
	Card();

    //another constructor
	Card (int faceValue, suite type);

    // overload the << operator
    friend ostream& operator << (ostream& os, const Card& cd);

    // compare the point value of cards *this and cd.
    // return true if *this has a smaller pointer value than cd.
    // otherwise, return false.
	bool operator < (const Card& cd) const;


    // compare the point value of cards *this and cd.
    // return true if *this has a larger point value than cd.
    // otherwise, return false.
	bool operator > (const Card& cd) const;

    // compare the point value of cards *this and cd
    // return true if they have the same point value,
    // otherwise return false.
	bool operator== (const Card& cd) const;

    // return the point value
	int getPointValue() const;

private:
	suite   type;       // the suite of the card
	int     faceValue;   // the face value of the card
	int     pointValue;      // the point value of the card, it is a derived value
                        // from type and faceValue.
};
#endif