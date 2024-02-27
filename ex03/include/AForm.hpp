/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:21:54 by uclement          #+#    #+#             */
/*   Updated: 2024/02/26 15:07:20 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  AFORM_HPP
# define  AFORM_HPP

#include "Bureaucrat.hpp"

#define  DEFAULT_CONTRACT_NAME "Bail"
#define  DEFAULT_SIGNED 50
#define  DEFAULT_EXECUTE 50

class Bureaucrat;

class AForm
{
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSigned;
		const int			_gradeExecute;

	public :
		//Orthodox Canonical Class Form
		AForm();
		AForm(std::string name, const int gradeSigned, const int gradeExecute);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm();

		//Getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeSigned() const;
		int			getGradeExecute() const;
		
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
		class FormNotSignedException : public std::exception
		{
			public :
				const char *what() const throw();	
		};

		//members
		void	beSigned(const Bureaucrat& emlpoyee);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream& os, const AForm& obj);

#endif