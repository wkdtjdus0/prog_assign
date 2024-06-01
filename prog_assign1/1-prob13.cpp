#include <iostream>
using namespace std;

int main() {
	int result = 0;
	double d2;
	for(int x=0;x<=100;x++)
		for (int y = 0; y <= 100; y++) {
			d2 = x * x + y * y;
			if (y <= 2.0 * x / 3 && y >= 1.0 * x / 3 && d2 <= 10000)
				result++;
		}

	cout << result << endl;

	return 0;
}