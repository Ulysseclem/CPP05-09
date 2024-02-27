/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:41:41 by uclement          #+#    #+#             */
/*   Updated: 2024/02/26 16:15:10 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFROM_HPP
#define ROBOTOMYREQUESTFROM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		const std::string _target;
		
	public :
		//Orthodox Canonical Class Form
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();

		//Members
		void execute(Bureaucrat const & executor) const;
		
};

#endif
