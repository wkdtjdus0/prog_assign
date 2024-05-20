#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	int acnt = 0, bcnt = 0;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 1000000; i++) {
		bool a_oc = false;
		bool b_oc = false;

		for (int j = 0; j < 6; j++) {
			if (rand() % 6 + 1 == 1) {
				a_oc = true;
				break;
			}
		}
		for (int k = 0; k < 12; k++) {
			if (rand() % 6 + 1 == 1) {
				if (b_oc) {
					bcnt++;
					break;
				}
				else
					b_oc = true;
			}
		}
		if (a_oc)
			acnt++;
	}

	double aresult = (double)acnt / 1000000;
	double bresult = (double)bcnt / 1000000;

	cout << aresult << " " << bresult << endl;

	return 0;
}