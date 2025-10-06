#include "config.h"

const std::unordered_map<config::units, const char *> config::unitMap = {
    // Specific Heat Capacity
    {J_PER_G_C, "J/(g·°C)"},
    {J_PER_KG_C, "J/(kg·°C)"},
    {KJ_PER_KG_C, "kJ/(kg·°C)"},
    {CAL_PER_G_C, "cal/(g·°C)"},

    // Latent Heat
    {J_PER_G, "J/g"},
    {KJ_PER_G, "kJ/g"},
    {J_PER_KG, "J/kg"},
    {KJ_PER_KG, "kJ/kg"},
    {CAL_PER_G, "cal/g"},

    // Energy
    {JOULES, "J"},
    {KILOJOULES, "kJ"},
    {CALORIES, "cal"}};
