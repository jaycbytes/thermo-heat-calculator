#include "config.h"

const std::unordered_map<config::specificHCUnits, std::string> specificHeatMap =
    {
        // Specific Heat Capacity
        {config::specificHCUnits::J_PER_G_C, "J/(g·°C)"},
        {config::specificHCUnits::J_PER_KG_C, "J/(kg·°C)"},
        {config::specificHCUnits::KJ_PER_KG_C, "kJ/(kg·°C)"},
        {config::specificHCUnits::CAL_PER_G_C, "cal/(g·°C)"},

};

const std::unordered_map<config::latentHUnits, std::string> latentHeatMap = {
    {config::latentHUnits::J_PER_G, "J/g"},
    {config::latentHUnits::KJ_PER_G, "kJ/g"},
    {config::latentHUnits::J_PER_KG, "J/kg"},
    {config::latentHUnits::KJ_PER_KG, "kJ/kg"},
    {config::latentHUnits::CAL_PER_G, "cal/g"},

};

const std::unordered_map<config::energyUnits, std::string> energyMap = {
    {config::energyUnits::JOULES, "J"},
    {config::energyUnits::KILOJOULES, "kJ"},
    {config::energyUnits::CALORIES, "cal"}};

bool config::setSpecificHUnits(config::specificHCUnits units) {
  auto it = specificHeatMap.find(units);
  if (it != specificHeatMap.end()) {
    specific_heat_unit = it->second;
    return true;
  } else {
    return false;
  }
};

bool config::setLatentUnits(config::latentHUnits units) {
  auto it = latentHeatMap.find(units);
  if (it != latentHeatMap.end()) {
    latent_heat_unit = it->second;
    return true;
  } else {
    return false;
  }
};
bool config::setEnergyUnits(config::energyUnits units) {

  auto it = energyMap.find(units);
  if (it != energyMap.end()) {
    energy_unit = it->second;
    return true;
  } else {
    return false;
  }
};
