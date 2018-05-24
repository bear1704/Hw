#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
static void live(char **arr, int row, int col);
static int countNeighbor(char **arr, int row, int col, int i, int j);

int main(void) {
	ifstream in;
	int numTestCases;

	in.open("input.txt");
	

	in >> numTestCases;
	for (int i = 0; i<numTestCases; i++) {
		int row = 0;
		int col = 0;
		in >> row >> col;

		int turn = 0;
		in >> turn;

		char **arr = new char*[row];
		for (int i = 0; i<row; i++) {
			arr[i] = new char[col];
		}
		for (int i = 0; i<row; i++) {
			for (int j = 0; j<col; j++) {
				in >> arr[i][j];
			}
		}

		for (int i = 0; i<turn; i++) {
			live(arr, row, col);
		}
		int countLiveCell = 0;
		for (int i = 0; i<row; i++) {
			for (int j = 0; j<col; j++) {
				if (arr[i][j] == 'O') {
					countLiveCell++;
				}
			}
		}
		cout << countLiveCell << endl;
		for (int i = 0; i<row; i++) {
			for (int j = 0; j<col; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i<row; i++) {
			delete arr[i];
		}
		delete arr;
	}
	in.close();
	return 0;
}

void live(char **arr, int row, int col) {
	int count[row][col];
	for (int i = 0; i<row; i++) {
		for (int j = 0; j<col; j++) {
			count[i][j] = countNeighbor(arr, row, col, i, j);
		}
	}
	
	for (int i = 0; i<row; i++) {
		for (int j = 0; j<col; j++) {
			if (count[i][j] <= 1) {
				arr[i][j] = 'X';
				continue;
			}
			else if (count[i][j] >= 4) {
				arr[i][j] = 'X';
				continue;
			}
			if (count[i][j] <= 3 && arr[i][j] == 'O') {
				arr[i][j] = 'O';
				continue;
			}
			if (count[i][j] == 3 && arr[i][j] == 'X') {
				arr[i][j] = 'O';
				continue;
			}
		}
	}

}

int countNeighbor(char **arr, int row, int col, int i, int j) {
	int count = 0;
	if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == 'O') {
		count++;
	}
	if (i - 1 >= 0 && arr[i - 1][j] == 'O') {
		count++;
	}
	if (i - 1 >= 0 && j + 1 < col && arr[i - 1][j + 1] == 'O') {
		count++;
	}
	if (j - 1 >= 0 && arr[i][j - 1] == 'O') {
		count++;
	}
	if (j + 1 < col && arr[i][j + 1] == 'O') {
		count++;
	}
	if (i + 1 < row && j - 1 >= 0 && arr[i + 1][j - 1] == 'O') {
		count++;
	}
	if (i + 1 < row && arr[i + 1][j] == 'O') {
		count++;
	}
	if (i + 1 < row && j + 1 < col && arr[i + 1][j + 1] == 'O') {
		count++;
	}

	return count;
}