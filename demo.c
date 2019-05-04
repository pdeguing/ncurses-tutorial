/**
 * File              : demo.c
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 04.05.2019
 * Last Modified Date: 04.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include <ncurses.h>
#include <unistd.h>

#define DELAY	30000

int	main(void) {

	int	x = 0, y = 0;
	int	max_y = 0, max_x = 0;
	int	next_x = 0;
	int	direction = 1;

	initscr(); // Initialize the window
	noecho(); // Don't echo any keypresses
	curs_set(FALSE); // Don't display a cursor

	// Global var `stdscr` is created by the call to `initscr()`
	getmaxyx(stdscr, max_y, max_x);

	while (1) {
		clear(); // Clear the screen of all previous characters
		mvprintw(y, x, "o");
		refresh();

		usleep(DELAY); // Delay between movements

		next_x = x + direction;

		if (next_x >= max_x || next_x < 0) {
			direction *= -1;
		} else {
			x += direction;
		}
	}

	endwin(); // Restore normal temrinal behavior
}
