#include "heatCalculator.h"

int main(int argc, char *argv[]) {
  // TODO: Make loop for multiple calculations
  // TODO: Consider adding argument parser
  // TODO: TRY BUILDING, FIX redefinition

  // create or load config. Constructor should be all needed, extra
  // parameterized one just in case
  config heatConfig = config();

  heatCalc calculator = heatCalc(heatConfig);
  // run calc until exit
  calculator.runCalc();
  return 0;
}
