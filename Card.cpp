//
// Created by Travis on 9/11/16.
//

#include "Card.h"

using namespace std;

//Constructors
/*****************************************************/
Card::Card() {

}

Card::Card(int faceValue, suite type) {

}

ostream& operator << (ostream& os, const Card& cd){
    os << cd.pointValue;
    return os;
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
    return pointValue;
}

