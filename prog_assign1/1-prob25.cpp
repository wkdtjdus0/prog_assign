#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int n, a[MAX];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for(int i=n-1;i>0;i--)
		for(int j=0;j<i;j++)
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}

	int k = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != a[i - 1])
			a[++k] = a[i];

	cout << k << ": ";
	for (int i = 1; i <= k; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}