#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();

		Fixed	&operator=(const Fixed &copy);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &value);

#endif
