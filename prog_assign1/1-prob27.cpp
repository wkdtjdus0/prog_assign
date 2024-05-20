#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int N, a[MAX];
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	int max = a[0], cnt = 0;

	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (max > a[j])
				cnt++;
		}
		max = a[i];
	}

	cout << cnt << endl;

	return 0;
}