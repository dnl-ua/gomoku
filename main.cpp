#include <iostream>
#include <ncurses.h>
#include "Gomoku.h"

void print(Board);
void game(Board);

int main() {
	initscr();

	Board b;
	game(b);

	endwin();

	return 0;
}

void game(Board board) {
	WINDOW *win = newwin(30, 30, 0, 0);
	int x, y;
	do {	
		wrefresh(win);

		printw("\n");
		print(board);
		printw("\n");	

		scanw("%d %d", &x, &y);
		clear();

		board.push(x, y);

		refresh();
	} while (!board.check());

	clear();
	printw("\n");
	print(board);
	printw("\nthe end\n");
	refresh();
	wrefresh(win);
	getch();
}

void print(Board board) {
	for (int i = 0; i < 15; i++) {
		printw("\t");
		for (int o = 0; o < 15; o++) {
			switch (board.get(i, o)) {
				case 1:
					//std::cout << "x";
					printw("x");
					break;
				case 0:
					//std::cout << "o";
					printw("o");
					break;
				default:
					//std::cout << ".";
					printw(".");
					break;
			}
			//std::cout << " ";
			printw(" ");
		}
		//std::cout << "\n";
		printw("\n");
	}
}
