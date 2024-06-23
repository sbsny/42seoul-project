#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal
{
	private:
			Brain *brain;

	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog&		operator=(const Dog &rhs);
		std::string	getType(void) const;
		void		makeSound() const;
		void		getIdeas(int i) const;
		void		setIdeas(std::string str, int i);
};

#endif
