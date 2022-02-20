//
//  RGB.hpp
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/29/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#ifndef RGB_hpp
#define RGB_hpp

#include <stdio.h>

struct RGB
{
    double m_red;
    double m_green;
    double m_blue;
    RGB(double red, double green , double blue);
    
    friend RGB operator -( const RGB& rgb1 , const RGB& rgb2);

};

//RGB operator -( const RGB& rgb1 , const RGB& rgb2);


#endif /* RGB_hpp */
