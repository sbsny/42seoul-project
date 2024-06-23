#include "FragTrap.hpp"

int	main()
{
	FragTrap	num1("Num1");

	std::cout << std::endl << num1 << std::endl;

	num1.highFivesGuys();
	num1.attack("enemy");
	num1.beRepaired(50);
	num1.takeDamage(150);

	std::cout << std::endl << num1 << std::endl;

	FragTrap	frag("Num2");
	ClapTrap	*clap = &frag;
	frag.attack("enemy");
	clap->attack("enemy");

	return 0;
}
