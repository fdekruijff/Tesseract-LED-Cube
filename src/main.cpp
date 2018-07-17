///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

#include "hwlib.hpp"
#include "cube.hpp"
#include "layer.hpp"
#include "vector.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "rotating_plane.hpp"
#include "pulsing_cube.hpp"
#include "alphabet.hpp"
#include "kitt.hpp"

int main( void ) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
   
    auto pos_pin = hwlib::target::pin_out( hwlib::target::pins::d53 );
    auto clock   = hwlib::target::pin_out( hwlib::target::pins::d51 );
    
    auto interrupt = hwlib::target::pin_in( hwlib::target::pins::d49 );
    
    auto neg_0   = hwlib::target::pin_out( hwlib::target::pins::d52 );
    auto neg_1   = hwlib::target::pin_out( hwlib::target::pins::d50 );
    auto neg_2   = hwlib::target::pin_out( hwlib::target::pins::d48 );
    auto neg_3   = hwlib::target::pin_out( hwlib::target::pins::d46 );
    auto neg_4   = hwlib::target::pin_out( hwlib::target::pins::d44 );
    auto neg_5   = hwlib::target::pin_out( hwlib::target::pins::d42 );
    auto neg_6   = hwlib::target::pin_out( hwlib::target::pins::d40 );
    auto neg_7   = hwlib::target::pin_out( hwlib::target::pins::d38 );
    
    layer l0 ( 0, neg_0 );
    layer l1 ( 1, neg_1 );
    layer l2 ( 2, neg_2 );
    layer l3 ( 3, neg_3 );
    layer l4 ( 4, neg_4 );
    layer l5 ( 5, neg_5 );
    layer l6 ( 6, neg_6 );
    layer l7 ( 7, neg_7 );
    
    cube ipass( clock, pos_pin, &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7 );
    
    int delay_ms = 10;
    
    pulsing_cube   animation_1 ( ipass, delay_ms );
    rotating_plane animation_2 ( ipass, delay_ms );
    kitt           animation_3 ( ipass, delay_ms, '|' );
    
//    rectangle plane(ipass, vector(0, 4, 0), vector(7, 4, 7), 1); // frame 1
    rectangle plane(ipass, vector(0, 3, 0), vector(7, 5, 7), 1); // frame 1
    plane.draw();
    
    while(true) {
//        animation_1.draw();        
//            animation_2.draw();
//            animation_3.draw();
    ipass.show();
    }
}