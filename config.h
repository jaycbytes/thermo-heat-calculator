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

  std::string DEFAULT_CONFIG_LOCATION =
      "/Users/jabooty/.config/thermo-calc/config.ini";
  std::string CONFIG_LOCATION;

  std::string DEFUALT_PHASE = "solid";
  std::string DEFAULT_SUBSTANCE = "h2o";
  std::string specific_heat_unit;
  std::string latent_heat_unit;
  std::string energy_unit;

private:
  enum units {
    // Specific Heat Capacity
    J_PER_G_C,
    J_PER_KG_C,
    KJ_PER_KG_C,
    CAL_PER_G_C,

    // Latent Heat
    J_PER_G,
    KJ_PER_G,
    J_PER_KG,
    KJ_PER_KG,
    CAL_PER_G,

    // Energy
    JOULES,
    KILOJOULES,
    CALORIES
  };
  static const std::unordered_map<units, std::string> unitMap;
};
