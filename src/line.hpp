///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file

#ifndef LINE_HPP
#define LINE_HPP

#include "cube.hpp"
#include "animation.hpp"
#include "vector.hpp"

/// @class line
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file line.hpp
/// @brief line class decleration
/// @details
/// Simple line object to draw lines in three dimentional space. Conprises of the start and end vector.

class line : public animation {
private:
    vector start, end;
public:
    line( const cube &c, vector start, vector end );
    void draw( hwlib::pin_in &interrupt = hwlib::pin_in_dummy ) override;
};

#endif // LINE_HPP