/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:47:40 by uclement          #+#    #+#             */
/*   Updated: 2024/02/27 13:54:12 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	if (DEBUG)
		std::cout << "Intern " << GREEN << " Constructed" << NC << std::endl;
}

Intern::Intern(const Intern& obj)
{
	*this = obj;
	if (DEBUG)
		std::cout << "Intern " << GREEN << " Constructed" << NC << std::endl;
}

Intern &Intern::operator=(const Intern& obj)
{
	(void)obj;
	return *this;
}

Intern::~Intern()
{
	if (DEBUG)
		std::cout << "Intern " << RED << " Destructed" << NC << std::endl;
}


AForm *makeShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *makeRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *makePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}


AForm *Intern::makeForm(std::string name, std::string target) const
{
    std::string formNameArray[3] = {"shrubbery creation", 
									"robotomy request", 
									"presidential pardon"};
    funcPtr funcArray[3] = {&makeShrubberyCreationForm, 
							&makeRobotomyRequestForm, 
							&makePresidentialPardonForm};
    for (int i = 0; i < 3; i++)
    {
        if (name == formNameArray[i])
        {
            std::cout << "Intern creates " << CYAN << name << NC << std::endl;
            return (funcArray[i])(target);
        }
    }
    std::cout << "Intern can't create " << CYAN << name << NC << std::endl;
    return NULL;
}

//autre methode

// AForm *Intern::makeForm(std::string name, std::string target)
// {
//     std::string formListName[] = {
//         "robotomy request",
//         "presidential pardon",
//         "shrubbery creation"
//     };
//     AForm*    formNew[] = {
//         new RobotomyRequestForm(target),
//         new PresidentialPardonForm(target),
//         new ShrubberyCreationForm(target)
//     };
// 	for (int i = 0; i < 3; i++)
// 	{
// 		if (formListName[i] != name)
// 			delete formNew[i];
// 	}
// 	for (int i = 0; i < 3; i++)
// 	{
// 		if (formListName[i] == name)
// 		{
// 			std::cout << "Intern creates " << CYAN << name << NC << std::endl;
// 			return formNew[i];
// 		}
// 	}
// 	return NULL;
// }

