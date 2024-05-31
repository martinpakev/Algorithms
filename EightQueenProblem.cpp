#include <iostream>
using namespace std;


static char board[8][8] = {
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' },
	{ '-', '-', '-', '-', '-', '-', '-', '-' }
};

bool canPlaceQueen(int row, int col) {

	for (size_t c = 0; c < 8; c++) {
		if (board[row][c] == '*')
			return false;
	}
	for (size_t r = 0; r < 8; r++) {
		if (board[r][col] == '*')
			return false;
	}

	int r = row;
	int c = col;

	while (r >= 0 && c >= 0) {
		if (board[r--][c--] == '*')
			return false;
	}

	r = row;
	c = col;

	while (r < 8 && c < 8) {
		if (board[r++][c++] == '*')
			return false;
	}

	r = row;
	c = col;

	while (r >= 0 && c < 8) {
		if (board[r--][c++] == '*')
			return false;
	}

	r = row;
	c = col;

	while (r < 8 && c >= 0) {
		if (board[r++][c--] == '*')
			return false;
	}
	return true;
}

void removeQueen(int row, int col) {
	board[row][col] = '-';
}

void putQueen(int row, int col) {
	board[row][col] = '*';
}



void printSoluton() {
	for (size_t r = 0; r < 8; r++) {
		for (size_t c = 0; c < 8; c++) {
			cout << board[r][c] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void findQueenPositions(int row) {
	if (row == 8) {
		printSoluton();

	}
	else {
		for (size_t col = 0; col < 8; col++) {
			if (canPlaceQueen(row, col)) {
				putQueen(row, col);
				findQueenPositions(row + 1);
				removeQueen(row, col);
			}
		}
	}
}

int main(void)
{
	findQueenPositions(0);

	return 0;
}