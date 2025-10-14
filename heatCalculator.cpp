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

double heatCalc::calcLatentHeat(double mass, heatCalc::latentPhase phaseType) {
  // get latent heat value
  auto it = latentConstants.find(phaseType);
  if (it != latentConstants.end()) {
    double phaseConstant = it->second;
    return mass * phaseConstant;
  } else {
    std::cout
        << "Error: Latent constant for water at that phase wasn't found\n";
    return 0.0;
  }
};
