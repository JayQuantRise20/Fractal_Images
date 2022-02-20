//
//  RGB.cpp
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/29/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#include "RGB.hpp"


RGB::RGB(double red, double green , double blue): m_red(red), m_green(green) , m_blue(blue)
{
    
}

RGB operator -( const RGB& rgb1 , const RGB& rgb2)
{
    
    RGB rgb( rgb1.m_red - rgb2.m_red ,rgb1.m_green - rgb2.m_green , rgb1.m_blue - rgb2.m_blue);
    
    return rgb;
}
