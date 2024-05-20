#include <iostream>
using namespace std;

int main() {
	int a[7];
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
		if (a[i] < 1 && a[i]>13)
			return 1;
	}

	for(int i=6;i>0;i--)
		for(int j=0;j<i;j++)
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}

	int k = 0;
	for (int i = 1; i < 7; i++)
		if (a[i] != a[i - 1])
			a[++k] = a[i];

	int len = 1;
	for(int i=0;i<k;i++)
		if (len != 5) {
			if (a[i + 1] - a[i] == 1)
				len++;
			else
				len = 1;
		}

	if (len == 5)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}