#pragma once

#include <map>
#include <string>

// Cannot be inside the class. Arrays with initializers cannot be declared static inside a class.
// Code in the source file cannot access an array that is not declared static.
static const int	WORD_DELIMS_LENGTH = 23;
static const char	WORD_DELIMS[WORD_DELIMS_LENGTH] = {
	' ',
	',',
	';',
	':',
	'.',
	'!',
	'?',
	'-',
	'_',
	'&',
	'*',
	'(',
	')',
	'#',
	'%',
	'+',
	'=',
	'"',
	'\'',
	'\\',
	'/',
	'\t',
	'\n'
};

static const int	TOKEN_DELIMS_LENGTH = 9;
static const char	TOKEN_DELIMS[TOKEN_DELIMS_LENGTH] = {
	' ',
	',',
	';',
	':',
	'.',
	'?',
	'\\',
	'\t',
	'\n'
};

static const int								SKIPPED_TAGS = 2;
static const std::map<std::string, std::string> SKIP_TAGS = {
	{ "<?xml", "" },
	{ "<!-- ", "" }
};

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
// Windows console colors
enum class COLORS {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	BLUE_BOLD,
	GREEN_BOLD,
	CYAN_BOLD,
	RED_BOLD,
	PURPLE_BOLD,
	YELLOW_BOLD,
	WHITE_BOLD
};

#elif defined(__linux) || defined(linux) || defined(__APPLE__)
// Linux console colors
enum class COLORS {
	RESET,
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	BOLDBLACK,
	BOLDRED,
	BOLDGREEN,
	BOLDYELLOW,
	BOLDBLUE,
	BOLDMAGENTA,
	BOLDCYAN,
	BOLDWHITE
};

#define RESET		"\033[0m"
#define BLACK		"\033[30m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"
#define WHITE		"\033[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"
#endif

enum class CONTENTS {
	ALL,
	DIRECTORIES,
	FILES
};

enum class CASE {
	LOWERCASE,
	UNCHANGED,
	UPPERCASE
};

static const int			BUFFER_WIDTH	= 9999;
static const int			BUFFER_HEIGHT	= 9999;
static const int			NODE_ADDED		= 0;
static const int			DUPLICATE_NODE	= 1;
static const int			NO_MORE_RAM		= 2;
static const std::string	PUNCTUATION		= "~`!@#$%^&*()_-+={[}]|\\:;""'<,>.?/ ";
