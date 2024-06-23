#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	num1("Num1");

	std::cout << std::endl << num1 << std::endl;

	num1.attack("enemy");
	num1.beRepaired(5);
	num1.takeDamage(20);

	std::cout << std::endl << num1 << std::endl;

	num1.attack("enemy");
	num1.beRepaired(10);
	num1.takeDamage(5);
	std::cout << std::endl;

	return 0;
}
