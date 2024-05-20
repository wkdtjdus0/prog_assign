#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream infile("table.txt");
	ofstream outfile("output.txt");

	int ROWS, COLS;
	infile >> ROWS >> COLS;

	infile.ignore();


	for (int i = 0; i < ROWS; i++) {
		vector<string> result;
		string cell, line;
		getline(infile, line);
		
		for (auto c : line) {
			if (c != '&')
				cell += c;
			else {
				cell.erase(remove_if(cell.begin(), cell.end(), ::isspace),cell.end());
				if (!cell.empty())
					result.push_back(cell);
				cell.clear();
			}
		}
		cell.erase(remove_if(cell.begin(), cell.end(), ::isspace), cell.end());
		if (!cell.empty())
			result.push_back(cell);

		for (auto cell : result)
			outfile << cell << '\t';
		outfile << endl;
	}

	infile.close();
	outfile.close();

	return 0;
}