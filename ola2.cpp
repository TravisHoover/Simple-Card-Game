/*Author: Travis Hoover
 *
 * This main file handles a game to be played between a player and computer.
 * It will make use of classes Card, Deck, and Player to accomplish this. Instructions
 * to play game are detailed at runtime.
 * */

#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

int main() {

    string playerName;

    cout << "Hello! Please enter your name: ";      //prompt for player name
    cin >> playerName;                              //read in player name
    Player player(playerName);                      //create Player object using player's name
    Player computer("Computer");                    //create Player object for the computer

    //Display instructions to player
    cout << "OK " << playerName << "! Let the game begin! You will be given 3 cards, as will the computer.\n";
    cout << "One of these cards will be selected to play. The player who submits the highest cards will have \n";
    cout << "both cards added to their score. Whoever has the highest score wins!\n";
    cout << endl;

    //Display deck of cards
    cout << "The following deck will be used:\n";
    Deck deck;
    cout << endl;

    //Shuffle deck of cards and display the deck from the Shuffle function
    cout << "It will of course be shuffled:\n";
    deck.Shuffle();
    cout << endl;

    //While loop to step through the game. Continues as long as the deck is not empty
    while(!deck.isEmpty()){

        //Player and Computer draws cards into their hand
        player.drawCard(deck);
        computer.drawCard(deck);

        /************* Headers for both player's names and scores **********************/
        cout << "**********************************************************************************" << endl;
        cout << "\t\t" << player.getName() << "\t\t\t\t\t\t\t\t\t\t" << computer.getName() << endl;         //Display names
        cout << "Hand: " << player << "\t\t\t" << computer << endl;                                         //Display cards in Hand
        cout << "Score: " << player.total() << "\t\t\t\t\t\t\t\t\t\t" << computer.total() << endl;          //Display Scores


        cout << endl << player.getName() << " chooses " << player.playCard() << endl;                       //Display Player's choice
        cout << computer.getName() << " chooses " << computer.playCard() << endl;                           //Display Computer's choice

        //If block for if Player and Computer cards have identical value
        if (player.playCard() == computer.playCard()){      //if player's card is equal to computer's card
            player.addScore(player.playCard());             //give points to player
            computer.addScore(computer.playCard());         //give points to computer
            cout << "Both cards are equal, " << player.getName() << " gets " << player.playCard().getPointValue() << " points, and " << computer.getName() << " gets " << computer.playCard().getPointValue() << " points" << endl;
        }

        //If block for if Player's card is higher in value than Computer's card
        if(player.playCard() > computer.playCard()){        //If player's card is higher than computer's
            player.addScore(player.playCard());             //give points to player from player's card
            player.addScore(computer.playCard());           //give points to player from computer's card
            cout << player.getName() << " gets " << player.playCard().getPointValue() + computer.playCard().getPointValue() << " points!" << endl << endl;
        }
        //If block for if Computer's card is higher in value than Player's card
        else if (computer.playCard() > player.playCard()){  //if computer's card is higher than player's
            computer.addScore(player.playCard());           //give points to computer from player's card
            computer.addScore(computer.playCard());         //give points to computer from computer's card
            cout << computer.getName() << " gets " << player.playCard().getPointValue() + computer.playCard().getPointValue() << " points!" << endl << endl;
        }
    }

    //Display final scores and winner of game
    cout << "************************************************************" << endl;
    cout << "************************************************************" << endl;
    cout << endl << "The final score is: " << endl;
    cout << player.getName() << " with " << player.total() << endl;
    cout << computer.getName() << " with " << computer.total();
    cout << endl << endl;

    //if statement to handle winning Player
    if (player.total() > computer.total())
        cout << player.getName() << " wins!" << endl;
    else
        cout << computer.getName() << " wins!" << endl;

    cout << endl << "************************************************************" << endl;
    cout << "************************************************************";
    return 0;
}