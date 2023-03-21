#include <iostream>
#include <climits>

using namespace std;

bool lte(int a, int b) {
    return a <= b;
}

bool gte(int a, int b) {
    return a >= b;
}

int extract_min_or_max(int arr[], int size, bool (*cmp) (int, int)) {
    int item = arr[1];
    for (int i = 1; i < size; i++) {
        if ((*cmp)(arr[i], item)) {
            item = arr[i];
        }
    }
    return item;
}

int main() {
    int array[12] = {1, 5, 106, 3, -1, 2, 106, 76, -65, 3, 5, 2};
    cout << extract_min_or_max(array, 12, &gte) << endl;
    cout << extract_min_or_max(array, 12, &lte) << endl;
}
