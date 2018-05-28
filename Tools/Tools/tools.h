#pragma once

/*
	Current Version		2.3.9

	Known Bugs

	Function				Description
	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------


	Known Restrictions

	Function				Description
	--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	tokenSplit()			Cannot currently handle parenthesis (e.g., "a = (b + c) - 5")
	setColor				For Linux: cannot set background color
	dirExists()				For Linux only for now
	readDirectory()			Requires Boost, disabled for now
	isATree()				The node(s) of a tree cannot appear on the same line as the tree's open and close tags.


	Change History (Version.Release.Update)
	
	Version		Date		Class, Function							Description
	V.R.U		yyyy/mm/dd
	-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	2.3.9		2018/5/8	Tools									Added "Error" and "Warning" prefixes to all messages.
	2.3.8		2018/7/5	XMLTree<T1,T2>							Added isValid() and hasErrors().
	2.3.7		2018/4/21	Tools::validateTag()					Now correctly identifies missing or invalid close tag when open tag and close tag are on the same line.
	2.3.6		2018/4/19	Tools::findXMLCloseRecursive()			Renamed findXMLCloseRecursive().
	2.3.5		2018/4/12	XMLTree<T1,T2>, XMLNode<T1,T2>			Now declaring and implementing only in header files. Implementating templated classes in source files (.cpp) 
																	causes linker errors while building executables (.exe), requiring the #included of those source files.
	2.3.4		2018/4/10	XMLTree<T1,T2>							Modified addNode() and addNodeRecursive() to alphabetize based on key first, value second.
	2.3.3		2018/4/9	XMLTree<T1,T2>							Renamed getTrees() to getTreesInPreOrder().
							XMLTree<T1,T2>							Renamed getNodes() to getNodesInOrder() and getNodesRecursive() to getNodesInOrderRecursive().
							XMLTree<T1,T2>							Added getNodesInPreOrder() and getNodesInPreOrderRecursive().
	2.3.2		2018/4/8	Tools::XMLParser()						Now storing root Tree key in Tree object key instead of Node object key. Call getTreeKey(), not getNodeKey().
	2.3.1		2018/4/4	Tree, SubTree, Node						Removed these classes.
	2.3.0		2018/4/2	XMLTree<T1,T2>, XMLNode<T1,T2>			Added new classes, replacing Tree, SubTree and Node classes.
	2.2.2		2018/3/26	Various									Changed various function parameters and local variables to const.
							Tree<T1, T2>::isEmpty()					Added function.
	2.2.1		2018/3/25	Tree<T1, T2>::addNode()					Incorrectly passing prevTree instead of nextTree to addTreeRecursive().
	2.2.0		2018/3/21	Tree<T1, T2>							Implemented pre-order, in-order and post-order traverals.
							SubTree<T1, T2>							Added node id to Tree, SubTree and Node classes via static class variable and function in Tree class.
							Node<T1, T2>							
							Tools::XMLParserOld()					Now linking first in series of same subtrees as a subtree, all others as previous Trees.
							Tools::XMLParserOld()					Now inserting message into messages vector when the file is not found (was going to cout).
	2.1.11		2018/1/17	PUNCTUATION								Added to constants.h
	2.1.10		2018/1/16	removeAll()								Renamed function removeAll().
	2.1.9		2018/1/13	digitToName()							Added function.
	2.1.8		2018/1/9	XMLParserOld()								Updated code per JetBrains ReSharper recommendations.
							addNodesRecursiveOld()
							rainbow()
							Tree<T1, T2>::addTree()
							Tree<T1, T2>::addTreeRecursive()
	2.1.7		2018/1/2	createDictionary()						Added function.
							readFile()								Added call to close().
	2.1.6		2018/1/1	readFile()								Added check for file path ending in '/', now add '/' if missing.
	2.1.5		2017/12/26	removeAll()								Added function.
	2.1.4		2017/12/9	Tree::inOrderTreeTraversal()				Privatized, getTreesInOrder() is now the only in-order traversal public interface.
							SubTree::inOrderSubtreeTraversal()		Privatized, getSubtreesInOrder() is now the only in-order traversal public interface.
							SubTree::inOrderSubtreeTraversal(int)	Privatized, getSubTreesInOrder(int) is now the only in-order traversal public interface.
							SubTree::inOrderNodeTraversal()			Privatized, getNodesInOrder() is now the only in-order traversal public interface.
							Tree::inOrderTraversalRecursive()		Do not include the root tree, only its subtrees.
	2.1.3		2017/12/3	XMLParserOld()								Translate tag name to lower case before adding it to the Tree and Subtree.
							addNodesOld()								Translate tag name to lower case before adding it to the Subtree and Node.
							addNodesRecursiveOld()						Translate tag name to lower case before adding it to the Subtree and Node.
	2.1.2		2017/11/29	validateTag()							Corrected "Error, missing close tag" message.
																	Added ""Error, missing open tag", found close tag instead of expected open tag.
	2.1.1		2017/11/16											Various bug fixes:
							XMLParserOld()								Missing root tag. Typing leading periods ahead of an open tag causes the error.
							isATree()								Warning: card without text.
							XMLParserOld()								If a comment ends in double-> crashes the tools app, vector iterator cannot be incremented.
																	Now stripping all characters following -->
	2.1.0		2017/11/15	isNumeric()								Removed Boost from several functions, converted to C++ 11+
							fileExists()
	2.0.0		2017/10/29	XMLParserOld()								Renamed readXMLFile().
							setColor()								Modified Linux version to match Windows version.
	2.0.0		2017/10/28	readXMLFile()							Added new version of XML parser that does not use Boost.
							findXMLClose()
							validateTag()
							addNodesOld()
							isATree()
							findClose()
							addSubNodes()
							Tree class()
	1.0.15		2017/09/17	readFile()								Now saving trimmed blank lines.
	1.0.14		2017/09/04	trim()									Check for blank string, return empty string.
	1.0.13		2017/08/20											Added additional checks to #defines for Windows, Linux.
							setColor()								Added Linux overload with #defines for colors.
	1.0.12		2017/08/07	dateToString()							Added function to convert today's date to string.
							dateToString()							Added function to convert some date to string.
							dirExists()								Added function.
							fileExists()							Changed code to use Boost::filesystem
																	Removed using namespace std; Added std:: throughout.
	1.0.11		2017/07/24	readXMLFile()							Added support for partial third level (root + 2 levels).
																	Third level tag lost; its tags are grouped with level 2's.
																	Original ReadXMLFile() renamed readXMLFile_1_0_8().
	1.0.10		2017/03/24	trimDelimiters()						Added function.
	1.0.9		2017/03/11	wordSplit()								Added overload with lower-case/upper-case/unchanged-case enum
	1.0.8		2017/03/06	readXMLFile()							Check for "/" at end of file path, add it if not found
	1.0.7		2017/03/05	readXMLFile()							Separated error catching into two try/catches to better track specific errors
	1.0.6		2017/03/05	wordSplit()								Added forward-slash '/' to WORD_DELIMS
	1.0.5		2017/03/04	isNumeric()								Replaced code with Boost::Regex for negative/positive integers and floating-point numbers
	1.0.4		2017/03/03	isNumeric()								Added check for negative integers and negative floating-point numbers
	1.0.3		2017/03/03	clearScreen()							Added (inadvertedly dropped)
	1.0.2		2017/03/02	readXMLFile()							Added ptree_error exception catch
	1.0.1		2017/03/02	wordSplit()								Added back-slash '\\' to WORD_DELIMS
	1.0.1		2017/03/02	tokenSplit()							Removed underscore from TOKEN_DELIMS (may be used in file names)
	1.0.1		2017/03/02	tokenSplit()							Added  back-slash '\\' to TOKEN_DELIMS for readDirectory()
	1.0.1		2017/03/02	readDirectory()							Return directory and file names without the path	
	1.0.1		2017/03/02	readDirectory()							Added CONTENTS enum class
	1.0.1		2017/03/02	readDirectory()							Added CONTENTS enum parameter
	1.0.1		2017/03/02	readDirectory()							Replaced call to wordSplit() with tokenSplit() to allow underscores in file names
*/

#include "constants.h"
#include "xmltree.h"

#include <string>
#include <algorithm>		// For transform()
#include <iostream>
#include <vector>
#include <map>
#include <ctime>			// AKA <time.h> For localtime_s(), time_t, struct tm, time, mktime
#include <iomanip>			// For std::put_time()
#include <sstream>
#include <cstddef>			// For std::size_t
#include <regex>
#include <fstream>

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#include <windows.h>		// Windows console
#elif defined(__linux) || defined(linux) || defined(__APPLE__)
#include <dirent.h>			// Linux-only: for opendir()
#endif

// Boost
// File System
#if defined(BOOST)
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#endif

class Tools {
	private:		
		// Helper functions
		static std::vector<std::string>::iterator	findXMLClose(std::vector<std::string> &data, std::vector<std::string>::iterator iterator, std::string key);
		static bool									validateTag(std::vector<std::string> &data, const std::vector<std::string>::iterator iterator, std::vector<std::string>::iterator &closeTagIterator, std::string &tagName, std::vector<std::string> &errors, std::vector<std::string> &warnings);
		static void									addNodes(std::vector<std::string> &data, std::vector<std::string>::iterator& iterator, std::vector<std::string>::iterator &closeTagIterator, XMLTree<std::string, std::string>* tree, int currentLevel, std::vector<std::string> &errors, std::vector<std::string> &warnings);
		static bool									isATree(std::vector<std::string> &data, const std::vector<std::string>::iterator iterator, const std::vector<std::string>::iterator closeTagIterator, std::string &tagName, std::vector<std::string> &errors, std::vector<std::string> &warnings);

		// Recursive helper functions
		static std::vector<std::string>::iterator	findXMLCloseRecursive(std::vector<std::string> &data, std::vector<std::string>::iterator iterator, std::string &key);
		static void									addNodesRecursive(std::vector<std::string> &data, std::vector<std::string>::iterator& iterator, const std::vector<std::string>::iterator closeTagIterator, XMLTree<std::string, std::string>* tree, int currentLevel, std::vector<std::string> &errors, std::vector<std::string> &warnings);

	public:
		// Console functions
		static void									clearScreen(std::string message);
		static void									setFullScreen();

		#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
				static void setColor(COLORS background, COLORS foreground);
		#elif defined(__linux) || defined(linux) || defined(__APPLE__)
				static void setColor(COLORS foreground);
		#endif

		static void									rainbow(std::string message);
		
		// String functions
		static std::string							toUpper(std::string text);
		static std::string							toLower(std::string text);
		static std::vector<std::string>				wordSplit(std::string text);
		static std::vector<std::string>				wordSplit(std::string text, CASE letterCase);
		static std::vector<std::string>				tokenSplit(std::string text);
		static std::string							trim(std::string text);
		static std::string							trimDelimiters(std::string text);
		static bool									isNumeric(std::string text);
		static std::string							dateToString();
		static std::string							dateToString(time_t dateTime);
		static std::string							dateTimeToString();
		static std::string							removeAll(std::string text, std::string replaceChars);
		static std::string							digitToName(std::string text);

		// File functions
		// dirExists() currently uses the Linux-only #include <dirent.h>
		#if defined(__linux) || defined(linux) || defined(__APPLE__)
		static bool dirExists(std::string filePath);
		#endif

		static bool									fileExists(std::string filePath, std::string fileName);
		static std::vector<std::string>				readFile(std::string filePath, std::string fileName);
		static std::map<std::string, void*>			createDictionary(std::string filePath, std::string fileName);
		static XMLTree<std::string, std::string>*	XMLParser(std::string filePath, std::string fileName, std::vector<std::string> &messages);

		// Boost file functions
		#if defined(BOOST)
		static std::vector<std::string> readDirectory(std::string filePath, std::string directoryName, CONTENTS contents);
		#endif
};
