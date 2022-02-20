//
//  Bitmap.hpp
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/23/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#ifndef Bitmap_hpp
#define Bitmap_hpp
#include <iostream>
#include <fstream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

class Bitmap
{
private:
    int m_width{0};
    int m_height{0};
    std::unique_ptr<uint8_t[]> m_pPixels{nullptr};
public:
    Bitmap() {}
    Bitmap(int width, int height);
     void setPixel(int x, int y, uint8_t red, uint8_t green , uint8_t blue);
    bool write(std::string filename);
    virtual ~Bitmap();
    
};

#include <stdio.h>

#endif /* Bitmap_hpp */
