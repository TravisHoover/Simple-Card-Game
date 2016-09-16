//
// Created by Travis on 9/11/16.
//

#include "Deck.h"
#include "Card.h"

using namespace std;


Deck::Deck() {
    for(int i = 0; i < 4; i++){            //for loop to handle each suite
        for(int j = 0; j < 13; j++){
            int x = j;
            if(j > 10)                      //if statement to assign value of 10 to royal cards, change later
                x = 10;
            Card(x, (suite)i);              //Create card
        }
    }
}


Card Deck::dealCard() {
    return theDeck[topCard];

}

void Deck::Shuffle() {
    //random_shuffle(1,Card_Num);
}

bool Deck::isEmpty() {
    if(!topCard)
        return true;
    else
        return false;
}

ostream& operator << (ostream&, const Deck& deck){
    cout << deck.theDeck;
}

