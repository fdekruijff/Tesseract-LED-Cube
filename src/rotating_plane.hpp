///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE.txt)

/// @file

#ifndef ROTATING_PLANE_HPP
#define ROTATING_PLANE_HPP

#include "vector.hpp"
#include "cube.hpp"
#include "animation.hpp"

/// @class rotating_plane
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file rotating_plane.hpp
/// @brief rotating plane class decleration
/// @details
/// The rotating plane class is a simple demonstration of a 2D plane rotating in 3D space.

class rotating_plane : public animation {
public:
    rotating_plane( const cube &c, int frame_delay );
    void draw( hwlib::pin_in &interrupt = hwlib::pin_in_dummy ) override;
};

#endif // ROTATING_PLANE_HPP