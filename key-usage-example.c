/**
 * File              : key-usage-example.c
 * Author            : pdeguing <pdeguing@student.42.us.org>
 * Date              : 04.05.2019
 * Last Modified Date: 04.05.2019
 * Last Modified By  : pdeguing <pdeguing@student.42.us.org>
 */

#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH	30
#define HEIGHT	10

int	startx = 0;
int	starty = 0;

char	*choices[] = {
			"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit"
};

int	n_choices = sizeof(choices) / sizeof(char *);

void	printMenu(WINDOW *menu_win, int hl);

int	main() {
	WINDOW	*menu_win;
	int	hl = 1;
	int	choice = 0;
	int	c;

	initscr();
	clear();
	noecho();
	cbreak();
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice\n");
	refresh();
	printMenu(menu_win, hl);
	while (1) {
		c = wgetch(menu_win);
		switch (c) {

			case KEY_UP:
				if (hl == 1)
					hl = n_choices;
				else
					--hl;
				break ;

			case KEY_DOWN:
				if (hl == n_choices)
					hl = 1;
				else
					++hl;
				break ;
			
			case 10:
				choice = hl;
				break ;

			default:
				mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break ;
		}
		printMenu(menu_win, hl);
		if (choice != 0)
			break ;
	}
	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	sleep(1);
	clrtoeol();
	refresh();
	endwin();
	return 0;
}

void	printMenu(WINDOW *menu_win, int hl) {
	int	x, y, i;

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for (i = 0; i < n_choices; i++) {
		if (hl == i + 1) {
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		} else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		y++;
	}
	wrefresh(menu_win);
}
