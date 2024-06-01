#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int n = i;
		while (n > 0) {
			if (n % 10 == 0)
				cnt++;
			n /= 10;
		}
	}

	cout << cnt << endl;
	
	return 0;
}