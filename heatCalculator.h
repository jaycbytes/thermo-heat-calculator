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

  enum class Mode {
    CALCULATE,
    SETTINGS,
  };

  const std::unordered_map<std::string, double> latentConstants = {
      {"fusion", 3.34e5}, {"vaporization", 2.26e6}};

  // Form Response
  // TODO: Finish making templatel for all calculation responses
  std::string response();

  // Calculation methods

  double calcSpecificHeat(double deltaTemp, double mass, std::string &phase);

  double calcLatentHeat(double mass, std::string &phase);

  void Run();

private:
  // store copy of the one config object for the calc
  config &userConf;

  void specificHeatMode();
  void latentHeatMode();
  // what context does this calc need?

  std::string substanceType;
  std::string phase;
  double mass;
};
