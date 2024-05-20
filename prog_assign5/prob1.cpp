#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class OrderedVecInt {
private:
	int capacity = 0, size = 0; //capacity�� ���� �迭�� ����, size�� ����� ���� ����
	int* arr = nullptr; //���� �迭�� ���� �ּ�, ó������ ���̰� 0�� �迭
	
public:
	OrderedVecInt() = default;
	OrderedVecInt(int Ocapacity, int Osize) :capacity(Ocapacity), size(Osize) {}
	~OrderedVecInt() { delete[] arr; }

	int get_size() const{
		return size;
	}

	int& operator[](int idx) {
		return arr[idx];
	}

	void insert(int k) {
		
		if (size == capacity) {
			if (capacity == 0)
				capacity = 1;
			else
				capacity *= 2;
			/*ù��° ���Ұ� ���Եɶ� ���̸� 1�� �����,
			�� ���� ���ʹ� �ʿ�� ���̸� 2��� �ø���.*/
			
			int* tmp = new int[capacity];
			for (int i = 0; i < size; i++)
				tmp[i] = arr[i];

			delete[] arr;
			arr = tmp;
		}

		int newidx = 0;
		while (newidx < size && arr[newidx] < k)
			newidx++;

		for (int i = size; i > newidx; i--)
			arr[i] = arr[i - 1];

		arr[newidx] = k;
		size++;
	}

	bool remove_by_val(int k) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == k) {
				for (int j = i; j < size - 1; j++)
					arr[j] = arr[j + 1];
				size--;
				return true;
			}
		}
		return false;
	}

	bool remove_by_index(int idx) {
		if (idx<0 || idx>size)
			return false;
		for (int i = idx; i < size - 1; i++)
			arr[i] = arr[i + 1];
		size--;
		return true;
	}
};

int main() {
	srand((unsigned int)time(NULL));
	int n, k;
	OrderedVecInt vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k = rand() % 1000;
		vec.insert(k); //���� k�� �����Ѵ�. �������� ���ĵǾ� ����Ǿ�� �Ѵ�.
	}

	for (int i = 0; i < vec.get_size(); i++)
		cout << vec[i] << " "; //indexing������ []�� �����Ѵ�.
	cout << endl;

	if (vec.remove_by_val(vec[2])) //�Ű������� �־��� ������ ã�� �����Ѵ�.
		cout << "Remove done" << endl; //�׷� ���� �����ϸ� true
	else //�ƴϸ� false
		cout << "Remove failed" << endl;

	if (vec.remove_by_index(4)) //�Ű������� �־��� �ε��� ��ġ�� ������ �����Ѵ�.
		cout << "RemoveIndex done" << endl; //��ȿ�� �ε����� true
	else //�ƴϸ� false
		cout << "RemoveIndex failed" << endl;

	for (int i = 0; i < vec.get_size(); i++) //size()�� ����� ������ ������ ��ȯ�Ѵ�.
		vec[i] -= 10; //����� ������ ������ �� �ִ�. �� ��� ������ ��Ʈ���� �� �ִ�.

	for (int i = 0; i < vec.get_size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	return 0;
}