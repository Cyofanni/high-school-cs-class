#include "truck.h"
#include <iostream>

Truck::Truck(std::string s, double m): Vehicle(s), max_load_kg(m) {
  std::cout << "called Truck constructor" << std::endl;
}

double Truck::get_max_load_kg() {
  return max_load_kg;
}
