#include "Card.h"
#include <iostream>
using namespace std;
Card::Card(){
    rank = 0;
    suit = 0;
} //default constructor
Card::Card(int x, int y){
    rank = x;
    suit = y;
} //alternate constructor

bool Card::operator<(Card c){ //don't need a case if they are equal because the cards will always have a different rank or suit?
    //cout << "< operator called" << endl;
    if (this->rank < c.rank){
        return true;
    }
    if (this-> rank > c.rank){
        return false;
    }
    else if (this->rank == c.rank){
        if (this->suit < c.suit){
            return true;
        }
        else if (this->suit > c.suit){
            return false;
        }
    }
}

bool Card::operator>(Card c) {
   // cout << "> operator called" << endl;
    if (this->rank > c.rank) {
        return true;
    } else if (this->rank < c.rank) {
        return false;
    }
    else if (this->rank == c.rank){
        if (this->suit > c.suit){
            return true;
        }
        else if (this->suit < c.suit){
            return false;
        }
    }
}

string Card::specificValue (int w, int z){ //returns the value of the card at the randomly selected integer index
  string value;
  value = ranks [w] + "of " + suits[z];
  //return value;
}
string Card::print(){ //prints the card
    return ranks[rank] + " of " + suits [suit];
}
