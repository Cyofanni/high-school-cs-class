#include "vehicle.h"

class Truck: public Vehicle {
private:
  double max_load_kg;
public:
  Truck(std::string, double);
  double get_max_load_kg();
};
