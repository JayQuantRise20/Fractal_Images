//
//  main.cpp
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/22/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//
#include <iostream>
#include "Zoom.h"
#include "FractalCreator.hpp"
#include <vector>

int main() {
    
    
    FractalCreator fractalCreator(800,600);
    
    fractalCreator.addRange(0.0, RGB(100, 200, 255));
    fractalCreator.addRange(0.05, RGB(255, 200, 71));
    fractalCreator.addRange(0.08, RGB(255, 215, 0));
    fractalCreator.addRange(1.0, RGB(100, 255, 255));

    
    fractalCreator.AddZoom(Zoom(295, 202, 0.1));
    fractalCreator.AddZoom(Zoom(312, 304, 0.1));
    fractalCreator.run("test_1.bmp");
    
    std::cout << "finished" << std::endl;
    return 0;
}
