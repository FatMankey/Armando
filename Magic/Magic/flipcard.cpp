#include "flipcard.h"

FlipCard::FlipCard() : Card() {
	currentSide = BLANK_CARD;
	flippable	= false;
	flipped		= false;
}

FlipCard::FlipCard(Card* frontSide, Card* backSide) : Card(SIDES::FRONT_SIDE, frontSide->getName(), frontSide->getType(), frontSide->getMana(), frontSide->getText()) {	
	currentSide	= 1;
	backSides.push_back(backSide);
	flippable	= true;
	flipped		= false;
}

FlipCard::FlipCard(Card* frontSide, Card* backSide1, Card* backSide2, Card* backSide3) : Card(SIDES::FRONT_SIDE, frontSide->getName(), frontSide->getType(), frontSide->getMana(), frontSide->getText()) {
	backSides.push_back(backSide1);
	backSides.push_back(backSide2);
	backSides.push_back(backSide3);
}

// FOR DISCUSSION PURPOSES ONLY (AUTO. OBJECTS VS. DYNAMIC OBJECTS)
// Parms passed by copy (copy #1)
FlipCard::FlipCard(Card frontSide, Card backSide1, Card backSide2, Card backSide3) {
	// Vector makes its own copy before inserting object (copy #2)
	backSideAuto.push_back(frontSide);

	// Retrieving an object from a Vector (copy #3)
	Card card = backSideAuto.at(0);

	backSideAuto.push_back(backSide1);
	backSideAuto.push_back(backSide2);
	backSideAuto.push_back(backSide3);
}

FlipCard::~FlipCard() {
	for (std::vector<Card*>::iterator iterator = backSides.begin(); iterator != backSides.end(); ++iterator) {
		delete *iterator;
		backSides.erase(iterator);
	}
}

bool FlipCard::isFlipped() const {
	return currentSide == 2;
}

int FlipCard::getCurrentSide() const {
	return currentSide;
}

void FlipCard::setSide(SIDES side, Card* card) {
	if (side == SIDES::FRONT_SIDE) {
		Card::setCard(side, card->getName(), card->getType(), card->getMana(), card->getText(), card->isTapped());
	}
	else {
		backSides.push_back(card);
	}
}

/*
bool FlipCard::flip(int side) {
	bool flip = false;

	switch (side) {
		case 1: {
			if (Card::isFlippable() && !Card::isFlipped()) {
				flipped = true;
				flip	= true;
			}
			break;
		}
		case 2: {
			if (backSides.isFlippable() && !backSides.isFlipped()) {
				backSides.flipped = true;
				flip				= true;
			}
			break;
		}
	}

	return flip;
}
*/

/*
bool FlipCard::tap(int side) {
	bool tap = false;

	switch (side) {
		case 1: {
			if (!tapped) {
				tapped	= true;
				tap		= true;
			}
			break;
		}
		case 2: {
			if (!backSides.tapped) {
				backSides.tapped	= true;
				tap					= true;
			}
			break;
		}
	}

	return tapped;
}
*/
