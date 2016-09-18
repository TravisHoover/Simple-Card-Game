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

    return Player::hand[0];
}

void Player::drawCard(Deck &dk) {

    int index = 0;
    if (dk.isEmpty())
        cout << "The deck is empty!" << endl;

    while (!dk.isEmpty() && index < 3) {            //while the deck isn't empty,
        if(!played[index])                          //check hand slot to see if it is empty,
            hand[index] = dk.dealCard();            //if it is then assign a card

     index++;
    }
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
    if(played[0] || played[1] || played[2])                           //if hand is empty
        return false;
    else
        return true;
}

std::ostream& operator << (std::ostream& out, const Player& player){
    out << player.hand[0] << " " << player.hand[1] << " " << player.hand[2];
    return out;
}
