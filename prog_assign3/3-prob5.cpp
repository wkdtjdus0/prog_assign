#include <iostream>
#include <vector>
using namespace std;

struct Point {
	int x;
	int y;
};

struct Segment {
	Point start;
	Point end;
};

vector<Point> result;

bool intersect(vector<Segment>& points) {
	for (int i = 0; i < points.size(); i++) {
		int x1 = points[i].start.x;
		int x2 = points[i].end.x;
		int y1 = points[i].start.y;
		int y2 = points[i].end.y;

		for (int j = i + 1; j < points.size(); j++) {
			int x3 = points[j].start.x;
			int x4 = points[j].end.x;
			int y3 = points[j].start.y;
			int y4 = points[j].end.y;

			if ((x1 <= x3 && x3 <= x2 || x1 <= x4 && x4 <= x2) && (y3 <= y1 && y1 <= y4 || y3 <= y2 && y2 <= y4)) {
				int x = (x1 == x2) ? x1 : (x3 == x4) ? x3 : (x1 < x2) ? x2 : x1;
				int y = (y1 == y2) ? y1 : (y3 == y4) ? y3 : (y1 < y2) ? y2 : y1;

				Point intersection;
				intersection.x = x;
				intersection.y = y;
				result.push_back(intersection);
			}
		}
	}
	return !result.empty();
}

void sorted(vector<Point>& result) {
	for (int i = 0; i < result.size() - 1; i++)
		for (int j = 0; j < result.size() - i - 1; j++)
			if (result[j].x > result[j + 1].x || (result[j].x == result[j + 1].x && result[j].y > result[j + 1].y)) {
				int tempX = result[j].x;
				result[j].x = result[j + 1].x;
				result[j + 1].x = tempX;

				int tempY = result[j].y;
				result[j].y = result[j + 1].y;
				result[j + 1].y = tempY;
			}
}

int main() {
	int N;
	cin >> N;

	vector<Segment> points(N);
	
	for (int i = 0; i < N; i++) {
		cin >> points[i].start.x >> points[i].start.y >> points[i].end.x >> points[i].end.y;
	}

	if (intersect(points)) {
		sorted(result);
		for (auto p : result)
			cout << "[" << p.x << ", " << p.y << "]" << endl;
	}

	return 0;
}