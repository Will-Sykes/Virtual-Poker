/*
* William Sykes
* This is Card.cpp
* This has the constructor and method definitions for the card class
*/
#include "Card.h"
#include <iostream>

using namespace cardInfo;



// default card constructor
Card::Card() {
    value = Value::Two;
    suit = Suit::Heart;
}

// card constructor with parameters Value and Suit
Card::Card(Value cardValue, Suit cardSuit) {
    value = cardValue;
    suit = cardSuit;
}

/*
* Card setter method
* @param card value to set
*/
void Card::setCardValue(Value cardValue) {
    value = cardValue;
}

/*
* Card getter method
* @return the value of the card object.
*/
Value Card::getCardValue() const {
    return value;
}

/*
* Card Setter method
* @param card suit to set
*/

void Card::setCardSuit(Suit cardSuit) {
    suit = cardSuit;
}

/*
* Card getter method
* @return the suit of the card object
*/
Suit Card::getCardSuit() const {
    return suit;
}

/*
* ostream operater << overload for card class
* @param ostream output stream variable
* @param card object
* @return os
*/
std::ostream& operator<<(std::ostream& os, const Card& card) {
    // Implement how you want to print a Card object
    
    card.printCard();
    return os;
}

/*
* Prints the suit and value of the card
* turns value and suit of card into int and prints that indecie of
* @return the value of the card object.
*/
void Card::printCard() const {

    // declaring variables string conversion
    // declaring an array of char to denote the symbols for each suit
    std::string suitStr;
    std::string valueStr;
    char suitSymbol[4] = { 'S','H','C','D' };

    // converting enums to strings for display based on suit and value of card object
    switch (suit) {
    case Suit::Spade:
        suitStr = suitSymbol[0];
        break;
    case Suit::Heart:
        suitStr = suitSymbol[1];
        break;
    case Suit::Club:
        suitStr = suitSymbol[2];
        break;
    case Suit::Diamond:
        suitStr = suitSymbol[3];
        break;
    }

    switch (value) {
    case Value::Ace:
        valueStr = "A";
        break;
    case Value::Two:
        valueStr = "2";
        break;
    case Value::Three:
        valueStr = "3";
        break;
    case Value::Four:
        valueStr = "4";
        break;
    case Value::Five:
        valueStr = "5";
        break;
    case Value::Six:
        valueStr = "6";
        break;
    case Value::Seven:
        valueStr = "7";
        break;
    case Value::Eight:
        valueStr = "8";
        break;
    case Value::Nine:
        valueStr = "9";
        break;
    case Value::Ten:
        valueStr = "10";
        break;
    case Value::Jack:
        valueStr = "J";
        break;
    case Value::Queen:
        valueStr = "Q";
        break;
    case Value::King:
        valueStr = "K";
        break;
    }
    // printing the card value + suit 
    std::cout << valueStr << suitStr << std::endl;

}


