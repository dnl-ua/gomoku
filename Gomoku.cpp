#include "Gomoku.h"

int Board::get(int x, int y) {
	return board[x][y];
}

int Board::get_move() {
	return ((move % 2) ? 1 : 0);
}

int Board::check() {
	int val = (move % 2) ? 0 : 1;

	for (int i = 0; i < 15; i++) {
	for (int o = 0; o < 15; o++) {
		if (board[i][o] == val) {
			// i hate how it looks but it saves 
			// few checks (i guess)
			if (board[i+1][o] == val &&
			    board[i-1][o] == val) {
				if (board[i+2][o] == val &&
				    board[i-2][o] == val)
					return 1;
			} if (board[i][o+1] == val &&
			      board[i][o-1] == val) {
				if (board[i][o+2] == val &&
				    board[i][o-2] == val)
					return 1;
			} if (board[i-1][o-1] == val &&
			      board[i+1][o+1] == val) {
				if (board[i-2][o-2] == val &&
				    board[i+2][o+2] == val)
					return 1;
			} if (board[i-1][o+1] == val &&
			      board[i+1][o-1] == val) {
				if (board[i-2][o+2] == val &&
				    board[i+2][o-2] == val)
					return 1;
			}
		}
	}}

	return 0;
}

int Board::push(int x, int y) {
	if (board[x][y] != -1) return -1;

	board[x][y] = (move % 2) ? 1 : 0;
	move += 1;
	
	return 1;
}
