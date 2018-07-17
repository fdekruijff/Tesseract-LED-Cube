///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file

#ifndef LAYER_HPP
#define LAYER_HPP

#include "hwlib.hpp"
#include "shift_register.hpp"
#include "vector.hpp"
#include <array>

/// @class layer
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file layer.hpp
/// @brief layer class decleration
/// @details
/// The layer object represents the physical layer of the cube.
/// Each layer has a 8x8 matrix that store the boolean values for the led. 
/// 1 being ON and 0 being OFF. 
/// A layer object comprises of a negative shift register and a negative data array
/// to process the matrix data.

class layer {
private:
    int layer_id;
    std::array<bool, 8> neg_data;
    shift_register neg_reg;
    std::array< std::array< bool, 8>, 8> matrix;
public:
    layer( int layer_id, hwlib::pin_out &neg_pin);
    int get_layer_id();
    void set_coordinate( vector v, bool value );
    void move( int index );
    void write_registers( int index );
    std::array< std::array< bool, 8>, 8> get_matrix();
};

#endif //LAYER_HPP