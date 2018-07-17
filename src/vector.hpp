///          Copyright Floris de Kruijff 2018.
/// Distributed under the Boost Software License, Version 1.0.
///    (See accompanying file LICENSE.txt or copy at
///          https://www.boost.org/LICENSE.txt)

/// @file

#ifndef VECTOR_HPP
#define VECTOR_HPP

/// @class vector
/// @author Floris de Kruijff
/// @date 25-06-2018
/// @file vector.hpp
/// @brief vector ADT
/// @details
/// Custom vector ADT to define coordinates cube.

class vector {
public:
    /// @brief specifies the x-coordinate of the vector as an integer.
    int x;
    /// @brief specifies the y-coordinate of the vector as an integer.
    int y;
    /// @brief specifies the z-coordinate of the vector as an integer.
    int z;
    
    /// \brief
    /// Construct a vector from x y z values.
    /// \details
    /// This constructor initializes a vector from an x and y value.
    /// The z value is optional and initiated as 0 if leaved blanc.
    vector(int x, int y, int z = 0):
        x( x ), y( y ), z( z )
    {}
    
    /// \brief   
    /// Compare two vector values
    /// \details
    /// This operator tests for equality. It returns true
    /// if and only if the x, y and z value of both vectors match.
    bool operator==( const vector &rhs ) const {
        return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
    }
    
    /// \brief   
    /// Add two vectors together.
    /// \details
    /// This operator+ adds a vector value with another vector.
    vector operator+( const vector &rhs ) const {
      vector temp = *this;
      temp += rhs;
      return temp;
    }
    
    /// \brief   
    /// Add a vector to this object.
    /// \details
    /// Add vector values to this object and return this object.
    vector &operator+=( const vector &rhs ) {
      x += rhs.x;
      y += rhs.y;
      z += rhs.z;
      return *this;
    }
   
    /// \brief   
    /// Subtract two vectors.
    /// \details
    /// This operator- subtracts a vector value with another vector.
    vector operator-( const vector &rhs ) const {
      vector temp = *this;
      temp -= rhs;
      return temp;
    }
   
    /// \brief   
    /// Subtract a vector from this object.
    /// \details
    /// Subtract vector values from this object and return this object.
    vector &operator-=( const vector &rhs ) {
      x -= rhs.x;
      y -= rhs.y;
      z -= rhs.z;
      return *this;
    }
   
    /// \brief   
    /// Multiply two vectors together.
    /// \details
    /// Multiply two vectors and return the result as vector.
    vector operator*( const vector &rhs ) const {
      vector temp = *this;
      temp *= rhs;
      return temp;
    }

    /// \brief   
    /// Multiply a vector with this object.
    /// \details
    /// Multiply a vector with this object and return this object.
    vector &operator*=( const vector &rhs ) {
      x *= rhs.x;
      y *= rhs.y;
      z *= rhs.z;
      return *this;
    }
    
    /// \brief   
    /// Add one to this vector.
    /// \details
    /// Adds 1 to the (x,y,z) of this object.
    vector &operator++() {
       x++; y++; z++;
       return *this;
    }

    /// \brief   
    /// Subtract one from this vector.
    /// \details
    /// Subtract 1 from the (x,y,z) of this object.
    vector &operator--() {
       x--; y--; z--;
       return *this;
    }
};

#endif //VECTOR_HPP