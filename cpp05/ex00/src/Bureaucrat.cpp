/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:57 by uclement          #+#    #+#             */
/*   Updated: 2024/02/26 14:07:06 by uclement         ###   ########.fr       */
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
		_grade  -=  value;
}

void Bureaucrat::decrementGrade(const int value)
{
	if (_grade + value > 150)
		throw GradeTooLowException();
	else
		_grade  +=  value;
}