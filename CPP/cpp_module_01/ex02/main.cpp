/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:16:35 by seonyun           #+#    #+#             */
/*   Updated: 2023/01/20 09:04:11 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "The memory address of the string variable: " << &string << std::endl;
	std::cout << "The memory address held by stringPTR     : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF     : " << &stringREF << std::endl;

	std::cout << "The value of the string variable         : " << string << std::endl;
	std::cout << "The value pointed to by stringPTR        : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF        : " << stringREF << std::endl;
}
