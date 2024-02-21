#include "include/cfd.hpp"
#include <iostream>

// ressources :
// https://www.editions.polytechnique.fr/files/pdf/EXT_1332_5.pdf
// https://fr.wikipedia.org/wiki/A%C3%A9rodynamique_automobile

int main(void){
    std::cout << "Welcome to the Aerodynamics Calculator" << std::endl;
    std::cout << cfd_drag_coefficients(12.72, 1.225, 3, 0, 4.24, 0, 288.16, 2.8, 1.7894e-5, 1.4, 1400) << std::endl;
}