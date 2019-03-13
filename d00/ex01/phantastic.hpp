/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phantastic.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:41:33 by pbie              #+#    #+#             */
/*   Updated: 2019/03/13 13:48:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHANTASTIC_H
#define PHANTASTIC_H

#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

std::string getInfo(std::string field);
void handleAdd(Phonebook *phonebook);
void handleFormat(std::string string);
void handleSearch(Phonebook *phonebook);
void printSpaces(int spaces);

#endif // PHANTASTIC_H
