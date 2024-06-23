#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal
{
	private:
			Brain *brain;

	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat& 		operator=(const Cat &rhs);
		std::string	getType(void) const;
		void 		makeSound() const;
		void		getIdeas(int i) const;
		void		setIdeas(std::string str, int i);
};

#endif
