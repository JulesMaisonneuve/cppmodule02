#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->floatpoint = 0;
	return ;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	floatpoint = nb << bitsleft;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f * (float)(1 << bitsleft)));
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}
int Fixed::getRawBits(void) const
{
	return (this->floatpoint);
}

void Fixed::setRawBits(int const raw)
{
	this->floatpoint = raw;
}

float Fixed::toFloat(void) const
{
	return (floatpoint / (float)(1 << bitsleft));
}

int Fixed::toInt(void) const
{
	return (floatpoint >> bitsleft);
}

std::ostream &operator<<(std::ostream &output, const Fixed &f)
{
	output << f.toFloat();
	return output;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
