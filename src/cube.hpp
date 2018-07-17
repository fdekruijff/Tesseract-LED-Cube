///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file

#ifndef CUBE_HPP
#define CUBE_HPP

#include "hwlib.hpp"
#include "layer.hpp"
#include "shift_register.hpp"
#include "vector.hpp"

/// @class cube
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file cube.hpp
/// @brief cube class decleration
/// @details
/// Cube class is the top level class that manages all the actions performed on the physical cube. 
/// It consists of the positive register, 8 layers and the clock pin. With all these physical connections it
/// can theoraticlly alter any led in any way and create virtually any animation.

class cube {
private:
    hwlib::pin_out &shift_clock;
    shift_register pos_reg;
    layer * block[8];
    int layer_amount;
    int set_layer_count();
public:
    cube( 
        hwlib::pin_out &shift_clock, 
        hwlib::pin_out &pos_pin, 
        layer  *l0 = 0,
        layer  *l1 = 0,
        layer  *l2 = 0,
        layer  *l3 = 0,
        layer  *l4 = 0,
        layer  *l5 = 0,
        layer  *l6 = 0,
        layer  *l7 = 0
    ); 
    void clock( int amount = 1, int delay = 0 );
    void set_coordinate( vector v, bool value );
    void show();
    void set_brick( bool value );
    layer* get_layer( int index );
};

#endif //CUBE_HPP