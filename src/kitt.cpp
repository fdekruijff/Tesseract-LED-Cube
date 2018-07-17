///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file kitt.cpp
/// @brief kitt class implementation

#include "kitt.hpp"
#include "cube.hpp"
#include "rectangle.hpp"
#include "vector.hpp"

/// @brief
/// Kitt constructor instantiates a new Kitt object.
/// @details
/// Constructs a Kitt, switching frames based on frame delay. 
/// The frames are static defined in the draw function.
/// @param c : cube
/// @param frame_delay : int
/// @param mode : char
kitt::kitt( const cube &c, int frame_delay, char mode ):
    animation( c, frame_delay ), mode( mode ) {}

/// @brief
/// Draws Kitt in the virtual cube.
/// @details
/// The draw method overrides the draw method of animation and sets the 
/// corresponding coordinates in the virtual cube.
/// This animation consists of 16 frames, each frame having a different kind of cube.
/// @param interrupt : pin_in
void kitt::draw( hwlib::pin_in &interrupt ) {
    c.set_brick(0);
    if ( mode == '-' ) {
        if (frame_count < 8) {
            for( int x = 0; x < frame_count; x++ ) {
                rectangle plane( c, vector(0,x,0), vector(7,x,7), 1); plane.draw();
            }
        } else {
            for( int x = 15-frame_count ; x > 0; x-- ) {
                rectangle plane( c, vector(0,x,0), vector(7,x,7), 1); plane.draw();
            }
        }
    } else if ( mode == '|' ) {
        if (frame_count < 8) {
            for( int z = 0; z < frame_count; z++ ) {
                rectangle plane( c, vector(0,0,z), vector(7,7,z), 1); plane.draw();
            }
        } else {
            for( int z = 15-frame_count ; z > 0; z-- ) {
                rectangle plane( c, vector(0,0,z), vector(7,7,z), 1); plane.draw();
            }
        }
    } else { // '/'
        
    }
    
    for ( int i = 0; i < frame_delay; i++ ) c.show(); 
    
    if (frame_count == 16) frame_count = 0;
    frame_count++;
}