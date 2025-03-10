#include "tools.h"

void Tools::clearScreen(std::string message) {
	std::string text = "";

	if (message.length() > 0) {
		message = message + ". ";
	}

	message = message + "Press Enter to erase the screen...";

	std::cout << std::endl << message;
	std::getline(std::cin, text);

	#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
	system("cls");
	#elif defined(__linux) || defined(linux) || defined(__APPLE__)
	system("clear");
	#elif
	// Generic way to "clear" the console window buffer
	std::cout << std::string(CONSOLE_BUFFER_HEIGHT, '\n');
	#endif
}

void Tools::setFullScreen() {
	#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
	// Get the Windows console handle
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	// Resize the Console window buffer FIRST
	const COORD coordinates = { BUFFER_WIDTH, BUFFER_HEIGHT };
	SetConsoleScreenBufferSize(consoleHandle, coordinates);

	// Get the window console handle
	HWND consoleWindow = GetForegroundWindow();
	// Maximize Console Window LAST
	// The Windows Management Instrumentation Command-line (WMIC) enables
	// the Windows Console to display full screen
	system("wmic exit");
	ShowWindow(consoleWindow, SW_MAXIMIZE);
	#elif defined(__linux) || defined(linux) || defined(__APPLE__)

	#endif
}

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
void Tools::setColor(COLORS background, COLORS foreground) {
	// Get the Windows console handle
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	// Set console colors
	SetConsoleTextAttribute(consoleHandle, static_cast<int>(foreground) + static_cast<int>(background) * 16);
}
#elif defined(__linux) || defined(linux) || defined(__APPLE__)
void Tools::setColor(COLORS foreground) {
	std::string color = "";

	switch (foreground) {
		case static_cast<int>(COLORS::RESET) : {
			color = RESET;
			break;
		}
		case static_cast<int>(COLORS::BLACK) : {
			color = BLACK;
			break;
		}
		case static_cast<int>(COLORS::RED) : {
			color = RED;
			break;
		}
		case static_cast<int>(COLORS::GREEN) : {
			color = GREEN;
			break;
		}
		case static_cast<int>(COLORS::YELLOW) : {
			color = YELLOW;
			break;
		}
		case static_cast<int>(COLORS::BLUE) : {
			color = BLUE;
			break;
		}
		case static_cast<int>(COLORS::MAGENTA) : {
			color = MAGENTA;
			break;
		}
		case static_cast<int>(COLORS::CYAN) : {
			color = CYAN;
			break;
		}
		case static_cast<int>(COLORS::WHITE) : {
			color = WHITE;
			break;
		}
		case static_cast<int>(COLORS::BOLDBLACK) : {
			color = BOLDBLACK;
			break;
		}
		case static_cast<int>(COLORS::BOLDRED) : {
			color = BOLDRED;
			break;
		}
		case static_cast<int>(COLORS::BOLDGREEN) : {
			color = BOLDGREEN;
			break;
		}
		case static_cast<int>(COLORS::BOLDYELLOW) : {
			color = BOLDYELLOW;
			break;
		}
		case static_cast<int>(COLORS::BOLDBLUE) : {
			color = BOLDBLUE;
			break;
		}
		case static_cast<int>(COLORS::BOLDMAGENTA) : {
			color = BOLDMAGENTA;
			break;
		}
		case static_cast<int>(COLORS::BOLDCYAN) : {
			color = BOLDCYAN;
			break;
		}
		case static_cast<int>(COLORS::BOLDWHITE) : {
			color = BOLDWHITE;
			break;
		}
	}

	std::cout << color;
}
#endif

void Tools::rainbow(std::string message) {
	if (message.length() > 0) {
		#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
		// Loop through the bold colors
		int color = static_cast<int>(COLORS::BLUE_BOLD);

		for (char character : message) {
			switch (color) {
				case static_cast<int>(COLORS::BLUE_BOLD) : {
					Tools::setColor(COLORS::BLACK, COLORS::BLUE_BOLD);
					break;
				}
				case static_cast<int>(COLORS::GREEN_BOLD) : {
					Tools::setColor(COLORS::BLACK, COLORS::GREEN_BOLD);
					break;
				}
				case static_cast<int>(COLORS::CYAN_BOLD) : {
					Tools::setColor(COLORS::BLACK, COLORS::CYAN_BOLD);
					break;
				}
				case static_cast<int>(COLORS::RED_BOLD) : {
					Tools::setColor(COLORS::BLACK, COLORS::RED_BOLD);
					break;
				}
				case static_cast<int>(COLORS::PURPLE_BOLD) : {
					Tools::setColor(COLORS::BLACK, COLORS::PURPLE_BOLD);
					break;
				}
				case static_cast<int>(COLORS::YELLOW_BOLD) : {
					Tools::setColor(COLORS::BLACK, COLORS::YELLOW_BOLD);
					break;
				}
				case static_cast<int>(COLORS::WHITE_BOLD) : {
					Tools::setColor(COLORS::BLACK, COLORS::WHITE_BOLD);
					break;
				}
			}

			if (color < static_cast<int>(COLORS::WHITE_BOLD)) {
				color++;
			}
			else {
				color = static_cast<int>(COLORS::BLUE_BOLD);
			}

			std::cout << message.at(character);
		}
		#elif defined(__linux) || defined(linux) || defined(__APPLE__)
		// Loop through the bold colors
		int color = static_cast<int>(COLORS::BOLDRED);

		for (int character = 0; character < message.length(); character++) {
			switch (color) {
				case static_cast<int>(COLORS::BOLDRED) : {
					Tools::setColor(BOLDRED);
					break;
				}
				case static_cast<int>(COLORS::BOLDGREEN) : {
					Tools::setColor(BOLDGREEN);
					break;
				}
				case static_cast<int>(COLORS::BOLDYELLOW) : {
					Tools::setColor(BOLDYELLOW);
					break;
				}
				case static_cast<int>(COLORS::BOLDBLUE) : {
					Tools::setColor(BOLDBLUE);
					break;
				}
				case static_cast<int>(COLORS::BOLDMAGENTA) : {
					Tools::setColor(BOLDMAGENTA);
					break;
				}
				case static_cast<int>(COLORS::BOLDCYAN) : {
					Tools::setColor(BOLDCYAN);
					break;
				}
			}

			if (color < static_cast<int>(COLORS::BOLDWHITE)) {
				color++;
			}
			else {
				color = static_cast<int>(COLORS::BOLDRED);
			}

			std::cout << message.at(character);
		}
		#endif
	}
}

std::string Tools::toUpper(std::string text) {
	std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	return text;
}

std::string Tools::toLower(std::string text) {
	std::transform(text.begin(), text.end(), text.begin(), ::tolower);
	return text;
}

std::vector<std::string> Tools::wordSplit(std::string text) {
	std::vector<std::string> words;

	// Trim trailing and leading white characters
	text = trim(text);

	// Convert text to lower case
	text = toLower(text);

	// Avoid Gotcha #1: if text is empty, incorrectly counts 1 word
	if (text.length() > 0) {
		int count = 0;

		// Avoid Gotcha #2: multiple delims in a row cause a word miscount
		int wordLength = 0;

		// Declare the loop counter variable outside the for loop
		// to be able to use it after the for loop
		int index = 0;

		for (index; index < text.length(); index++) {
			// Check the next text character is not a lower-case letter.
			// Do not lookup as delimiters the lower-case letters.
			if (text[index] < 97 || text[index] > 122) {
				// Look for a word delim (e.g., "go north")
				for (int delim = 0; delim < WORD_DELIMS_LENGTH; delim++) {
					if (text[index] == WORD_DELIMS[delim]) {
						// Check we have found a word prior to finding the delim
						if (wordLength > 0) {
							words.push_back(text.substr(index - wordLength, wordLength));
							count++;
							wordLength = 0;
						}

						break;
					}
				}
			}
			else {
				wordLength++;
			}
		}

		// Gotcha #3: "Dangling word problem". Check for a last word not yet copied
		if (wordLength > 0) {
			words.push_back(text.substr(index - wordLength, wordLength));
		}
	}

	return words;
}

std::vector<std::string> Tools::wordSplit(std::string text, CASE letterCase) {
	std::vector<std::string> words;

	// Trim trailing and leading white characters
	text = trim(text);

	// Convert text to the requested case, or keep orginal case
	if (letterCase == CASE::LOWERCASE) {
		text = toLower(text);
	}
	else if (letterCase == CASE::UPPERCASE) {
		text = toUpper(text);
	}

	// Avoid Gotcha #1: if text is empty, incorrectly counts 1 word
	if (text.length() > 0) {
		int count = 0;

		// Avoid Gotcha #2: multiple delims in a row cause a word miscount
		int wordLength = 0;

		// Declare the loop counter variable outside the for loop
		// to be able to use it after the for loop
		int index = 0;

		for (index; index < text.length(); index++) {
			// Check the next text character is not a upper-case or lower-case letter.
			// Do not lookup as delimiters the upper-case and the lower-case letters.
			if (!(text[index] >= 65 && text[index] <= 90) && !(text[index] >= 97 && text[index] <= 122)) {
				// Look for a word delim (e.g., "go north")
				for (int delim = 0; delim < WORD_DELIMS_LENGTH; delim++) {
					if (text[index] == WORD_DELIMS[delim]) {
						// Check we have found a word prior to finding the delim
						if (wordLength > 0) {
							words.push_back(text.substr(index - wordLength, wordLength));
							count++;
							wordLength = 0;
						}

						break;
					}
				}
			}
			else {
				wordLength++;
			}
		}

		// Gotcha #3: "Dangling word problem". Check for a last word not yet copied
		if (wordLength > 0) {
			words.push_back(text.substr(index - wordLength, wordLength));
		}
	}

	return words;
}

// Tools tokenSplit() cannot currently handle parenthesis
// "a = (b + c) - 5"
std::vector<std::string> Tools::tokenSplit(std::string text) {
	std::vector<std::string> tokens;

	// Trim trailing and leading white characters
	text = trim(text);

	// Convert text to lower case
	text = toLower(text);

	// Avoid Gotcha #1: if text is empty, incorrectly counts 1 token
	if (text.length() > 0) {
		int count = 0;

		// Avoid Gotcha #2: multiple delims in a row cause a token miscount
		int tokenLength = 0;

		// Declare the loop counter variable outside the for loop
		// to be able to use it after the for loop
		int index = 0;

		for (index; index < text.length(); index++) {
			// Check the next text character is not a lower-case letter or a digit.
			// Do not lookup as delimiters the lower-case letters and digits.
			bool matched = false;

			if ((text[index] < 97 || text[index] > 122) && (text[index] < 48 || text[index] > 57)) {
				// Look for a token delim (e.g., "a + b")
				for (int delim = 0; delim < TOKEN_DELIMS_LENGTH; delim++) {
					if (text[index] == TOKEN_DELIMS[delim]) {
						// Check we have found a token prior to finding the delim
						if (tokenLength > 0) {
							tokens.push_back(text.substr(index - tokenLength, tokenLength));
							count++;
							tokenLength = 0;
						}

						matched = true;
						break;
					}
				}

				// Gotcha #3: avoid discarding a character that is not a letter, digit or delim
				if (!matched) {
					tokenLength++;
				}
			}
			else {
				tokenLength++;
			}
		}

		// Gotcha #4: "Dangling token problem". Check for a last token not yet copied
		if (tokenLength > 0) {
			tokens.push_back(text.substr(index - tokenLength, tokenLength));
		}
	}

	return tokens;
}

std::string Tools::trim(std::string text) {
	// Check for an empty string
	if (text.length() > 0) {
		// Trim leading whitespace characters
		const int startPos = text.find_first_not_of(" \t\n");

		if (startPos > 0) {
			text = text.substr(startPos);
		}

		// Trim trailing whitespace characters
		const int endPos = text.find_last_not_of(" \t\n");

		if (endPos < text.length() - 1) {
			text = text.substr(0, endPos + 1);
		}

		// Check for blank string
		if (startPos < 0 && endPos < 0) {
			text = "";
		}
	}

	return text;
}

std::string Tools::trimDelimiters(std::string text) {
	// Check for an empty string
	if (text.length() > 0) {
		// Remove all delimiters
		for (int index = 0; index < WORD_DELIMS_LENGTH; index++) {
			text.erase(remove(text.begin(), text.end(), WORD_DELIMS[index]), text.end());
		}
	}

	return text;
}

bool Tools::isNumeric(std::string text) {
	// Must specify start and end of string (^ and $)
	// Allow EITHER a positive or negative INTEGER, or (|)
	// a positive or negative DECIMAL (with/without a leading or trailing digit)
	// OK Integer Examples:
	// 1		+1		-1
	// OK Decimal Examples:
	// 1.0		+1.0	-1.0	1.		+1.		-1.		0.1		+0.1	-0.1		
	// OK Unusual Decimal Examples:
	// 0.		+0.		-0.		1.		+1.		-1.
	// OK Unusual Decimal Examples that would be rejected by string to int conversion (stoi)
	// .1		+.1		-.1		.		+.		-.
	// Invalid examples:
	// +		-		+-1		1..2	empty string	alphanumeric string

	return std::regex_match(text, std::regex("^([+-]?[0-9]+)|([+-]?[0-9]*[.][0-9]*)$"));
}

std::string Tools::dateToString() {
	time_t now = std::time(nullptr);
	std::ostringstream osstring;

	#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
	struct tm buffer;
	localtime_s(&buffer, &now);
	osstring << std::put_time(&buffer, "%Y-%m-%d");
	#elif defined(__linux) || defined(linux) || defined(__APPLE__)
	tm* buffer = localtime(&now);
	osstring << std::put_time(buffer, "%Y-%m-%d");
	#endif

	return osstring.str();
}

std::string Tools::dateToString(time_t dateTime) {
	std::ostringstream osstring;

	#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
	struct tm buffer;
	localtime_s(&buffer, &dateTime);
	osstring << std::put_time(&buffer, "%Y-%m-%d");
	#elif defined(__linux) || defined(linux) || defined(__APPLE__)
	tm* buffer = localtime(&dateTime);
	osstring << std::put_time(buffer, "%Y-%m-%d");
	#endif

	return osstring.str();
}

std::string Tools::dateTimeToString() {
	time_t now = std::time(nullptr);
	std::ostringstream osstring;

	#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
	struct tm buffer;
	localtime_s(&buffer, &now);
	osstring << std::put_time(&buffer, "%Y-%m-%d-%T");
	#elif defined(__linux) || defined(linux) || defined(__APPLE__)
	tm* buffer = localtime(&now);
	osstring << std::put_time(buffer, "%Y-%m-%d-%T");
	#endif

	return osstring.str();
}

std::string Tools::removeAll(std::string text, std::string replaceChars) {
	for (char replaceCharacter : replaceChars) {	
		text.erase(std::remove(text.begin(), text.end(), replaceCharacter), text.end());
	}

	return text;
}

std::string Tools::digitToName(std::string text) {
	std::string transformedText;

	for (char character : text) {
		switch (character) {
			case 48: {
				transformedText.append("ZERO");
				break;
			}
			case 49: {
				transformedText.append("ONE");
				break;
			}
			case 50: {
				transformedText.append("TWO");
				break;
			}
			case 51: {
				transformedText.append("THREE");
				break;
			}
			case 52: {
				transformedText.append("FOUR");
				break;
			}
			case 53: {
				transformedText.append("FIVE");
				break;
			}
			case 54: {
				transformedText.append("SIX");
				break;
			}
			case 55: {
				transformedText.append("SEVEN");
				break;
			}
			case 56: {
				transformedText.append("EIGHT");
				break;
			}
			case 57: {
				transformedText.append("NINE");
				break;
			}
			default: {
				transformedText.append(std::string(1, character));
				break;
			}
		}
	}

	return transformedText;
}

#if defined(__linux) || defined(linux) || defined(__APPLE__)
bool Tools::dirExists(std::string filePath) {
	bool exists = false;

	const char* directory = filePath.c_str();

	DIR* dir = opendir(directory);

	if (dir) {
		closedir(dir);
		exists = true;
	}
	else if (ENOENT == errno) {
		// Directory does not exist
	}
	else {
		// opendir() failed for some other reason
	}
	return exists;
}
#endif

bool Tools::fileExists(std::string filePath, std::string fileName) {
	bool exists = false;

	// Tell the OS to find a text/sequential file
	std::ifstream inputFile(filePath + fileName, std::ios::in);

	if (inputFile.is_open()) {
		inputFile.close();
		exists = true;
	}

	return exists;
}

std::vector<std::string> Tools::readFile(std::string filePath, std::string fileName) {
	std::vector<std::string> text;
	std::string line = "";

	// Add the final "/" to the file path if it does not exist
	if (filePath.length() > 0 && filePath.substr(filePath.length() - 1, 1) != "/") {
		filePath = filePath + "/";
	}

	// Tell the OS we wish to read a text/sequential file
	std::ifstream inputFile(filePath + fileName, std::ios::in);

	if (inputFile.is_open()) {
		while (!inputFile.eof()) {
			// Read the next line of text from the file
			std::getline(inputFile, line);

			// Trim the line and save it
			line = trim(line);
			text.push_back(line);
		}

		inputFile.close();
	}

	return text;
}

std::map<std::string, void*> Tools::createDictionary(std::string filePath, std::string fileName) {
	std::map<std::string, void*> dictionary;
	std::string word = "";

	// Add the final "/" to the file path if it does not exist
	if (filePath.length() > 0 && filePath.substr(filePath.length() - 1, 1) != "/") {
		filePath = filePath + "/";
	}

	// Tell the OS we wish to read a text/sequential file
	std::ifstream inputFile(filePath + fileName, std::ios::in);

	if (inputFile.is_open()) {
		while (!inputFile.eof()) {
			// Read the next line of text from the file
			std::getline(inputFile, word);

			// Trim the word and save it
			word = trim(word);

			// Convert word to upper case first
			word = Tools::toUpper(word);

			dictionary.insert(std::make_pair(word, nullptr));
		}

		inputFile.close();
	}

	return dictionary;
}

XMLTree<std::string, std::string>* Tools::XMLParser(std::string filePath, std::string fileName, std::vector<std::string> &messages) {
	// Create a temporary empty root tree. If the XML file is not found we will return this non-null empty root tree.
	XMLTree<std::string, std::string>* rootTree = new XMLTree<std::string, std::string>();

	// The root tree is at level 0
	int currentLevel = 0;

	std::vector<std::string> warnings;
	std::vector<std::string> errors;

	// Add the final "/" to the file path if it does not exist
	if (filePath.length() > 0 && filePath.substr(filePath.length() - 1, 1) != "/") {
		filePath = filePath + "/";
	}

	std::vector<std::string> data;
	bool rootTagFound = false;

	// Check if the XML file exists
	if (fileExists(filePath, fileName)) {
		std::vector<std::string> text = readFile(filePath, fileName);

		// Save data tags, skip non-data tags
		for (auto iterator = text.begin(); iterator != text.end(); ++iterator) {
			// Trim any characters before <
			const int openCharPosition = (*iterator).find_first_of('<');
			const int trimmedLength = (*iterator).length() - openCharPosition;

			if (openCharPosition > 0) {
				(*iterator) = (*iterator).substr(openCharPosition, trimmedLength);
			}

			// Check for blank tags
			if (Tools::trim(*iterator).length() == 0) {
			}
			// Check for the XML doc tag
			else if ((*iterator).substr(0, 5) == "<?xml") {
			}
			// Check for comment tags
			else if ((*iterator).substr(0, 4) == "<!--") {
				// Trim all characters after -->
				const int closeCharPosition = (*iterator).find("-->", 0);

				if (closeCharPosition >= 0 && (*iterator).length() > closeCharPosition + 3) {
					(*iterator) = (*iterator).substr(0, closeCharPosition + 3);
				}

				// Skip all text lines until we find the --> mark
				if ((*iterator).substr((*iterator).length() - 3, 3) == "-->") {
				}
				else {
					// Recurse through the text until we find the --> mark
					iterator = findXMLClose(text, iterator, "-->");
				}
			}
			else {
				data.push_back(*iterator);
			}
		}

		// Process data tags
		for (auto iterator = data.begin(); iterator != data.end(); ++iterator) {
			std::string tagName = "";
			std::string tagText = "";

			// Determine if tag is valid
			std::vector<std::string>::iterator closeTagIterator = iterator;

			if (validateTag(data, iterator, closeTagIterator, tagName, errors, warnings)) {
				// Determine if this tag is a tree
				if (isATree(data, iterator, closeTagIterator, tagName, errors, warnings)) {
					// Check if this is the root tree
					if (!rootTagFound) {
						rootTree->setLevel(currentLevel);
						rootTree->setTreeKey(Tools::toLower(tagName));

						rootTagFound = true;

						addNodes(data, iterator, closeTagIterator, rootTree, currentLevel, errors, warnings);
						currentLevel++;
					}
					else {
						// WE SHOULD NEVER GET HERE
						// This message must be displayed in App's catch() via e.what()
						std::string message = "Error: Tools::XMLParser(): Recursive calls to addNodes() means we should not be here!";
						// The MSVC extension to exception class has a C-style string constructor not available in standard C++
						//throw std::exception(message.c_str());
						throw std::runtime_error(message.c_str());
					}
				}
				else {
					// Check if the root tree has already been found
					if (!rootTagFound) {
						errors.emplace_back("Error: Tools::XMLParser(): missing root tag. First tag must be a tree");
						//*** TEST THIS! ***
						// Stop processing and exit
						break;
					}
				}
			}
		}
	}
	else {
		errors.emplace_back("Error: Tools::XMLParser(): unable to find file " + filePath + fileName);
	}

	if (!errors.empty()) {
		messages.insert(messages.end(), errors.begin(), errors.end());
		rootTree->setErrors(errors.size());
	}
	if (!warnings.empty()) {
		messages.insert(messages.end(), warnings.begin(), warnings.end());
		rootTree->setWarnings(warnings.size());
	}

	return rootTree;
}

std::vector<std::string>::iterator Tools::findXMLClose(std::vector<std::string> &data, std::vector<std::string>::iterator iterator, std::string key) {
	// Search for the close tag on the same line
	if (key.length() <= (*iterator).length() && (*iterator).substr((*iterator).length() - key.length(), key.length()) == key) {
		// Found it, exit
		return iterator;
	}
	else {
		// Search for the close tag on the next line, if any
		return Tools::findXMLCloseRecursive(data, ++iterator, key);
	}
}

bool Tools::validateTag(std::vector<std::string> &data, const std::vector<std::string>::iterator iterator, std::vector<std::string>::iterator &closeTagIterator, std::string &tagName, std::vector<std::string> &errors, std::vector<std::string> &warnings) {
	bool valid = false;

	// Validate this is an open tag, not a close tag
	if ((*iterator).substr(0, 2) != "</") {
		// Validate the open tag
		if ((*iterator).substr(0, 1) == "<") {
			// Find the close > position on the open tag
			std::size_t closePosition		= (*(iterator)).find_first_of('>');
			std::size_t openLastPosition	= (*(iterator)).find_last_of('<');

			if (closePosition != std::string::npos || openLastPosition == 0) {
				// Check if there is a tag name
				if (closePosition >= 2) {
					// Extract the tag name from the open tag
					const std::string name = (*iterator).substr(1, closePosition - 1);

					// Try to find the close tag on the same line as the open tag
					const std::string closeTag			= "</" + name + ">";
					const std::size_t closeTagPosition	= (*(iterator)).find(closeTag);

					if (closeTagPosition == std::string::npos) {
						// See if there is a partial tag at the end of the same line
						std::size_t closeTagOpenPosition	= (*(iterator)).find_last_of('<');
						std::size_t closeTagClosePosition	= (*(iterator)).find_last_of('>');

						// Check we have not found the open tag opening < mark or closing > mark
						if (closeTagOpenPosition == 0 && closeTagClosePosition == closePosition) {
							// Try to find the close tag on other lines
							closeTagIterator = iterator;
							closeTagIterator = findXMLClose(data, closeTagIterator, closeTag);

							// Check if we found the close tag
							if (closeTagIterator != data.end()) {
								// Check (after the fact) if we really found the close tag.
								// If the close tag is missing we may have picked up the next tag.
								tagName = name;

								if ((*closeTagIterator) == closeTag) {
									valid = true;
								}
								else {
									// Missing close tag
									errors.push_back("Error: Tools::XMLParser(): missing close tag " + *(iterator));
								}
							}
							else {
								// Missing close tag
								errors.push_back("Error: Tools::XMLParser(): missing close tag " + *(iterator));
							}
						}
						else {
							// Missing close tag. Will come here if open tag-close tag on same line and close tag is invalid,
							// such as missing the '/', '<' or '>' marks
							errors.push_back("Error: Tools::XMLParser(): missing close tag " + *(iterator));
						}
					}
					else {
						tagName = name;
						valid	= true;
					}
				}
				else {
					// Missing tag name
					errors.push_back("Error: Tools::XMLParser(): missing tag name on open tag " + (*iterator));
				}
			}
			else {
				// Missing close > on open tag
				errors.push_back("Error: Tools::XMLParser(): missing close > char on open tag " + (*iterator));
			}
		}
		else {
			// Missing open < on open tag
			errors.push_back("Error: Tools::XMLParser(): missing open < char on open tag " + (*iterator));
		}
	}
	else {
		errors.push_back("Error: Tools::XMLParser(): missing open tag for " + (*iterator));
	}

	return valid;
}

std::vector<std::string>::iterator Tools::findXMLCloseRecursive(std::vector<std::string> &data, std::vector<std::string>::iterator iterator, std::string &key) {
	if (iterator == data.end()) {
		return iterator;
	}

	// Search for the close tag on the same line
	if (key.length() <= (*iterator).length() && (*iterator).substr((*iterator).length() - key.length(), key.length()) == key) {
		// Found it, exit
		return iterator;
	}
	else {
		// Search for the close tag on the next line, if any
		return Tools::findXMLCloseRecursive(data, ++iterator, key);
	}
}

void Tools::addNodes(std::vector<std::string> &data, std::vector<std::string>::iterator& iterator, std::vector<std::string>::iterator &closeTagIterator, XMLTree<std::string, std::string>* tree, int currentLevel, std::vector<std::string> &errors, std::vector<std::string> &warnings) {
	// TEST PAST END OF TEXT
	if (iterator + 1 < data.end()) {
		// Increment the current level only once for all the subtrees found at this level.
		// They are subtrees of the root tree.

		// Process node tags
		for (++iterator; iterator < closeTagIterator; ++iterator) {
			std::string tagName = "";
			std::string tagText = "";

			// Determine if tag is valid
			std::vector<std::string>::iterator closeIterator = iterator;

			if (validateTag(data, iterator, closeIterator, tagName, errors, warnings)) {
				// Determine if this tag is a tree
				if (isATree(data, iterator, closeIterator, tagName, errors, warnings)) {
					// Recurse adding the nodes of this subtree
					XMLTree<std::string, std::string>* subtree = new XMLTree<std::string, std::string>(tree->getLevel() + 1, Tools::toLower(tagName));

					addNodesRecursive(data, iterator, closeIterator, subtree, tree->getLevel() + 1, errors, warnings);
					tree->addTree(subtree);
				}
				else {
					// Extract the tag's text beginning on the open tag line
					// after the close >. Then loop through the remaining lines
					// between the close tag line and closePosition, inclusive.
					// Note that the close tag may be on the same last line of text.

					// Check if open and close tags are on the same line
					if (iterator == closeIterator) {
						// Check if there text on this line
						if ((*iterator).length() > tagName.length() + 2 + tagName.length() + 3) {
							tagText = (*iterator).substr(tagName.length() + 2, (*iterator).length() - (tagName.length() + 2) - (tagName.length() + 3));
						}
					}
					else {
						// Check if there is text on the open tag line
						if ((*iterator).length() > tagName.length() + 2) {
							tagText = (*iterator).substr(tagName.length() + 2, (*iterator).length() - (tagName.length() + 2));
						}

						// Extract any text between the open and close tag lines
						for (++iterator; iterator < closeIterator; ++iterator) {
							tagText += (*iterator) + " ";
						}

						// Check if there is text on the close tag line
						if ((*closeIterator).length() > tagName.length() + 3) {
							tagText += (*closeIterator).substr(0, (*closeIterator).length() - (tagName.length() + 3));
						}
					}

					// Validate the tag text
					if (tagText.length() == 0) {
						warnings.push_back("Warning: Tools::XMLParser(): tag <" + tagName + "> has no text");
					}

					tree->addNode(Tools::toLower(tagName), tagText);
				}
			}
		}
	}
	else {
		errors.push_back("Error: Tools::XMLParser(): empty tree: " + (*iterator));
	}
}

bool Tools::isATree(std::vector<std::string> &data, const std::vector<std::string>::iterator iterator, const std::vector<std::string>::iterator closeTagIterator, std::string &tagName, std::vector<std::string> &errors, std::vector<std::string> &warnings) {
	bool isATree = true;

	// A tree has only a key (the tag name), never a value (text) between its open-tag-close-> and close-tag-open-<
	// First check if the open and close tags are on the same text line
	if (iterator == closeTagIterator) {
		// Check if there is any text between the open tag > and the close tag <
		if ((*iterator).length() > tagName.length() + 2 + tagName.length() + 3) {
			// Check the text to see if it is a tag
			for (int index = tagName.length() + 2; index < (*iterator).length(); index++) {
				if ((*iterator).substr(index, 1) == "<") {
					// It is a tree. Issue a warning and treat the tag as as a node tag.
					// Node(s) on the same line as the tree's open and close tags are not allowed
					errors.push_back("Error: Tools::XMLParser(): found tree with embeded node(s): \n" + (*iterator) + "\nTrees with node(s) on the same line as treated as nodes.");
					break;
				}
				else {
					// It is not a tree
					isATree = false;
					break;
				}
			}
		}
		else {
			// It is not a tree
			isATree = false;
		}
	}
	else {
		// Check if there is text on the open tag line
		if ((*iterator).length() > tagName.length() + 2) {
			isATree = false;
		}

		// Check if there is a tag between the open and close tag lines
		std::vector<std::string>::iterator searchIterator = iterator;
		for (++searchIterator; searchIterator < closeTagIterator; ++searchIterator) {
			if ((*searchIterator).substr(0, 1) == "<") {
				// It is a tree
				break;
			}
			else {
				isATree = false;
				break;
			}
		}

		// Check if there is text on the close tag line
		if ((*closeTagIterator).length() > tagName.length() + 3) {
			isATree = false;
		}
	}

	return isATree;
}

void Tools::addNodesRecursive(std::vector<std::string> &data, std::vector<std::string>::iterator& iterator, const std::vector<std::string>::iterator closeTagIterator, XMLTree<std::string, std::string>* tree, int currentLevel, std::vector<std::string> &errors, std::vector<std::string> &warnings) {
	// TEST PAST END OF TEXT
	if (iterator + 1 < data.end()) {
		// Process node tags
		for (iterator = iterator + 1; iterator < closeTagIterator; ++iterator) {
			std::string tagName = "";
			std::string tagText = "";

			// Determine if tag is valid
			std::vector<std::string>::iterator closeIterator = iterator;

			if (validateTag(data, iterator, closeIterator, tagName, errors, warnings)) {
				// Determine if this tag is a tree
				if (isATree(data, iterator, closeIterator, tagName, errors, warnings)) {
					// Recurse adding the nodes of this subtree
					XMLTree<std::string, std::string>* subtree = new XMLTree<std::string, std::string>(tree->getLevel() + 1, Tools::toLower(tagName));

					addNodesRecursive(data, iterator, closeIterator, subtree, tree->getLevel() + 1, errors, warnings);
					tree->addTree(subtree);
				}
				else {
					// Extract the tag's text beginning on the open tag line
					// after the close >. Then loop through the remaining lines
					// between the close tag line and closePosition, inclusive.
					// Note that the close tag may be on the same last line of text.

					// Check if open and close tags are on the same line
					if (iterator == closeIterator) {
						// Check if there text on this line
						if ((*iterator).length() > tagName.length() + 2 + tagName.length() + 3) {
							tagText = (*iterator).substr(tagName.length() + 2, (*iterator).length() - (tagName.length() + 2) - (tagName.length() + 3));
						}
					}
					else {
						// Check if there is text on the open tag line
						if ((*iterator).length() > tagName.length() + 2) {
							tagText = (*iterator).substr(tagName.length() + 2, (*iterator).length() - (tagName.length() + 2));
						}

						// Extract any text between the open and close tag lines
						for (++iterator; iterator < closeIterator; ++iterator) {
							tagText += (*iterator) + " ";
						}

						// Check if there is text on the close tag line
						if ((*closeIterator).length() > tagName.length() + 3) {
							tagText += (*closeIterator).substr(0, (*closeIterator).length() - (tagName.length() + 3));
						}
					}

					// Validate the tag text
					if (tagText.length() == 0) {
						warnings.push_back("Warning: Tools::XMLParser(): tag <" + tagName + "> has no text");
					}

					tree->addNode(Tools::toLower(tagName), tagText);
				}
			}
		}
	}
	else {
		errors.push_back("Error: Tools::XMLParser(): empty tree: " + (*iterator));
	}
}

#if defined(BOOST)
std::vector<std::string> Tools::readDirectory(std::string filePath, std::string directoryName, CONTENTS contents) {
	std::vector<std::string> files;

	boost::filesystem::path path(filePath + "/" + directoryName);

	std::vector<boost::filesystem::directory_entry> entries;

	if (boost::filesystem::is_directory(path)) {
		copy(boost::filesystem::directory_iterator(path), boost::filesystem::directory_iterator(), back_inserter(entries));

		for (std::vector<boost::filesystem::directory_entry>::const_iterator it = entries.begin(); it != entries.end(); ++it) {
			// Check if this is a directory name
			std::string name = "";
			std::vector<std::string> names = Tools::tokenSplit((*it).path().string());

			if (boost::filesystem::is_directory(*it) && names.size() >= 1) {
				if (contents == CONTENTS::ALL || contents == CONTENTS::DIRECTORIES) {
					name = names[names.size() - 1];
				}
			}
			else if (boost::filesystem::is_regular_file(*it) && names.size() >= 2) {
				if (contents == CONTENTS::ALL || contents == CONTENTS::FILES) {
					name = names[names.size() - 2] + "." + names[names.size() - 1];
				}
			}
			// It's neither a directory nor a file (?).
			// Return it if ALL contents requested, otherwise ignore it.
			else if (contents == CONTENTS::ALL) {
				name = (*it).path().string();
			}

			if (name.length() > 0) {
				files.push_back(name);
			}
		}
	}

	return files;
}
#endif