/*
* William Sykes
* This is the Header file for Hand.cpp
* The Hand Class has declarations for a constructor, addCardToHand, printHand, handSize, discard, hasAce and getHandValue public methods
* as well as multiple declarations for boolean private methods for checking special cases of hand values and card / int vectors for hand
* It is meant to build a hand of card objects and return a value based off the cards in the hand
*/
#pragma once
#include "Card.h"
#include <vector>


class Hand {
public:
    // hand constructor
    Hand();
    
    // public methods
    void addCardToHand(const Card& card);  // adds card to hand
    void printHand();                      // prints contents of hand
    int handSize();                        // returns handsize
    void discard(int index, Card card);    // discards a card from given index in hand and replaces it
    bool hasAce() const;                   // determines if an ace is in the hand
    int getHandValue() const;                    // determines the hands value
    friend std::ostream& operator<<(std::ostream& os, const Hand& hand);
    std::strong_ordering operator<=>(const Hand& other) const;

private:
    // private property
    std::vector<Card> hand; 
    std::vector<int> getHandSuits() const;
    std::vector<int> getHandValues() const;

    bool hasKing();
    int getHighCard(std::vector<int> handValues) const;
    bool isFlush(std::vector<int> handSuits) const;
    bool isStraight(std::vector<int> handValues) const;
    bool isFourOfKind(std::vector<int> handValues) const;
    bool isThreeOfKind(std::vector<int> handValues) const;
    bool isTwoPair(std::vector<int> handValues) const;
    bool isPair(std::vector<int> handValues) const;
    bool isFullHouse(std::vector<int> handValues) const;
    bool isRoyalFlush(std::vector<int> handValues, std::vector<int> handSuits) const;
    bool isStraightFlush(std::vector<int> handValues, std::vector<int> handSuits) const;


};
