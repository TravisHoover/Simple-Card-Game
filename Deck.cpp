/*Author: Travis Hoover
 * Implementatin file for Deck class, as defined in Deck.h.
 * This class is an array to hold objects of class Card.
 * */

#include "Deck.h"

using namespace std;

//Constructor for the card deck. It will output all cards when called.
Deck::Deck() {

    topCard = 0;
    for(int i = 1; i < 14; i++){            //for loop to handle each face value
        for(int j = 0; j < 4; j++){         //for loop to handle each suite value
            int x = i;
            if(i == 1)                      //if statement to assign value of 15 to Ace card
                x = 15;
            if(i > 10)                      //if statement to assign value of 10 to royal cards, change later
                x = 10;
            theDeck[topCard] = Card(x,(suite)j);    //create a card object using the top card of the deck
            topCard++;
            cout << " ";
        }
        cout << endl;
    }
}


Card Deck::dealCard() {
    int index = topCard;        //temporary variable to be called to prevent lowering deck number prematurely
    index--;
    topCard--;                  //decrease size of deck by 1
    return theDeck[index];      //return the top card in the deck
}

void Deck::Shuffle() {
    random_shuffle(&theDeck[0], &theDeck[52]);      //Shuffles the deck
    int deckIndex = 0;                                  //temporary variable to traverse new deck
/********************************** Display new deck composition ***************************************/
        for(int i = 1; i < 14; i++){            //for loop to handle each face value
             for(int j = 0; j < 4; j++){         //for loop to handle each suite value
                 cout << " " << theDeck[deckIndex];         //print out this card
                 deckIndex++;
             }
            cout << endl;
        }
}

bool Deck::isEmpty() {
    if(topCard > 0)         //if there are no more cards in the deck, return true
        return false;
    else
        return true;
}

ostream& operator << (ostream& os, const Deck& deck){
    os << deck.theDeck;                                     //prints out the array of card objects
    return os;
}

