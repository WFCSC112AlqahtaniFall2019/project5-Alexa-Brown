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
    ~Deck();
    void shuffle();
    void populate ();
    Card pickCard (int value);
    void swap(Card num1, Card num2);

};
//int Deck::operator=(int a);

#endif //BLINDMANSBLUFF_DECK_H
