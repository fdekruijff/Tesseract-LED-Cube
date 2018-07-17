///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file cube.cpp
/// @brief cube class implementation

#include "cube.hpp"
#include <array>

/// @brief
/// cube constructor.
/// @details
/// Cube constructor instantiates the cube object, in a program there will probably never be more than one object.
/// Not all layers have to be connected for the cube to work. It can work with 0 to 8 layers. The clock and positive shift register
/// are also instantiated in the constructor and all cube values are set to 0 to start with.
/// To be on the safe side that there are no stray bits in the system the cube quickly clocks 16 times through all the connected 
/// shift registers.
/// @param shift_clock : pin_out
/// @param pos_pin : pin_out
/// @param l0 : layer
/// @param l1 : layer
/// @param l2 : layer
/// @param l3 : layer
/// @param l4 : layer
/// @param l5 : layer
/// @param l6 : layer
/// @param l7 : layer
cube::cube( hwlib::pin_out &shift_clock, hwlib::pin_out &pos_pin, layer *l0, layer *l1, layer *l2, layer *l3, layer *l4, layer *l5, layer *l6, layer *l7 ):
    shift_clock( shift_clock ), 
    pos_reg( shift_register( pos_pin ) ),
    block{l0, l1, l2, l3, l4, l5, l6, l7 },
    layer_amount( set_layer_count() )
{ 
    set_brick(0);
    clock(16);
}

/// @brief
/// Translate virtual 3D array to physical cube
/// @details
/// This algorithm translates the virtual 3D array to the connected shift registers of the cube.
/// If this function is called in an loop the image will be visualised as it should be.

/// The algorithm does this in a few steps:
/// step 1.     Loop through the y-axis, the 8 positive register outputs. The outputs are for all the layers the same. 
///             Layer 0 through 7 all have y0 connected, the same for y1, y2 etc. 
/// step 2.     Prepare the negative data for each connected layer.
/// step 3.     Clock the positive and negative byte per per layer to the registers.
/// step 4.     Repeat this process untill all y-axis elements have been traversed. 
void cube::show() {
    std::array<int, 8> pos_data;
    clock(8); // Get rid of stray bits in the registers by clocking 8 times.
    
    for (int i = 0; i < 8; i++) {
        pos_data.fill(0);
        pos_data[ i ] = 1; // Positive byte just traverses from y0 to y7.
        
        for (int k = 0; k < layer_amount; k++) { 
            block[ k ]->move( i ); // Move negative data byte for each layer
        }
        
        for (int j = 0; j < 8; j++) { // Clock the byte through the registers.
            pos_reg.set( pos_data[ j ]); // Clock the positive bit.
            
            for (int k = 0; k < layer_amount; k++) { 
                block[ k ]->write_registers( j ); // Clock the negative bit for each layer.
            } 
            clock();
        }
        pos_reg.set(0); // Make sure positive output is low again
        clock(); // One final clock to move everything to it's correct location.
        hwlib::wait_us( 850 ); // Multiplex duty-cycle.
    }
}

/// @brief
/// Private function to register the connected layers.
/// @details
/// This private function just registers the amount of connected layers, 
/// this makes the show() algorithm more effecient because it does not have
/// to process the layers that are not connected.
int cube::set_layer_count() {
    int amount = 0;
    for (int i = 0; i < 8; i++ ) {
        if (block[ i ] != 0 ) {
            if (block[i]->get_layer_id() != -1 ) {
                amount++;
            }
        }
    }
    return amount;
}

/// @brief
/// Clock function for registers.
/// @details
/// Simple clock function with optional amount and delay parameters.
/// Amount for simplicity and delay for debuuging.
/// @param amount : int
/// @param delay : int
void cube::clock( int amount, int delay ) {
    for ( int i = 0; i < amount; i ++) {
        shift_clock.set( 1 );
        hwlib::wait_ms( delay / 2 );
        shift_clock.set( 0 );
        hwlib::wait_ms( delay / 2 );
    }
}

/// @brief
/// Set coordinate.
/// @details
/// Finds the cooresponding layer object in the brick and calls it's set coordinate function 
/// Set the corresponding matrix value.
/// @param v : vector
/// @param value : int
void cube::set_coordinate( vector v, bool value ) {
    if (block[ v.z ]->get_layer_id() != -1 ) {
        block[ v.z ]->set_coordinate( v, value );
    }
}

/// @brief
/// Set a boolean value to the entire brick.
/// @details
/// If the entire cube has to be turned on or off, this function will loop throught the connected layers
/// and set the corresponding value to it's entire matrix.
/// @param value : bool
void cube::set_brick( bool value) {
    for ( int z = 0; z < layer_amount; z++ ) {
        for  (int x = 0; x < 8; x++ ) {
            for (int y = 0; y < 8; y++ ) {
                block[ z ]->set_coordinate( vector(x,y), value );
            }
        }
    }
}

/// @brief
/// Return the layer pointer based on index.
/// @details
/// For the unit testing the layers are required. This function returns a specific layer to run the functions
/// individually.
/// @param index : int
layer* cube::get_layer( int index ) {
    return block[ index ];
}
