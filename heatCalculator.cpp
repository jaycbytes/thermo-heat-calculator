#include "heatCalculator.h"
#include <iostream>

double heatCalc::calcSpecificHeat(double deltaTemp, double mass,
                                  std::string &phase) {
  // Q = mcT
  auto it = waterConstants.find(phase);
  if (it != waterConstants.end()) {
    double specificHeatCapacity = it->second;
    return mass * specificHeatCapacity * deltaTemp;
  } else {
    std::cout << "Error: Water constants weren't found\n";
    return 0.0;
  }
};
