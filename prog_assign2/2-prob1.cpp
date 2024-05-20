#include <iostream>
#include <vector>
using namespace std;

int arraynum(int a, int b) {
	while (a >= 10)
		a /= 10;
	while (b >= 10)
		b /= 10;

	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
		return 0;
}

int main(){
	vector<int> v1;
	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v1.push_back(num);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			int result = arraynum(v1.at(j), v1.at(j + 1));
			if (result == 1) {
				int temp = v1.at(j);
				v1.at(j) = v1.at(j + 1);
				v1.at(j + 1) = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << v1[i] << " ";
	cout << endl;

	return 0;
}