/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:21:54 by uclement          #+#    #+#             */
/*   Updated: 2024/02/26 12:46:38 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FORM_HPP
# define  FORM_HPP

#include "Bureaucrat.hpp"

#define  DEFAULT_CONTRACT_NAME "Bail"
#define  DEFAULT_SIGNED 50
#define  DEFAULT_EXECUTE 50

class Bureaucrat;

class Form
{
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSigned;
		const int			_gradeExecute;

	public :
		//Orthodox Canonical Class Form
		Form();
		Form(std::string name, const int gradeSigned, const int gradeExecute);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form();

		//Getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int	getGradeSigned() const;
		int	getGradeExecute() const;
		
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

		//members
		void	beSigned(const Bureaucrat& emlpoyee);
};

std::ostream &operator<<(std::ostream& os, const Form& obj);

#endif