/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:59:28 by seonyun           #+#    #+#             */
/*   Updated: 2023/01/17 20:59:29 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		std::string str;
		for (int i = 1; i < ac; i++)
		{
			str = av[i];
			for (int j = 0; str[j]; j++)
				std::cout << (char)toupper(str[j]);
		}
	}
	std::cout << std::endl;
	return 0;
}
