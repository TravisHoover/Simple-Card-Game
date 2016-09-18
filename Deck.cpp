//
// Created by Travis on 9/11/16.
//

#include "Deck.h"
#include "Card.h"

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
            theDeck[topCard] = Card(x,(suite)j);
            topCard++;
            cout << " ";
        }
        cout << endl;
    }
}


Card Deck::dealCard() {
    int index = topCard;
    index--;
    topCard--;                  //decrease size of deck by 1
    return theDeck[index];
}

void Deck::Shuffle() {
    random_shuffle(&theDeck[0], &theDeck[52]);
    int deckIndex = 0;
/********************************** Display new deck composition ***************************************/
        for(int i = 1; i < 14; i++){            //for loop to handle each face value
             for(int j = 0; j < 4; j++){         //for loop to handle each suite value
                 cout << " " << theDeck[deckIndex];
                 deckIndex++;
             }
            cout << endl;
        }
}

bool Deck::isEmpty() {
    if(topCard > 0)
        return false;
    else
        return true;
}

ostream& operator << (ostream& os, const Deck& deck){
    os << deck.theDeck;
    return os;
}

