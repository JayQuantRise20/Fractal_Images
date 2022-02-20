//
//  FractalCreator.hpp
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/28/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#ifndef FractalCreator_hpp
#define FractalCreator_hpp

#include <iostream>
#include <vector>
#include "Zoom.h"
#include "Mandelbrot.hpp"
#include <cmath>
#include "Bitmap.hpp"
#include "Zoom.h"
#include "ZoomList.hpp"
#include "RGB.hpp"

class FractalCreator
{
private:
    int m_width;
    int m_height;
    ZoomList m_zoomlist;
    Bitmap m_bitmap;
    int m_total{0};
    bool m_bGotFirstRange{false};
    std::unique_ptr<int[]> fractal;
    std::unique_ptr<int[]> Histogram;
    
    std::vector<RGB> colors;
    std::vector<int> ranges;
    std::vector<int> RangeTotals;
    
private:
    
    void calculateIterations();
    void calculateTotalIterations();
    void calculateTotalRanges();
    void DrawFractals();
    void WriteBitmap(std::string filename);
    
public:
    int getRange(int iterations) const;
    FractalCreator(int width, int height);
    void addRange( double rangeEnd, const RGB& rgb );
    void run(std::string filename);
    void AddZoom(const Zoom& zoom);

};
#endif /* FractalCreator_hpp */
