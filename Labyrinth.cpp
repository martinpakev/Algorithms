#include <iostream>
#include <vector>
using namespace std;


static vector<char> path;

void printPath() {



	for (char item : path) {
		cout << item;
	}
	cout << endl;
	if (path.size()) {
		path.pop_back();
	}
}

void findPathInLabyrinth(vector<vector<char>> matrix, int row, int col, char direction) {

	if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[row][col] == '*' || matrix[row][col] == 'V') {
		return;
	}

	if (direction != ' ') path.push_back(direction);

	if (matrix[row][col] == 'e') {

		printPath();

		return;
	}

	matrix[row][col] = 'V';

	findPathInLabyrinth(matrix, row + 1, col, 'D');
	findPathInLabyrinth(matrix, row - 1, col, 'U');
	findPathInLabyrinth(matrix, row, col - 1, 'L');
	findPathInLabyrinth(matrix, row, col + 1, 'R');

	matrix[row][col] = '-';
	if (path.size()) {
		path.pop_back();
	}
}


void enterMatrix(vector<vector<char>>& matrix, int rows, int cols) {
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++) {
			cin >> matrix[r][c];
		}
}


int main(void) {

	int rows, cols;
	cin >> rows >> cols;

	vector<vector<char>> matrix(rows, vector<char>(cols));

	enterMatrix(matrix, rows, cols);


	char direction = ' ';

	findPathInLabyrinth(matrix, 0, 0, direction);

	return 0;
}