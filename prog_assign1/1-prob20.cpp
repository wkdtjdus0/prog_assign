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

	if (n >= k) {
		for (int i = 0; i < k; i++) {
			int last = a[n - 1];
			for (int j = n - 1; j > 0; j--)
				a[j] = a[j - 1];
			a[0] = last;
		}
	}
	else {
		cout << "잘못된 입력입니다." << endl;
		return 1;
	}

	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}