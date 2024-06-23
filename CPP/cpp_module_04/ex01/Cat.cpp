#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = copy.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdeas(copy.brain->getIdeas(i), i);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat assignment constructor called" << std::endl;
	this->type = rhs.type;
	for (int i = 0; i < 100; i++)
		this->brain->setIdeas(rhs.brain->getIdeas(i), i);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat sound" << std::endl;
}

std::string	Cat::getType(void) const
{
	return (this->type);
}

void	Cat::getIdeas(int i) const
{
	std::cout << brain->getIdeas(i) << std::endl;
}

void	Cat::setIdeas(std::string str, int i)
{
	if (i >= 0 && i < 100)
		brain->setIdeas(str, i);
}