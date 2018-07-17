///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE.txt)

/// @file
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file rotating_plane.cpp
/// @brief rotating plane class implementation

#include "rotating_plane.hpp"
#include "cube.hpp"
#include "rectangle.hpp"
#include "vector.hpp"

/// @brief
/// Rotating plane constructor instantiates a new rotating plane object.
/// @details
/// Constructs a rotating plane, switching frames based on frame delay. 
/// The frames are static defined in the draw function.
/// @param c : cube
/// @param frame_delay : int
rotating_plane::rotating_plane( const cube &c, int frame_delay ):
    animation( c, frame_delay, 0 )
{}

/// @brief
/// Draws the rectangle in the virtual cube.
/// @details
/// The draw method overrides the draw method of animation and sets the 
/// corresponding coordinates in the virtual cube.
/// This animation consists of 16 frames, each frame having a different kind of rectangle.
/// @param interrupt : pin_in
void rotating_plane::draw( hwlib::pin_in &interrupt ) {
    c.set_brick(0);
    
//    if ( frame_count >= 0 && frame_count < 4 ) {
//        rectangle plane(c, vector(0, 0, 4-frame_count), vector(7, 7, 4+frame_count), 1);
//        plane.draw();
//    } else if ( frame_count >= 3 && frame_count < 12 ) {
//        rectangle plane(c, vector(0, frame_count-4, 0), vector(7, 12-frame_count, 7), 1);
//        plane.draw();
//    } else if ( frame_count >= 12 && frame_count < 16 ) {
//        rectangle plane(c, vector(0, 0, 19-frame_count), vector(7, 7, frame_count-12), 1);
//        plane.draw();
//    }

    
    
    for ( int i = 0; i < frame_delay; i++ ) c.show();
    if (frame_count == 15) frame_count = 1;
    
    frame_count++;
}