#include "vehicle.h"
#include <iostream>

Vehicle::Vehicle(std::string s): serial_number(s) {
  std::cout << "called Vehicle constructor" << std::endl;
}

std::string Vehicle::get_serial_number() {
  return serial_number;
}
