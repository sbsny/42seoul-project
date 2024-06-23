#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(Animal const &copy);
		Animal &operator=(Animal const &rhs);
		virtual ~Animal();

		virtual std::string		getType() const;
		virtual void			makeSound() const = 0;
};

#endif
