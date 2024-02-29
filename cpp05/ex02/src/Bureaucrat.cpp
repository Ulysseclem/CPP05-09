/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:57 by uclement          #+#    #+#             */
/*   Updated: 2024/02/27 15:21:43 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructors
Bureaucrat::Bureaucrat() : _name(DEFAULT_NAME), _grade(DEFAULT_GRADE)
{
	if (DEBUG)
		std::cout << "Bureaucrat " << getName() << GREEN << " Constructed" << NC << std::endl; 
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else if (DEBUG)
		std::cout << "Bureaucrat " << getName() << GREEN << " Constructed (set)" << NC << std::endl; 
}

Bureaucrat::~Bureaucrat()
{
	if (DEBUG)
		std::cout << "Bureaucrat " << getName() << RED << " Destroyed" << NC << std::endl; 
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade)
{
	if (DEBUG)
		std::cout << "Bureaucrat " << getName() << GREEN << " Constructed (copy)" << NC << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
	{
		_grade = obj.getGrade();
		if (DEBUG)
			std::cout << "Bureaucrat" << YELLOW << " Assigned" << NC << std::endl; 
	}
	return *this;
}

//Overload
std::ostream &operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}

//Getters
std::string Bureaucrat::getName() const
{
	return(_name);	
}

int Bureaucrat::getGrade() const
{
	return(_grade);	
}

//Exception
const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Grade too low";
}

//Members
void Bureaucrat::incrementGrade(const int value)
{
	if (_grade - value < 1)
		throw GradeTooHighException();
	else
	{
		_grade  -=  value;
		std::cout << getName() << " is  promoted !" << std::endl;
	}
}

void Bureaucrat::decrementGrade(const int value)
{
	if (_grade + value > 150)
		throw GradeTooLowException();
	else
	{
		_grade  +=  value;
		std::cout << getName() << " is  demoted :(" << std::endl;
	}
}

void Bureaucrat::signForm(AForm& AForm)
{
	if (AForm.getIsSigned())
	{
		std::cout << CYAN << AForm.getName() << NC << " is already signed !" << std::endl;
		return ;
	}
	try
	{
		AForm.beSigned(*this);
		std::cout << getName() << " Signed " << CYAN << AForm.getName() << NC << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't  sign " << CYAN << AForm.getName() << NC << " because " << e.what() << " (catch)" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & AForm)
{
	try
	{
		std::cout << getName() << " try to execute " << CYAN << AForm.getName() << NC << std::endl;
		AForm.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't  execute " << CYAN << AForm.getName() << NC << " because " << e.what() << " (catch)" <<std::endl;
	}
}
