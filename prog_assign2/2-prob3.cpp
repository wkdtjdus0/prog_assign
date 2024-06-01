#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void tolowercase(string& str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
}

int main() {
	ifstream infile("input3.txt");

	vector<string> word;
	string str;
	vector<int> count;

	while (infile >> str) {
		tolowercase(str);
		word.push_back(str);
	}

	for (int i = 0; i < word.size(); i++) {
		int cnt = 1;
		for (int j = i + 1; j < word.size(); j++) {
			if (word[i] == word[j]) {
				cnt++;
				word.erase(word.begin() + j);
				j--;
		}
		count.push_back(cnt);
	}

	for(int i=0;i<count.size()-1;i++)
		for(int j=0;j<count.size()-i-1;j++)
			if (count[j] < count[j + 1]) {
				int tmp = count[j];
				count[j] = count[j + 1];
				count[j + 1] = tmp;

				string temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;
			}

	for (int i = 0; i < word.size(); i++) {
		cout << word[i] << ":" << count[i] << endl;
	}

	infile.close();

	return 0;
}