/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:49:36 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 20:52:35 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIALSOURCE_H
#define IMATERIALSOURCE_H

#include "AMateria.hpp"

class IMateriaSource
{
private:
	/* data */
public:
	virtual ~IMateriaSource() { }
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif // IMATERIALSOURCE_H
