#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int N, a[MAX];
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (a[i] != 0 && a[i] != 1)
			return 1;
	}

	int max_len = 0;
	for (int i = 0; i < N; i++) {
		int len = 0, cnt = 0;
		for (int j = i; j < N; j++) {
			if (a[j] == 1)
				len++;
			else if (cnt == 0) {
				cnt = 1;
				len++;
			}
			else
				break;
		}
		if (len > max_len)
			max_len = len;
	}

	cout << max_len << endl;

	return 0;
}