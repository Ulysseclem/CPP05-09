/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:05 by uclement          #+#    #+#             */
/*   Updated: 2024/02/27 11:31:19 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREACRAT_HPP
# define BUREACRAT_HPP

// #define GREY		"\033[0;30m"
// #define RED			"\033[0;31m"
// #define GREEN		"\033[0;32m"
// #define YELLOW		"\033[0;33m"
// #define BLUE		"\033[0;34m"
// #define MAGENTA		"\033[0;35m"
// #define CYAN		"\033[0;36m"
// #define NC			"\033[0m"
// # define GREEN_B            "\033[32;01m"

#include "Color.hpp"

#ifndef DEBUG
# define DEBUG true
#endif

#include <fstream> 
#include <iostream>
#include <string>
#include <cstring>
#include "AForm.hpp"

#define DEFAULT_NAME "bob"
#define DEFAULT_GRADE 50

class AForm;

class Bureaucrat
{
	private :
		const std::string	_name;
		int					_grade;
		
	public :

		//Orthodox Canonical Class Form
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat& operator=(const Bureaucrat &obj);
		~Bureaucrat();

		//Getters
		std::string getName() const;
		int getGrade() const;
		
		//Members
		void incrementGrade(const int value);
		void decrementGrade(const int value);
		void signForm(AForm& AForm);
		void executeForm(AForm const & AForm) ;

		//Exeption
		class GradeTooHighException : public std::exception
		{
			public :
				const char *what() const throw();	
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char *what() const throw();	
		};
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& obj);

#endif