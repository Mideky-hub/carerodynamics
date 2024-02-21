#pragma once

#include <cmath>
#include <vector>
#include <stdexcept>

namespace dragforce{
    double aerodynamic_drag_force(double& density, double& speed, double&reference_area, double& drag_coefficient) noexcept {
        if (density <= 0 || reference_area <= 0 || drag_coefficient <= 0) {
            throw std::invalid_argument("Invalid input: density, reference_area, or drag coefficient must be positive.");
        }

        return 0.5 * density * pow(speed, 2) * reference_area * drag_coefficient;
    }

    double average_aerodynamic_drag_force(const std::vector<double>& speeds, double& density, double& reference_area, double& drag_coefficient) noexcept {
        if (density <= 0 || reference_area <= 0 || drag_coefficient <= 0) {
            throw std::invalid_argument("Invalid input: density, reference_area, or drag coefficient must be positive.");
        }

        double total_squared_speed = 0.0;
        for (double speed : speeds) {
            total_squared_speed += speed * speed;
        }

        double average_speed = std::sqrt(total_squared_speed / speeds.size());

        return aerodynamic_drag_force(density, average_speed, reference_area, drag_coefficient);
    }

    double drag_coefficient(double& drag_force, double& density, double& speed, double& reference_area) noexcept {
        if (drag_force <= 0 || density <= 0 || speed <= 0 || reference_area <= 0) {
            throw std::invalid_argument("Invalid input: drag force, density, speed, or reference area must be positive.");
        }

        return 2 * drag_force / (density * pow(speed, 2) * reference_area);
    }
}