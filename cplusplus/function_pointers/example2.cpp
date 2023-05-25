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
    int item = arr[0];
    for (int i = 1; i < size; i++) {
        if ((*cmp)(arr[i], item)) {
            item = arr[i];
        }
    }
    return item;
}

int main() {
}
