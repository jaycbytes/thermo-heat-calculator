
# Simple Stupid Specific Heat Calculator

## Program Flow

1. Program begins and LOADS CONFIG either default or user set from
last session, those
configs are set and ready for first use of calculator.
2. Calculator cli begins, it can access the config units for proper printing of responses.
3. when user quits it will make sure to save units chosen.

## Notes

Enum class is more modern and better due to it not having scope issues within the same file for the terms.

## Purpose

This program will be able to calculate heat caused my change in temperature.
Specific heat will be assumed constant, variations due to temperature will not
be taken into account

## Specific Heat Capacity Constants Used

### Water Table

| Phase | Specific Heat Capacity (J/g*c)|
| ---| ---|
| liquid | 4.18|
| steam | 2.00|
| solid | 2.11|
| caca | 69420 |

## Configuration

A simple "config.ini" file is used to set the various options
listed below. This file can be found in the "~/.config/thermo-calc/" folder.



## Things I learned
Enum class is a safer approach to enum's that avoid naming conflicts.
Input sanitation is bet with getline() and sstream's. Instead of having
std::cin fail, that can be handled in a sstream.



