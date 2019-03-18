/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:56:08 by pbie              #+#    #+#             */
/*   Updated: 2019/03/18 11:23:44 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool doesFileExist (const std::string& name) {
	std::ifstream f(name.c_str());
	return f.good();
}

std::string getFileName(std::string str)
{
	int x = 0;
	int index = 0;

	while(str[x] != '\0'){
		if (str[x] == '.') index = x;
		x++;
	}
	if (index == 0) return str;
	return str.substr(0, index);
}

std::string replaceString(std::string subject, const std::string& search, const std::string& replace)
{
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
	pos += replace.length();
	}
	return subject;
}

std::string toUpper(std::string str)
{
	int x = -2;
	while (str[++x]) {
		if (str[x] >= 'a' && str[x] <= 'z') {
			str[x] = str[x] - 32;
		}
	}
	return str;
}

int main(int argc, char const *argv[])
{
	std::ifstream givenFile;
	std::ofstream newFile;

	if (argc < 4) return 0;
	if (!doesFileExist(argv[1])) {
		std::cout << "File does not exist" << std::endl;
		return 0;
	}
	if (strcmp(argv[2], "") == 0 || strcmp(argv[3], "") == 0) return 0;
	givenFile.open(argv[1]);
	std::string fileName = getFileName(argv[1]);
	fileName = toUpper(fileName).append(".replace");
	std::cout << fileName << std::endl;

	newFile.open(fileName);
	std::string line;
	while(getline(givenFile, line)){
		newFile << replaceString(line, argv[2], argv[3]) << "\n";
	}
	givenFile.close();
	newFile.close();
	return 0;
}
