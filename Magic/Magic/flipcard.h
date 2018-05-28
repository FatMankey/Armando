#pragma once

#include "card.h"
#include <vector>

// OOP Inheritance: a FlipCard IS A (front) Card
class FlipCard : public Card {
	private:
		int					currentSide;

		// OOP Composition: a FlipCard HAS A (back) Card
		std::vector<Card*>	backSides;

		// FOR DISCUSSION PURPOSES ONLY (AUTO. OBJECTS VS. DYNAMIC OBJECTS)
		std::vector<Card>	backSideAuto;

		bool				flippable;
		bool				flipped;

	public:
		FlipCard();
		FlipCard(Card* frontSide, Card* backSide);
		FlipCard(Card* frontSide, Card* backSide1, Card* backSide2, Card* backSide3);

		// FOR DISCUSSION PURPOSES ONLY (AUTO. OBJECTS VS. DYNAMIC OBJECTS)
		FlipCard(Card frontSide, Card backSide1, Card backSide2, Card backSide3);

		~FlipCard();

		// Getters
		int		getCurrentSide() const;
		bool	isFlippable() const;
		bool	isFlipped() const;
		
		// Setters
		void	setSide(SIDES side, Card* card);

		bool	flip(int side);
		bool	tap(int side);
};
