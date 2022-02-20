//
//  ZoomList.hpp
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/26/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#ifndef ZoomList_hpp
#define ZoomList_hpp
#include "Zoom.h"
#include <stdio.h>
#include <tuple>


class ZoomList
{
private:
    double m_xCenter{0};
    double m_yCenter{0};
    double m_scale{1.0};
    int m_width;
    int m_height;
    std::list<Zoom> list;
public:
    ZoomList( int width , int height);
    void Add( const Zoom& z);
    std::pair<double,double> DoZoom( int x , int y);
    
};


#endif /* ZoomList_hpp */
