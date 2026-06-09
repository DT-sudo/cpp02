#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
    private:
    static const int fract = 8;
    int value;

    public:
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;


    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed& x);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
};

std::ostream &operator<<(std::ostream& out, const Fixed& obj);

#endif
