/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:46:46 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 13:39:40 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain
{
private:
	std::string name;
	int iq;
public:
	Brain(std::string name, int iq);
	~Brain();
	std::string identify(void) const;
};

#endif // BRAIN_H
