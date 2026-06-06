#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
    private:
    static const int fract = 8;
    int value;

    public:
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed& operator=(const Fixed& other);
    
    Fixed();
    Fixed(const Fixed& x);
    ~Fixed();
};


#endif