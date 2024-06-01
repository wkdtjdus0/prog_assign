#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a > b && c > d)
		return 1;

	if (b<c || a>d)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}