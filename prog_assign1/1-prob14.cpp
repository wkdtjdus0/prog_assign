#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	int count = 0;
	
	for (int a = 2; a <= 100; a++)
		for (int b = a + 1; b <= 100; b++)
			for (int c = b + 1; c <= 100; c++) {
				if (gcd(a, b) == 1 && gcd(b, c) == 1 && gcd(c, a) == 1)
					count++;
			}

	cout << count << endl;

	return 0;
}