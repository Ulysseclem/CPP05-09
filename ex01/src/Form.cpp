/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:28:23 by uclement          #+#    #+#             */
/*   Updated: 2024/02/26 13:55:41 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructor
Form::Form() : _name(DEFAULT_CONTRACT_NAME), _gradeSigned(DEFAULT_SIGNED), _gradeExecute(DEFAULT_EXECUTE)
{
	_isSigned = false;
	if(DEBUG)
		std::cout << "Form " << getName() << GREEN << " Constructed" << NC << std::endl; 
}

Form::Form(const std::string name, const int value1, const int value2) : \
_name(name), _gradeSigned(value1),  _gradeExecute(value2)
{
	if (value1 < 1 || value2 < 1)
		throw GradeTooHighException();
	else if (value1 >150 || value2 > 150)
		throw GradeTooLowException();
	else
		_isSigned = false;
	if(DEBUG)
		std::cout << "Form " << getName() << GREEN << " Constructed" << NC << std::endl; 
}

Form::Form(const Form& obj) : _name(obj._name), _gradeSigned(obj._gradeSigned), _gradeExecute(obj._gradeExecute)
{
	_isSigned = obj._isSigned;
	if(DEBUG)
		std::cout << "Form " << getName() << GREEN << " Constructed (copy)" << NC << std::endl; 
}

Form&   Form::operator=( const Form& obj )
{
    if ( this != &obj )
        _isSigned = obj.getIsSigned();
    return *this;
}

Form::~Form()
{
	if (DEBUG)
			std::cout << "Form " << getName() << RED << " Destroyed" << NC << std::endl;
}

//Getters

std::string	Form::getName() const
{
	return _name;
}

bool		Form::getIsSigned() const
{
	return _isSigned;
}

 int	Form::getGradeSigned() const
{
	return _gradeSigned;
}

 int	Form::getGradeExecute() const
{
	return _gradeExecute;
}

std::ostream &operator<<(std::ostream& os, const Form& obj)
{
	std::string boolSigned;
	if (obj.getIsSigned())
		boolSigned =  "signed";
	else
		boolSigned = "not signed";
	os << "Form name : " << CYAN << obj.getName()  << NC
	<< ", status : " << boolSigned 
	<< ", grade to be signed " << obj.getGradeSigned() 
	<< ", grade to be executed " << obj.getGradeExecute() << ".";
	return os;
}

//Exception
const char *Form::GradeTooHighException::what() const throw() 
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() 
{
	return "Grade too low";
}

//Members
void	Form::beSigned(const Bureaucrat& emlpoyee)
{
	if (emlpoyee.getGrade() > getGradeSigned())
		throw  Form::GradeTooLowException();
	else
		_isSigned = true;
}