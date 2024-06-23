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

		bool	operator>(const Fixed &copy) const;
		bool	operator<(const Fixed &copy) const;
		bool	operator>=(const Fixed &copy) const;
		bool	operator<=(const Fixed &copy) const;
		bool	operator==(const Fixed &copy) const;
		bool	operator!=(const Fixed &copy) const;

		Fixed	operator+(const Fixed &copy) const;
		Fixed	operator-(const Fixed &copy) const;
		Fixed	operator*(const Fixed &copy) const;
		Fixed	operator/(const Fixed &copy) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &value);

#endif
