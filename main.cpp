#include "heatCalculator.h"

int main(int argc, char *argv[]) {
  // TODO: Consider adding argument parser
  // TODO: TRY BUILDING, FIX redefinition

  // create or load config. Constructor should be all needed, extra
  // parameterized one just in case
  config heatConfig = config();

  // heat calc HAS-A configuration, which is why we save a reference to it,
  // and use inheritence
  heatCalc calculator = heatCalc(heatConfig);
  //
  // run calc until exit
  calculator.Run();
  return 0;
}
