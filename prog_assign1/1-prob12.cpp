#include <iostream>
using namespace std;
#define MAX 100

int main(void) {
    int a[MAX];
    int size = 0;

    while (cin >> a[size] && a[size] != -1 && size < MAX)
        size++;

    int local_min = 0;
    if (a[0] <= a[1])
        local_min++;
    for (int i = 1; i < size; i++) {
        if (a[i] <= a[i - 1] && a[i] <= a[i + 1])
            local_min++;
    }
    if (a[size - 1] <= a[size - 2])
        local_min++;

    cout << local_min << endl;

    return 0;
}