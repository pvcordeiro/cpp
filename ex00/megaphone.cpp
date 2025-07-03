/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvcordeiro <pvcordeiro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:58:28 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/03 12:13:27 by pvcordeiro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (int i = 1; i < argc; i++) {
		std::string str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char)toupper(str[j]);
	}
	std::cout << std::endl;
	return (0);
}