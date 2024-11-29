/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:09:44 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/29 12:05:05 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("unnamed") {
    // std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target) : AForm("PresidentialPardonForm", 25, 5), target(_target) {
    // std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PresidentialPardonForm", 25, 5) {
    // std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    this->target = other.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    // std::cout << "PresidentialPardonForm copy assignment called" << std::endl;
    if (this != &other) {
        this->target = other.target;
    }
    return (*this);
}


PresidentialPardonForm::~PresidentialPardonForm() {
    // std::cout << "PresidentialPardonForm destructore called" << std::endl;
    
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (getIsSigned() == false)
        throw NotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    std::cout << target + " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
