#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> words;
vector<vector<int>> lineNums;
vector<string> lines;

void makeIndex(string fileName);
void handle_find(string keyword);
void addWord(string word, int lineNum);
int findWord(string keyword);
vector<string> split_line(string line, char delimiter);

int main() {
	string command;
	while (1) {
		cout << "$ ";
		cin >> command;
		if (command == "read") {
			string fileName;
			cin >> fileName;
			makeIndex(fileName);
		}
		else if (command == "find") {
			string keyword;
			cin >> keyword;
			handle_find(keyword);
		}
		else if (command == "exit")
			break;
	}
	return 0;
}

void makeIndex(string fileName) {
	ifstream theFile(fileName);
	int lineNum = 0;
	string line;
	while (getline(theFile, line)) {
		lines.push_back(line);
		vector<string> tokens = split_line(line, ' ');
		for (auto& s : tokens) {
			s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) { return !isalpha(c); }), s.end());
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			if (s.length() >= 3)
				addWord(s, lineNum);
		}
		lineNum++;
	}
	theFile.close();
}

void handle_find(string keyword) {
	int index = findWord(keyword);
	if (index != -1) {
		cout << "The word " << keyword << " appears " << lineNums[index].size() << " times in lines: "<<endl;
		for (auto v : lineNums[index])
			cout << v << ": "<<lines[v]<<endl;
	}
	else
		cout << "The word " << keyword << " doesn¡¯t appear." << endl;
}

void addWord(string word, int lineNum) {
	int index = findWord(word);
	if (index > -1) {
		auto it = find(lineNums[index].begin(), lineNums[index].end(), lineNum);
		if (it == lineNums[index].end())
			lineNums[index].push_back(lineNum);
	}
	else {
		words.push_back(word);
		vector<int> tmp = { lineNum };
		lineNums.push_back(tmp);
	}
}

int findWord(string keyword) {
	transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

	for (int i = 0; i < words.size(); i++) {
		string word = words[i];
		transform(word.begin(), word.end(), word.begin(), ::tolower);

		if (words[i] == keyword)
			return i;
	}
	return -1;
}

vector<string> split_line(string line, char delimiter) {
	vector<string> tokens;

	stringstream sstream(line);

	string str;
	while (getline(sstream, str, delimiter))
		tokens.push_back(str);

	return tokens;
}