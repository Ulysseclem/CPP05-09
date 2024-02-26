/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:28:23 by uclement          #+#    #+#             */
/*   Updated: 2024/02/26 15:30:38 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//Constructor
AForm::AForm() : _name(DEFAULT_CONTRACT_NAME), _gradeSigned(DEFAULT_SIGNED), _gradeExecute(DEFAULT_EXECUTE)
{
	_isSigned = false;
	if(DEBUG)
		std::cout << "AForm " << getName() << GREEN << " Constructed" << NC << std::endl; 
}

AForm::AForm(const std::string name, const int value1, const int value2) : \
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

AForm::AForm(const AForm& obj) : _name(obj._name), _gradeSigned(obj._gradeSigned), _gradeExecute(obj._gradeExecute)
{
	_isSigned = obj._isSigned;
	if(DEBUG)
		std::cout << "Form " << getName() << GREEN << " Constructed (copy)" << NC << std::endl; 
}

AForm&   AForm::operator=( const AForm& obj )
{
    if ( this != &obj )
        _isSigned = obj.getIsSigned();
    return *this;
}

AForm::~AForm()
{
	if (DEBUG)
			std::cout << "Form " << getName() << RED << " Destroyed" << NC << std::endl;
}

//Getters

std::string	AForm::getName() const
{
	return _name;
}

bool		AForm::getIsSigned() const
{
	return _isSigned;
}

 int	AForm::getGradeSigned() const
{
	return _gradeSigned;
}

 int	AForm::getGradeExecute() const
{
	return _gradeExecute;
}

std::ostream &operator<<(std::ostream& os, const AForm& obj)
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
const char *AForm::GradeTooHighException::what() const throw() 
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() 
{
	return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() 
{
	return "Form not signed";
}

//Members
void	AForm::beSigned(const Bureaucrat& emlpoyee)
{
	if (emlpoyee.getGrade() > getGradeSigned())
		throw  AForm::GradeTooLowException();
	else
		_isSigned = true;
}