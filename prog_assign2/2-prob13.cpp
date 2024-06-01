#include <iostream>
#include <vector>
#include <string>
using namespace std;

int len_compare(string str1, string str2) {
	if (str1.length() > str2.length())
		return 2;
	else if (str1.length() < str2.length())
		return 1;
	else
		return 0;
}

int main() {
	int n;
	cin >> n;

	if (n > 20)
		return 1;

	vector<string> word;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		word.push_back(str);
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (len_compare(word[j], word[j + 1]) == 2) {
				string temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;
			}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (len_compare(word[j], word[j + 1]) == 0)
				if (word[j] > word[j + 1]) {
					string temp = word[j];
					word[j] = word[j + 1];
					word[j + 1] = temp;
				}

	cout << endl;
	for (auto s : word)
		cout << s << endl;

	return 0;
}