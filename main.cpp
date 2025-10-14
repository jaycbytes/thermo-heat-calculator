#include "heatCalculator.h"
#include <iostream>

// TODO: Make loop for multiple calculations
void runCalculator(heatCalc &calc, config settings) {
  // Calculator modes that we're in
  enum Mode {
    CALCULATE,
    SETTINGS,
  };

  // Needs to run until user quits
  bool running = true;
  Mode mode = CALCULATE;
  char calcChoice;

  std::cout << "Welcome to the specific and latent heat calculator.\n";
  std::cout << "To use this calculator, you choose which type of calculation "
               "you'd like to do.";
  do {
    // user starts off in def mode which is calculate
    // request input
    std::cout << "Enter the type of calculation: ";
    std::cin >> calcChoice;
    switch (calcChoice) {
    case 'q':
      running = false;
      break;
    case 's':
      double mass;
      std::cout << "Enter mass: ";
      std::cin >> mass;

      std::cout << "Enter change in temp: ";
      double temp;
      std::cin >> temp;

      std::cout << "Enter which phase to calculate for: ";
      std::string phase;
      std::cin >> phase;
      config::specific_heat_unit unit = J_Per;
      double result = calc.calcSpecificHeat(temp, mass, phase);
      std::cout << "Your result is: " << result < < < < " " <<:
    }

    // print calculations

    //
  } while (running);
}

int main(int argc, char *argv[]) {
  // TODO: Consider adding argument parser
  // TODO: TRY BUILDING, FIX redefinition

  // create or load config. Constructor should be all needed, extra
  // parameterized one just in case
  config heatConfig = config();

  // heat calc HAS-A configuration, which is why we save a reference to it,
  // and use inheritence
  heatCalc calculator = heatCalc(heatConfig);

  // run calc until exit
  return 0;
}
