**Overview**
This project implements a terminal-based virtual poker game for two players. It uses a multi-file structure to manage cards, decks, and player hands, allowing players to draw and discard cards and determine a winner based on hand rankings.

**Features**
Card Management: Represents individual cards with a suit and value.
Deck Management: Handles the creation, shuffling, and dealing of cards.
Hand Management: Builds hands of cards for players and evaluates their hand values.
Game Logic: Simulates a round of poker where players draw, discard, and compare hands to determine the winner.

**Files**
Main.cpp: The main driver of the program. Initializes the deck and hands for two players, facilitates card dealing, and evaluates the value of the players' hands.
Card.cpp / Card.h: Implements the Card class, which represents individual playing cards, including suits and values. Provides methods for setting and getting card attributes.
Deck.cpp / Deck.h: Implements the Deck class, which handles the shuffling and dealing of cards from a standard 52-card deck.
Hand.cpp / Hand.h: Implements the Hand class, which manages a player's hand of cards. Provides methods for adding cards, discarding cards, and calculating the hand's value.

**How to Run**
Compile the project using Visual Studio or your preferred C++ compiler.
Run the Main.cpp file, which will start a round of poker between two players.
Players will be dealt cards, and the program will allow them to discard and draw new cards before evaluating the hands to determine the winner.

**Game Flow**
The deck is shuffled, and each player is dealt five cards.
Players can choose to discard some cards and receive new ones from the deck.
The hand values are compared, and the player with the higher hand wins.
