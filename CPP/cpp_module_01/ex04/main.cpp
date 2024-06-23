/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 06:00:50 by seonyun           #+#    #+#             */
/*   Updated: 2023/01/23 06:00:52 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string		filename = av[1];
		std::string		s1 = av[2];
		std::string		s2 = av[3];
		std::ifstream	file(filename);

		if(file.is_open())
		{
			std::ofstream	newFile(filename + ".replace");
			std::string		line;

			while (std::getline(file, line))
			{
				size_t pos = 0;
				while(s1.length() && (pos = line.find(s1, pos)) != std::string::npos)
				{
					line.erase(pos, s1.length());
					line.insert(pos, s2);
					pos += s2.length();
				}
				newFile << line << std::endl;
			}
			file.close();
			newFile.close();
		}
		else
			std::cerr << "Error: File could not be opened" << std::endl;
	}
	else
		std::cerr << "Error: Wrong number of arguments" << std::endl;
	return 0;
}
