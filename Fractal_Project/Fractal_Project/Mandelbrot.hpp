//
//  Mandelbrot.hpp
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/25/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#ifndef Mandelbrot_hpp
#define Mandelbrot_hpp

#include <stdio.h>

class Mandelbrot
{
public:
    static const int MAX_ITERATIONS = 1000;
public:
    static int getIterations(double x, double y);
    
};

#endif /* Mandelbrot_hpp */
