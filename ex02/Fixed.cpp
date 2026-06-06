#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    float res;
    float pwr = 1;
    
    for (int i = 0; i < fract ; i++)
        pwr *= 2;
    res = value / pwr;
    return res;
}

int Fixed::toInt(void) const
{
    int res;
    int pwr = 1;
    
    for (int i = 0; i < fract ; i++)
        pwr *= 2;
    res = value / pwr;
    return res;
}

Fixed& Fixed::min(Fixed& p1, Fixed& p2)
{
    if (p1.value > p2.value)    
        return p2;
    else 
        return p1;
}

const Fixed& Fixed::min(const Fixed& p1, const Fixed& p2)
{
      if (p1.value > p2.value)    
        return p2;
    else 
        return p1;
}

Fixed& Fixed::max(Fixed& p1, Fixed& p2)
{
    if (p1.value < p2.value)
        return p2;
    else 
        return p1;
}

const Fixed& Fixed::max(const Fixed& p1, const Fixed& p2)
{
    if (p1.value < p2.value)
        return p2;
    else 
        return p1;
}

bool Fixed::operator>(const Fixed& other) const
{
    if (this->value > other.value)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& other) const
{
    if (this->value < other.value)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
    if (this->value >= other.value)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& other) const
{
    if (this->value <= other.value)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed& other) const
{
    if (this->value == other.value)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& other) const
{
    if (this->value != other.value)
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed& other)
{
    Fixed a(*this);

    a.value = this->value + other.value;
    return a;
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed a(*this);

    a = this->value - other.value;
    return a;
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed a(*this);

    a = this->toFloat() * other.toFloat();
    return a;
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed a(*this);

    a = this->toFloat() / other.toFloat();
    return a;
}

Fixed Fixed::operator++(int)
{
    Fixed a(*this);

    this->value += 1;
    return a;
}

Fixed& Fixed::operator++()
{
    this->value += 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed a(*this);

    this->value -= 1;
    return a;
}

Fixed& Fixed::operator--()
{
    this->value -= 1;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
    out << obj.toFloat();
    return out;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->value = other.value;
    }
    return *this;
}

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    int pwr = 1;

    for (int i = 0; i < fract ; i++)
        pwr *= 2;
    value = num * pwr;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
    int pwr = 1;
    
    for (int i = 0; i < fract ; i++)
        pwr *= 2;
    value = num * pwr;
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
