//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"", "~/dotfiles/scripts/blocks/volume",      1,  0},
	{"", "~/dotfiles/scripts/blocks/cpu",         3,  0},
	{"", "~/dotfiles/scripts/blocks/memory",      3,  0},
	{"", "~/dotfiles/scripts/blocks/storage",     3,  0},
	{"", "~/dotfiles/scripts/blocks/time",        3,  0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "\0";
static unsigned int delimLen = 5;