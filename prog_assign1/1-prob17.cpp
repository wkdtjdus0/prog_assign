#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100

int main() {
	int n, a[MAX], size = 0;
	cin >> n;

	if (n > 100)
		return 1;

	while (size < n && cin >> a[size])
		size++;

	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	double avg = (double)sum / size;

	double SD_sum = 0.0;
	for (int i = 0; i < size; i++)
		SD_sum += (a[i] - avg) * (a[i] - avg);
	double SD = sqrt(SD_sum/size);

	cout << avg << " " << SD << endl;

	return 0;
}