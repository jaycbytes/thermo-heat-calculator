#include <string>
#include <unordered_map>

// TODO: CHECK TO SEE IF USER HS CONFIG WHERE EXPECTED, LOAD UNITS PREFERENCES
// FROM THERE
// TODO: Function that "saves" config settings and writes them, useful for when
// user changes settings while using the calculator

class config {
public:
  config() : CONFIG_LOCATION{DEFAULT_CONFIG_LOCATION} {};
  config(std::string &userLocation) : CONFIG_LOCATION{userLocation} {};
  // units

  enum class specificHCUnits {
    // Specific Heat Capacity
    J_PER_G_C,
    J_PER_KG_C,
    KJ_PER_KG_C,
    CAL_PER_G_C
  };

  enum class latentHUnits {
    // Latent Heat
    J_PER_G,
    KJ_PER_G,
    J_PER_KG,
    KJ_PER_KG,
    CAL_PER_G
  };

  enum class energyUnits {
    // Energy
    JOULES,
    KILOJOULES,
    CALORIES
  };

  // Set units

  bool setSpecificHUnits(specificHCUnits units);
  bool setLatentUnits(latentHUnits units);
  bool setEnergyUnits(energyUnits units);

  std::string DEFAULT_CONFIG_LOCATION =
      "/Users/jabooty/.config/thermo-calc/config.ini";
  std::string CONFIG_LOCATION;

  std::string DEFUALT_PHASE = "solid";
  std::string DEFAULT_SUBSTANCE = "h2o";
  // units used during runtime, strings b/c they'll be printed in terminal.
  std::string specific_heat_unit = "J/(g·°C)";
  std::string latent_heat_unit = "J/g";
  std::string energy_unit = "J";

private:
  static const std::unordered_map<specificHCUnits, std::string> specificHeatMap;
  static const std::unordered_map<latentHUnits, std::string> latentHeatMap;
  static const std::unordered_map<energyUnits, std::string> energyMap;
};
