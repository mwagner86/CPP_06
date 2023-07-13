/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:23:48 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/13 16:23:52 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	if (argc != 2)	{
		std::cout << "Error: Wrong number of arguments!\nInsert: <char>, <int>, <float> or <double>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);


	return 0;
}
