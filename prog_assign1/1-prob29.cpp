#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int N, K, a[MAX];
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> a[i];
	cin >> K;

	int maxlen = 0, len = 0, sum = a[0];
	for (int i = 0; i < N; i++) {
		if (sum <= K) {
			sum += a[i];
			len++;
			if (len > maxlen)
				maxlen = len;
		}
		else {
			sum = a[i];
			len = 0;
		}
	}

	cout << maxlen << endl;

	return 0;
}