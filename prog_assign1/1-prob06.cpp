#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int max, min;
	cin >> max;
	min = max;

	cout << 0 << " ";

	for (int i = 1; i < N; i++) {
		int n;
		cin >> n;

		if (n < min)
			min = n;
		else if (n > max)
			max = n;

		cout << max - min << " ";
	}
	cout << endl;

	return 0;
}