#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int n, a[MAX];
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = n - 1; i > 0; i--) {
		int max = i;
		for (int j = 0; j <= i; j++)
			if (a[j] > a[max])
				max = j;

		if (i != max) {
			int temp = a[i];
			a[i] = a[max];
			a[max] = temp;
		}
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}