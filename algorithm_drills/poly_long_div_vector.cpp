#include <iostream>
#include <vector>

using namespace std;

void print_poly(const vector<double>& poly) {
  int deg = poly.size() - 1;
  for (auto coeff : poly) {
    cout << coeff << "x^" << deg;
    if (deg > 0) {
      cout << " + ";
    }
    deg--;
  }
  cout << endl;
}

vector<double> poly_times_scalar(const vector<double>& poly,
				 double scalar) {
  vector<double> res(poly.size());
  for (int i = 0; i < poly.size(); i++) {
    res.at(i) = poly.at(i) * scalar;
  }

  return res;
}

vector<double> poly_diff(const vector<double>& p1,
			 const vector<double>& p2) {
  vector<double> res(p1.size());
  for (int i = 0; i < p1.size(); i++) {
    res.at(i) = p1.at(i) - p2.at(i);
  }

  return res;
}

void poly_long_div(const vector<double>& divd,
		   const vector<double>& divs) {
  vector<double> partial(divs.size());
  vector<double> quotient;
  for (int i = 0; i < divs.size(); i++) {
    partial.at(i) = divd.at(i);
  }

  for (int i = 0; i <= divd.size() - divs.size() - 1; i++) {
    double q = partial.at(0) / divs.at(0);
    quotient.push_back(q);
    vector<double> q_times_divs = poly_times_scalar(divs, q);
    partial = poly_diff(partial, q_times_divs);
    partial.erase(partial.begin());
    partial.push_back(divd.at(i + divs.size()));
  }
  double q = partial.at(0) / divs.at(0);
  quotient.push_back(q);
  vector<double> q_times_divs = poly_times_scalar(divs, q);
  partial = poly_diff(partial, q_times_divs);
  partial.erase(partial.begin());

  cout << "dividend:" << endl;
  print_poly(divd);
  cout << endl;
  cout << "divisor:" << endl;
  print_poly(divs);
  cout << endl;
  cout << "quotient:" << endl;
  print_poly(quotient);
  cout << endl;
  cout << "remainder:" << endl;
  print_poly(partial);
}

int main(int argc, char* argv[]) {
  vector<double> divd = {6, 5, 0, 4, -4};
  vector<double> divs = {2, 1, -1};
  poly_long_div(divd, divs);
}
