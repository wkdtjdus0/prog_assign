#include <iostream>
using namespace std;

int main() {
	int n, a=1;
	cin >> n;
	double result = 0.0, b = 1.0;

	for (int i = 0; i <= n; ++i) {
		result += a / b;
		a *= -1;
		b *= 2.0;
	}

	cout << result << endl;

	return 0;
}