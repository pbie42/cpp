/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:10:11 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 14:11:06 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
#define HUMAN_H

#include "Brain.hpp"
#include <string>

class Human
{
private:
	const Brain brain;
public:
	Human();
	~Human();
	std::string identify(void) const;
	const Brain &getBrain(void) const;
};

#endif // HUMAN_H
