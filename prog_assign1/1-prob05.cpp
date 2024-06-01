#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int N;
	cin >> N;

	int a[MAX];
	int size = 0;
	while (cin >> a[size] && size < N-1)
		size++;

	int min = -1;
	for (int i = 0; i < N; i++) {
		if (a[i] > 0)
			if (a[i] < min || min == -1)
				min = a[i];
	}
	cout << min << endl;

	return 0;
}