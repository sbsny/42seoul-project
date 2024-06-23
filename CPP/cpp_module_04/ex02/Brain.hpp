#include <iostream>

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();

		Brain&	operator=(const Brain &rhs);

		std::string	getIdeas(int i) const;
		void		setIdeas(std::string copy, int i);
};

#endif
