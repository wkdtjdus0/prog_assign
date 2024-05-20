#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Point {
public:
    double x, y;

    Point() = default;
    Point(double a, double b) :x(a), y(b) {}
};

class Circle {
private:
    Point center;
    double radius;
public:
    Circle() = default;
    Circle(Point c, double r) :center(c), radius(r) {}

    double area() const {
        return radius * radius * 3.14;
    }

    bool intersect(const Circle& other) const {
        double dist = sqrt((center.x - other.center.x) * (center.x - other.center.x) + (center.y - other.center.y) * (center.y - other.center.y));
        return dist <= (radius + other.radius);
    }

    void print() {
        cout << "C " << center.x << " " << center.y << " " << radius << endl;
    }
};

class Rect {
private:
    Point lu, rl;
public:
    Rect() = default;
    Rect(Point leftup, Point rightlow) :lu(leftup), rl(rightlow) {}

    double area() const {
        return (rl.x - lu.x) * (lu.y - rl.y);
    }

    bool intersect(const Point& center, double radius) const {
        int distX = abs((lu.x + rl.x) / 2 - center.x);
        int distY = abs((lu.y + rl.y) / 2 - center.y);
        
        if (center.x >= lu.x && center.x <= rl.x && center.y >= rl.y && center.y <= lu.y)
			return true;
        if (distX <= (rl.x - lu.x) / 2 + radius && distY <= (lu.y - rl.y) / 2 + radius)
            return true;
        if (((center.x - lu.x) * (center.x - lu.x) + (center.y - lu.y) * (center.y - lu.y) <= (radius * radius))
            || ((center.x - lu.x) * (center.x - lu.x) + (center.y - rl.y) * (center.y - rl.y) <= (radius * radius))
            || ((center.x - rl.x) * (center.x - rl.x) + (center.y - rl.y) * (center.y - rl.y) <= (radius * radius))
            || ((center.x - rl.x) * (center.x - rl.x) + (center.y - lu.y) * (center.y - lu.y) <= (radius * radius)))
            return true;

        return false;
    }

    void print() {
        cout << "R " << lu.x << " " << rl.x << " " << lu.y << " " << rl.y << endl;
    }
};

bool compare(const pair<int, double>& a, const pair<int, double>& b) {
    return a.second > b.second;
}

int main() {
    ifstream infile("input1.txt");

    int N;
    infile >> N;

    vector<Circle> circles;
    vector<Rect> rects;

    for (int i = 0; i < N; i++) {
        char type;
        infile >> type;

        if (type == 'R') {
            double x1, x2, y1, y2;
            infile >> x1 >> x2 >> y1 >> y2;
            rects.push_back({ Point(x1, y1), Point(x2, y2) });
        }
        else if (type == 'C') {
            double xc, yc, r;
            infile >> xc >> yc >> r;
            circles.push_back({ Point(xc, yc), r });
        }
    }

    double xc, xy, radi;
    infile >> xc >> xy >> radi;
    Circle newCircle(Point(xc, xy), radi);

    vector<pair<int, double>> intersectShapes;
    for (int i = 0; i < rects.size(); i++) {
        if (rects[i].intersect(Point(xc, xy), radi))
            intersectShapes.push_back({ i + 1, rects[i].area() });
    }

    for (int i = 0; i < circles.size(); i++) {
        if (circles[i].intersect(newCircle))
            intersectShapes.push_back({ i + 1 + rects.size(), circles[i].area() });
    }

    sort(intersectShapes.begin(), intersectShapes.end(), compare);

    for (auto s : intersectShapes) {
        if (s.first <= rects.size())
            rects[s.first - 1].print();
        else
            circles[s.first - rects.size() - 1].print();
    }

    infile.close();
    return 0;
}
