#include <iostream>
#include <vector>
using namespace std;

void compute_set(vector<int>& A, vector<int>& B) {
	for (int i = 0; i < B.size(); i++) {
		if (find(A.begin(), A.end(), B[i]) == A.end())
			A.push_back(B[i]);
		else
			A.erase(remove(A.begin(), A.end(), B[i]), A.end());
	}

	for(int i=A.size()-1;i>0;i--)
		for(int j=0;j<i;j++)
			if (A[j] > A[j + 1]) {
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
}

int main() {
	int m, n, k;
	vector<int> first, second;

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		first.push_back(k);
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		second.push_back(k);
	}

	compute_set(first, second);

	for (auto item : first)
		cout << item << " ";
	cout << endl;

	return 0;
}