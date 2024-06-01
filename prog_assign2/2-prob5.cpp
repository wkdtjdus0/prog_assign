#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAX 1000
#define MAX_cnt 100

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

int countword(string str) {
	int cnt = 0, inword = 0;

	for (auto ch : str) {
		if (!isspace(ch)) {
			if (inword == 0) {
				cnt++;
				inword = 1;
			}
		}
		else
			inword = 0;
	}
	return cnt;
}

int main() {
	ifstream infile("sample_lines.txt");

	string str, lines[MAX];
	int wordcnt[MAX_cnt] = { 0 }, n = 0;

	while (getline(infile, str)) {

		string result = removespace(str);
		if (result.empty())
			continue;

		int cnt = countword(result);
		lines[n] = result;
		wordcnt[n] = cnt;
		n++;
	}

	infile.close();

	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if (wordcnt[j] < wordcnt[j + 1]) {
				int tmp = wordcnt[j];
				wordcnt[j] = wordcnt[j + 1];
				wordcnt[j + 1] = tmp;

				string temp = lines[j];
				lines[j] = lines[j + 1];
				lines[j + 1] = temp;
			}

	

	for (int i = 0; i < n; i++)
		cout << lines[i] << ":" << wordcnt[i] << endl;

	return 0;
}