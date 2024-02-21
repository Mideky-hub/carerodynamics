#pragma once

#include <cmath>
#include <vector>
#include <stdexcept>


namespace liftforce{
    namespace base{
        double lift_force(double& density, double& speed, double& reference_area, double& lift_coefficient) noexcept {
            if (density <= 0 || reference_area <= 0 || lift_coefficient <= 0) {
                throw std::invalid_argument("Invalid input: density, reference_area, or lift coefficient must be positive.");
            }

            return 0.5 * density * pow(speed, 2) * reference_area * lift_coefficient;
        }

        double average_lift_force(const std::vector<double>& speeds, double& density, double& reference_area, double& lift_coefficient) noexcept {
            if (density <= 0 || reference_area <= 0 || lift_coefficient <= 0) {
                throw std::invalid_argument("Invalid input: density, reference_area, or lift coefficient must be positive.");
            }

            double total_squared_speed = 0.0;
            for (double speed : speeds) {
                total_squared_speed += speed * speed;
            }

            double average_speed = std::sqrt(total_squared_speed / speeds.size());

            return lift_force(density, average_speed, reference_area, lift_coefficient);
        }

        double lift_coefficient(double lift_force, double density, double reference_area, double speed) noexcept {
            if (lift_force <= 0 || density <= 0 || reference_area <= 0 || speed <= 0) {
                throw std::invalid_argument("Invalid input: lift force, density, reference area, or speed must be positive.");
            }

            double dynamic_pressure = 0.5 * density * pow(speed, 2);
            return lift_force / (dynamic_pressure * reference_area);
        }
    }   // namespace base    
    namespace lateral{
        double lateral_lift_force(double& density, double& speed, double& reference_area, double& lateral_lift_coefficient) noexcept {
            if (density <= 0 || reference_area <= 0 || lateral_lift_coefficient <= 0) {
                throw std::invalid_argument("Invalid input: density, reference_area, or lift coefficient must be positive.");
            }

            return 0.5 * density * pow(speed, 2) * reference_area * lateral_lift_coefficient;
        }

        double average_lateral_lift_force(const std::vector<double>& speeds, double& density, double& reference_area, double& lateral_lift_coefficient) noexcept {
            if (density <= 0 || reference_area <= 0 || lateral_lift_coefficient <= 0) {
                throw std::invalid_argument("Invalid input: density, reference_area, or lift coefficient must be positive.");
            }

            double total_squared_speed = 0.0;
            for (double speed : speeds) {
                total_squared_speed += speed * speed;
            }

            double average_speed = std::sqrt(total_squared_speed / speeds.size());

            return lateral::lateral_lift_force(density, average_speed, reference_area, lateral_lift_coefficient);
        }
        
        double lateral_lift_coefficient(double lift_force, double density, double reference_area, double speed) noexcept {
            if (lift_force <= 0 || density <= 0 || reference_area <= 0 || speed <= 0) {
                throw std::invalid_argument("Invalid input: lift force, density, reference area, or speed must be positive.");
            }

            double dynamic_pressure = 0.5 * density * pow(speed, 2);
            return lift_force / (dynamic_pressure * reference_area);
        }
    }   // namespace lateral
}   // namespace liftforce
