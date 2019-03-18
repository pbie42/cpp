/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:53:08 by pbie              #+#    #+#             */
/*   Updated: 2019/03/18 15:30:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>

Logger::Logger(const std::string fileName)
{
	this->fileName = fileName;
}

Logger::~Logger()
{
}

void Logger::logToConsole(const std::string message)
{
	std::cout << this->makeLogEntry(message) << std::endl;
}

void Logger::logToFile(const std::string message)
{
	std::ofstream outfile;

	outfile.open(this->fileName, std::ios_base::app);
	outfile << this->makeLogEntry(message);
	outfile.close();
}

std::string Logger::makeLogEntry(const std::string message)
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	std::stringstream timeStampEntry;
	std::string str;

	timeStampEntry << now->tm_mday << "/" << (now->tm_mon + 1) << "/" << (now->tm_year + 1900) << " ";
	timeStampEntry << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec  << " - " << message;
	str = timeStampEntry.str();
	return str;
}

void Logger::log(std::string const &dest, std::string const &message)
{
	typedef void (Logger::*Actions)(std::string const message);

	Actions actions[3] = { &Logger::logToConsole, &Logger::logToFile };

	std::string actionsNames[] =
	{
		"logToConsole",
		"logToFile"
	};

	int actionNum = 2;
	int x = 0;

	while(x < actionNum){
		if (actionsNames[x] == dest)
			(this->*actions[x])(message);
		x++;
	}
}
