#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = copy.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdeas(copy.brain->getIdeas(i), i);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog assignment constructor called" << std::endl;
	this->type = rhs.type;
	for (int i = 0; i < 100; i++)
		this->brain->setIdeas(rhs.brain->getIdeas(i), i);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog sound" << std::endl;
}

std::string	Dog::getType(void) const
{
	return (this->type);
}

void	Dog::getIdeas(int i) const
{
	std::cout << brain->getIdeas(i) << std::endl;
}

void	Dog::setIdeas(std::string str, int i)
{
	if (i >= 0 && i < 100)
		brain->setIdeas(str, i);
}
