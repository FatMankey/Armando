#include "carddeck.h"

CardDeck::CardDeck(std::string fileName, Types* types) {
	this->types = types;
	create(fileName);
}

CardDeck::~CardDeck() {
}

std::pair<bool, std::vector<std::string>>  CardDeck::create(std::string fileName) {
	std::pair<bool, std::vector<std::string>> result;
	bool valid = true;

	std::vector<std::string> messages;
	std::vector<std::string> errors;
	std::vector<std::string> warnings;

	XMLTree<std::string, std::string>* rootTree = Tools::XMLParser(DATA_PATH, fileName, messages);

	if (!rootTree->isEmpty()) {
		if (!rootTree->hasErrors()) {
			std::vector<XMLTree<std::string, std::string>*> rootTreeSubtrees = rootTree->getTreesInPreOrder();

			// Temp: only 2 Cards defined in xml file
			if (rootTreeSubtrees.size() >= 2) {
				for (XMLTree<std::string, std::string>* cardSubTree : rootTreeSubtrees) {
					// Retrieve all nodes in whatever order they appear in the file.
					// The name and type nodes are required. Validate and issue errors.
					std::vector<std::pair<std::string, std::string>> nodes = cardSubTree->getNodesInOrder();

					for (std::pair<std::string, std::string> pair : nodes) {
						if (pair.first == "type") {
							std::string type = Tools::toUpper(pair.second);

							// Validate the type against the Types cardType
							if (types->findCardType(type)) {
								
							}
							else {
								// Skip rest of unknown Card
								errors.emplace_back("Error: CardDeck::create(): Invalid Card type " + type);
								break;
							}
						}
					}

				}


			}
			else {
				errors.emplace_back("Error: CardDeck::create(): Found " + std::to_string(rootTreeSubtrees.size()) + std::string(" Cards. Card Deck must have at least 60 Cards. Please correct and re-run."));
			}
		}
		else {
			errors.emplace_back("Error: CardDeck::create(): Error(s) found parsing the Card Deck file. Please correct and re-run.");
		}
	}
	else {
		errors.emplace_back("CardDeck::create(): Card Deck file is empty or was not found");
	}

	if (!errors.empty()) {
		messages.insert(messages.begin(), errors.begin(), errors.end());
		valid = false;
	}

	if (!warnings.empty()) {
		messages.insert(messages.end(), warnings.begin(), warnings.end());
	}

	result.first	= valid;
	result.second	= messages;

	return result;
}
