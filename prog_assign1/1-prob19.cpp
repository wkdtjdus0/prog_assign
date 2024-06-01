#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int n, a[MAX], size = 0;
	cin >> n;

	if (n > 100)
		return 1;

	while (size<n && cin >> a[size])
		size++;

	int k;
	cin >> k;

	int mindiff = abs(a[0] - k), result = a[0];
	for (int i = 1; i < size; i++) {
		if (abs(a[i] - k) < mindiff) {
			mindiff = abs(a[i] - k);
			result = a[i];
		}
	}

	cout << result << endl;

	return 0;
}