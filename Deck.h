/*
* William Sykes
* This is the Header file for Deck.cpp
* The Deck Class has declarations for a constructor, deal card and deck size methods
* It is meant to build a deck of cards to draw from stored in vector deck
*/
#pragma once
#include "Card.h"
#include <vector>
using namespace cardInfo;

class Deck {
public:
    // deck constructor
    Deck();

    // public methods
    Card dealCard();           // deals a card and removes a card from deck vector
    int deckSize();            // gets deck size as int

    
private:
    // private property
    std::vector<Card> deck;
};




