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
}

bool Card::operator<(int a){ //don't need a case if they are equal because the cards will always have a different rank or suit
    cout << "< operator called" << endl;
    if (this->rank < a){
        return true;
    }
    if (this-> rank > a){
        return false;
    }
    /*else if (this->suit < a){
        return true;
    }
    else{
        return false;
    }*/
}
bool Card::operator>(int a) {
    cout << "> operator called" << endl;
    if (this->rank > a) {
        return true;
    } else if (this->suit > a) {
        return false;
    }
}

string Card::specificValue (int w, int z){
  string value;
  value = ranks [w] + "of " + suits[z];
  return value;

    }

void Card::print(){
    cout << ranks[rank] + " of " + suits [suit];
}

