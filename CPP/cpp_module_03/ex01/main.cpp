#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	num1("Num1");

	std::cout << std::endl << num1 << std::endl;

	num1.guardGate();
	num1.attack("enemy");
	num1.beRepaired(50);
	num1.takeDamage(150);

	std::cout << std::endl << num1 << std::endl;

	ScavTrap 	scav("Num2");
	ClapTrap	*clap = &scav;
	scav.attack("enemy");
	clap->attack("enemy");

	return 0;
}
