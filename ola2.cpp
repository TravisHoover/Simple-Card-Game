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

    cout << travis.getName();
    cout << endl;
    cout << travis.total();



    return 0;
}