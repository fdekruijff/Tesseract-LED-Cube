///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE.txt)

/// @file
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file rectangle.cpp
/// @brief rectangle class implementation

#include "rectangle.hpp"
#include "vector.hpp"

/// @brief
/// Rectangle constructor instantiates a new rectangle object.
/// @details
/// Rectangle is a child of animation and consists of a start and end vector, either in 2D of 3D space. 
/// With an optional filled parameter.
/// @param c : cube
/// @param start : vector
/// @param end : vector
/// @param filled : bool
rectangle::rectangle( const cube &c, vector start, vector end, bool filled ):
    animation( c ),
    start( start ),
    end( end ),
    left  ( c, vector( end.x  , start.y, start.z ), vector( end.x  , end.y  , end.z   ) ),
    right ( c, vector( start.x, start.y, start.z ), vector( start.x, end.y  , end.z   ) ),
    top   ( c, vector( start.x, end.y  , end.z   ), vector( end.x  , end.y  , end.z   ) ),
    bottom( c, vector( start.x, start.y, start.z ), vector( end.x  , start.y, start.z ) ),
    filled( filled )
{}

/// @brief
/// Draws the rectangle in the virtual cube.
/// @details
/// The draw method overrides the draw method of animation and sets the 
/// corresponding coordinates in the virtual cube.
/// @param interrupt : pin_in
void rectangle::draw( hwlib::pin_in &interrupt ) {
    if ( !filled ) {
        left.draw();
        right.draw();
        top.draw();
        bottom.draw();
    } else {
       for ( int x = start.x; x <= end.x; x++ ) {
           line l( c, vector( end.x - x  , start.y, start.z), vector( end.x - x  , end.y  , end.z) );
           l.draw();
       } 
    }
}