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

    static Fixed& min(Fixed& p1, Fixed& p2);
    static const Fixed& min(const Fixed& p1, const Fixed& p2);
    static Fixed& max(Fixed& p1, Fixed& p2);
    static const Fixed& max(const Fixed& p1, const Fixed& p2);

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other);
    Fixed operator-(const Fixed& other);
    Fixed operator*(const Fixed& other);
    Fixed operator/(const Fixed& other);

    Fixed operator++(int);
    Fixed& operator++();
    Fixed operator--(int);
    Fixed& operator--();
    Fixed& operator=(const Fixed& other);

    Fixed();
    Fixed(const int num);
    Fixed(const float num);

    Fixed(const Fixed& x);
    ~Fixed();
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif