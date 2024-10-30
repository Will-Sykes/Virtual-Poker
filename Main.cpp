/*
* William Sykes
* This is Main.cpp
* This holds the declaration and definition for goodDiscards, as well as runs the poker program 
* initiallizes a deck and hand and populates each with card objects
* prints card in hands and gets a value for the hand. 
*/
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <iostream>

using namespace std;

/*
* Checking if the user chooses cards to discard within the specified parameters
* @param const vector<int>& numbers, the numbers for the indeces to be replaced entered by user.
* @param hasAce a boolean value to check if there is an ace in the hand.
* @return returns true or false
*/

bool goodDiscards(const vector<int>& numbers, bool hasAce);

int main() {

    bool play = true;
    
    do {
        // create deck and hand vector objects
        Deck Deck;
        Hand Hand1;
        Hand Hand2;
        Card testCard = Deck.dealCard();
       

        //deal and add cards to the hand
        for (int i = 0; i < 5; ++i) {
            Card dealtCard1 = Deck.dealCard();
            Hand1.addCardToHand(dealtCard1);
            Card dealtCard2 = Deck.dealCard();
            Hand2.addCardToHand(dealtCard2);
        }
        
        //cout << Hand1; 
        // for testing
         /*
        // No Special Case
        Deck Deck;
        Hand Hand1;
        Card specificCards[5] = {
            Card(Value::Four, Suit::Club),
            Card(Value::Nine, Suit::Spade),
            Card(Value::Two, Suit::Diamond),
            Card(Value::Three, Suit::Spade),
            Card(Value::Seven, Suit::Club)
        };

        // populate the hand with the specific cards
        for (const Card& specificCard : specificCards) {
            Hand1.addCardToHand(specificCard);
        }*/

        // get and print the hand size
        // then print the hand
        // calculate and print the hand value
        cout << "\nThere are " << Hand1.handSize() << " cards in each hand" << std::endl;
        cout << "\nThese cards are in Player 1's Hand: " << std::endl;
        //Hand1.printHand();
        cout << Hand1;
        int handValue1 = Hand1.getHandValue();
        std::cout << "Your Hand Value: " << handValue1 << std::endl;
        cout << "There are " << Deck.deckSize() << " cards remaining in the deck" << std::endl;
        cout << "You may replace three cards in your hand, four if you have an ace" << std::endl;
        
        //excepting cards to discard
        vector<int> userNumbers;
        bool isInputValid = false;
        cout << "Please enter the number of the card(s) you wish to discard, followed by <0>: ";
        bool aceCheck;
        int num;
        userNumbers.clear();
        cin.clear();
        while (cin >> num && num != 0) {
            userNumbers.push_back(num);
        }
        //discard check
        aceCheck = Hand1.hasAce();
        isInputValid = goodDiscards(userNumbers, aceCheck);
        if (isInputValid == false) {
            return 0;     
        }
        //replacing card in indeces with card from deck if discards good
        for (int userNumber : userNumbers) {
            Card dealtCard = Deck.dealCard();
            Hand1.discard(userNumber, dealtCard);  
        }
        //get and print the hand size
        //print the cards in hand
        // calculate and print the hand value
        // calculate and print the hand value
        std::cout << "\nThese cards are in the Player 1's hand: " << std::endl;
        cout << Hand1;
        handValue1 = Hand1.getHandValue();
        std::cout << "Your Hand Value: " << handValue1 << std::endl;
        cout << "There are " << Deck.deckSize() << " cards remaining in the deck" << std::endl;

        //get and print the hand size
        //print the cards in hand
        // calculate and print the hand value
        // calculate and print the hand value
        cout << "Player 2 it is your turn!" << endl;
        cout << "\nThere are " << Hand2.handSize() << " cards in player two's hand" << std::endl;
        cout << "\nThese cards are in Player 2's hand: " << std::endl;
        cout << Hand2;
        int handValue2 = Hand2.getHandValue();
        std::cout << "Your Hand Value: " << handValue2 << std::endl;
        cout << "You may replace three cards in your hand, four if you have an ace" << std::endl;
        isInputValid = false;
        int num2;
        cout << "Please enter the number of the card(s) you wish to discard, followed by <0>: " << endl;
        userNumbers.clear();
        cin.clear();
        while (cin >> num2 && num2 != 0) {

            userNumbers.push_back(num2);
        }
        aceCheck = Hand2.hasAce();
        isInputValid = goodDiscards(userNumbers, aceCheck);

        if (isInputValid == false) {

            return 0;
        }
        //replacing card in indeces with card from deck
        for (int userNumber : userNumbers) {
            Card dealtCard3 = Deck.dealCard();
            Hand2.discard(userNumber, dealtCard3);
        }
        //get and print the hand size
        std::cout << "\nThere are " << Hand2.handSize() << " cards in the hand" << std::endl;
        std::cout << "\nThese cards are in the hand: " << std::endl;
        //print the cards in hand
        cout << Hand2;
        // calculate and print the hand value
        handValue2 = Hand2.getHandValue();
        std::cout << "Your Hand Value: " << handValue2 << std::endl;

        strong_ordering compareResult = Hand1 <=> Hand2;

        if (compareResult == strong_ordering::greater) {
            cout << "Player 1 Wins!" << endl;
        }
        else if (compareResult == strong_ordering::equal) {
            cout << "its a tie!" << endl;
        }
        else {
            cout << "Player 2 Wins!" << endl;
        }

        //strong_ordering compareResult = *hand1 <=> *hand2;

        //Prompt the user to play again
        std::cout << "Press Y to play again, N to quit: ";
        char yon;
        std::cin >> yon;

        if (yon == 'N' || yon == 'n') {
            play = false;
        }

        // Clear any remaining characters in the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (play);
    

    return 0;
}

bool goodDiscards(const vector<int>& numbers, bool hasAce) {

    //checking user entered at least 1 card to replace
    if (numbers.size() < 1) {
        cout << "Please enter cards to discard" << endl;
        return false;
    }

    //checking the number of cards to discard based on the presence of an Ace
    int maxAllowedCards = hasAce ? 4 : 3;
    if (numbers.size() > maxAllowedCards) {
        cout << "You've drawn too many cards" << endl;
        return false;
    }

    //checking for duplicates
    for (int number : numbers) {
        int count = 0;                 //counts how many times a particular number appears in vector
        for (int n : numbers) {
            if (number == n) {
                count++;
            }
            if (count > 1) {
                cout << "Please do not enter duplicate numbers." << endl;
                return false;

            }
        }
    }

    //checking for valid card values (1-5)
    for (int number : numbers) {
        if (number < 1 || number > 5) {
            cout << "Please choose cards to discard within the specified range." << endl;
            return false;

        }
    }


    return true;
}