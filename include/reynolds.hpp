#pragma once

#include <cmath>
#include <stdexcept>

namespace reynolds{
    double reynolds_number(double& density, double& speed, double& characteristic_length, double& dynamic_viscosity) noexcept {
        if (density <= 0 || characteristic_length <= 0 || dynamic_viscosity <= 0) {
            throw std::invalid_argument("Invalid input: density, characteristic length, or dynamic viscosity must be positive.");
        }

        return (density * speed * characteristic_length) / dynamic_viscosity;
    }

    double reynolds_number(double& density, double& speed, double& characteristic_length, double& dynamic_viscosity, double& kinematic_viscosity) noexcept {
        if (density <= 0 || characteristic_length <= 0 || kinematic_viscosity <= 0) {
            throw std::invalid_argument("Invalid input: density, characteristic length, or kinematic viscosity must be positive.");
        }

        return (speed * characteristic_length) / kinematic_viscosity;
    }
}