#include <string>
#include <unordered_map>

class config {
public:
  config() : CONFIG_LOCATION{DEFAULT_CONFIG_LOCATION} {};
  config(std::string &userLocation) : CONFIG_LOCATION{userLocation} {};
  // units

private:
  std::string DEFAULT_CONFIG_LOCATION =
      "/Users/jabooty/.config/thermo-calc/config.ini";
  std::string CONFIG_LOCATION;
  std::string specific_heat_unit;
  std::string latent_heat_unit;
  std::string energy_unit;

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
