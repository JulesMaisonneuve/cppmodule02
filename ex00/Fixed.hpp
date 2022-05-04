#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int floatpoint;
		static const int bitsleft = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed(void);
};

#endif
