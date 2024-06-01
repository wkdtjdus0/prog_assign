#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int a[MAX], size = 0;

	while (cin >> a[size] && a[size] != -1 && size < MAX)
		size++;

	int profit = 0;


	for (int i = 1; i < size; i++) {
		if (a[i] < a[i - 1]) {
			a[i - 1] = a[i];
		}
		else {
			profit += a[i] - a[i - 1];
		}
	}
	
	cout << profit << endl;

	return 0;
}