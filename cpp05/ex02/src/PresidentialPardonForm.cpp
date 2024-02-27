/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:47:53 by uclement          #+#    #+#             */
/*   Updated: 2024/02/27 14:00:11 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <stdlib.h>   


//Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm "<< GREEN << " Constructed" << NC << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), _target(obj._target)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm "<< GREEN << " Constructed (copy)" << NC << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
	{
		if (DEBUG)
			std::cout << "PresidentialPardonForm" << YELLOW << " Assigned" << NC << std::endl; 
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm" << RED << " Destroyed" << NC << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void) executor;
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
	std::cout << _target << " has been " << C_G_GREEN_TREE << " PARDONNED BY ZAPHOD BEEBLEBROX !" << NC << std::endl;
}