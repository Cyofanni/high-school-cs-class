#include <iostream>
#include "truck.h"

int main() {
  Truck t("abcde12345", 4500);
  std::cout << "truck's serial number is: " << t.get_serial_number() << std::endl;
  std::cout << "truck's max load (kg) is " << t.get_max_load_kg() << std::endl;
}
