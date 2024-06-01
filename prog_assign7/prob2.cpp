#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
 0                  19 y
0--------------------
1--------------------
2--------------------
3--------------------
4--------------------
5--------------------
6--------------------
7--------------------
8--------------------
9--------------------
x
*/

class GameObject {
protected:
	int distance;
	int x, y;
public:
	GameObject(int startX, int startY, int distance) {
		this->x = startX; this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {};
	
	virtual void move() = 0;
	virtual char getShape() = 0;
	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject* p) {
		if (this->x == p->getX() && this->y == p->getY()) return true;
		else return false;
	}
};

class Human: public GameObject {
public:
	Human() = default;
	Human(int x, int y, int dist) :GameObject(x, y, dist) {};
	char getShape() { return 'H'; }
	void move() {
		char key;
		while (true) {
			cout << "����(a), �Ʒ�(s), ��(d), ������(f) >> ";
			cin >> key;

			if (key == 'a') { //��
				if (y != 0) {
					y -= distance;
					break;
				}
				else
					cout << "�̵� ����" << endl;
			}
			else if (key == 's') { //�Ʒ�
				if (x != 9) {
					x += distance;
					break;
				}
				else
					cout << "�̵� ����" << endl;
			}
			else if (key == 'd') { //��
				if (x != 0) {
					x -= distance;
					break;
				}
				else
					cout << "�̵� ����" << endl;
			}
			else if (key == 'f') { //����
				if (y != 19) {
					y += distance;
					break;
				}
				else
					cout << "�̵� ����" << endl;
			}
			else break;
		}
	}
};

class Monster: public GameObject { //��ĭ�̵�
public:
	Monster() = default;
	Monster(int x, int y, int dist) :GameObject(x, y, dist) {};
	char getShape() { return 'M'; }
	void move() {
		srand((unsigned)time(NULL));
		while (true) {
			int m = rand() % 4;
			if (m == 0) { //��
				if (y > 1) {
					y -= distance;
					break;
				}
			}
			else if (m == 1) { //�Ʒ�
				if (x < 8) {
					x += distance;
					break;
				}
			}
			else if (m == 2) { //��
				if (x > 1) {
					x -= distance;
					break;
				}
			}
			else { //����
				if (y < 18) {
					y += distance;
					break;
				}
			}
		}
	}
};

class Food: public GameObject {
private:
	int fcnt;
public:
	Food() = default;
	Food(int x, int y, int dist) :GameObject(x, y, dist) {};
	char getShape() { return '@'; }
	void move() {
		fcnt = (fcnt + 1) % 5;
		if(fcnt==3||fcnt==4){
			srand((unsigned)time(NULL));
			while (true) {
				int f = rand() % 4;
				if (f == 0) { //��
					if (y != 0) {
						y -= distance;
						break;
					}
				}
				else if (f == 1) { //�Ʒ�
					if (x != 9) {
						x += distance;
						break;
					}
				}
				else if (f == 2) { //��
					if (x != 0) {
						x -= distance;
						break;
					}
				}
				else { //����
					if (y != 19) {
						y += distance;
						break;
					}
				}
			}
		}
	}
};

class Game {
private:
	string board[10][20];
	Human *h = new Human(0, 0, 1);
	Monster* m = new Monster(5, 5, 2);
	Food* f = new Food(9, 9, 1);
public:
	Game() {
		cout << "** Human�� Food �Ա� ������ �����մϴ�. **" << endl;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 20; j++)
				board[i][j] = "-";
	}
	~Game() {
		delete h;
		delete m;
		delete f;
	}
	void CurrentDel1() {
		board[h->getX()][h->getY()] = "-";
		board[m->getX()][m->getY()] = "-";
	}
	void CurrentDel2() {
		board[f->getX()][f->getY()] = "-";
	}
	void XY() {
		board[h->getX()][h->getY()] = h->getShape();
		board[m->getX()][m->getY()] = m->getShape();
		board[f->getX()][f->getY()] = f->getShape();
	}
	void show() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++)
				cout << board[i][j];
			cout << endl;
		}
	}
	void game() {
		srand((unsigned)time(NULL));
		XY();
		show();
		while (true) {
			CurrentDel1();
			h->move();
			m->move();
			CurrentDel2();
			f->move();
			XY();
			show();
			if (h->collide(m)) {
				cout << "Human is Loser!!" << endl;
				break;
			}
			if (h->collide(f)) {
				cout << "Human is Winner!!" << endl;
				break;
			}
		}
	}
};

int main() {
	Game *g=new Game;
	g->game();
	delete g;
	return 0;
}