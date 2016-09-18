/*Author: Travis Hoover
 * Implementation file for Player class as defined in Player.h.
 * This class will use the Deck and Card class and perform functions
 * necessary to play a game designed in ola2.cpp
 * */

#include "Player.h"

using namespace std;


Player::Player(string name) {                   //Constructor for Player class. It receives a name and initializes the
    Player::name = name;                            //score
    Player::score = 0;
    Player::hand[Max_Cards];
}


Card Player::playCard() {

    return Player::hand[0];                     //submits a card from the Player's hand to be used for scoring
}

void Player::drawCard(Deck &dk) {

    int index = 0;
    if (dk.isEmpty())                               //check to see if the deck is empty
        cout << "The deck is empty!" << endl;

    while (!dk.isEmpty() && index < 3) {            //while the deck isn't empty,
        if(!played[index])                          //check hand slot to see if it is empty,
            hand[index] = dk.dealCard();            //if it is then assign a card

     index++;
    }
}

void Player::addScore(Card acard) {                 //add score of card to Player object that calls it
    score += acard.getPointValue();
}

int Player::total() const {                         //return the total score of Player
    return score;
}

string Player::getName() const {                    //returns the name of Player to be displayed
    return name;
}

bool Player::emptyHand() const {
    if(played[0] || played[1] || played[2])             //if there are any cards in the hand, return false
        return false;
    else
        return true;
}

std::ostream& operator << (std::ostream& out, const Player& player){
    out << player.hand[0] << " " << player.hand[1] << " " << player.hand[2];            //prints out all cards in the player's hand
    return out;
}
