#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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

std::ostream &operator<<(std::ostream& out, const Fixed& obj)
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
    value = roundf(num * pwr);
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
