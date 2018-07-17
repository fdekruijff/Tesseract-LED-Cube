///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE.txt)

/// @file
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file shift_register.cpp
/// @brief shift register class implementation

#include "shift_register.hpp"
#include "hwlib.hpp"

/// @brief
/// Shift register constructor.
/// @details
/// Shift register contructor instantiates a new shift register object.
/// @param data : pin_out
shift_register::shift_register( hwlib::pin_out &data ):
    data ( data ) {}

/// @brief
/// Set value to data pin.
/// @details
/// Set a boolean value to the assigned hwlib::pin_out data pin of this object.
/// @param value : bool
void shift_register::set( bool value ) {
    data.set( value );
}