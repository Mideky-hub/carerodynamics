#pragma once

#include <cmath>
#include <stdexcept>

namespace estimation_test{
    double estimated_top_speed(double original_top_speed, double new_power, double original_power) noexcept {
        if (original_top_speed <= 0 || new_power <= 0 || original_power <= 0) {
            throw std::invalid_argument("Invalid input: original top speed, new power, or original power must be positive.");
        }

        return original_top_speed * std::cbrt(new_power / original_power);
    }

    double power_required(double original_power, double target_speed, double original_speed) noexcept {
        if (original_power <= 0 || target_speed <= 0 || original_speed <= 0) {
            throw std::invalid_argument("Invalid input: original power, target speed, or original speed must be positive.");
        }

        return original_power * pow(target_speed / original_speed, 3);
    }
}

namespace consumption{
    double propelling_force(double mass, double rolling_resistance, double aerodynamic_drag_force) noexcept {
        if (mass <= 0 || rolling_resistance <= 0) {
            throw std::invalid_argument("Invalid input: mass or rolling resistance must be positive.");
        }

        return mass * rolling_resistance + aerodynamic_drag_force;
    }

    double rv_propelling_force(double mass, double rolling_resistance, double aerodynamic_drag_force, double rv_drag_force) noexcept {
        if (mass <= 0 || rolling_resistance <= 0) {
            throw std::invalid_argument("Invalid input: mass or rolling resistance must be positive.");
        }

        return (1 / (1 + (mass*rolling_resistance/aerodynamic_drag_force))) * rv_drag_force;
    }

    
}