#include "heatCalculator.h"
#include <iostream>
#include <sstream>
#include <string>

//
double heatCalc::getQuantity() {
  std::string line;
  std::getline(std::cin, line);

  double quantity;
  std::istringstream iss(line);

  if (iss >> quantity) {
    return quantity;
  } else {
    std::cout << "Improper unit inputted. Must be an integer or decimal\n";
    return 0.0;
  }
}

void heatCalc::printOptions() {
  for (std::string option : options) {
    std::cout << option << '\n';
  }
}

void heatCalc::latentHeatMode() {
  double mass;
  std::cout << "Enter mass: ";
  mass = getQuantity();
  std::cout << "Enter which phase to calculate for: ";

  std::string phase;
  std::getline(std::cin, phase);

  double result = calcLatentHeat(mass, phase);
  std::cout << "Your result is: " << result << " " << userConf.latent_heat_unit
            << "\n";
}

void heatCalc::specificHeatMode() {
  double mass;
  std::cout << "Enter mass: ";
  mass = getQuantity();

  std::cout << "Enter change in temp: ";
  double temp;
  temp = getQuantity();

  std::cout << "Enter which phase to calculate for: ";
  std::string phase;
  std::getline(std::cin, phase);

  double result = calcSpecificHeat(temp, mass, phase);
  std::cout << "Your result is: " << result << " "
            << userConf.specific_heat_unit << "\n";
}

/* TODO: Better way of dynamically printing options available.
 *
 */
void heatCalc::Run() {
  bool running = true;
  Mode mode = heatCalc::Mode::CALCULATE;
  std::string userInput;

  std::cout << "Welcome to the specific and latent heat calculator.\n";
  std::cout << "To use this calculator, you can choose from the following: \n";

  printOptions();

  do {
    // user starts off in def mode which is calculate
    // request input
    std::cout << "Enter your choice of calculation: \n";
    std::getline(std::cin, userInput);
    char choice = userInput[0];
    switch (choice) {
    case 'q':
      running = false;
      break;
    case 's':
      specificHeatMode();
      break;
    case 'l':
      latentHeatMode();
      break;
    default:
      std::cout << "\nMake sure to enter one of the available options!\n\n";
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
