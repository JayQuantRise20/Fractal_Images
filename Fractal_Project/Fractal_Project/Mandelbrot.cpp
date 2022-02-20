//
//  Mandelbrot.cpp
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/25/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#include "Mandelbrot.hpp"
#include <complex>
#include <cmath>


int Mandelbrot::getIterations(double x, double y)
{
    std::complex<double> c(x,y);
    std::complex<double> z(0,0);
    
    int iterations = 0;
    
    while ( iterations < MAX_ITERATIONS) {
    
        z = z*z + c;
        if( std::norm(z) > 2)
        { break; }
        
        iterations++;
    }
    
    return iterations;
}
