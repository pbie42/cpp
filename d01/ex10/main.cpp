/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:49:56 by pbie              #+#    #+#             */
/*   Updated: 2019/03/18 17:14:20 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

bool doesFileExist (const std::string& name) {
	std::ifstream f(name.c_str());
	return f.good();
}

int main(int argc, char const *argv[])
{
	std::string input;
	std::ifstream givenFile;
	int x = 1;
	if (argc == -1) return 0;
	while(x < argc){
		std::cout << "\n" << argv[x] << "\n" << std::endl;
		if (strcmp(argv[x], "-") == 0)
			while(std::getline(std::cin, input))
				std::cout << input << std::endl;
		if (doesFileExist(argv[x]))
		{
			std::cout << "file exists" << std::endl;
			givenFile.open(argv[x]);
			while(std::getline(givenFile, input))
				std::cout << input << std::endl;
			givenFile.close();
		}
		x++;
	}
	return 0;
}
