/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:28:12 by pbie              #+#    #+#             */
/*   Updated: 2019/04/03 22:56:05 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <time.h>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void *serialize(void)
{
	char *str1 = new char[9];
	char *str2 = new char[9];
	char alphaNum[] = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int x = 0;
	while(x < 8)
	{
		int random1 = rand() % 62;
		str1[x] = alphaNum[random1];
		x++;
	}
	str1[x] = '\0';
	std::cout << "rand string1: " << str1 << std::endl;

	int random = 100 + rand() % ((200 + 1) - 100);
	std::cout << "random int " << random << std::endl;
	char intStr[sizeof(random)];
	*(reinterpret_cast<int*>(intStr)) = random;
	x = 0;
	while(x < 8)
	{
		int random1 = rand() % 62;
		str2[x] = alphaNum[random1];
		x++;
	}
	str2[x] = '\0';

	std::cout << "rand string2: " << str2 << std::endl;

	char *fullStr = new char[20];
	x = 0;
	while(x < 8)
	{
		fullStr[x] = str1[x];
		x++;
	}
	int y = 0;
	while(x < 12)
	{
		fullStr[x] = intStr[y];
		x++;
		y++;
	}
	y = 0;
	while(x < 20){
		fullStr[x] = str2[y];
		x++;
		y++;
	}
	fullStr[x] = '\0';
	
	return reinterpret_cast<void *>(fullStr);
}

Data *deserialize(void * raw)
{
	Data *data = new Data;
	data->s1.assign(reinterpret_cast<char*>(raw), 8);
	data->n = *reinterpret_cast<int*>(&reinterpret_cast<char*>(raw)[8]);
	data->s2.assign(&reinterpret_cast<char*>(raw)[12], 8);
	std::cout << "\n" << std::endl;
	std::cout << "deserialized s1: " << data->s1 << std::endl;
	std::cout << "deserialized n: " << data->n << std::endl;
	std::cout << "deserialized s2: " << data->s2 << std::endl;
	return data;
}

int main()
{
	srand(time(0) + rand());
	deserialize(serialize());
	return 0;
}
