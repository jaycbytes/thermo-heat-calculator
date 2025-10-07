#include "config.h"
#include <string>
#include <unordered_map>
#include <vector>
/* How will the class be used?
 * heatCalc() object will be created for each type of material
   TODO : map with objects make it const
 * TODO: Figure out how to store constants, consider that you don't want to have
 * the ununsed constants in memory if not required.
 */

const std::vector<std::string> substances = {"h2o"};

using thermalMap = std::unordered_map<std::string, double>;
const thermalMap waterConstants = {
    {"liquid", 4.18}, {"vapor", 2.00}, {"solid", 2.11}};

// Main calculator class required to start application
class heatCalc {
public:
  // Constructor is a function called at initialization of class
  // must have fluid type, no point of a heatCalc that doesn't know what
  // constants to use
  heatCalc(config &configuration) : userConf{configuration} {};

  void saveCustomConfig();

  // Get list of constants that will be used for these calculations
  std::string constantsUsed();

  double calcSpecificHeat(double deltaTemp, double mass, std::string &phase);

  double calcLatentHeat(double mass);

  void runCalc();

private:
  // store copy of the one config object for the calc
  config &userConf;
  // what context does this calc need?
  std::string substanceType;
  std::string phase;
  double mass;
};
