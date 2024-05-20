#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> result;
void wordpuzzle(vector<string>& words, vector<string>& dict) {
	for (string& word : words)
		for (string& dict_word : dict) {
			if (dict_word.find(word) != string::npos) {
				result.push_back(word);
				break;
			}
		}
}

void sorted(vector<string>& result) {
	for (int i = result.size() - 1; i > 0; i--)
		for(int j=0;j<i;j++)
			if (result[j] > result[j + 1]) {
				string temp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = temp;
			}
}

int main() {
	ifstream thefile("dictionary.txt");
	vector<string> dict;
	string line;

	while (getline(thefile, line))
		dict.push_back(line);

	thefile.close();

	ifstream infile("puzzle.txt");
	int N;
	infile >> N;

	string word;
	vector<string> words;

	while (infile >> word)
		words.push_back(word);

	infile.close();

	wordpuzzle(words, dict);
	sorted(result);

	for (string& res : result)
		cout << res << endl;

	return 0;
}