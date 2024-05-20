#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class OrderedVecInt {
private:
	int capacity = 0, size = 0; //capacity는 동적 배열의 길이, size는 저장된 정수 개수
	int* arr = nullptr; //동적 배열의 시작 주소, 처음에는 길이가 0인 배열
	
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
			/*첫번째 원소가 삽입될때 길이를 1로 만들고,
			그 다음 부터는 필요시 길이를 2배로 늘린다.*/
			
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
		vec.insert(k); //정수 k를 삽입한다. 정수들은 정렬되어 저장되어야 한다.
	}

	for (int i = 0; i < vec.get_size(); i++)
		cout << vec[i] << " "; //indexing연산자 []를 제공한다.
	cout << endl;

	if (vec.remove_by_val(vec[2])) //매개변수로 주어진 정수를 찾아 삭제한다.
		cout << "Remove done" << endl; //그런 값이 존재하면 true
	else //아니면 false
		cout << "Remove failed" << endl;

	if (vec.remove_by_index(4)) //매개변수로 주어진 인덱스 위치의 정수를 삭제한다.
		cout << "RemoveIndex done" << endl; //유효한 인덱스면 true
	else //아니면 false
		cout << "RemoveIndex failed" << endl;

	for (int i = 0; i < vec.get_size(); i++) //size()는 저장된 정수의 개수를 반환한다.
		vec[i] -= 10; //저장된 정수를 수정할 수 있다. 이 경우 정렬이 흐트러질 수 있다.

	for (int i = 0; i < vec.get_size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	return 0;
}