#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> word;
	string str;

	while (true) {
		bool isdupli = false;
		cin >> str;
		if (str == "exit")
			break;

		for(int i=0;i<word.size();i++)
			if (word[i] == str) {
				isdupli = true;
				break;
			}

		if (!isdupli) {
			auto it = word.begin();
			while (it != word.end() && *it < str)
				it++;

			if (it == word.end())
				word.push_back(str);
			else
				word.insert(it, str);

			for (auto s : word)
				cout << s << " ";
			cout << endl;
		}
		else
			cout << "duplicate" << endl;
	}

	return 0;
}