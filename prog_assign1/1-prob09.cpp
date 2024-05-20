#include <iostream>
using namespace std;

int main() {
	int coef, expo_x, expo_y;
	cin >> coef >> expo_x >> expo_y;

	if (coef != 0) {
		if (coef == 1 && expo_x != 0 && expo_y != 0)
			cout << "";
		else if (coef == -1 && expo_x != 0 && expo_y != 0)
			cout << "-";
		else
			cout << coef;

		if (expo_x != 0) {
			cout << "x";
			if (expo_x != 1)
				cout << "^" << expo_x;
		}
		else
			cout << "";

		if (expo_y != 0) {
			cout << "y";
			if (expo_y != 1)
				cout << "^" << expo_y;
		}
		else
			cout<<"";
	}

	return 0;
}