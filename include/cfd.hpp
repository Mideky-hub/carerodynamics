#pragma once

#include <cmath>
#include <vector>
#include <stdexcept>

// The goal of CFD is to simulate the interaction of liquids and gases with surfaces defined by boundary conditions.

double cfd_drag_coefficients(double reference_area, double density, double depth,
                             double enthalpy, double length, double pressure,
                             double temperature, double velocity, double viscosity,
                             double ratio_of_specific_heats, int iteration) noexcept
{   // source: https://en.wikipedia.org/wiki/Drag_coefficient
    double drag_coefficient = 0.0;

    for (int i = 0; i < iteration; i++)
    {
        double reynolds_number = (density * velocity * length) / viscosity;
        double mach_number = velocity / std::sqrt(ratio_of_specific_heats * pressure / density);
        double prandtl_number = viscosity / (ratio_of_specific_heats * pressure);

        if (reynolds_number < 1e3)
        {
            drag_coefficient = 24 / reynolds_number;
        }
        else if (reynolds_number < 3e5)
        {
            drag_coefficient = 0.5;
        }
        else if (reynolds_number < 2e6)
        {
            drag_coefficient = 0.2;
        }
        else
        {
            drag_coefficient = 0.1;
        }
    }

    return drag_coefficient;
}