#include <iostream>
#include <string>
using namespace std;

string removespace(string str) {
	string result;
	int pre = 0;
	for (auto ch : str) {
		if (!isspace(ch)) {
			result += ch;
			pre = 1;
		}
		else {
			if (pre == 1) {
				result += " ";
				pre = 0;
			}
		}
	}
	return result;
}

int main() {
	string text;

	while (1) {
		getline(cin, text);

		if (text == "exit")
			break;

		string result = removespace(text);
		cout << result;
		cout << ": " << result.length() << endl;
	}

	return 0;
}