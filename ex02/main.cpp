/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/02/27 14:06:50 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat  *bureaucrat = new Bureaucrat("Bureaucrat", 40);
        AForm        *form = new PresidentialPardonForm("Pardon");
        RobotomyRequestForm		form2 = RobotomyRequestForm("Charly");
        ShrubberyCreationForm	form3 = ShrubberyCreationForm("Finland");

        std::cout << *bureaucrat << std::endl;
        std::cout << *form << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Sign Form section " << std::endl;
        bureaucrat->signForm(*form);
        bureaucrat->signForm(form2);
        bureaucrat->signForm(form3);

        std::cout << "----------------------------------------" << std::endl;
        std::cout << *bureaucrat << std::endl;
        std::cout << *form << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;

        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Execute Form section " << std::endl;
        bureaucrat->executeForm(*form);
        bureaucrat->executeForm(form2);
        bureaucrat->executeForm(form3);
    
        delete bureaucrat;
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "(catch)" << std::endl;
    }

    return (0);
}