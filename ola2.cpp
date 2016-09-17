//
// Created by Travis on 9/11/16.
//

#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

int main() {

    Player travis("Travis");
    Deck deck;


    cout << travis.getName();
    cout << endl;
    cout << travis.total();
    cout << endl;
    deck.Shuffle();




    return 0;
}