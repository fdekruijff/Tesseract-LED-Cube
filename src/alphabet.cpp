///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file alphabet.cpp
/// @brief alphabet class implementation

#include "alphabet.hpp"
#include "animation.hpp"
#include "vector.hpp"
#include "cube.hpp"
#include "rectangle.hpp"

/// @brief
/// Alphabet constructor instantiates an new alphabet object.
/// @details
/// The alphabet object contains the functions necessery to display text on the cube. 
/// The constructor sets the animation super constructor.
/// @param c : cube
alphabet::alphabet( cube&c ):
    animation( c ), current_char( ' ' )
{}

/// @brief
/// Draws the character in the virtual cube.
/// @details
/// The draw method overrides the draw method of animation and sets the 
/// corresponding coordinates in the virtual cube.
/// This is a static animation.
/// @param interrupt : pin_in
void alphabet::draw( hwlib::pin_in &interrupt ) {
    for ( int z = 0; z < 8; z++ ) {
        for  (int y = 0; y < 8; y++ ) {
            for (int x = 0; x < 8; x++ ) {
                c.set_coordinate( vector( x, y, z ), current_char_data[ 7-y ][ x ] );
            }
        }
    }
}

/// @brief
/// The offset function moves character along the x-axis
/// @details
/// This function moves a 2D character matrix by n amount defined by 
/// amount. The amount can be either positive or negative and must be 
/// in the bounds of -8 and +8.
/// @param character : std::array< std::array< bool, 8>, 8>
/// @param amount : int
std::array< std::array< bool, 8>, 8> alphabet::offset(std::array< std::array< bool, 8>, 8> character, int amount ) {
    if ( amount < -8 || amount == 0 || amount > 8 ) {
        return character;
    } else {   
        std::array< std::array< bool, 8>, 8> new_char;

        for ( int y = 0; y < 8; y++ ) {
            std::array< bool, 8> tmp;
            
            for ( int x = 0; x < 8; x++ ) {
                if ( amount > 0 ) {
                    if ( (x + 1) < amount ) {
                        tmp[x] = 0;
                    } else {
                        tmp[x] = character[y][x-amount];
                    }
                } else if ( amount < 0 ) {
                    if ( amount > (x + 1) ) {
                        tmp[x] = character[y][x-amount];
                    } else {
                        tmp[x] = 0;
                    }
                }
            }
            new_char[y] = tmp;
        }
        return new_char;
    }
}

/// @brief
/// Set char takes a char input and, if defined, matches it to its corresponding 2D array assosiation.
/// @details
/// The input capital letter must be higer case. If the letter is defined an 2D matrix is placed in the current_char_data array 
/// This can be used to display the character, or offset it to make it seem like its moving along.
void alphabet::set_char( char capital_letter, int offset_int ) {
    switch( capital_letter ) {
        case 'A':
            current_char_data =
            { {
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }}
            } };
            break; 
        case 'B':
            current_char_data = 
            { {
                {{ 1,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,0 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,0 }}
            } };
            break;
        case 'C':
            current_char_data = 
            { {
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 0,1,1,1,1,1,1,0 }}
            } };
            break;
        case 'D':
            current_char_data = 
            { {
                {{ 1,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,0 }}
            } };
            break;
        case 'E':
            current_char_data = 
            { {
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,1,1,1,0,0 }},
                {{ 1,1,1,1,1,1,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }}
            } };
            break;
        case 'F':
            current_char_data = 
            { {
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,1,1,1,0,0 }},
                {{ 1,1,1,1,1,1,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }}
            } };
            break;
        case 'G':
            current_char_data = 
            { {
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 0,1,1,1,1,1,1,0 }}
            } };
            break;
        case 'H':
            current_char_data = 
            { {
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }}
            } };
            break;
        case 'I':
            current_char_data = 
            { {
                {{ 0,0,0,1,1,1,0,0 }},
                {{ 0,0,0,1,1,1,0,0 }},
                {{ 0,0,0,1,1,1,0,0 }},
                {{ 0,0,0,1,1,1,0,0 }},
                {{ 0,0,0,1,1,1,0,0 }},
                {{ 0,0,0,1,1,1,0,0 }},
                {{ 0,0,0,1,1,1,0,0 }},
                {{ 0,0,0,1,1,1,0,0 }}
            } };
            break;
        case 'J':
            current_char_data = 
            { {
                {{ 0,0,0,0,1,1,1,0 }},
                {{ 0,0,0,0,1,1,1,0 }},
                {{ 0,0,0,0,1,1,1,0 }},
                {{ 0,0,0,0,1,1,1,0 }},
                {{ 0,0,0,0,1,1,1,0 }},
                {{ 0,0,0,0,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,0,0 }}
            } };
            break;
        case 'K':
            current_char_data = 
            { {
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 0,0,1,1,1,1,0,0 }}
            } };
            break;
        case 'L':
            current_char_data = 
            { {
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }}
            } };
            break;
        case 'M':
        current_char_data = 
            { {
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }}
            } };
            break;
        case 'N':
            current_char_data = 
            { {
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,0,1,1,1 }},
                {{ 1,1,1,1,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,1,1,1,1 }},
                {{ 1,1,1,0,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }}
            } };
            break;
        case 'O':
            current_char_data = 
            { {
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 0,1,1,1,1,1,1,0 }}
            } };
            break;
        case 'P':
            current_char_data = 
            { {
                {{ 1,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,0 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,0,0,0,0,0 }}
            } };
            break;
        case 'Q':
            current_char_data = 
            { {
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,0,1,1 }},
                {{ 1,1,1,0,0,1,0,1 }},
                {{ 1,1,1,1,0,1,1,0 }},
                {{ 0,1,1,1,1,0,1,1 }}
            } };
            break;
        case 'R':
            current_char_data = 
            { {
                {{ 1,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }}
            } };
            break;
        case 'S':
            current_char_data = 
            { {
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,0,0,0,0,0 }},
                {{ 1,1,1,1,1,1,1,0 }},
                {{ 0,1,1,1,1,1,1,1 }},
                {{ 0,0,0,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 0,1,1,1,1,1,1,0 }}
            } };
            break;
        case 'T':
            current_char_data = 
            { {
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 0,0,0,1,1,0,0,0 }},
                {{ 0,0,0,1,1,0,0,0 }},
                {{ 0,0,0,1,1,0,0,0 }},
                {{ 0,0,0,1,1,0,0,0 }},
                {{ 0,0,0,1,1,0,0,0 }},
                {{ 0,0,0,1,1,0,0,0 }}
            } };
            break;
        case 'U':
            current_char_data = 
            { {
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 0,1,1,1,1,1,1,0 }}
            } };
            break;
        case 'V':
            current_char_data = 
            { {
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 0,0,1,1,1,1,0,0 }}
            } };
            break;
        case 'W':
            current_char_data = 
            { {
                {{ 1,1,0,0,0,0,1,1 }},
                {{ 1,1,0,0,0,0,1,1 }},
                {{ 1,1,0,0,0,0,1,1 }},
                {{ 1,1,0,0,0,0,1,1 }},
                {{ 1,1,0,1,1,0,1,1 }},
                {{ 1,1,0,1,1,0,1,1 }},
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 0,0,1,1,1,1,0,0 }}
            } };
            break;
        case 'X':
            current_char_data = 
            { {
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 0,0,1,1,1,1,0,0 }},
                {{ 0,0,1,1,1,1,0,0 }},
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }}
            } };
            break;
        case 'Y':
            current_char_data = 
            { {
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 1,1,1,0,0,1,1,1 }},
                {{ 0,1,1,1,1,1,1,0 }},
                {{ 0,0,1,1,1,1,0,0 }},
                {{ 0,0,0,1,1,0,0,0 }},
                {{ 0,0,0,1,1,0,0,0 }},
                {{ 0,0,0,1,1,0,0,0 }}
            } };
            break;
        case 'Z':
            current_char_data = 
            { {
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 0,0,0,0,1,1,1,1 }},
                {{ 0,0,0,1,1,1,1,0 }},
                {{ 0,0,1,1,1,1,0,0 }},
                {{ 1,1,1,1,0,0,0,0 }},
                {{ 1,1,1,1,1,1,1,1 }},
                {{ 1,1,1,1,1,1,1,1 }}
            } };
            break;
        default:
            current_char_data =
            { {
                {{ 0,0,0,0,0,0,0,0 }},
                {{ 0,0,0,0,0,0,0,0 }},
                {{ 0,0,0,0,0,0,0,0 }},
                {{ 0,0,0,0,0,0,0,0 }},
                {{ 0,0,0,0,0,0,0,0 }},
                {{ 0,0,0,0,0,0,0,0 }},
                {{ 0,0,0,0,0,0,0,0 }},
                {{ 0,0,0,0,0,0,0,0 }}
            } };
            break;
    }
    
    current_char_data = offset(current_char_data, offset_int);
}