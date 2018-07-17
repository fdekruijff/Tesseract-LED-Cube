///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file pulsing_cube.cpp
/// @brief pulsing cube class implementation

#include "pulsing_cube.hpp"
#include "cube.hpp"
#include "rectangle.hpp"
#include "vector.hpp"

/// @brief
/// Pulsing cube constructor instantiates a new pulsing cube object.
/// @details
/// Constructs a pulsing cube, switching frames based on frame delay. 
/// The frames are static defined in the draw function.
/// @param c : cube
/// @param frame_delay : int
pulsing_cube::pulsing_cube( const cube &c, int frame_delay ):
    animation( c, frame_delay, 0 )
{}

/// @brief
/// Draws the cube in the virtual cube.
/// @details
/// The draw method overrides the draw method of animation and sets the 
/// corresponding coordinates in the virtual cube.
/// This animation consists of 7 frames, each frame having a different kind of cube.
/// @param interrupt : pin_in
void pulsing_cube::draw( hwlib::pin_in &interrupt ) {
    c.set_brick(0);
    
    rectangle side1( c, 
        vector(0 + frame_count, 0 + frame_count, 0 + frame_count), 
        vector(7 - frame_count, 0 + frame_count, 7 - frame_count) 
    ); side1.draw();
    rectangle side2( c, 
        vector(7 - frame_count, 7 - frame_count, 0 + frame_count), 
        vector(0 + frame_count, 7 - frame_count, 7 - frame_count) 
    ); side2.draw();
    line line_1    ( c, 
        vector(0 + frame_count, 0 + frame_count, 0 + frame_count), 
        vector(0 + frame_count, 7 - frame_count, 0 + frame_count) 
    ); line_1.draw();
    line line_2    ( c, 
        vector(0 + frame_count, 0 + frame_count, 7 - frame_count), 
        vector(0 + frame_count, 7 - frame_count, 7 - frame_count) 
    ); line_2.draw();
    line line_3    ( c, 
        vector(7 - frame_count, 0 + frame_count, 7 - frame_count), 
        vector(7 - frame_count, 7 - frame_count, 7 - frame_count) 
    );  line_3.draw();
    line line_4    ( c, 
        vector(7 - frame_count, 0 + frame_count, 0 + frame_count), 
        vector(7 - frame_count, 7 - frame_count, 0 + frame_count) 
    );  line_4.draw();
    
    
    for ( int i = 0; i < frame_delay; i++ ) {
        c.show();
    }
    
    if (frame_count == 7) frame_count = 0;
    frame_count++;
}