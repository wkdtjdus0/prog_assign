#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> num;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		num.push_back(a);
	}

	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if (num[j] > num[j + 1]) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}

	vector<int> result;
	result.push_back(num[0]);
	for (int i = 1; i < n; i++) {
		if (num[i] != num[i - 1])
			result.push_back(num[i]);
	}

	cout << result.size() << ":";
	for (int x : result)
		cout << " " << x;
	cout << endl;

	return 0;
}