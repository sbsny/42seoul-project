/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 05:00:46 by seonyun           #+#    #+#             */
/*   Updated: 2023/01/20 05:02:59 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	N = atoi(av[1]);
		if (N > 0)
		{
			std::string	name = av[2];
			Zombie* zombie = zombieHorde(N, name);
			for (int i = 0; i < N; i++)
				zombie[i].announce();
			delete[] zombie;
		}
		else
			std::cout << "Error: Wrong number of zombies" << std::endl;
	}
	else
		std::cout << "Error: Wrong number of arguments" << std::endl;
	return 0;
}
