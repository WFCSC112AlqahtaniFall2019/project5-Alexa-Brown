#include "Deck.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

Deck::Deck() {
    arraySize = 52;
    cards = new Card [arraySize];
   // cards.populate();-- have to populate the deck
    cardsLeft = 52; //changes as you draw cards from the deck, then decreases
}
Deck::~Deck(){
    cout << "Destructor called" << endl;
    delete cards;
}

void Deck::populate() {
    for (int i = 0; i < 12; ++i) { //13 ranks
        for (int j = 0; j < 3; ++j) { //4 suits
            Card c = Card (i, j);
            cards[(4 * i + j)] = c;
        }

    }
}

void Deck::shuffle() {
    for (int i = 0; i < 52; i++){
       swap (cards[i], cards[i+1]);
    }
}
Card Deck::pickCard(int value) {
    cardsLeft--;
    return cards[value];
}

void Deck::swap(Card num1, Card num2) { //changes & to *
    Card temp = num1; // save the value of num1
    num1 = num2; // copy over num2 to num1
    num2 = temp; // copy the saved value of num1 --- switching their values not their pointers
}



/*int Deck::operator=(int a) {
    cout << "> operator called" << endl;
    if (this->rank = a) {
        return this->rank;
    } else if (this->suit > a) {
        return this->rank;
    }
}*/