/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:43:17 by seonyun           #+#    #+#             */
/*   Updated: 2023/01/19 21:54:45 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;

	while (true)
	{
		std::string input;
		while (input.empty())
		{
			std::cout << "Enter a command: ";
			std::getline(std::cin, input);
			if (std::cin.eof())
				exit (0);
		}
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cerr << "Invalid command" << std::endl;
	}
	return 0;
}
