#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool check(vector<vector<int>>& board, int user, int size) {
	for(int i=0;i<size;i++)
		for (int j = 0; j < size-4; j++) {
			bool winHorizon = true, winVertic = true;
			for (int k = 0; k < 5; k++) {
				if (board[i][j + k] != user)
					winHorizon = false;
				if (board[j + k][i] != user)
					winVertic = false;
			}
			if (winHorizon || winVertic)
				return true;
		}

	for(int i=0;i<size-4;i++)
		for (int j = 0; j < size - 4; j++) {
			bool winLeftRight = true, winRightLeft = true;
			for (int k = 0; k < 5; k++) {
				if (board[i + k][j + k] != user)
					winLeftRight = false;
				if (board[i + k][size - j - 1 - k] != user)
					winRightLeft = false;
			}
			if (winLeftRight || winRightLeft)
				return true;
		}

	return false;
}

int main() {
	ifstream theFile("board.txt");

	int N;
	theFile >> N;

	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			theFile >> board[i][j];
		}

	}
	theFile.close();

	bool winB = check(board, 1, N);
	bool winW = check(board, 2, N);

	if (winB)
		cout << "Black" << endl;
	else if (winW)
		cout << "White" << endl;
	else
		cout << "Not Finished" << endl;

	return 0;
}