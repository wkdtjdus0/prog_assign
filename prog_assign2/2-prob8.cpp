#include <iostream>
#include <string>
#include <vector>
using namespace std;

string samestr(string str1, string str2) {
	string result;
	int len;
	if (str1.length() > str2.length())
		len = str1.length();
	else
		len = str2.length();

	for (int i = 0; i < len; i++) {
		if (str1[i] == str2[i])
			result += str1[i];
		else
			break;
	}

	return result;
}

int main() {
	int n;
	cin >> n;

	if (n >= 100)
		return 1;

	vector<string> word;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		word.push_back(str);
	}

	string prefix = word[0];

	for (int i = 0; i < n-1; i++) {
		prefix = samestr(word[i], word[i + 1]);
	}

	if (prefix.empty())
		cout << "nothing" << endl;
	else
		cout << prefix << endl;

	return 0;
}