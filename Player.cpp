//
// Created by Travis on 9/11/16.
//

#include "Player.h"
#include "Card.h"

using namespace std;

Player::Player(string name) {
    Player::name = name;
    Player::score = 0;
    Player::hand[Max_Cards];
}


Card Player::playCard() {

}

void Player::drawCard(Deck &dk) {

}

void Player::addScore(Card acard) {
    score += acard.getPointValue();
}

int Player::total() const {
    return score;
}

string Player::getName() const {
    return name;
}

bool Player::emptyHand() const {
    if(played)                           //if hand is empty
        return false;
    else
        return true;
}

std::ostream& operator << (std::ostream&, const Player&){

}
