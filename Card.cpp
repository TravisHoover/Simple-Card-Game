//
// Created by Travis on 9/11/16.
//

#include "Card.h"

using namespace std;

//Constructors
/*****************************************************/
//Card card;
//Card card1(int,suite);

ostream& operator << (ostream& os, const Card& cd){

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

