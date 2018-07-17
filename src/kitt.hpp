///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

#ifndef KITT_HPP
#define KITT_HPP

#include "line.hpp"
#include "cube.hpp"
#include "animation.hpp"

/// @class kitt
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file kitt.hpp
/// @brief kitt class decleration
/// @details
/// The kitt class is a simple demonstration of a Kitt animation through the cube.

class kitt : public animation {
    char mode;
public:
    kitt( const cube &c, int frame_delay, char mode = '/' );
    void draw( hwlib::pin_in &interrupt = hwlib::pin_in_dummy ) override;
};

#endif // KITT_HPP
