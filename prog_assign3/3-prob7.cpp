#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 8;

vector<vector<int>> board(SIZE, vector<int>(SIZE));
const int Black = 1;
const int White = 2;

int countStoneToCapture(int x, int y, int color) {
	int oppositeColor = (color == Black) ? White : Black;
	int cnt = 0;

	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0)
				continue;
			int nx = x + dx;
			int ny = y + dy;
			if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE)
				continue;
			if (board[nx][ny] == oppositeColor) {
				while (true) {
					nx += dx;
					ny += dy;
					if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE || board[nx][ny] == 0)
						break;
					if (board[nx][ny] == color) {
						cnt++;
						break;
					}
				}
			}
		}
	}
	return cnt;
}

bool isvalidmove(int x, int y, int color) {
	if (board[x][y] != 0) {
		cout << "Invalid Move - Already placed" << endl;
		return false;
	}
	for (int dx = -1; dx <= 1; ++dx) {
		for (int dy = -1; dy <= 1; ++dy) {
			if (dx == 0 && dy == 0)
				continue;
			int nx = x + dx;
			int ny = y + dy;
			while (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] != 0) {
				if (board[nx][ny] != color) {
					return true;
				}
				nx += dx;
				ny += dy;
			}
		}
	}
	return false;
}

void placeStone(int x, int y, int color) {
	board[x][y] = color;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0)
				continue;
			int nx = x + dx;
			int ny = y + dy;
			while (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] != 0) {
				if (board[nx][ny] == color) {
					int cx = x + dx;
					int cy = y + dy;
					while (cx != nx || cy != ny) {
						board[cx][cy] = color;
						cx += dx;
						cy += dy;
					}
					break;
				}
				nx += dx;
				ny += dy;
			}
		}
	}
}

int main() {
	board[SIZE / 2 - 1][SIZE / 2 - 1] = White;
	board[SIZE / 2][SIZE / 2] = White;
	board[SIZE / 2][SIZE / 2 - 1] = Black;
	board[SIZE / 2 - 1][SIZE / 2] = Black;

	int turn = Black;

	while (true) {
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				if (board[i][j] == Black) cout << "1 ";
				else if (board[i][j] == White) cout << "2 ";
				else cout << "0 ";
			}
			cout << endl;
		}
		cout << endl;

		int x, y;
		int maxCaptured = 0;
		int bestX = -1, bestY = -1;
		if (turn == Black) {
			cout << "My turn (1): ";
			cin >> x >> y;
			placeStone(x, y, Black);
		}
		else {
			for (int x = 0; x < SIZE; x++) {
				for (int y = 0; y < SIZE; y++) {
					if (board[x][y] == 0 && isvalidmove(x, y, White)) {
						int captured = countStoneToCapture(x, y, White);
						if (captured > maxCaptured) {
							maxCaptured = captured;
							bestX = x;
							bestY = y;
						}
					}
				}
			}
			cout << "Computer's turn (2): " << bestX << " " << bestY << endl;
			placeStone(bestX, bestY, White);
		}
		turn = (turn == Black) ? White : Black;
	}

	return 0;
}