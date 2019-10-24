#include <iostream>
#include <time.h>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int turn = 0;
    Card compValue, userValue;
    int nWin = 0, nLoss = 0, nTie = 0;
    srand(time(NULL));
    Deck d; //object of deck
    Deck discard;
    d.populate();
    //testing operators
    if (1>0){
        cout << "true" << endl;
    }

    //**need to figure out how to get Ace to be the lowest card- might be in the overloaded?**

    play = true;
    while(play) {
        // assign values to computer and user
        compValue = d.pickCard();
        discard.add(compValue);
        userValue = d.pickCard();
        discard.add(userValue);
        d.shuffle();
        // get user's bet
        cout << "Computer's value is ";
        cout << compValue.print();
        cout << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
            turn = turn + 2;
        }

        // determine outcome
        if((compValue < userValue && guessedHigher) || (compValue > userValue && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if((compValue > userValue && guessedHigher) || (compValue < userValue && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {

            cout << "It's a tie:" << endl;
            nTie++;
        }

        cout << "\tyour value is ";
        cout << userValue.print();
        cout << endl;
        discard.Discardprint();

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << endl << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }

        }
        if (turn >= 52){
            invalid = false;
            break;
        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;

    return 0;
}