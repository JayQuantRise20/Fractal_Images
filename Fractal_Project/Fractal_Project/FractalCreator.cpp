//
//  FractalCreator.cpp
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/28/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#include "FractalCreator.hpp"

void FractalCreator::run(std::string filename)
{
    
    calculateIterations();
    calculateTotalIterations();
    calculateTotalRanges();
    DrawFractals();
    WriteBitmap(filename);
    
}

FractalCreator::FractalCreator(int width, int height):m_width(width) , m_height(height), m_zoomlist(m_width, m_height),
m_bitmap(m_width, m_height), fractal( new int[m_width*m_height]{0}), Histogram(new int[Mandelbrot::MAX_ITERATIONS]{0})

{
    
    m_zoomlist.Add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));

}

void FractalCreator::addRange(double rangeEnd , const RGB& rgb)
{
    ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS );
    colors.push_back(rgb);
    
    if(m_bGotFirstRange)
    {
        RangeTotals.push_back(0);
    }
    
    m_bGotFirstRange = true;
}

void FractalCreator::calculateIterations()
{
    
    for (int x =0 ; x< m_width ; ++x)
    {
        for(int y = 0 ; y < m_height ; ++y)
        {
            
            std::pair<double,double> coords = m_zoomlist.DoZoom(x,y);
            int iterations = Mandelbrot::getIterations(coords.first,coords.second);
            fractal[y*m_width + x] = iterations;
            if(iterations != Mandelbrot::MAX_ITERATIONS){
                Histogram[iterations]++;}
        }
    }
    
}
void FractalCreator::calculateTotalRanges()
{
    int rangeindex = 0;
    for (int j = 0 ; j <= Mandelbrot::MAX_ITERATIONS ; ++j){
        int pixels = Histogram[j];
        if (j >= ranges[rangeindex + 1])
        { rangeindex++;}
            RangeTotals[rangeindex] += pixels;
        }
    
}

int FractalCreator::getRange(int iterations) const {
    int range =0;
    for ( int i = 1 ; i < ranges.size(); ++i ){
        range = i;
        if (ranges[i] >= iterations ){ break;}

        
    }
    range--;
    
    assert(range > -1);
    assert( range < ranges.size());
    return range;
}


void FractalCreator::calculateTotalIterations()
{
    for (int i = 0; i <  Mandelbrot::MAX_ITERATIONS ; ++i){
        m_total += Histogram[i];
    }

}


void FractalCreator::DrawFractals()
{
    
    
    
    for (int x =0 ; x < m_width ; ++x)
    {
        for(int y = 0 ; y < m_height ; ++y)
        {
            
            int iterations = fractal[y*m_width + x];
            
            int range = getRange(iterations);
            int rangeTotal = RangeTotals[range];
            int rangeStart = ranges[range];
            
            RGB& startcolor = colors[range];
            RGB& endcolor = colors[range + 1];
            RGB colordiff = endcolor - startcolor;
            
            uint8_t red = 0;
            uint8_t green = 0.0;
            uint8_t blue = 0;
            
            
            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                
                int totalPixels = 0;
                for( int i = rangeStart ; i <= iterations ; ++i ){
                    
                    totalPixels += Histogram[i];
                }
                red = startcolor.m_red +   colordiff.m_red * (double)totalPixels/rangeTotal;
                green = startcolor.m_green + colordiff.m_green * (double)totalPixels/rangeTotal;
                blue = startcolor.m_blue + colordiff.m_blue * (double)totalPixels/rangeTotal;

            }
            m_bitmap.setPixel(x,y,red,green,blue);
        }
    }
    
}



void FractalCreator::WriteBitmap(std::string filename)
{
    m_bitmap.write("test.bmp");

}
void FractalCreator::AddZoom(const Zoom& zoom)
{
    m_zoomlist.Add(zoom);

}


