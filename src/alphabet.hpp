///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE_1_0.txt)

/// @file

#ifndef ALPHABET_HPP
#define ALPHABET_HPP

#include "cube.hpp"
#include "vector.hpp"
#include "animation.hpp"
#include <array>

/// @class alphabet
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file alphabet.hpp
/// @brief alphabet class decleration
/// @details
/// This class contains the 2D 8x8 representations of the letters in the alphabet.
/// Together with an offset functions to display them on a 2D vector it lays the foundation
/// to display matrix strings on the cube.

class alphabet : public animation {
private:
    char current_char;
    std::array< std::array< bool, 8>, 8> current_char_data;
public:
    alphabet( cube &c );
    void set_char( char capital_letter, int offset = 0 );
    std::array< std::array< bool, 8>, 8> offset(std::array< std::array< bool, 8>, 8> character, int amount );
    void draw( hwlib::pin_in &interrupt = hwlib::pin_in_dummy ) override;
};

#endif //ALPHABET_HPP