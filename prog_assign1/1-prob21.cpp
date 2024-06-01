#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int n, a[MAX], size = 0;
	cin >> n;

	if (n > 100)
		return 1;

	while (size<n && cin >> a[size])
		size++;

	int leader = a[0], leader_list[MAX], j = 1;
	leader_list[0] = leader;

	for (int i = 1; i < n; i++) {
		if (leader <= a[i]) {
			leader_list[j] = a[i];
			j++;
		}
	}

	cout << j << ": ";
	for (int k = 0; k < j; k++)
		cout << leader_list[k] << " ";
	cout << endl;

	return 0;
}