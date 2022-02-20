//
//  Zoom.h
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/26/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#ifndef Zoom_h
#define Zoom_h
#include <list>
//using tup = std::tuple<int>;
struct Zoom
{
    int x{0};
    int y{0};
    double scale{0.0};
    
    Zoom(int x, int y , double scale): x(x), y(y) , scale(scale) {}
    
    
};


#endif /* Zoom_h */

