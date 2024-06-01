#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

class Point {
public:
	int x, y;

	Point() = default;
	Point(int a, int b) : x(a), y(b) {}
};

class Rect {
public:
	Point lu, rl;

	Rect() = default;
	Rect(Point leftup, Point rightlow) :lu(leftup), rl(rightlow) {}

	Point center() {
		int centX = (lu.x + rl.x) / 2;
		int centY = (lu.y + rl.y) / 2;

		return { centX, centY };
	}
};

double distance(const Point& a, const Point& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void FindMinCircle(vector<Rect>& rects) {
	int cx = 0, cy = 0;
	int cnt = 0;

	for (auto r : rects) {
		cx += r.center().x;
		cy += r.center().y;
		cnt++;
	}
	cx /= cnt;
	cy /= cnt;

	double maxdist = 0.0;
	for (auto r : rects) {
		double dist = distance({cx,cy},r.center());
		if (maxdist < dist)
			maxdist = dist;
	}

	cout << "(" << cx << "," << cy << ")" << endl;
	cout << "¹ÝÁö¸§: " << maxdist << endl;
}

int main() {
	ifstream infile("input2.txt");

	int N;
	infile >> N;

	vector<Rect> rects;
	for (int i = 0; i < N; i++) {
		Point lu, rl;
		infile >> lu.x >> rl.x >> lu.y >> rl.y;
		Rect r(lu, rl);
		rects.push_back(r);
	}
	infile.close();

	FindMinCircle(rects);

	return 0;
}