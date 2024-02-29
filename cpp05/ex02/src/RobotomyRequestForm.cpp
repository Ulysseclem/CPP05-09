/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:47:53 by uclement          #+#    #+#             */
/*   Updated: 2024/02/27 15:22:08 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>   


//Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm "<< GREEN << " Constructed" << NC << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), _target(obj._target)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm "<< GREEN << " Constructed (copy)" << NC << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
	{
		if (DEBUG)
			std::cout << "RobotomyRequestForm" << YELLOW << " Assigned" << NC << std::endl; 
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm" << RED << " Destroyed" << NC << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand(time(NULL));
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
	if (rand() % 2 == 1)
		std::cout << _target << " has been " << CORAIL << "lo" << GREEN_TREE << "bo" << PINK << "to" << DARK_RED << "mi" << YELLOW << "zed" << NC << " !" << std::endl;
}