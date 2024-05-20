#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream infile("harry.txt");

	vector<string> word;
	string str, prefix;
	cin >> str;

	while (infile >> prefix) {
		if(find(word.begin(),word.end(),prefix)==word.end())
			word.push_back(prefix);
	}
	infile.close();

	for (int i = 0; i < word.size() - 1; i++)
		for (int j = 0; j < word.size() - i - 1; j++)
			if (word[j] > word[j + 1]) {
				string temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;
			}

	int index = 0, cnt = 0;
	while (index<word.size()) {
		int isword = word[index].find(str);

		if (isword == 0) {
			cout << word[index] << endl;
			cnt++;
		}
		index++;
	}

	cout << cnt << endl;

	return 0;
}