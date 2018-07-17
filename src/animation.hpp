///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "cube.hpp"
#include "hwlib.hpp"

/// @class animation
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file animation.hpp
/// @brief animation class decleration and implementation
/// @details
/// The animation class is an abstract class that every shape or
/// animation must implement to draw to the cube. Every instance must supply
/// the cube and implement the draw method.

class animation {
protected:
    /// @brief stores the cube object to which the animation writes.
    cube c;
    /// @brief sets the delay in millisecons between displaying frames, with 5 as default.
    int frame_delay;
    /// @brief holds the current frame number to display the correct shape.
    int frame_count;
public:
    /// @brief Animation constructor sets the cube attribute.
    animation( const cube &c, int frame_delay = 5, int frame_count = 0 ): c( c ), frame_delay( frame_delay ), frame_count( frame_count ) {}
    /// @brief Draw function that has to be implemented by every class that implements animation.
    virtual void draw( hwlib::pin_in &interrupt = hwlib::pin_in_dummy ) = 0;
    /// @brief If the frame delay has to change throughout the animation, this functinon takes care of that.
    void set_frame_delay( int delay ) { frame_delay = delay; }
};

#endif // ANIMATION_HPP