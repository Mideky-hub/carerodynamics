#pragma once

#include <stdexcept>

#define AIR_DENSITY 1.225
#define GRAVITY 9.81

namespace components{
    double reference_area(double height, double width, double fill_factor) {
        if (height <= 0 || width <= 0 || fill_factor <= 0 || fill_factor > 1) {
            throw std::invalid_argument("Invalid input: height, width, or fill factor must be positive.");
        }

        return height * width * fill_factor;
    }
}