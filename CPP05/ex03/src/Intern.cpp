/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:09:42 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/29 16:05:32 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

Intern::Intern() {
    // std::cout << "Intern default constructor called" << std::endl;
    formArray[0].name = "PresidentialPardonForm";
    formArray[0].creator = &createPresidentialPardonForm;
    formArray[1].name = "RobotomyRequestForm";
    formArray[1].creator = &createRobotomyRequestForm;
    formArray[2].name = "ShrubberyCreationForm";
    formArray[2].creator = &createShrubberyCreationForm;
}

Intern::Intern(const Intern &other) {
    // std::cout << "Intern copy constructor called" << std::endl;
    formArray[0].name = other.formArray[0].name;
    formArray[0].creator = other.formArray[0].creator;
    formArray[1].name = other.formArray[1].name;
    formArray[1].creator = other.formArray[1].creator;
    formArray[2].name = other.formArray[1].name;
    formArray[2].creator = other.formArray[2].creator;
}

Intern &Intern::operator=(const Intern &other) {
    // std::cout << "Intern copy assignment called" << std::endl;
    if (this != &other) {
        formArray[0].name = other.formArray[0].name;
        formArray[0].creator = other.formArray[0].creator;
        formArray[1].name = other.formArray[1].name;
        formArray[1].creator = other.formArray[1].creator;
        formArray[2].name = other.formArray[1].name;
        formArray[2].creator = other.formArray[2].creator;
    }
    return (*this);
}

Intern::~Intern() {
    // std::cout << "Intern destructore called" << std::endl;
}

Form* createPresidentialPardonForm(const std::string& target) {
    return (new PresidentialPardonForm(target));
}

Form* createRobotomyRequestForm(const std::string& target) {
    return (new RobotomyRequestForm(target));
}

Form* createShrubberyCreationForm(const std::string& target) {
    return (new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(std::string formName, std::string target) {
    for (int i = 0; i < 3; ++i) {
        if (formArray[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (formArray[i].creator(target));
        }
    }
    std::cerr << "Error: Form name '" << formName << "' isn't in the form menu." << std::endl;
    return (NULL);
}
