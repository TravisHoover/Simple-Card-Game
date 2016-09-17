//
// Created by Travis on 9/11/16.
//

#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

//Constructors
/*****************************************************/
Card::Card() {
}

Card::Card(int faceValue, suite type) {
    Card::faceValue = faceValue;
    Card::type = type;

    if(faceValue <= 10)
        Card::pointValue = faceValue;
    if(faceValue > 10)
        Card::pointValue = 10;
    if(faceValue == 15)
        Card::pointValue = 15;

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
    else
        cout << "Error assigning card type";
}

ostream& operator << (ostream& os, const Card& cd){
    //os << cd.faceValue << " " << cd.type;
    //return os;
}

bool Card::operator<(const Card &cd) const {
    if(pointValue < cd.pointValue)
        return true;
    else
        return false;
}

bool Card::operator>(const Card &cd) const {
    if(pointValue > cd.pointValue)
        return true;
    else
        return false;
}

bool Card::operator==(const Card &cd) const {
    if(pointValue == cd.pointValue)
        return true;
    else
        return false;
}

int Card::getPointValue() const {

}