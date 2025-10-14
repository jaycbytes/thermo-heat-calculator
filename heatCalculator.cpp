#include "heatCalculator.h"
#include <iostream>

void heatCalc::latentHeatMode() {
  double mass;
  std::cout << "Enter mass: ";
  std::cin >> mass;

  std::cout << "Enter which phase to calculate for: ";
  std::string phase;
  std::cin >> phase;

  double result = calcLatentHeat(mass, phase);
  std::cout << "Your result is: " << result << " " << userConf.latent_heat_unit
            << "\n";
}

void heatCalc::specificHeatMode() {
  double mass;
  std::cout << "Enter mass: ";
  std::cin >> mass;

  std::cout << "Enter change in temp: ";
  double temp;
  std::cin >> temp;

  std::cout << "Enter which phase to calculate for: ";
  std::string phase;
  std::cin >> phase;
  double result = calcSpecificHeat(temp, mass, phase);
  std::cout << "Your result is: " << result << " "
            << userConf.specific_heat_unit << "\n";
}

void heatCalc::Run() {
  bool running = true;
  Mode mode = heatCalc::Mode::CALCULATE;
  char calcChoice;

  std::cout << "Welcome to the specific and latent heat calculator.\n";
  std::cout << "To use this calculator, you can choose from the following: \n";
  std::cout << "q - quit\ns - specific heat\n";

  do {
    // user starts off in def mode which is calculate
    // request input
    std::cout << "Enter your choice of calculation: \n";
    std::cin >> calcChoice;
    switch (calcChoice) {
    case 'q':
      running = false;
      break;
    case 's':
      specificHeatMode();
      break;
    case 'l':
      latentHeatMode();
    default:
      std::cout << "Make sure to enter one of the available options!\n";
    }
  } while (running);
}

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

double heatCalc::calcLatentHeat(double mass, std::string &phase) {
  // get latent heat value
  auto it = latentConstants.find(phase);
  if (it != latentConstants.end()) {
    double phaseConstant = it->second;
    return mass * phaseConstant;
  } else {
    std::cout
        << "Error: Latent constant for water at that phase wasn't found\n";
    return 0.0;
  }
};
