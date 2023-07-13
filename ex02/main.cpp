/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:31:17 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/13 16:31:22 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int	main(void)
{
	Base	*BaseObject;
	srand(time(NULL));

	std::cout << DARKBLUE << "GENERATE BASE OBJECT\nObject type:" << COLOR_DEFAULT << std::endl;
	BaseObject = generate();
	std::cout << COLOR_CYAN << "TRY IDENTIFYING BY REFERENCE:" << COLOR_DEFAULT << std::endl;
	identify(BaseObject);
	std::cout << COLOR_PURPLE << "TRY IDENTIFYING BY POINTER:" << COLOR_DEFAULT << std::endl;
	identify(*BaseObject);

	delete BaseObject;

	return (0);
}
