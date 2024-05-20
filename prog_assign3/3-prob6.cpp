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

bool intersect(vector<Segment>& a, Segment& newSegment) {
	for (Segment seg : a) {
		if (newSegment.start.x <= seg.end.x && newSegment.start.y <= seg.end.y ||
			newSegment.end.x >= seg.start.x && newSegment.end.y >= seg.start.y) {
			return true;
		}
	}
	return false;
}

int main() {
	vector<Segment> a;
	Segment v = { {0,0}, {0,0} };
	int i = 0;
	
	while (true) {
		int whereD, howD;
		cin >> whereD >> howD;

		if (whereD == -1 && howD == -1)
			break;
		
		switch (whereD)
		{
		case 0:
			v.end.y += howD;
			break;
		case 1:
			v.end.x += howD;
			break;
		case 2:
			v.end.y -= howD;
			break;
		case 3:
			v.end.x -= howD;
			break;
		default:
			break;
		}

		if (intersect(a, v))
			cout << "invalid move" << endl;
		else {
			a.push_back(v);
			cout << a[i].end.x << " " << a[i].end.y << endl;
			i++;
		}
	}

	return 0;
}