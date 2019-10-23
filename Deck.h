#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"
#include <iostream>
class Deck {

private:
    Card* cards;
    int arraySize;
    int cardsLeft;

public:
    Deck(); //default constructor
    ~Deck();//destructor
    Deck(const Deck& C);//copy constructor
    void shuffle(); //shuffles the deck
    void populate (); //fills the deck with cards
    Card pickCard (int value); //returns the card based on the random number generated
    void swap(Card num1, Card num2); //helps shuffle the deck
    bool add();
};


#endif //BLINDMANSBLUFF_DECK_H
