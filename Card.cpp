/*Author: Travis Hoover
 * Implementation file for Card class as defined in Card.h.
 *
 * Instances of Card will be assned a point value and suite type.
 * Overloaded functions are defined to compare instances of Card.
 *
 * */

#include "Card.h"

using namespace std;


/************************ Constructors *****************************/

//Default constructor
Card::Card() {
}

//Constructor accepting card number and suite type, makes appropriate card
Card::Card(int faceValue, suite type) {
    Card::faceValue = faceValue;
    Card::type = type;

    if(faceValue <= 10)                      //If 10 or lower, assign face value
        Card::pointValue = faceValue;
    if(faceValue > 10)                       //If over 10 (royal or face cards), assign value of 10
        Card::pointValue = 10;
    if(faceValue == 15)
        Card::pointValue = 15;               //If Ace, assign value of 15

    cout << faceValue;

    //TODO convert written suite type to synbols; hearts(char)0x03, diamonds(char)0x04, clubs(char)0x05, and spades(char)0x06
    if(type == hearts)
        cout << "-hearts";
    else if(type == diamonds)
        cout << "-diamonds";
    else if(type == clubs)
        cout << "-clubs";
    else if(type == spades)
        cout << "-spades";
}

ostream& operator << (ostream& os, const Card& cd){
    os << cd.faceValue;                 //Displays how much the card is worth
    if(cd.type == hearts)               //Display the suite type:
        cout << "-hearts";
    else if(cd.type == diamonds)
        cout << "-diamonds";
    else if(cd.type == clubs)
        cout << "-clubs";
    else if(cd.type == spades)
        cout << "-spades";
    return os;
}

bool Card::operator<(const Card &cd) const {
    if(this->faceValue < cd.faceValue)      //if the face value of the Card calling this (on the left) is less than the target card (on the right),
        return true;                            //return true.
    else
        return false;
}

bool Card::operator>(const Card &cd) const {
    if(this->faceValue > cd.faceValue)      //if the face value of the Card calling this (on the left) is greater than the target card (on the right),
        return true;                            //return true
    else
        return false;
}

bool Card::operator==(const Card &cd) const {
    if(this->faceValue == cd.faceValue)     //if the face value of the Card calling this (on the left) is equal to the target card (on the right),
        return true;                            //return true
    else
        return false;
}

int Card::getPointValue() const {           //returns value of calling Card
    return pointValue;
}