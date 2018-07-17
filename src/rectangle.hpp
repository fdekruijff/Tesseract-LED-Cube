///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE.txt)

/// @file

#ifndef RECTANGLE_HPP
#define RECTAGNELE_HPP

#include "line.hpp"
#include "vector.hpp"

/// @class rectangle
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file rectangle.hpp
/// @brief rectangle class decleration
/// @details
/// This class draws a rectangle, filled or skeleton, in 3D space. 
/// It works on implementing one or more line objects.

class rectangle : public animation {
private:
    vector start, end;
    line left, right, top, bottom;
    bool filled;
public:
    rectangle( const cube &c, vector start, vector end, bool filled = false );
    void draw( hwlib::pin_in &interrupt = hwlib::pin_in_dummy ) override;
};

#endif // RECTANGLE_HPP