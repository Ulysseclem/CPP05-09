/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:47:53 by uclement          #+#    #+#             */
/*   Updated: 2024/02/26 16:05:38 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm "<< GREEN << " Constructed" << NC << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), _target(obj._target)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm "<< GREEN << " Constructed (copy)" << NC << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
	{
		if (DEBUG)
			std::cout << "Bureaucrat" << YELLOW << " Assigned" << NC << std::endl; 
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm" << RED << " Destroyed" << NC << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExecute())
		throw GradeTooLowException();
	std::cout  << GREEN_B << "   ^   " << std::endl;
    std::cout << "  / \\  " << std::endl;
    std::cout << " /   \\ " << std::endl;
    std::cout << "/_____\\" << std::endl;
    std::cout  << BROWN << "   ||" << NC << std::endl;
}