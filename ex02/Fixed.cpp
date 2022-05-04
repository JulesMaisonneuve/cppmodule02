#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->fp = 0;
	return ;
}

Fixed::Fixed(const int nb)
{
	// std::cout << "Int constructor called" << std::endl;
	fp = nb << bitsleft;
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f * (float)(1 << bitsleft)));
}

Fixed::Fixed(const Fixed &f)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed &f)
{
	// std::cout << "Copy assignement operator called" << std::endl;
	if (this != &f)
	{
		fp = f.fp;
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->fp);
}

bool Fixed::operator ==(const Fixed &f) const
{
	if (fp == f.fp)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

bool Fixed::operator !=(const Fixed &f) const
{
	if (fp != f.fp)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

bool Fixed::operator <(const Fixed &f) const
{
	if (fp < f.fp)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

bool Fixed::operator >(const Fixed &f) const
{
	if (fp > f.fp)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

bool Fixed::operator >=(const Fixed &f) const
{
	if (fp >= f.fp)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

bool Fixed::operator <=(const Fixed &f) const
{
	if (fp <= f.fp)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

Fixed Fixed::operator+(const Fixed &f)
{
	fp += f.fp;
	return (*this);
}

Fixed Fixed::operator-(const Fixed &f)
{
	fp -= f.fp;
	return (*this);
}

Fixed Fixed::operator*(const Fixed &f)
{
	return (this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f)
{
	return (this->toFloat() / f.toFloat());
}

Fixed Fixed::operator++()
{
	fp += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--()
{
	fp -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

void Fixed::setRawBits(int const raw)
{
	this->fp = raw;
}

float Fixed::toFloat(void) const
{
	return (fp / (float)(1 << bitsleft));
}

int Fixed::toInt(void) const
{
	return (fp >> bitsleft);
}

float Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a.toFloat() : b.toFloat());
}

float Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a.toFloat() : b.toFloat());
}
float Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a.toFloat() : b.toFloat());
}

float Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a.toFloat() : b.toFloat());
}

std::ostream &operator<<(std::ostream &output, const Fixed &f)
{
	output << f.toFloat();
	return output;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}
