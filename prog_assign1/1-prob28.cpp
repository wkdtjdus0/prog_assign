#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int n, a[MAX];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int first = a[0], maxlen = 1, len = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] <= a[i + 1]) {
			len++;
			if (len > maxlen)
				maxlen = len;
		}
		else
			len = 1;
	}

	cout << maxlen << endl;

	return 0;
}