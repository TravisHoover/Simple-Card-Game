//
// Created by Travis on 9/11/16.
//

#include "Deck.h"
#include "Card.h"

using namespace std;

//Constructor for the card deck. It will output all cards when called.
Deck::Deck() {

    //theDeck[Card_Num] = Card();            //initialize array of cards
    int deckIndex = 0;
    for(int i = 1; i < 14; i++){            //for loop to handle each face value
        for(int j = 0; j < 4; j++){         //for loop to handle each suite value
            int x = i;
            if(i == 1)                      //if statement to assign value of 15 to Ace card
                x = 15;
            if(i > 10)                      //if statement to assign value of 10 to royal cards, change later
                x = 10;
            theDeck[deckIndex] = Card(x,(suite)j);
            deckIndex++;
            cout << " ";
        }
        cout << endl;
    }
}


Card Deck::dealCard() {
    return theDeck[topCard];

}

void Deck::Shuffle() {
    //random_shuffle(1,Card_Num);
/********************************** Display new deck composition ***************************************/
    for(int i = 0; i < 4; i++){            //for loop to handle each suite
        for(int j = 1; j < 14; j++){
            int x = j;
            if(j == 1)                      //if statement to assign value of 15 to Ace card
                x = 15;
            if(j > 10)                      //if statement to assign value of 10 to royal cards, change later
                x = 10;
            cout << " " << Card(x,(suite)i);
            cout << " ";
        }
        cout << endl;
    }
}

bool Deck::isEmpty() {
    if(!topCard)
        return true;
    else
        return false;
}

ostream& operator << (ostream&, const Deck& deck){

}

