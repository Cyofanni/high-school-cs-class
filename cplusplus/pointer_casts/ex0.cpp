#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a = 65235125;
    int *p = &a;
    cout << p << '\t' << p + 1 << '\t' << p + 2
              << '\t' << p + 3 << '\n';

    char *p_cast = (char*)p;
    cout << (void*)p_cast << '\t' << (void*)(p_cast + 1)
         << '\t' << (void*)(p_cast + 2)
              << '\t' << (void*)(p_cast + 3) << '\n';
    printf("0-th Most Significant Byte: 0x%02X\n", (uint8_t)*p_cast);
    printf("1-th Most Significant Byte: 0x%02X\n", (uint8_t)*(p_cast + 1));
    printf("2-th Most Significant Byte: 0x%02X\n", (uint8_t)*(p_cast + 2));
    printf("3-th Most Significant Byte: 0x%02X\n", (uint8_t)*(p_cast + 3));
}
