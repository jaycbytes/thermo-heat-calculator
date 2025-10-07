#include "config.h"

const std::unordered_map<config::units, std::string> config::unitMap = {
    // Specific Heat Capacity
    {config::units::J_PER_G_C, "J/(g·°C)"},
    {config::units::J_PER_KG_C, "J/(kg·°C)"},
    {config::units::KJ_PER_KG_C, "kJ/(kg·°C)"},
    {config::units::CAL_PER_G_C, "cal/(g·°C)"},

    // Latent Heat
    {config::units::J_PER_G, "J/g"},
    {config::units::KJ_PER_G, "kJ/g"},
    {config::units::J_PER_KG, "J/kg"},
    {config::units::KJ_PER_KG, "kJ/kg"},
    {config::units::CAL_PER_G, "cal/g"},

    // Energy
    {config::units::JOULES, "J"},
    {config::units::KILOJOULES, "kJ"},
    {config::units::CALORIES, "cal"}};
