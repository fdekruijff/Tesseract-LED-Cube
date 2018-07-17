///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file line.cpp
/// @brief cube class implementation

#include "line.hpp"
#include "vector.hpp"
#include <cmath>
#include <algorithm>

/// @brief
/// Line constructor instantiates a new line object.
/// @details
/// Line is a child of animation and passes the cube object to the animation constructor.
/// It also sets the start and end vector for this line.
line::line( const cube &c, vector start, vector end ): 
    animation( c ), start( start ), end( end )
{}

/// @brief
/// Bresenham's 3D Line Drawing Algorithm
/// @details
/// This 3D line drawing algorithm is based off Bresenham's and found here: http://members.chello.at/easyfilter/bresenham.c
/// @param interrupt : pin_in
void line::draw( hwlib::pin_in &interrupt ) {
    int x0 = start.x;
    int y0 = start.y;
    int z0 = start.z;
    int x1 = end.x;
    int y1 = end.y ;
    int z1 = end.z;
    
    int dx = abs(x1-x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0 < y1 ? 1 : -1;
    int dz = abs(z1-z0), sz = z0 < z1 ? 1 : -1;
    int dm = dx > dy && dx > dz ? dx : dy > dz ? dy : dz, i = dm;
    x1 = y1 = z1 = dm / 2;

    for (;;) {
        c.set_coordinate(vector(x0,y0,z0), 1);
        if (i-- == 0) break;
        x1 -= dx; if (x1 < 0) { x1 += dm; x0 += sx; }
        y1 -= dy; if (y1 < 0) { y1 += dm; y0 += sy; }
        z1 -= dz; if (z1 < 0) { z1 += dm; z0 += sz; }
    }
}