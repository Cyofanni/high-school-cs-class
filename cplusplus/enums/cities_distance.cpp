#include <iostream>
using namespace std;

enum CITIES {new_york, boston, chicago, san_francisco};

double distances[4][4] = {
                                {-1, 232.2, 789.9, 2901.6},
                                {232.2, -1, 983.1, 3094.8},
                                {789.9, 983.1, -1, 2127.3},
                                {2901.6, 3094.8, 2127.3, -1}
                         };

int main() {
    cout << "New York -> New York: " << distances[new_york][new_york]
                                           << " mi " << endl;
    cout << "New York -> Boston: " << distances[new_york][boston]
                                           << " mi " << endl;
    cout << "New York -> Chicago: " << distances[new_york][chicago]
                                           << " mi " << endl;
    cout << "New York -> San Francisco: " << distances[new_york][san_francisco]
                                           << " mi " << endl;

    cout << "Boston -> New York: " << distances[boston][new_york]
                                           << " mi " << endl;
    cout << "Boston -> Boston: " << distances[boston][boston]
                                           << " mi " << endl;
    cout << "Boston -> Chicago: " << distances[boston][chicago]
                                           << " mi " << endl;
    cout << "Boston -> San Francisco: " << distances[boston][san_francisco]
                                           << " mi " << endl;

    cout << "Chicago -> New York: " << distances[chicago][new_york]
                                           << " mi " << endl;
    cout << "Chicago -> Boston: " << distances[chicago][boston]
                                           << " mi " << endl;
    cout << "Chicago -> Chicago: " << distances[chicago][chicago]
                                           << " mi " << endl;
    cout << "Chicago -> San Francisco: " << distances[chicago][san_francisco]
                                               << " mi " << endl;

    cout << "San Francisco -> New York: " << distances[san_francisco][new_york]
                                               << " mi " << endl;
    cout << "San Francisco -> Boston: " << distances[san_francisco][boston]
                                               << " mi " << endl;
    cout << "San Francisco -> Chicago: " << distances[san_francisco][chicago]
                                               << " mi " << endl;
    cout << "San Francisco -> San Francisco: " << distances[san_francisco][san_francisco]
                                               << " mi" << endl;
}
