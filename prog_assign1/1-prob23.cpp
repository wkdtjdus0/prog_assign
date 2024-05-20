#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int a[MAX], size = 0;
	
	while (cin>>a[size]&&a[size]!=-1&&size<MAX) {
		bool isdupli = false;

		for(int i=0;i<size;i++)
			if (a[i] == a[size]) {
				isdupli = true;
				break;
			}

		if (!isdupli) {

			size++;

			for (int j = size - 1; j > 0; j--)
				if (a[j] < a[j - 1]) {
					int tmp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = tmp;
				}

			for (int i = 0; i < size; i++)
				cout << a[i] << " ";
			cout << endl;
		}
		else
			cout << "duplicate" << endl;
	}

	return 0;
}