/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:07:27 by seonyun           #+#    #+#             */
/*   Updated: 2023/01/20 07:28:49 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact
{
	private:
		std::string	preData[5];
		std::string	data[5];

	public:
		Contact();

		void	addContact();
		void	printContact();
		void	printAll();
};

#endif
