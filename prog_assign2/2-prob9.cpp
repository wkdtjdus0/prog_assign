#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct WORD {
	string word;
	string mean;
};

int main() {
	ifstream infile("shuffled_dict.txt");

	vector<WORD> list;
	string line, word, mean;

	while (getline(infile, line)) {
		int tab = line.find('\t');
		if (tab != string::npos) {
			word = line.substr(0, tab);
			mean = line.substr(tab + 1);
			list.push_back({ word,mean });
		}
	}
	infile.close();

	for (int i = 0; i < list.size() - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < list.size(); j++) {
			if (list[j].word < list[minIndex].word) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			WORD temp = list[i];
			list[i] = list[minIndex];
			list[minIndex] = temp;
		}
	}

	string prefix;
	cin >> prefix;

	bool found = false;

	cout << "Result of prefix search:" << endl;
	for (int i = 0;i<list.size();i++) {
		if (list[i].word.find(prefix) == 0 && found == false) {
			cout << list [i] .word << ": " << list[i].mean << endl;
			found = true;
		}
		if (list[i].word > prefix) {
			cout << "NOT FOUND" << endl;
			if (i > 0)
				cout << "- " << list[i - 1].word << ": " << list[i - 1].mean << endl;
			if (i < list.size() - 1)
				cout << "+ " << list[i + 1].word << ": " << list[i + 1].mean << endl;
			break;
		}
	}

	return 0;
}