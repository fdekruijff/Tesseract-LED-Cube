///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE.txt)

/// @file

#ifndef SHIFT_REGISTER_HPP
#define SHIFT_REGISTER_HPP

#include "hwlib.hpp"

/// @class shift_register
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file shift_register.hpp
/// @brief shift register class decleration
/// @details
/// This shift register object holds the abstract data pin for the shift register. 
/// This object can set a boolean value to the data pin. Future updates will include setting
/// Output Enable pins and seperating the clock.

class shift_register {
private:
    hwlib::pin_out &data;
public:
    shift_register( hwlib::pin_out &data = hwlib::pin_out_dummy );
    void set( bool value );
};

#endif // SHIFT_REGISTER_HPP
