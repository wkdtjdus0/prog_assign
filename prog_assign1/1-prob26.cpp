#include <iostream>
using namespace std;
#define COL 2
#define MAX 100

int main() {
	int n;
	cin >> n;
	int a[MAX][COL];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < COL; j++)
			cin >> a[i][j];

	for(int i=0;i<n;i++)
		for(int j=0;j<n-i-1;j++)
			if (a[j][0] > a[j + 1][0] || (a[j][0] == a[j + 1][0] && a[j][1] > a[j + 1][1])) {
				int temp1 = a[j][0];
				int temp2 = a[j][1];
				a[j][0] = a[j + 1][0];
				a[j][1] = a[j + 1][1];
				a[j + 1][0] = temp1;
				a[j + 1][1] = temp2;
			}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < COL; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	return 0;
}