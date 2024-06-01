#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAX 1000

int main() {
	ifstream infile("sample.txt");
	string str, word[MAX];
	int n = 0;

	while (infile >> str) {
		int s = 0, t = str.length() - 1;
		while (s < str.length() && !isalnum(str[s]))
			s++;
		while (t >= 0 && !isalnum(str[t]))
			t--;

		if (s <= t) {
			string pureword = str.substr(s, t - s + 1);

			for (int i = 0; i < pureword.length(); i++)
				pureword[i] = tolower(pureword[i]);

			bool found = false;
			for (int i = 0; i < n; i++) {
				if (word[i] == pureword) {
					found = true;
					break;
				}
			}
			if (!found)
				word[n++] = pureword;
		}
	}
	infile.close();

	for (int i = 0; i < n; i++)
		cout << word[i] << endl;

	return 0;
}