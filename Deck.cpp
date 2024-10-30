/*
* William Sykes
* This is Deck.cpp
* This the definitions for the constructor, deal card and dec size methods.
*/
#include "Deck.h"
#include <random>
#include <algorithm>
#include <ctime>

using namespace cardInfo;


/*
* Deck Constructor
* populates the deck with 52 card objects
*/
Deck::Deck() {
    // seeding random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // create a standard deck of 52 cards 
    for (const Suit& suit : allSuits) {
        for (const Value& value : allValues) {
            deck.push_back(Card(value, suit));
        }
    }
    std::random_device rd;
    std::mt19937 g(rd());  
    // shuffle the deck
    std::shuffle(deck.begin(), deck.end(), g);
}

/*
* dealCard method
* copies and returns a card from the back of the deck vector and 
* pops that card off the deck to remove it
* @return returns a card from the back of deck
*/
Card Deck::dealCard() {
    if (!deck.empty()) {
        Card card = deck.back();
        deck.pop_back();
        return card;
    }
    else {
        return Card();
    }
}

/*
* deckSize method
* @return returns deck size as an int
*/
int Deck::deckSize() {
    return static_cast<int>(deck.size());
}
