#include "flipcard.h"
#include "controller.h"
#include "carddeck.h"
#include "types.h"
#include "humanplayer.h"
#include "aiplayer.h"
#include <iostream>

// Function prototype statements
void testFlipCard();
void testController();
void testCardDeck();
void runAllTests();
void TestPlayer();
int main() {
	int option = 0;

	try {
		while (option != 9) {
			// Re-initialize to clear the previous option, in case "garbage" is entered by the user
			option = 0;

			std::cout << "Unit Tests" << std::endl << std::endl;
			std::cout << "1. Test FlipCard" << std::endl;
			std::cout << "2. Test Controller" << std::endl;
			std::cout << "3. Test Card Deck" << std::endl;
			std::cout << "4. Test Player" << std::endl;
			std::cout << "8. Run all tests" << std::endl;
			std::cout << "9. Exit" << std::endl << std::endl;

			std::cout << "Enter your Menu option: ";
			std::cin >> option;

			// Prevent "the matrix" (warning: '/' causes cin to "hang"!)
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');

			switch (option) {
				case 1: {
					testFlipCard();
					break;
				}
				case 2: {
					testController();
					break;
				}
				case 3: {
					testCardDeck();
					break;
				}
				case 4: {
					TestPlayer();
					break;
				}
				case 8: {
					runAllTests();
					break;
				}
				case 9: {
					std::cout << std::endl << "All Unit Tests completed." << std::endl;
					break;
				}
				default: {
					std::cout << std::endl << "Invalid Menu option" << std::endl;
					break;
				}
			}
		}
	}
	catch (const std::exception& e) {
		// This catch also catches runtime_error exceptions, derived from std::exception
		// Display the error message built by the function that threw the runtime_error exception
		std::cout << e.what() << std::endl;
		std::cout << "Unit Tests: System error, unable to continue." << std::endl;
		return EXIT_FAILURE;
	}
}

void testFlipCard() {
	std::cout << std::endl << "Testing the FlipCard:" << std::endl << std::endl;

	Card* one	= new Card();
	Card* two	= new Card();
	Card* three = new Card();
	Card* four	= new Card();
	
	FlipCard* card = new FlipCard(one, two, three, four);

	FlipCard* card2 = new FlipCard();
	card2->setSide(SIDES::FRONT_SIDE, one);

	// FOR DISCUSSION PURPOSES ONLY (AUTO. OBJECTS VS. DYNAMIC OBJECTS)
	//Card oneAuto;
	//Card twoAuto;
	//Card threeAuto;
	//Card fourAuto;

	// Parms passed by copy
	//FlipCard cardAuto(oneAuto, twoAuto, threeAuto, fourAuto);
}

void testController() {
	std::cout << std::endl << "Testing the Controller:" << std::endl << std::endl;

	Controller controller;
}

void testCardDeck() {
	std::cout << std::endl << "Testing the Card Deck:" << std::endl << std::endl;

	Types* types = new Types();
	CardDeck cardDeck1("carddeck.xml", types);


}

void runAllTests() {
	std::cout << std::endl << "Running all tests:" << std::endl;

	testFlipCard();
	testController();
	testCardDeck();
	TestPlayer();
}
void TestPlayer() {
	std::cout << std::endl << "Testing the player: " << std::endl << std::endl;
	Types* types = new Types();
	std::vector<Player*> player;
	Player* player1 = new HumanPlayer("eric", "carddeck.xml", types);
	Player* player2 = new AIPlayer("David", "carddeck.xml", types);
	player.emplace_back(player1);
	player.emplace_back(player2);
}