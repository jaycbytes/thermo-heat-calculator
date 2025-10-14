#include "config.h"
#include <string>
#include <unordered_map>
#include <vector>

const std::vector<std::string> substances = {"h2o"};

using thermalMap = std::unordered_map<std::string, double>;
const thermalMap waterConstants = {
    {"liquid", 4.18}, {"vapor", 2.00}, {"solid", 2.11}};

// Calculator object that should contain all the info it needs, functions
// that would be useful to user during main() cli portion.
class heatCalc {
public:
  heatCalc(config &configuration) : userConf{configuration} {};

  enum class UnitChange { CHANGE_SPEC_HEAT, CHANGE_LATENT_HEAT, CHANGE_ENERGY };

  enum class latentPhase { FUSION, VAPORIZATION };

  const std::unordered_map<latentPhase, double> latentConstants = {
      {heatCalc::latentPhase::FUSION, 3.34e5},
      {heatCalc::latentPhase::VAPORIZATION, 2.26e6}};

  // Form Response
  // TODO: Finish making templatel for all calculation responses
  std::string response();

  // Calculation methods

  double calcSpecificHeat(double deltaTemp, double mass, std::string &phase);

  double calcLatentHeat(double mass, latentPhase phaseType);

private:
  // store copy of the one config object for the calc
  config &userConf;

  // what context does this calc need?

  std::string substanceType;
  std::string phase;
  double mass;
};
