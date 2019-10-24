#include "Deck.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

Deck::Deck() {
    arraySize = 52;
    cards = new Card [arraySize];
    cardsLeft = 52; //decreases
} //default constructor

Deck::Deck(const Deck& C){
    //cout << "Copy Constructor called." << endl;
    cards = new Card;
    *cards = *(C.cards);
    arraySize = C.arraySize;
} //copy constructor

Deck::~Deck(){
   // cout << "Destructor called" << endl;
    delete cards;
} //destructor

Deck& Deck::operator = (const Deck& rhs){ //copy assignment operator
    if (this != &rhs){
        delete cards;
        cards = new Card;
        *cards = *(rhs.cards);
    }
    return *this;
}

void Deck::populate() { //filling the deck with cards
    for (int i = 0; i < 13; ++i) { //13 ranks
        for (int j = 0; j < 4; ++j) { //4 suits
            Card c = Card (i, j);
            cards[(4 * i + j)] = c;
            //cout << 4 * i + j << " " << c.print() << " " << (cards[(4 * i + j)]).print() << endl; //to check that all the cards are there
        }
    }
}

void Deck::shuffle() { //shuffling the deck
    int index1;
    int index2;
    Card temp;
    for (int i = 0; i < (cardsLeft)*(cardsLeft); i++) {
        index1 = rand() % cardsLeft;
        index2 = rand() % cardsLeft;
        temp = cards[index1]; // save the value of index1
        cards[index1] = cards[index2]; // copy over index2 to index1
        cards[index2] = temp; // copy the saved value of index1
    }
}
Card Deck::pickCard() { //returning the card at the value randomly selected
    cardsLeft--;
    return cards[cardsLeft];
}


bool Deck::add(Card discarded){ //add to the discard pile
    if (cardsLeft == 0){
        cout << "There is no space for a card." << endl;
        return false;
    }
    else{
        cards[cardsLeft-1] = discarded;
        cardsLeft--;
        return true;
    }
}

void Deck::Discardprint(){ //prints the card
        cout << "Added " << cards[cardsLeft+1].print() << " and " << cards[cardsLeft].print() << " to the discard pile. " << endl;

}