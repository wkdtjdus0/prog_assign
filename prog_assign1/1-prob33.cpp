#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#define MAX 100

int main() {
	int N, puppy[MAX][MAX];
	cin >> N;

	srand((unsigned int)time(NULL));
	double success = 0.0;

	if (N > 100)
		return 1;

	int T = 0;
	while (T < 10000) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				puppy[i][j] = 0;

		int x = N / 2, y = N / 2;

		puppy[x][y] = 1;

		while (1) {
			int notvisit[4][2] = { 0 };
			int n_notvisit = 0;

			if (y > 0 && puppy[x][y - 1] == 0) {
				notvisit[n_notvisit][0] = x;
				notvisit[n_notvisit][1] = y - 1;
				n_notvisit++;
			}
			if (y < N - 1 && puppy[x][y + 1] == 0) {
				notvisit[n_notvisit][0] = x;
				notvisit[n_notvisit][1] = y + 1;
				n_notvisit++;
			}
			if (x > 0 && puppy[x - 1][y] == 0) {
				notvisit[n_notvisit][0] = x - 1;
				notvisit[n_notvisit][1] = y;
				n_notvisit++;
			}
			if (y > 0 && puppy[x + 1][y] == 0) {
				notvisit[n_notvisit][0] = x + 1;
				notvisit[n_notvisit][1] = y;
				n_notvisit++;
			}

			if (n_notvisit == 0)
				break;

			int pup_move = rand() % n_notvisit;
			x = notvisit[pup_move][0];
			y = notvisit[pup_move][1];

			puppy[x][y] = 1;

			if (puppy[0][0] == 1 || puppy[N - 1][N - 1] == 1 || puppy[0][N - 1] == 1 || puppy[N - 1][0] == 1) {
				success++;
				break;
			}
		}
		
		T++;
	}
	double result = success / T;
	cout << result << endl;

	return 0;
}