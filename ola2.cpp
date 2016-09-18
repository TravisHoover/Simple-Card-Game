//
// Created by Travis on 9/11/16.
//

#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

int main() {

    string playerName;

    cout << "Hello! Please enter your name: ";
    cin >> playerName;
    Player player(playerName);
    Player computer("Computer");
    cout << "OK " << playerName << "! Let the game begin! You will be given 3 cards, as will the computer.\n";
    cout << "One of these cards will be selected to play. The player who submits the highest cards will have \n";
    cout << "both cards added to their score. Whoever has the highest score wins!\n";
    cout << endl;

    cout << "The following deck will be used:\n";
    Deck deck;
    cout << endl;

    cout << "It will of course be shuffled:\n";
    deck.Shuffle();
    cout << endl;


    while(!deck.isEmpty()){

        player.drawCard(deck);
        computer.drawCard(deck);

        /************* Headers for both player's names and scores **********************/
        cout << "\t\t" << player.getName() << "\t\t\t\t\t\t\t\t\t\t" << computer.getName() << endl;
        cout << "Hand: " << player << "\t\t\t" << computer << endl;
        cout << "Score: " << player.total() << "\t\t\t\t\t\t\t\t\t\t" << computer.total() << endl;


        cout << endl << player.getName() << " chooses " << player.playCard() << endl;
        cout << computer.getName() << " chooses " << computer.playCard() << endl;


        if(player.playCard() > computer.playCard()){
            player.addScore(player.playCard());
            player.addScore(computer.playCard());
            cout << player.getName() << " gets " << player.playCard().getPointValue() + computer.playCard().getPointValue() << " points!" << endl << endl;
        }
        else if (computer.playCard() > player.playCard()){
            computer.addScore(player.playCard());
            computer.addScore(computer.playCard());
            cout << computer.getName() << " gets " << player.playCard().getPointValue() + computer.playCard().getPointValue() << " points!" << endl << endl;
        }
        else
            cout << "error\n";
    }
    cout << endl << "The final score is: " << endl;
    cout << player.getName() << " with " << player.total() << endl;
    cout << computer.getName() << " with " << computer.total();
    cout << endl << endl;

    if (player.total() > computer.total())
        cout << player.getName() << " wins!";
    else
        cout << computer.getName() << " wins!";

    return 0;
}