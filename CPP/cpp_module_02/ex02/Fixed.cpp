#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(int const value) : value(value << fractionalBits)
{
}

Fixed::Fixed(float const value) : value(roundf(value * (1 << fractionalBits)))
{
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->value = copy.value;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int	Fixed::toInt(void) const
{
	return this->value >> fractionalBits;
}

float	Fixed::toFloat(void) const
{
	return (float)this->value / (1 << fractionalBits);
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return this->value > copy.value;
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return this->value < copy.value;
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return this->value >= copy.value;
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return this->value <= copy.value;
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return this->value == copy.value;
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return this->value != copy.value;
}

Fixed	Fixed::operator+(const Fixed &copy) const
{
	return Fixed(this->toFloat() + copy.toFloat());
}

Fixed	Fixed::operator-(const Fixed &copy) const
{
	return Fixed(this->toFloat() - copy.toFloat());
}

Fixed	Fixed::operator*(const Fixed &copy) const
{
	return Fixed(this->toFloat() * copy.toFloat());
}

Fixed	Fixed::operator/(const Fixed &copy) const
{
	return Fixed(this->toFloat() / copy.toFloat());
}

Fixed	&Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->value++;
	return tmp;
}

Fixed	&Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->value--;
	return tmp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}
