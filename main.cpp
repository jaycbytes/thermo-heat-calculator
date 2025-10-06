#include "config.h"
#include "heatCalculator.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  // TODO: Make loop for multiple calculations
  // TODO: Consider adding argument parser

  // create or load config. Constructor should be all needed, extra
  // parameterized one just in case
  config heatConfig = config();

  // start calculator loop

  // exit and save config
  /*
    *
  std::cout
      << "Enter substance to calculate heat for from the following list\n";
  for (auto i : substances) {
    std::cout << i << '\n';
  }
  std::string fluidChoice;
  std::cin >> fluidChoice;

  std::cout << "Now enter your delta temp: ";
  double dTemp;
  std::cin >> dTemp;

  std::string phaseChoice;
  std::cout << "Now enter phase from the following list: \n";
  for (auto i : waterConstants) {
    std::cout << i.first << '\n';
  }
  std::cin >> phaseChoice;

  std::cout << "Finally enter mass: ";
  double mass;
  std::cin >> mass;

  heatCalc hCalc = heatCalc(fluidChoice, phaseChoice);
  double heatResult = hCalc.calcSpecificHeat(dTemp, mass, phaseChoice);
  std::cout << "Your heat result is: " << heatResult;
    */

  return 0;
}
