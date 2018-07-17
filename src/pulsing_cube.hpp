///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file

#ifndef PULSING_CUBE_HPP
#define PULSING_CUBE_HPP

#include "vector.hpp"
#include "cube.hpp"
#include "animation.hpp"

/// @class pulsing_cube
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file pulsing_cube.hpp
/// @brief pulsing cube class decleration
/// @details
/// The pulsing cube class is a simple demonstration of the skeleton of a cube pulsing in and out the 3D cube.

class pulsing_cube : public animation {
public:
    pulsing_cube( const cube &c, int frame_delay );
    void draw( hwlib::pin_in &interrupt = hwlib::pin_in_dummy ) override;
};

#endif // PULSING_CUBE_HPP