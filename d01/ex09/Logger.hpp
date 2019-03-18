/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:53:30 by pbie              #+#    #+#             */
/*   Updated: 2019/03/18 14:59:04 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
private:
	std::string fileName;
	void logToConsole(const std::string message);
	void logToFile(const std::string message);
	std::string makeLogEntry(const std::string message);
public:
	Logger(const std::string fileName);
	~Logger();
	void log(std::string const &dest, std::string const &message);
};

#endif // LOGGER_H
