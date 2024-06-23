#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain assignment constructor called" << std::endl;
	*this->ideas = *rhs.ideas;
	return (*this);
}

std::string	Brain::getIdeas(int i) const
{
	return (ideas[i]);
}

void	Brain::setIdeas(std::string src, int i)
{
	this->ideas[i] = src;
}