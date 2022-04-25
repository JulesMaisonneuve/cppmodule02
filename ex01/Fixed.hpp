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
			std::cout << "Copy assignement operator called" << std::endl;
			if (this != &f)
			{
				fp = f.fp;
			}
			return (*this);
		}
		Fixed(const Fixed &f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		~Fixed(void);
};

std::ostream &operator<<(std::ostream &output, const Fixed &f);

#endif
