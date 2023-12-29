#include <iostream>
#include <string>
using namespace std;

int pattern_match_bruteforce(const string& text, const string& pattern) {
  int match_index = -1;
  for (int i = 0; match_index == - 1 && i <= text.size() - pattern.size();
       i++) {
    bool found_match = true;
    for (int j = 0; j < pattern.size() && found_match; j++) {
      if (pattern.at(j) != text.at(i + j)) {
	found_match = false;
      }
    }
    if (found_match) {
      match_index = i;
    }
  }

  return match_index;
}

int main(int argc, char* argv[]) {
  string s1("hellohelloworld thisisa string");
  string s2(" thisis");
  cout << pattern_match_bruteforce(s1, s2) << endl;
}
