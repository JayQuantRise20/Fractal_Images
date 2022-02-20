//
//  BitmaoHeaderFile.h
//  Fractal_Project
//
//  Created by Javad Gholizadeh on 9/22/19.
//  Copyright © 2019 Javad Gholizadeh. All rights reserved.
//

#ifndef BitmapFileHeader_h
#define BitmapFileHeader_h
#pragma pack(2)

struct BitmapFileHeader
{
    char header [2]{'B' ,'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
    
};

#endif /* BitmaoHeaderFile_h */
