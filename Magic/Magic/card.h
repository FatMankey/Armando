#pragma once

#include "constants.h"
#include "mana.h"
#include <string>
#include <map>

class Card {
	private:
		SIDES					side;
		std::string				name;
		int						type;

		// Ordered, unique key/value pairs
		std::map<int, int>		&mana;

		int						convertedManaCost;		// CMC
		std::string				text;
		bool					tapped;
		bool					valid;

	public:
		Card();
		Card(SIDES side, std::string name, int type, std::map<int, int> &mana, std::string text);

		// Copy constructor and copy assignment operator
		Card(const Card *other);
		Card* operator =(const Card *other);

		~Card();

		// Getters
		// A function declared const cannot inadvertedly change a class variable
		SIDES getSide() const;
		std::string getName() const;
		int getType() const;
		std::map<int, int>& getMana() const;
		int getMana(int color) const;
		int getConvertedManaCost() const;
		std::string getText() const;
		bool isTapped() const;
		bool isBlank() const;
		bool isValid() const;

		// Setters
		void setCard(SIDES side, std::string name, int type, std::map<int, int> &mana, std::string text, bool tapped);
		void setSide(SIDES side);
		void setName(std::string name);
		void setType(int type);
		void setMana(std::map<int, int>	&mana);
		bool addMana(int color, int numberOfMana);
		void setText(std::string text);
		void setTapped();
		void setValid(bool valid);
};
