#include <string>

class Vehicle {
private:
  std::string serial_number;
public:
  Vehicle(std::string);
  std::string get_serial_number();
};
