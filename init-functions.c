/**
 * File              : init-functions.c
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 04.05.2019
 * Last Modified Date: 04.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include <ncurses.h>

int	main() {
	int	ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("Type any character to see it in bold\n");

	ch = getch();

	if (ch == KEY_F(1))
		printw("F1 Key pressed");
	else {
		printw("The pressed key is ");
		attron(A_BOLD);
		printw("%c",ch);
		attroff(A_BOLD);
	}
	refresh();
	getch();
	endwin();

	return 0;
}
