#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int fp;
		static const int bitsleft = 8;
	public:
		Fixed(void);
		Fixed(const int nb);
		Fixed(const float f);
		Fixed &operator=(const Fixed &f)
		{
			// std::cout << "Copy assignement operator called" << std::endl;
			if (this != &f)
			{
				fp = f.fp;
			}
			return (*this);
		}
		// Fixed &operator+=(const Fixed &f);
		bool operator ==(const Fixed &f) const;
		bool operator !=(const Fixed &f) const;
		bool operator <(const Fixed &f) const;
		bool operator >(const Fixed &f) const;
		bool operator >=(const Fixed &f) const;
		bool operator <=(const Fixed &f) const;
		Fixed operator+(const Fixed &f);
		Fixed operator-(const Fixed &f);
		Fixed operator*(const Fixed &f);
		Fixed operator/(const Fixed &f);
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
		Fixed(const Fixed &f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static float min(Fixed &a, Fixed &b);
		static float min(const Fixed &a, const Fixed &b);
		static float max(Fixed &a, Fixed &b);
		static float max(const Fixed &a, const Fixed &b);
		~Fixed(void);
};

std::ostream &operator<<(std::ostream &output, const Fixed &f);

#endif
