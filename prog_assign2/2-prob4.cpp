#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int sum = 0, n = 0;
	char last = '+';

	for (char c : s) {
		if (isdigit(c))
			n = n * 10 + (c - '0');
		else if (c == '+' || c == '-') {
			if (last == '+')
				sum += n;
			else
				sum -= n;
			n = 0;
			last = c;
		}
	}
	if (last == '+')
		sum += n;
	else
		sum -= n;

	cout << sum << endl;

	return 0;
}