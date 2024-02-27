/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:47:53 by uclement          #+#    #+#             */
/*   Updated: 2024/02/27 11:31:15 by uclement         ###   ########.fr       */
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
	std::string nameFile = _target + "_ShrubberyCreationForm";
	std::ofstream outputFile(nameFile.c_str());
	if (outputFile.is_open())
	{
		outputFile   << "   ^      ^   " << std::endl;
		outputFile << "  / \\    / \\  " << std::endl;
		outputFile << " /   \\  /   \\ " << std::endl;
		outputFile << "/_____\\/_____\\" << std::endl;
		outputFile  << "   ||     ||   " << std::endl;
		outputFile.close();
	}
	
}