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
    Card pickCard (); //returns the card based on the random number generated
    bool add(Card discarded); //to add a card to the deck if able to- returns false if no space
    Deck& operator= (const Deck& rhs);
    void Discardprint();
};


#endif //BLINDMANSBLUFF_DECK_H
