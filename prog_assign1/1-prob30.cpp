#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int N, a[MAX][2];
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2; j++)
			cin >> a[i][j];

	int maxlen = 0, x1, y1, x2, y2;
	for(int i=0;i<N-1;i++)
		for (int j = i + 1; j < N; j++) {
			int len = min(a[i][1], a[j][1]) - max(a[i][0], a[j][0]);
			if (len > maxlen) {
				maxlen = len;
				x1 = a[i][0];
				y1 = a[i][1];
				x2 = a[j][0];
				y2 = a[j][1];
			}
		}

	cout << "[" << x1 << ", " << y1 << "]" << endl;
	cout << "[" << x2 << ", " << y2 << "]" << endl;

	return 0;
}