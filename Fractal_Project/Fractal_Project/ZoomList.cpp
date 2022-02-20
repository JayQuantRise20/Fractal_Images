//
//  ZoomList.cpp
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/26/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#include "ZoomList.hpp"
#include <iostream>

ZoomList::ZoomList( int width , int height): m_width(width) , m_height(height)
{
    
}

void ZoomList::Add( const Zoom& z) 
{
    list.push_back(z);
    m_xCenter += (z.x - m_width/2.0)* m_scale;
    m_yCenter += -(z.y - m_height/2.0)* m_scale;
    
    m_scale *= z.scale;
    
}

 std::pair<double,double> ZoomList::DoZoom(int x , int y)
{
    double xFractal = (x - m_width/2.0)* m_scale + m_xCenter;
    double yFractal = (y - m_height/2.0)* m_scale + m_yCenter;

    
    return std::pair<double,double>(xFractal,yFractal);
}
