#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate()
{
	int	i;

	std::srand((unsigned int)time(NULL));
	i = std::rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else if (i == 2)
		return new C;
	else
		return NULL;
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(std::exception& e)
			{
				std::cout << "Error" << std::endl;
			}
		}
	}
}

int main()
{
	Base	*p = generate();

	identify(p);
	identify(*p);

	delete p;

	return 0;
}
