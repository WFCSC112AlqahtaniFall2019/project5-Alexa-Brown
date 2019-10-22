#ifndef BLINDMANSBLUFF_CARD_H
#define BLINDMANSBLUFF_CARD_H
#include <string>
#include <iostream>
using namespace std;

// ranks are ordered Ace-low and Queen-high
const string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","King","Queen"};
// suits are ordered alphabetically
const string suits[] = {"Clubs","Diamonds","Hearts","Spades"};

class Card {
private:
    int rank; //to the index of the array
    int suit;
public:
    Card(); //default constructor
    Card(int rankNum, int cardSuit);
    bool operator<(int a);
    bool operator>(int a);
    string specificValue (int w, int z);
    void print();

};


#endif //BLINDMANSBLUFF_CARD_H
