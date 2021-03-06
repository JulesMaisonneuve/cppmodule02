#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->floatpoint = 0;
	return ;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	floatpoint = f.getRawBits();
}
Fixed& Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &f)
	{
		floatpoint = f.getRawBits();
	}
	return (*this);
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->floatpoint);
}

void Fixed::setRawBits(int const raw)
{
	this->floatpoint = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
