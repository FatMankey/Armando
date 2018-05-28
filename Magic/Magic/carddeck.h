#pragma once

#include "constants.h"
#include "tools.h"
#include "xmltree.h"
#include "xmlnode.h"
#include "card.h"
#include "types.h"
#include <map>
#include <string>
#include <vector>

class CardDeck {
	private:
		std::map<std::string, Card*>	cardDeck;
		Types*							types;

		// Helper functions
		std::pair<bool, std::vector<std::string>> create(std::string fileName);

	public:
		CardDeck(std::string fileName, Types* types);
		~CardDeck();
};
