#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("Default"), healthPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const name)
	: name(name), healthPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->healthPoints = rhs.healthPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return *this;
}

std::string	ClapTrap::getName() const
{
	return this->name;
}

unsigned int	ClapTrap::getHealthPoints() const
{
	return this->healthPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return this->energyPoints;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->healthPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target
		<< ", causing " << this->attackDamage << " points of damage" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->name << " can't attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->healthPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " takes " << amount
		<< " points of damage" << std::endl;
		if (amount > this->healthPoints)
			amount = this->healthPoints;
		this->healthPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << this->name << " can't take damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->healthPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " is repaired by "
		<< amount << " points" << std::endl;
		this->healthPoints += amount;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->name << " can't be repaired" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, ClapTrap const &rhs)
{
	out << "Name        : " << rhs.getName() << std::endl;
	out << "HealthPoints: " << rhs.getHealthPoints() << std::endl;
	out << "EnergyPoints: " << rhs.getEnergyPoints() << std::endl;
	out << "AttackDamage: " << rhs.getAttackDamage() << std::endl;
	return out;
}
