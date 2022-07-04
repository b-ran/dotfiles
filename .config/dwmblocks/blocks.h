//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
//	{"", "~/dotfiles/scripts/blocks/volume.sh",      1,  0},
//	{"", "~/dotfiles/scripts/blocks/cpu.sh",         3,  0},
	{"", "~/dotfiles/scripts/blocks/memory.sh",      3,  0},
//	{"", "~/dotfiles/scripts/blocks/storage.sh",     3,  0},
//	{"", "~/dotfiles/scripts/blocks/clock.sh",       10, 0},
	{"", "~/dotfiles/scripts/blocks/uptime.sh",      30, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "\0";
static unsigned int delimLen = 5;