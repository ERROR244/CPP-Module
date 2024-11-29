/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:09:46 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/29 11:54:32 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("unnamed") {
    // std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target) : AForm("RobotomyRequestForm", 72, 45), target(_target) {
    // std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45) {
    // std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    this->target = other.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    // std::cout << "RobotomyRequestForm copy assignment called" << std::endl;
    if (this != &other) {
        this->target = other.target;
    }
    return (*this);
}


RobotomyRequestForm::~RobotomyRequestForm() {
    // std::cout << "RobotomyRequestForm destructore called" << std::endl;
    
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (getIsSigned() == false)
        throw NotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::cout << "Bzzzz...\nZzzz...\nVrrrr...\n";
    if (std::rand() % 2 == 0) {
        std::cout << target << " has been robotomized successfully!\n";
    }
    else {
        std::cout << "The robotomy of " << target << " has failed.\n";
    }
}
