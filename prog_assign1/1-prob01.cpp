#include <iostream>
using namespace std;

int fibonacci(int n) {
	if (n <= 1)
		return 1;
	else 
		return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int n;
	cin >> n;

	if (n <= 2 || n >= 30) {
		cout << "잘못된 입력입니다." << endl;
		return 1;
	}

	int result = fibonacci(n);
	cout << result << endl;

	return 0;
}