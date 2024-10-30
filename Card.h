/*
* William Sykes
* This is the Header file for Card.cpp
* This includes namespace CardInfo with enumerated classes Suit and Value to be used by the Card Class
* The Card Class has declarations for a constructor, getter and setter methods and a print card method
*/
#pragma once
#include <string>
#include <array>
#include <compare>

namespace cardInfo {
    // enumerated classes for Suit and Value
    enum class Suit {
        Spade,
        Heart,
        Club,
        Diamond
    };
    enum class Value {
        
        Two = 1,
        Three = 2,
        Four = 3,
        Five = 4,
        Six = 5,
        Seven = 6,
        Eight = 7,
        Nine = 8,
        Ten = 9,
        Jack = 10,
        Queen = 11,
        King = 12,
        Ace = 13
    };

    // Arrays for suits and values
    const std::array<Suit, 4> allSuits = { Suit::Spade, Suit::Heart, Suit::Club, Suit::Diamond };
    const std::array<Value, 13> allValues = { Value::Two, Value::Three, Value::Four, Value::Five, Value::Six, Value::Seven, Value::Eight, Value::Nine, Value::Ten, Value::Jack, Value::Queen, Value::King, Value::Ace };

    
}

using namespace cardInfo;

class Card {
public:

    // constructor
    Card();
    Card(cardInfo::Value cardValue, cardInfo::Suit cardSuit);

    // public methods
    void setCardValue(Value cardValue);           // set card value
    Value getCardValue() const;                   // get card value
    void setCardSuit(Suit cardSuit);              // set card suit
    Suit getCardSuit() const;                     // get card suit
    void printCard() const;                       // print card
    friend std::ostream& operator<<(std::ostream& os, const Card& card); 
    

    
private:
    // private property
    Value value;
    Suit suit;
};
