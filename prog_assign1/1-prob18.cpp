#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int N, a[MAX], size = 0;
	cin >> N;

	if (N <= 0)
		return 1;

	while (N > 0) {
		a[size] = N % 10;
		size++;
		N /= 10;
	}

	int count[10] = { 0 };

	for (int i = 0; i < size; i++)
		count[a[i]]++;

	for (int i = 0; i < 10; i++)
		cout << count[i] << " ";
	
	cout << endl;
	
	
	return 0;
}