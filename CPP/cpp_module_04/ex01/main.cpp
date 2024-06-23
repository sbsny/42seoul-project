#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << std::endl << "SUBJECT TEST :" << std::endl << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl << "ARRAY TEST :" << std::endl << std::endl;
	Animal *array[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		array[i]->makeSound();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete array[i];

	std::cout << std::endl << "COPY TEST :" << std::endl << std::endl;
	Dog dog1;
	dog1.setIdeas("test1", 0);

	Dog dog2 = Dog(dog1);
	std::cout << std::endl;
	dog1.getIdeas(0);
	dog2.getIdeas(0);

	std::cout << std::endl;
	dog1.setIdeas("test2", 0);
	dog1.getIdeas(0);
	dog2.getIdeas(0);
	std::cout << std::endl;

	return (0);
}