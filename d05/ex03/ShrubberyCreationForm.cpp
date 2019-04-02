/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:58:40 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 16:10:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(/* args */) :
Form("BullShit", "Shrubbery Creation Form", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
Form(target, "Shrubbery Creation Form", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f) :
Form(f.getTarget(), f.getName(), f.getGradeRequiredToSign(), f.getGradeRequiredToExecute())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

void ShrubberyCreationForm::action() const
{
	std::string tree = "         - - -\n" \
"       -        -  -     --    -\n" \
"    -                 -         -  -\n" \
"                    -\n" \
"                   -                --\n" \
"   -          -            -              -\n" \
"   -            '-,        -               -\n" \
"   -              'b      *\n" \
"    -              '$    #-                --\n" \
"   -    -           $:   #:               -\n" \
" --      -  --      *#  @):        -   - -\n" \
"              -     :@,@):   ,-**:'   -\n" \
"  -      -,         :@@*: --**'      -   -\n" \
"           '#o-    -:(@'-@*'  -\n" \
"   -  -       'bq,--:,@@*'   ,*      -  -\n" \
"              ,p$q8,:@)'  -p*'      -\n" \
"       -     '  - '@@Pp@@*'    -  -\n" \
"        -  - --    Y7'.'     -  -\n" \
"                  :@):.\n" \
"                 .:@:'.\n" \
"               .::(@:.\n";


	std::ofstream newFile;
	std::stringstream ss;

	ss << this->getTarget() << "_shrubbery";

	newFile.open(ss.str());
	std::string line;
	newFile << tree;
	newFile.close();
}
