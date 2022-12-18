#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/*euclidean algorithm - tail-recursive implementation*/
unsigned long gcd_euclid_recursive(unsigned long a, unsigned long b){
    if (!b){    //base case
        return a;
    }
    return gcd_euclid_recursive(b, a % b);    //recursive case (tail recursion)
}

/*euclidean algorithm - iterative implementation*/
unsigned long gcd_euclid_iterative(unsigned long a, unsigned long b){
    while (b){
        int remainder_a_b = a % b;
        a = b;
        b = remainder_a_b;
    }

    return a;
}

/*collatz conjecture - tail recursive implementation*/
unsigned long collatz_recursive(int n, unsigned int n_iterations){
    if (!n_iterations || n == 1){
        return n;
    }
    unsigned long result;
    n % 2 == 0 ? result = collatz_recursive(n / 2, n_iterations - 1) : result = collatz_recursive(3 * n + 1, n_iterations - 1);
    return result;
}

/*collatz conjecture - iterative implementation*/
unsigned long int collatz_iterative(int n, unsigned int n_iterations){
    for (int i = 1; i <= n_iterations && n != 1; i += 1){
        n % 2 == 0 ? n /= 2 : n = 3 * n + 1;
    }

    return n;
}

/*naive primality test - skip even numbers, they cannot be prime (except for 2)*/
bool primality_test_1(unsigned long n){
    bool answer = true;
    if (n < 2){
        answer = false;
    }
    else if (n == 2){
        answer = true;
    }
    else{
        if (!(n % 2)){
            answer = false;
        }
        else{
            int candidate_divisor;
            for (candidate_divisor = 3; candidate_divisor < n && answer; candidate_divisor++){
                if (!(n % candidate_divisor)){
                    answer = false;
                }
            }
        }
    }

    return answer;
}

/*naive primality test
  optimization: if n is odd, it cannot have even divisors
  if it had even divisors, then it could have been divided by 2.
  It means that n would have been even. But we know it is odd.
*/
bool primality_test_2(unsigned long n){
    bool answer = true;
    if (n < 2){
        answer = false;
    }
    else if (n == 2){
        answer = true;
    }
    else{
        if (!(n % 2)){
            answer = false;
        }
        else{
            int candidate_divisor;
            for (candidate_divisor = 3; candidate_divisor < n && answer; candidate_divisor += 2){
                if (!(n % candidate_divisor)){
                    answer = false;
                }
            }
        }
    }

    return answer;
}

/*naive primality test
  optimization: take an odd natural number n.
  Will you even find a divisor that is greater than n / 2?
  No!
  E.g. you have to find the divisors of 51:
      3  divides          51
      5  does not divide  51
      7  does not divide  51
      9  does not divide  51
     11  does not divide  51
     13  does not divide  51
     15  does not divide  51
     17  divides          51
     19  does not divide  51
     21  does not divide  51
     23  does not divide  51
     25  does not divide  51

     Now: 25 is the lower integer half of 51.
     Trying to divide 51 by a number > 25 will be useless.
     If you divide a number by its half, you get 2.
     If you divide a number by a number greater that its half, you get less than 2.
*/
bool primality_test_3(unsigned long n){
    bool answer = true;
    if (n < 2){
        answer = false;
    }
    else if (n == 2){
        answer = true;
    }
    else{
        if (!(n % 2)){
            answer = false;
        }
        else{
            int candidate_divisor;
            for (candidate_divisor = 3; candidate_divisor <= n / 2 && answer; candidate_divisor += 2){
                if (!(n % candidate_divisor)){
                    answer = false;
                }
            }
        }
    }

    return answer;
}

/*naive primality test
  optimization: take an odd natural number n.
  If q1 divides n, then: n / q1 = q2, and n / q2 = q1
  If q1 does not divide n, then n / q1 does not divide n

  Suppose you have to find the divisors of 51:
      3* divides 51, then also 51 / 3 = 17* divides 51
      5* does not divide  51,  then also 51 / 5 = 10 does not divide 51
      7* does not divide  51,  then also 51 / 7 = 7 does not divide 51
      9  does not divide  51,  but we already knew that (see above, we didn't find it)

  Suppose you have to find the divisors of 36:
      1* divides 36 ---> 36 /  1 = 36* divides 36
      2* divides 36 ---> 36 /  2 = 18* divides 36
      3* divides 36 ---> 36 /  3 = 12* divides 36
      4* divides 36 ---> 36 /  4 =  9* divides 36
      5* does not divide 36 ---> 36 / 5 = 7* does not divide 36
      6* divides 36 ---> 36 / 6 = 6* divides 36
      7 does not divide 36, but we already knew that (see above)
      8 does not divide 36, but we already knew that (see above, we didn't find it)
      9 divides 36, but we already knew that (see above)

   So, to search for divisors of n, we can stop at the lower integer part of sqrt(n)
*/
bool primality_test_4(unsigned long n){
    bool answer = true;
    if (n < 2){
        answer = false;
    }
    else if (n == 2){
        answer = true;
    }
    else{
        if (!(n % 2)){
            answer = false;
        }
        else{
            int candidate_divisor;
            for (candidate_divisor = 3; candidate_divisor <= static_cast<int>(sqrt(n)) && answer; candidate_divisor += 2){
                if (!(n % candidate_divisor)){
                    answer = false;
                }
            }
        }
    }

    return answer;
}

long double leibniz_pi(unsigned int n_iterations){
    long double result = 0;
    int8_t sign = 1;
    long double numerator = 4, denominator = 1;

    for (unsigned int counter = 1; counter <= n_iterations; counter++){
        result += sign * numerator / denominator;
        denominator += 2;
        sign = -sign;
    }

    return result;
}


int main(int argc, char *argv[]){
    cout << "************************************************************************" << endl;
    unsigned long int a, b;
    cout << "enter two integer numbers to compute their gcd: " << endl;
    cout << "first number: ";
    cin >> a;
    cout << "second number: ";
    cin >> b;
    cout << "the greatest common divisor of " << a << " and " << b << ", computed recursively, is " << gcd_euclid_recursive(a, b) << endl;
    cout << "the greatest common divisor of " << a << " and " << b << ", computed iteratively, is " << gcd_euclid_iterative(a, b) << endl;
    cout << "************************************************************************" << endl;

    cout << "************************************************************************" << endl;
    unsigned long start_collatz;
    int iterations;
    cout << "enter a natural number to verify the Collatz conjecture: ";
    cin >> start_collatz;
    cout << "enter the number of iterations of the Collatz procedure: ";
    cin >> iterations;
    cout << "after " << iterations << " iterations at most, the recursive collatz procedure yielded " << collatz_recursive(start_collatz, iterations) << endl;
    cout << "after " << iterations << " iterations at most, the recursive collatz procedure yielded " << collatz_iterative(start_collatz, iterations) << endl;
    cout << "************************************************************************" << endl;

    cout << "************************************************************************" << endl;
    unsigned int l_iterations;
    cout << "enter the number of iterations of the Leibniz series: ";
    cin >> l_iterations;
    cout.precision(17);
    cout << leibniz_pi(l_iterations) << endl;
    cout << "************************************************************************" << endl;


    cout << "************************************************************************" << endl;
    char start_p_test;
    cout << "starting primality test on many, quite large, numbers? [y/n]: ";
    cin >> start_p_test;

    switch (start_p_test){
        case 'y':
        case 'Y':
            for (unsigned long long i = 2345645341; i < ULLONG_MAX; i += 2){
                string is_prime;
                if (primality_test_4(i)){
                    is_prime = "True";
                }
                else{
                    is_prime = "False";
                }
                cout << "primality test 4 on " << i << " yielded " << is_prime << endl;
                cout << endl;
            }
        break;
    }

    return 0;
}
