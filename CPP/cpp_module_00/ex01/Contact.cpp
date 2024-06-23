/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:43:08 by seonyun           #+#    #+#             */
/*   Updated: 2023/01/19 01:50:19 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	preData[0] = "First name: ";
	preData[1] = "Last name: ";
	preData[2] = "Nickname: ";
	preData[3] = "Phone number: ";
	preData[4] = "Darkest secret: ";
}

void	Contact::addContact()
{
	for (int i = 0; i < 5; i++)
	{
		data[i].clear();
		while (data[i].empty())
		{
			std::cout << preData[i];
			std::getline(std::cin, data[i]);
			if (std::cin.eof())
				exit(0);
		}
	}
}

void	Contact::printContact()
{
	for (int i = 0; i < 3; i++)
	{
		if (data[i].length() > 10)
			std::cout << data[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << data[i];
		if (i < 2)
			std::cout << "|";
	}
	std::cout << std::endl;
}

void	Contact::printAll()
{
	for (int i = 0; i < 5; i++)
		std::cout << preData[i] << data[i] << std::endl;
}
