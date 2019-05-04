/**
 * File              : hello-world.c
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 04.05.2019
 * Last Modified Date: 04.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include <ncurses.h>

int	main() {
	initscr();			// Start curses mode
	printw("Hello, world!");	// Print Hello World
	refresh();			// Print it on to the real screen
	getch();			// Wait for user input 
	endwin();			// End curses node

	return 0;
}

// compile and link: gcc <file> -lncurses
