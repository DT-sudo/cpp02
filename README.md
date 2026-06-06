# C++ Module 02: Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form

## Overview

This module introduces operator overloading and the Orthodox Canonical Form, which is required from module 02 onwards.

## Orthodox Canonical Form

Every class must implement:
1. Default constructor
2. Copy constructor
3. Copy assignment operator
4. Destructor

Example:
```cpp
class Fixed {
private:
    int _value;
public:
    Fixed();                       // Default constructor
    Fixed(const Fixed &other);     // Copy constructor
    Fixed &operator=(const Fixed &other); // Assignment operator
    ~Fixed();                      // Destructor
};
```

## Exercises

### ex00 - My first Orthodox Canonical Form
Implement a Fixed-point number class with basic structure.

**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

**Features:**
- Private integer to store fixed-point value
- All four canonical form methods
- Getter/setter for raw bits
- Conversion between float/int and fixed-point

### ex01 - Towards a more usable fixed-point number
Add comparison operators to the Fixed class.

**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

**Operators to implement:**
- Comparison: `>`, `<`, `>=`, `<=`, `==`, `!=`
- Example output shows proper comparison behavior

### ex02 - Now we're talking
Implement arithmetic operators for Fixed-point numbers.

**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

**Operators to implement:**
- Arithmetic: `+`, `-`, `*`, `/`
- Increment/Decrement: `++`, `--` (prefix and postfix)
- Output: `<<` operator for stream insertion
- Min/Max: static functions

## Key Concepts

- **Operator Overloading**: Redefining operators for custom types
- **Orthodox Canonical Form**: Required structure for all classes
- **Deep Copy**: Proper memory management in copy operations
- **Const Correctness**: Using `const` for immutable operations
- **Ad-hoc Polymorphism**: Operator overloading provides custom behavior
- **Fixed-point Numbers**: Representing decimal numbers with integers

## Fixed-Point Representation

A fixed-point number stores a decimal number as an integer scaled by a factor (typically 2^8 or 2^16).

Example: 
- Integer value 1024 with scale 2^8 = 4.0
- Integer value 512 with scale 2^8 = 2.0

## Compilation

```bash
cd cppXX/exXX
make
```

## Testing

Each exercise includes a main function demonstrating the implemented functionality. Run the executable to verify operators work correctly.

## Important Rules

- No STL containers (vector, list, map, etc.)
- No Boost libraries
- No C-style functions (printf, malloc, free)
- Memory must be properly managed
- Include guards required for headers
