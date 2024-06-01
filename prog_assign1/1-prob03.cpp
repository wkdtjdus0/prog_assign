#include <iostream>
using namespace std;

int fac(int n) {
	if (n <= 1)
		return 1;
	else
		return n * fac(n - 1);
}

int main() {
	int n;
	cin >> n;

	double result = 0.0;

	for (int i = n; i>0; i--) {
		result += 1.0 / fac(i);
	}

	cout << result << endl;

	return 0;
}