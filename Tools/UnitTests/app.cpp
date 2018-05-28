#include "tools.h"
#include <iostream>
#include <string>
#include <vector>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void testTreeTraversals();
void testTree();
void testXMLParserRules();
void testXMLParserYugioh();
void testDateToString();
void testReplaceAll();
void runAllTests();

int main() {
	int option = 0;

	try {
		while (option != 9) {
			// Re-initialize to clear the previous option, in case "garbage" is entered by the user
			option = 0;

			std::cout << "Unit Tests Version 2" << std::endl << std::endl;

			std::cout << "1. Test Tree Traversals" << std::endl;
			std::cout << "2. Test Tree class" << std::endl;
			std::cout << "3. Test XMLParser-Rules" << std::endl;
			std::cout << "4. Test XMLParser-Yugioh" << std::endl;
			std::cout << "5. Test Date to String" << std::endl;
			std::cout << "6. Test removeAll()" << std::endl;
			std::cout << "8. Run all tests" << std::endl;
			std::cout << "9. Exit" << std::endl << std::endl;

			std::cout << "Enter your Menu option: ";
			std::cin >> option;

			// Prevent "the matrix" (warning: '/' causes cin to "hang"!)
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');

			switch (option) {
				case 1: {
					testTreeTraversals();
					break;
				}
				case 2: {
					testTree();
					break;
				}
				case 3: {
					testXMLParserRules();
					break;
				}
				case 4: {
					testXMLParserYugioh();
					break;
				}
				case 5: {
					testDateToString();
					break;
				}
				case 6: {
					testReplaceAll();
					break;
				}
				case 8: {
					runAllTests();
					break;
				}
				case 9: {
					std::cout << std::endl << "All Unit Tests completed." << std::endl << std::endl;
					break;
				}
				default: {
					std::cout << std::endl << "Invalid Menu option" << std::endl << std::endl;
					break;
				}
			}
		}

		return EXIT_SUCCESS;
	}
	catch (const std::exception& e) {
		// This catch also catches runtime_error exceptions, derived from std::exception
		// Display the error message built by the function that threw the runtime_error exception
		std::cout << e.what() << std::endl;
		std::cout << "Tools Unit Tests: System error, unable to continue." << std::endl;
		return EXIT_FAILURE;
	}
}

void testTreeTraversals() {
	std::cout << std::endl << "Testing Tree Traversals: Wikipedia one-Tree example" << std::endl;

	std::vector<std::string> messages;

	XMLTree<std::string, std::string>* rootTree1 = Tools::XMLParser("c:/data/tree", "test1.xml", messages);

	if (!rootTree1->isEmpty()) {
		if (!rootTree1->hasErrors()) {
			// Test pre-order traversal
			std::vector<XMLTree<std::string, std::string>*> preOrderTraverse = rootTree1->getTreesInPreOrder();

			if (!preOrderTraverse.empty()) {
				std::cout << std::endl << "Pre-Order Traversal" << std::endl << std::endl;

				for (XMLTree<std::string, std::string>* tree : preOrderTraverse) {
					std::cout << tree->getNodeKey() << "\t";
				}

				std::cout << std::endl << std::endl;
			}

			// Test in-order traversal
			/*
			std::vector<XMLTree<std::string, std::string>*> inOrderTraverse = rootTree1->inOrderTreeTraversal();

			if (!inOrderTraverse.empty()) {
				std::cout << "In-Order Traversal" << std::endl << std::endl;

				for (XMLTree<std::string, std::string>* tree : inOrderTraverse) {
					std::cout << tree->getNodeKey() << "\t";
				}

				std::cout << std::endl << std::endl;
			}

			// Test post-order traversal
			std::vector<XMLTree<std::string, std::string>*> postOrderTraverse = rootTree1->postOrderTreeTraversal();

			if (!postOrderTraverse.empty()) {
				std::cout << "Post-Order Traversal" << std::endl << std::endl;

				for (XMLTree<std::string, std::string>* tree : postOrderTraverse) {
					std::cout << tree->getNodeKey() << "\t";
				}

				std::cout << std::endl << std::endl;
			}
			*/
		}
		
		if (!messages.empty()) {
			std::cout << std::endl << "Messages:" << std::endl << std::endl;

			// Using a vector iterator
			/*
			for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it) {

			}
			*/
			// Using a for-each loop
			for (const std::string message : messages) {
				std::cout << message << std::endl;
			}
		}
	}
	else {
		std::cout << std::endl << "Oh crap! We did not get anything from the XML file!" << std::endl;
	}

	std::cout << std::endl << "Testing Tree Traversals: Wikipedia sub-Tree example" << std::endl;

	messages.clear();

	XMLTree<std::string, std::string>* rootTree2 = Tools::XMLParser("c:/data/tree", "test2.xml", messages);

	if (!rootTree2->isEmpty()) {
		if (!rootTree2->hasErrors()) {
			// Test pre-order traversal
			std::vector<XMLTree<std::string, std::string>*> preOrderTraverse = rootTree2->getTreesInPreOrder();

			if (!preOrderTraverse.empty()) {
				std::cout << std::endl << "Pre-Order Traversal" << std::endl << std::endl;

				for (XMLTree<std::string, std::string>* tree : preOrderTraverse) {
					std::cout << tree->getNodeKey() << "\t";
				}

				std::cout << std::endl << std::endl;
			}

			/*
			// Test in-order traversal
			std::vector<XMLTree<std::string, std::string>*> inOrderTraverse = rootTree2->inOrderTreeTraversal();

			if (!inOrderTraverse.empty()) {
				std::cout << "In-Order Traversal" << std::endl << std::endl;

				for (XMLTree<std::string, std::string>* tree : inOrderTraverse) {
					std::cout << tree->getNodeKey() << "\t";
				}

				std::cout << std::endl << std::endl;
			}

			// Test post-order traversal
			std::vector<XMLTree<std::string, std::string>*> postOrderTraverse = rootTree2->postOrderTreeTraversal();

			if (!postOrderTraverse.empty()) {
				std::cout << "Post-Order Traversal" << std::endl << std::endl;

				for (XMLTree<std::string, std::string>* tree : postOrderTraverse) {
					std::cout << tree->getNodeKey() << "\t";
				}

				std::cout << std::endl << std::endl;
			}
			*/
		}

		if (!messages.empty()) {
			std::cout << std::endl << "Messages:" << std::endl << std::endl;

			// Using a vector iterator
			/*
			for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it) {

			}
			*/
			// Using a for-each loop
			for (const std::string message : messages) {
				std::cout << message << std::endl;
			}
		}
	}
	else {
		std::cout << std::endl << "Oh crap! We did not get anything from the XML file!" << std::endl;
	}

	std::cout << "Testing Tree Traversals: Wikipedia Node example" << std::endl;

	messages.clear();

	XMLTree<std::string, std::string>* rootTree3 = Tools::XMLParser("c:/data/tree", "test3.xml", messages);

	if (!rootTree3->isEmpty()) {
		if (!rootTree3->hasErrors()) {
			// Test pre-order traversal
			std::vector<XMLTree<std::string, std::string>*> preOrderTraverse = rootTree3->getTreesInPreOrder();

			if (!preOrderTraverse.empty()) {
				std::cout << std::endl << "Pre-Order Tree Traversal" << std::endl << std::endl;

				for (XMLTree<std::string, std::string>* tree : preOrderTraverse) {
					std::cout << tree->getNodeKey() << "\t";
				}

				std::cout << std::endl << std::endl;
			}
			
			std::vector<std::pair<std::string, std::string>> preOrderNodeTraverse = rootTree3->getNodesInOrder();

			if (!preOrderNodeTraverse.empty()) {
				std::cout << std::endl << "In-Order Node Traversal" << std::endl << std::endl;

				std::cout << "Node" << "\t" << "Value" << std::endl;

				for (const std::pair<std::string, std::string> &pair : preOrderNodeTraverse) {
					std::cout << pair.first << "\t" << pair.second << std::endl;
				}

				std::cout << std::endl;
			}

			/*
			// Test in-order traversal
			std::vector<XMLTree<std::string, std::string>*> inOrderTraverse = rootTree3->inOrderTreeTraversal();

			if (!inOrderTraverse.empty()) {
				std::cout << "In-Order Traversal" << std::endl << std::endl;

				for (XMLTree<std::string, std::string>* tree : inOrderTraverse) {
					std::cout << tree->getNodeKey() << "\t";
				}

				std::cout << std::endl << std::endl;
			}

			// Test post-order traversal
			std::vector<XMLTree<std::string, std::string>*> postOrderTraverse = rootTree3->postOrderTreeTraversal();

			if (!postOrderTraverse.empty()) {
				std::cout << "Post-Order Traversal" << std::endl << std::endl;

				for (XMLTree<std::string, std::string>* tree : postOrderTraverse) {
					std::cout << tree->getNodeKey() << "\t";
				}

				std::cout << std::endl << std::endl;
			}
			*/
		}

		if (!messages.empty()) {
			std::cout << std::endl << "Messages:" << std::endl << std::endl;

			// Using a vector iterator
			/*
			for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it) {

			}
			*/
			// Using a for-each loop
			for (const std::string message : messages) {
				std::cout << message << std::endl;
			}
		}
	}
	else {
		std::cout << std::endl << "Oh crap! We did not get anything from the XML file!" << std::endl;
	}
}

void testTree() {
	std::cout << std::endl << "Testing Tree Class:" << std::endl;

	XMLTree<std::string, std::string>* emptyTree = new XMLTree<std::string, std::string>();

	if (emptyTree->isEmpty()) {
		std::cout << std::endl << "This tree is empty" << std::endl << std::endl;
	}
	else {
		std::cout << std::endl << "This tree is not empty" << std::endl << std::endl;
	}

	XMLTree<std::string, std::string>* rootTree = new XMLTree<std::string, std::string>(0, "world");

	if (rootTree->isEmpty()) {
		std::cout << "The root tree is empty" << std::endl << std::endl;
	}
	else {
		std::cout << "The root tree is not empty" << std::endl << std::endl;
	}

	// Add end-nodes to the World root tree
	rootTree->addNode("name", "Ryan World");

	/*
	if (rootTree->isEmpty()) {
		std::cout << "The root tree is still empty after adding name node" << std::endl << std::endl;
	}
	else {
		std::cout << "The root tree is not empty after adding name node" << std::endl << std::endl;
	}
	*/

	rootTree->addNode("description", "The top level");
	 
	/*
	if (rootTree->isEmpty()) {
		std::cout << "The root tree is still empty after adding description node" << std::endl << std::endl;
	}
	else {
		std::cout << "The root tree is not empty after adding description node" << std::endl << std::endl;
	}
	*/

	rootTree->addNode("rows", "100");
	rootTree->addNode("cols", "100");
	rootTree->addNode("moveable", "false");
	
	// Create an Actor Level subtree
	XMLTree<std::string, std::string>* alTree1 = new XMLTree<std::string, std::string>(1, "actor-level");
	alTree1->addNode("name", "Ryan's Castle");
	alTree1->addNode("description", "Ryan's very nice and roomy castle");
	alTree1->addNode("rows", "80");
	alTree1->addNode("cols", "80");
	alTree1->addNode("moveable", "false");
	// Create the Actor Level's Location subtree
	XMLTree<std::string, std::string>* location1 = new XMLTree<std::string, std::string>(2, "location");
	location1->addNode("name", "Ryan World");
	location1->addNode("row", "50");
	location1->addNode("col", "50");
	location1->addNode("direction", "south");
	// Add Location subtree to the Actor Level subtree
	alTree1->addTree(location1);
	// Add Actor Level subtree to the Word root tree
	rootTree->addTree(alTree1);

	if (rootTree->isEmpty()) {
		std::cout << "The root tree is still empty after adding Tree node" << std::endl << std::endl;
	}
	else {
		std::cout << "The root tree is not empty after adding Tree node" << std::endl << std::endl;
	}

	// Create an Actor Level subtree
	XMLTree<std::string, std::string>* alTree2 = new XMLTree<std::string, std::string>(1, "actor-level");
	alTree2->addNode("name", "Ryan's Dungeon");
	alTree2->addNode("description", "Ryan's very nice and roomy dungeon");
	alTree2->addNode("rows", "10");
	alTree2->addNode("cols", "10");
	alTree2->addNode("moveable", "false");
	// Create the Actor Level's Location subtree
	XMLTree<std::string, std::string>* location2 = new XMLTree<std::string, std::string>(2, "location");
	location2->addNode("name", "Ryan's Castle");
	location2->addNode("row", "40");
	location2->addNode("col", "40");
	location2->addNode("direction", "down");
	// Add Location subtree to the Actor Level subtree
	alTree2->addTree(location2);
	// Add Actor Level subtree to the Word root tree
	rootTree->addTree(alTree2);

	// Create an Actor Level subtree
	XMLTree<std::string, std::string>* alTree3 = new XMLTree<std::string, std::string>(1, "actor-level");
	alTree3->addNode("name", "The Strecher Room");
	alTree3->addNode("description", "For increasing your height");
	alTree3->addNode("rows", "5");
	alTree3->addNode("cols", "5");
	alTree3->addNode("moveable", "false");
	// Create the Actor Level's Location subtree
	XMLTree<std::string, std::string>* location3 = new XMLTree<std::string, std::string>(2, "location");
	location3->addNode("name", "Ryan's Dungeon");
	location3->addNode("row", "1");
	location3->addNode("col", "1");
	location3->addNode("direction", "west");
	// Add Location subtree to the Actor Level subtree
	alTree3->addTree(location3);
	// Add Actor Level subtree to the Word root tree
	rootTree->addTree(alTree3);
}

void testXMLParserRules() {
	std::cout << std::endl << "Testing XMLParser(): Rules.xml" << std::endl;

	static const std::string DATA_PATH	= "data/";
	static const std::string FILE_NAME	= "rules.xml";

	bool valid							= true;
	bool nameFound						= false;
	bool nameValid						= false;
	bool aliasesFound					= false;
	std::string name					= "";

	std::map<std::string, int>				directions;
	std::map<int, std::string>				directionIndexes;
	std::map<std::string, std::string>		directionAliases;

	std::vector<std::string>				errors;
	std::vector<std::string>				warnings;
	std::vector<std::string>				messages;

	XMLTree<std::string, std::string>* rootTree = Tools::XMLParser(DATA_PATH, FILE_NAME, messages);

	// Display all XMLParser Messages, if any
	std::cout << std::endl;

	if (!messages.empty()) {
		for (std::string message : messages) {
			std::cout << message << std::endl;
		}

		std::cout << std::endl;
	}

	if (rootTree->isValid()) {
		// Get the root subtrees
		std::vector<XMLTree<std::string, std::string>*> rootSubTrees = rootTree->getTreesInPreOrder();

		for (XMLTree<std::string, std::string>* rootSubTree : rootSubTrees) {
			if (rootSubTree->getNodeKey() == "directions") {

				// Get all the Direction Trees
				std::vector<XMLTree<std::string, std::string>*> directionTrees = rootSubTree->getTreesInPreOrder();

				for (XMLTree<std::string, std::string>* directionTree : directionTrees) {
					// Get the direction nodes. There should be a single <name> node
					std::vector<std::pair<std::string, std::string>> directionNodes = directionTree->getNodesInOrder();

					if (!directionNodes.empty()) {
						nameFound = false;
						nameValid = false;

						for (const std::pair<std::string, std::string> &directionNode : directionNodes) {
							if (directionNode.first == "name") {
								if (!nameFound) {
									name = directionNode.second;
									nameFound = true;

									// Validate direction name
									if (directions.find(name) != directions.end()) {
										nameValid = true;
									}
								}
								else {
									errors.emplace_back("Rules::create(): <directions>: duplicate <name> tag found");
								}
							}
							else {
								errors.emplace_back("Rules::create(): <directions>: unknown tag found: <" + directionNode.first + ">");
							}
						}
					}
					else {
						errors.emplace_back("Rules::create(): <directions>: no tags found");
					}

					// Get the aliases subtree. There should be a single <aliases> subtree
					std::vector<XMLTree<std::string, std::string>*> aliasesSubTrees = directionTree->getTreesInPreOrder();

					if (!aliasesSubTrees.empty()) {
						aliasesFound = false;

						for (XMLTree<std::string, std::string>* aliasesSubTree : aliasesSubTrees) {
							if (aliasesSubTree->getNodeKey() == "aliases") {
								if (!aliasesFound) {

									// Get the aliases nodes
									std::vector<std::pair<std::string, std::string>> aliasesNodes = aliasesSubTree->getNodesInOrder();

									if (!aliasesNodes.empty()) {
										aliasesFound = true;

										for (std::pair<std::string, std::string> aliasNode : aliasesNodes) {
											if (!directionAliases.emplace(std::make_pair(aliasNode.second, name)).second) {
												errors.push_back("Rules::create(): <directions>: duplicate <alias> tag found: " + aliasNode.second);
											}
										}
									}
									else {
										errors.emplace_back("Rules::create(): <directions> <aliases>: no tags found");
									}
								}
								else {
									errors.emplace_back("Rules::create(): <directions>: duplicate <aliases> tag found");
								}
							}
							else {
								errors.emplace_back("Rules::create(): <directions>: unknown tag found: <" + aliasesSubTree->getNodeKey() + ">");
							}
						}
					}
					else {
						errors.emplace_back("Rules::create(): <directions>: no <aliases> tag found");
					}
				}
			}
			else if (rootSubTree->getNodeKey() == "relational-directions") {

			}
		}
	}
	else if (rootTree->isEmpty()) {
		errors.emplace_back("Rules::create(): Rules file is empty or was not found: Data Path: " + DATA_PATH + " File Name: " + FILE_NAME);
	}
	else {
		errors.emplace_back("Rules::create(): Error(s) found parsing the " + FILE_NAME + " file. Correct and rerun.");
	}
	
	if (!errors.empty()) {
		messages.insert(messages.begin(), errors.begin(), errors.end());
		valid = false;
	}

	if (!warnings.empty()) {
		messages.insert(messages.end(), warnings.begin(), warnings.end());
	}	
}

void testXMLParserYugioh() {
	std::cout << std::endl << "Testing XMLParser(): Yugi Starter Deck" << std::endl;

	static const std::string DATA_PATH = "data/";
	static const std::string FILE_NAME = "yugistarterdeck.xml";
	
	bool valid = true;
	
	std::map<std::string, int>				directions;
	std::map<int, std::string>				directionIndexes;
	std::map<std::string, std::string>		directionAliases;

	std::vector<std::string>				errors;
	std::vector<std::string>				warnings;
	std::vector<std::string>				messages;

	XMLTree<std::string, std::string>* rootTree = Tools::XMLParser(DATA_PATH, FILE_NAME, messages);

	// Display all XMLParser Messages, if any
	std::cout << std::endl;

	if (!messages.empty()) {
		for (const std::string &message : messages) {
			std::cout << message << std::endl;
		}

		std::cout << std::endl;
	}

	if (rootTree->isValid()) {
		// Get the root nodes
		std::vector<std::pair<std::string, std::string>> rootNodes = rootTree->getNodesInOrder();

		if (!rootNodes.empty()) {
			for (const std::pair<std::string, std::string> &rootNode : rootNodes) {
				if (rootNode.first == "name") {

				}
				else if (rootNode.first == "type") {

				}
				else {
					errors.emplace_back("Yugioh::create(): <card-deck>: unknown tag found: <" + rootNode.first + ">");
				}
			}
		}
		else {
			errors.emplace_back("Yugioh::create(): <card-deck>: no name or type tags found");
		}

		// Get the root subtrees
		std::vector<XMLTree<std::string, std::string>*> rootSubTrees = rootTree->getTreesInPreOrder();

		for (XMLTree<std::string, std::string>* rootSubTree : rootSubTrees) {
			if (rootSubTree->getNodeKey() == "card") {
				// Get all the Card Trees
				std::vector<XMLTree<std::string, std::string>*> cardTrees = rootSubTree->getTreesInPreOrder();

				for (XMLTree<std::string, std::string>* cardTree : cardTrees) {
					// Get the Card nodes
					std::vector<std::pair<std::string, std::string>> cardNodes = cardTree->getNodesInOrder();

					if (!cardNodes.empty()) {
						for (const std::pair<std::string, std::string> &cardNode : cardNodes) {
							if (cardNode.first == "number") {
									
							}
							else if (cardNode.first == "name") {

							}
							else if (cardNode.first == "text") {

							}
							else if (cardNode.first == "class") {

							}
							else if (cardNode.first == "type") {

							}
							else if (cardNode.first == "monster-type") {

							}
							else if (cardNode.first == "spell-icon") {

							}
							else if (cardNode.first == "trap-icon") {

							}
							else if (cardNode.first == "attribute") {

							}
							else if (cardNode.first == "level") {

							}
							else if (cardNode.first == "atk") {

							}
							else if (cardNode.first == "def") {

							}
							else {
								errors.emplace_back("Yugioh::create(): <card>: unknown tag found: <" + cardNode.first + ">");
							}
						}
					}
					else {
						errors.emplace_back("Yugioh::create(): <card>: no tags found");
					}
				}
			}
		}

		// Validate we found 40-60 Cards
		if (rootSubTrees.size() < 40 || rootSubTrees.size() > 60) {
			errors.emplace_back("Yugioh::create(): Card Deck must have at least 40 and at most 60 Cards. Found " + std::to_string(rootSubTrees.size()));
		}
	}
	else if (rootTree->isEmpty()) {
		errors.emplace_back("Yugioh::create(): Yugioh file is empty or was not found: Data Path: " + DATA_PATH + " File Name: " + FILE_NAME);
	}
	else {
		errors.emplace_back("Yugioh::create(): Error(s) found parsing the " + FILE_NAME + " file. Correct and rerun.");
	}

	if (!errors.empty()) {
		messages.insert(messages.begin(), errors.begin(), errors.end());
		valid = false;
	}

	if (!warnings.empty()) {
		messages.insert(messages.end(), warnings.begin(), warnings.end());
	}
}

void testDateToString() {
	std::cout << std::endl << "Testing dateToString():" << std::endl;
	std::cout << "Today's date is " << Tools::dateToString() << std::endl;
	time_t dateTime = 0;
	std::cout << "Date since epoch began is " << Tools::dateToString(dateTime) << std::endl;
}

void testReplaceAll() {
	std::string base = "this is a test string.";
	std::string str = base;
	std::string str3 = "sample phrase";

	std::cout << std::endl << str << std::endl;
	std::cout << std::endl << str3 << std::endl;
	str.replace(str.begin(), str.end() - 3, str3);
	std::cout << std::endl << str << std::endl << std::endl;
	
	str = base;

	std::cout << std::endl << str << std::endl;
	std::cout << std::endl << str3 << std::endl;
	str.replace(0, str.length() - 3, str3);
	std::cout << std::endl << str << std::endl << std::endl;


	/*
	std::string text = "abcdefg";
	std::cout << "Remove all vowels from " << text << ": " << Tools::removeAll(text, "ae", "") << std::endl;
	std::cout << "Replace d's and g's with m's: " << Tools::removeAll(text, "dg", "m") << std::endl;
	*/
}

void runAllTests() {
	std::cout << std::endl << "Running all tests:" << std::endl;
	testTree();
	testXMLParserRules();
	testXMLParserYugioh();
	testDateToString();
	testReplaceAll();
}
