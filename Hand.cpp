/*
* William Sykes
* This is Hand.cpp
* This the definitions for the constructor, public and private methods
*/
#include "Hand.h"
#include <iostream>
#include <algorithm>

using namespace cardInfo;
// hand constructor / initiallizes empty hand vector
Hand::Hand() {
    hand.clear();
}

/*
* adds a card to the hand
* @param {Card} adds card object to the end of vector hand.
*/
void Hand::addCardToHand(const Card& card) {
    hand.push_back(card);
}

/*
* prints all card in the hand
* calls the printCard method for each card object in vector hand
*/
void Hand::printHand() {
    int i = 1;
    std::cout << "Hand contains the following cards:" << std::endl;
    for (const Card& card : hand) {
        std::cout << "Card" << i << ": ";
        std::cout << card;
        i++;
    }
}

std::ostream& operator<<(std::ostream& os, const Hand& hand) {
    os << "Hand contains the following cards:" << std::endl;
    int i = 1;
    for (const Card& card : hand.hand) {
        os << "Card" << i << ": " << card << std::endl; // Assuming Card has operator<< defined
        i++;
    }
    return os;
}




/*
* checks if there is an ace in the hand
*/
bool Hand::hasAce() const {
    for (const Card& card : hand) {
        if (card.getCardValue() == Value::Ace) {
            return true;
        }
    }
    return false;
}

/*
* returns hand size
* @return an int of the size of hand
*/
int Hand::handSize() {
    return static_cast<int>(hand.size());
}

/*
* hand discard method to discard a card from the hand and replace with a new one
* @param index for the card to replace
* @param card, card to replace the card in the hand with
*/
void Hand::discard(int index, Card card)
{
    if (index >= 0 && index <= hand.size()) {
        hand[static_cast<std::vector<Card, std::allocator<Card>>::size_type>(index) - 1] = card;
    }
}

/*
* gets the suit of each card in the hand
* @returns a vector of suits as integers
*/
std::vector<int> Hand::getHandSuits() const{
    std::vector<int> suits;
    for (const Card& card : hand) {
        suits.push_back(static_cast<int>(card.getCardSuit()));
    }
    return suits;
}

/*
* gets the value of each card in the hand
* @returns a vector of values as integers
*/
std::vector<int> Hand::getHandValues() const {
    std::vector<int> values;
    for (const Card& card : hand) {
        values.push_back(static_cast<int>(card.getCardValue()));
    }
    return values;
}

/*
* determine if hand has a king
* @returns true if there is a king in the hand
*/
bool Hand::hasKing() {
    for (const Card& card : hand) {
        if (card.getCardValue() == Value::King) {
            return true;
        }
    }
    return false;
}

/*
* gets the highest value card in the hand
* @param handValues a vector of the values in the hand
* @returns a vector of values as integers
*/
int Hand::getHighCard(std::vector<int> handValues) const {
    int maxCardValue = handValues[0];
    for (int value : handValues) {
        if (value > maxCardValue) {
            maxCardValue = value;
        }
    }
    return maxCardValue;
}

/*
* checks if the hand contains a full house
* @param handValues a vector of the values in the hand
* @returns true if a full house is present
*/
bool Hand::isFullHouse(std::vector<int> handValues) const {
    // sorting the hand values in ascending order
    std::sort(handValues.begin(), handValues.end());

    // the first three cards have the same rank and the last two cards have the same rank or
    // the first two cards have the same rank and the last three have the same rank
    if ((handValues[0] == handValues[1] && handValues[2] == handValues[3] && handValues[3] == handValues[4]) ||
        (handValues[0] == handValues[1] && handValues[1] == handValues[2] && handValues[3] == handValues[4])) {
        return true;
    }

    return false;
}

/*
* checks if the hand contains a royal flush
* @param handValues a vector of the values in the hand
* @param handSuits a vector of the suits in the hand
* @returns true if a royal flush is present
*/
bool Hand::isRoyalFlush(std::vector<int> handValues, std::vector<int> handSuits) const {
    // check if it's a straight flush first
    if (isStraight(handValues) && isFlush(handSuits)) {
        // check if the highest card is Ace (13) and the second highest card is King (12)
        if (handValues[0] == 13 && handValues[1] == 12) {
            return true;
        }
    }

    return false;
}

/*
* checks if the hand contains a flush
* @param handSuits a vector of the suits in the hand
* @returns true if a all suits are the same 
*/
bool Hand::isFlush(std::vector<int> handSuits) const {
    for (int suit : handSuits) {
        if (suit != handSuits[0]) {
            return false;
        }
    }
    return true;
}

/*
* checks if the hand contains a straight
* @param handValues a vector of the values in the hand
* @returns true if 5 cards are consecutive and thus a straight, compares value to previous value, 
* if value is equal to prevValue + 1 this means the values are consecutive
*/
bool Hand::isStraight(std::vector<int> handValues) const {
    std::sort(handValues.begin(), handValues.end());
    int prevValue = handValues[0];
    for (int value : handValues) {
        if (value != prevValue) {
            if (value != prevValue + 1) {
                return false;
            }
        }
        prevValue = value;
    }
    return true;
}

/*
* checks if the hand contains a straight flush
* @param handValues a vector of the values in the hand
* @param handSuits a vector of the values in the hand
* @returns true if there is a straight and a flush present
*/
bool Hand::isStraightFlush(std::vector<int> handValues, std::vector<int> handSuits) const {
    return isFlush(handSuits) && isStraight(handValues);
}



/*
* checks if the hand contains a four of a kind
* @param handValues a vector of the values in the hand
* @returns true if there is four of the same rank / value card in the hand. keeps count of each value in hand
*/
bool Hand::isFourOfKind(std::vector<int> handValues) const {
    for (int value : handValues) {
        auto count = static_cast<int>(std::count(handValues.begin(), handValues.end(), value));
        if (count == 4) {
            return true;
        }
    }
    return false;
}

/*
* checks if the hand contains a three of a kind
* @param handValues a vector of the values in the hand
* @returns true if there is three of the same rank / value card in the hand. keeps count of each value in hand
*/
bool Hand::isThreeOfKind(std::vector<int> handValues) const {
    for (int value : handValues) {
        auto count = static_cast<int>(std::count(handValues.begin(), handValues.end(), value));
        if (count == 3) {
            return true;
        }
    }
    return false;
}

/*
* checks if the hand contains two pairs
* @param handValues a vector of the values in the hand
* @returns returns trued if there are two values with more than 1 count 
*/
bool Hand::isTwoPair(std::vector<int> handValues) const {

    // array to count the occurrences of each card value
    int valueCounts[13] = { 0 }; // all counts to zero
    int pairs = 0;               // number of pairs

    for (int value : handValues) {

        // increment count for the corresponding card value
        valueCounts[value - 1]++;

        // encounter a value twice, pair++
        if (valueCounts[value - 1] == 2) {
            pairs++;
        }

        // two distinct pairs
        if (pairs >= 2) {
            return true; 
        }
    }

    return false;
}

/*
* checks if the hand contains a pair
* @param handValues a vector of the values in the hand
* @returns true if there is two of the same rank / value card in the hand. keeps count of each value in hand
*/
bool Hand::isPair(std::vector<int> handValues) const {
    for (int value : handValues) {
        auto count = static_cast<int>(std::count(handValues.begin(), handValues.end(), value));
        if (count == 2) {
            return true;
        }
    }
    return false;
}

std::strong_ordering Hand::operator<=>(const Hand& other) const {
    // Compare hands based on your criteria
    // Implement your comparison logic here, for example, using getHandValue()
    return getHandValue() <=> other.getHandValue();
}

/*
* gets a value for the hand based off the hands suits and values
* @returns an integer value based on the cards in the hand
*/
int Hand::getHandValue() const {

    // values and suits of the hand
    std::vector<int> handValues = getHandValues();
    std::vector<int> handSuits = getHandSuits();

    // sorting the hand values in descending order to assign weights to the cards
    std::sort(handValues.rbegin(), handValues.rend());
    // weights for each card
    int c1 = 3583;
    int c2 = 512;
    int c3 = 64;
    int c4 = 8;
    int c5 = 1;

    // all the booleans to check for each special cases
    bool havePair = isPair(handValues);
    bool haveTwoPair = isTwoPair(handValues);
    bool haveThreeOfKind = isThreeOfKind(handValues);
    bool haveFourOfKind = isFourOfKind(handValues);
    bool haveStraight = isStraight(handValues);
    bool haveFlush = isFlush(handSuits);
    bool haveFullHouse = isFullHouse(handValues);
    bool haveStraightFlush = isStraightFlush(handValues, handSuits);
    bool haveRoyalFlush = isRoyalFlush(handValues, handSuits);
    int highCard = getHighCard(handValues);

    /*
    * TotalHandvalue + Sumhand + HighcardValue + HandValue
    * SumHand = A8^4 + K8^3 +Q8^2
    * 
    * 
    */
    // if / else if statements to check for Royal Flush -> Pair, calculating weighted hand values of each
    // printing the special case if there is any
    if (haveRoyalFlush) {
        // sorts hand by value, multiplies by weight of each and adds 125,000
        int handValue = (c1 * handValues[0] * 2)
            + c2 * handValues[1]
            + c3 * handValues[2]
            + c4 * handValues[3]
            + c5 * handValues[4]
            + 200000;     //was 145,000   so + 55
        std::cout << "----------------------" << std::endl;
        std::cout << "Royal Flush!" << std::endl;
        return handValue;
    }
    else if (haveStraightFlush) {
        // mult weight and high card by 2 to exceed four of a kind and clearly define winner if two straight flush
        int handValue = (c1 * handValues[0] * 2)
            + c2 * handValues[1]
            + c3 * handValues[2]
            + c4 * handValues[3]
            + c5 * handValues[4]
            + 140000;     // was 120 so + 20
        std::cout << "----------------------" << std::endl;
        std::cout << "Straight Flush!" << std::endl;
        std::cout << "High Card: " << highCard << std::endl;
        return handValue;
    }
    else if (haveFourOfKind) {
        // reorder the hand values matching cards first
        if (handValues[0] != handValues[1]) {
            std::swap(handValues[0], handValues[4]);
        }
        // mult the weight and card value of second card by 2 to not overtake a straight flush and still account for high card
        int handValue = c1 * handValues[0]
            + (c2 * handValues[1] * 2)
            + c3 * handValues[2]
            + c4 * handValues[3]
            + c5 * handValues[4]
            + 115000;  //was 100,000 so + 15
        std::cout << "----------------------" << std::endl;
        std::cout << "Four Of a Kind!" << std::endl;
        std::cout << "High Card: " << highCard << std::endl;
        return handValue;
    }
    else if (haveFullHouse) {
        if (handValues[0] == handValues[1] && handValues[3] == handValues[4]) {
            // Check if swapping is necessary
            if (handValues[2] <= handValues[3]) {
                // swapping the three matching cards with the two matching cards to account for the highest value 3 matching
                std::swap(handValues[0], handValues[3]);
                std::swap(handValues[1], handValues[4]);
            }
        }
        int handValue = c1 * handValues[0]
            + (c2 * handValues[1])
            + c3 * handValues[2]
            + c4 * handValues[3]
            + c5 * handValues[4]
            + 70000;
        std::cout << "----------------------" << std::endl;
        std::cout << "Full House!" << std::endl;
        std::cout << "High Card: " << highCard << std::endl;
        return handValue;
    }
    else if (haveFlush) {
        int handValue = c1 * handValues[0]
            + c2 * handValues[1]
            + c3 * handValues[2]
            + c4 * handValues[3]
            + c5 * handValues[4]
            + 15000;
        std::cout << "----------------------" << std::endl;
        std::cout << "Flush!" << std::endl;
        std::cout << "High Card: " << highCard << std::endl;
        return handValue;
    }
    else if (haveStraight) {                        // good
        int handValue = c1 * handValues[0]
            + c2 * handValues[1]
            + c3 * handValues[2]
            + c4 * handValues[3]
            + c5 * handValues[4]
            + 10000;
        std::cout << "----------------------" << std::endl;
        std::cout << "Straight!" << std::endl;
        std::cout << "High Card: " << highCard << std::endl;
        return handValue;
    }
    else if (haveThreeOfKind) {
        // Check if swapping is necessary 
        if (handValues[0] != handValues[2] && handValues[2] == handValues[3]) {
            // Swapping the three matching cards to account for the highest value 3 matching
            std::swap(handValues[0], handValues[3]);
            std::swap(handValues[1], handValues[4]);
        }
        
        else if (handValues[0] > handValues[1] && handValues[1] == handValues[3]) {
            // Swapping the three matching cards to account for the highest value 3 matching
            std::swap(handValues[0], handValues[3]);
        }
        int handValue = c1 * handValues[0]
          
            // Doing this to keep to the hierarchy Straight > Three of a Kind
            //+ c2 * handValues[1]
            //+ c3 * handValues[2]
            //+ c4 * handValues[3]
            //+ c5 * handValues[4]
            - 10000;
        if (handValue < 10000) {
            handValue+=10000;
        }
        std::cout << "----------------------" << std::endl;
        std::cout << "Three Of a Kind" << std::endl;
        std::cout << "High Card: " << highCard << std::endl;
        return handValue;
    }
    else if (haveTwoPair) {
       

        // identify the positions of the pairs
        int firstPairPosition = -1;
        int secondPairPosition = -1;

        for (int i = 0; i < 4; ++i) {
            if (handValues[i] == handValues[i + 1]) {
                firstPairPosition = i;
                secondPairPosition = i + 1;
                break;
            }
        }

        // remaining card  at the 4th position
        if (firstPairPosition != 0 && secondPairPosition != 0) {
            if (firstPairPosition == 2 || secondPairPosition == 2) {
                std::swap(handValues[2], handValues[4]);
            }
            else {
                std::swap(handValues[1], handValues[4]);
            }
        }

        int handValue = c1 * handValues[4]
            // To Keep the hierarchy
            //+ c2 * handValues[1]
            //+ c3 * handValues[2]
            //+ c4 * handValues[3]
            //+ c5 * handValues[4]
            -5000;
        if (handValue > 12000) {
            handValue -= 6000;
        }
        std::cout << "----------------------" << std::endl;
        std::cout << "Two Pair!" << std::endl;
        std::cout << "High Card: " << highCard << std::endl;
        return handValue;
    }
    else if (havePair) {
        // attempting to keep hierarchy
        int handValue = c1 * handValues[0]
            + 1 * handValues[1]
            + 2 * handValues[2]
            + 3 * handValues[3]
            + 4 * handValues[4]
            -35000;
        std::cout << "----------------------" << std::endl;
        std::cout << "You got a Pair!" << std::endl;
        std::cout << "High Card: " << highCard << std::endl;
        return handValue;

    }
        // returns value based on cards in hand and high card
        int handValue = 2 * handValues[0]
            + 1 * handValues[1]
            + 1 * handValues[2]
            + 1 * handValues[3]
            + 1 * handValues[4];

        std::cout << "----------------------" << std::endl;
        std::cout << "High Card: " << highCard << std::endl;
        return handValue;
    
}

