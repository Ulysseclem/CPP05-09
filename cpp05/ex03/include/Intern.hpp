/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:17 by uclement          #+#    #+#             */
/*   Updated: 2024/02/27 13:54:21 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern
{
	private :

	public :
		//Orthodox Canonical Class Form
		Intern();
		Intern(const Intern &obj);
		Intern& operator=(const Intern &obj);
		~Intern();

		//Members
		AForm *makeForm(std::string formName, std::string target) const;
};

typedef AForm *(*funcPtr)(std::string target);

#endif