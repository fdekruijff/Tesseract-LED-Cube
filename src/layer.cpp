///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file layer.cpp
/// @brief layer class implementation

#include "hwlib.hpp"
#include "layer.hpp"
#include "vector.hpp"
#include "shift_register.hpp"

/// @brief
/// Layer constructor.
/// @details
/// Layer contructor instantiates a new layer object.
/// @param layer_id : int
/// @param neg_pin : pin_out
layer::layer( int layer_id, hwlib::pin_out &neg_pin ):
    layer_id( layer_id ),
    neg_data( {1,1,1,1,1,1,1,1} ),
    neg_reg( shift_register( neg_pin ))
{}

/// @brief
/// Move negative values.
/// @details
/// Sets the proper negative data relative to the layer matrix to the negative
/// data array to be processed later.
/// @param index : int
void layer::move( int index ) {
    neg_data = matrix[ index ];
            
    for (int j = 0; j < 8; j++) {
        if (neg_data[j] == 0) { neg_data[j] = 1; } 
        else if (neg_data[j] == 1) { neg_data[j] = 0; }
    }
}

/// @brief
/// Set coordinate.
/// @details
/// Set an axis coordinate for this layer and place it accordingly in the nested arrays.
/// This means placing the y-axis value from the other side to compensate the nested array placement.
/// @param v : vector
/// @param value : bool

void layer::set_coordinate( vector v, bool value ) {
    matrix[ v.y ][ v.x ] = value;
}

/// @brief
/// Write negative data array element to register.
/// @details
/// Writes element index of the negative data array to the shift register, managed by the cube class
/// write all the layers at the same time.
/// @param index : int
void layer::write_registers( int index ) {
    neg_reg.set( neg_data [ 7 - index ] );
}

/// @brief
/// Getter returing layer ID as integer.
int layer::get_layer_id() {
    return layer_id;
} 

/// @brief
/// Getter returning the layer matrix as 2D array.
std::array< std::array< bool, 8>, 8> layer::get_matrix() {
    return matrix;
}