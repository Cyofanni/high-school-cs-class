#include <iostream>

using namespace std;

int collatz_tail(int number, int iterations){
    cout << number << endl;
    if (iterations == 0){
        return number;
    }
    if (number % 2 == 0){
        return collatz_tail(number / 2, iterations - 1);
    }
    return collatz_tail(3 * number + 1, iterations - 1);
}

int main(){
    cout << collatz_tail(12, 12) << endl;

}
