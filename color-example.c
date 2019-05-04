/**
 * File              : color-example.c
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 04.05.2019
 * Last Modified Date: 04.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

void	printInMiddle(WINDOW *win, int starty, int startx, int width, char *str);

int	main() {
	initscr();

	if (has_colors() == FALSE) {
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	printInMiddle(stdscr, LINES / 2, 0, 0, "Voila! In color...");
	attroff(COLOR_PAIR(1));

	getch();
	endwin();

	return 0;
}

void	printInMiddle(WINDOW *win, int starty, int startx, int width, char *str) {
	int	length, x, y;
	float	tmp;

	if (win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if (startx != 0)
		x = startx;
	if (starty != 0)
		y = starty;
	if (width == 0)
		width = 80;

	length = strlen(str);
	tmp = (width - length) / 2;
	x = startx + (int)tmp;
	mvwprintw(win, y, x, "%s", str);
	refresh();
}
