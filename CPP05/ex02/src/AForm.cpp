/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:34:53 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/29 11:41:34 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("bob"), signGrade(150), executeGrade(150), isSigned(false) {
    // std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string _name, const int _sGrade, const int _eGrade) : name(_name), signGrade(_sGrade), executeGrade(_eGrade), isSigned(false) {
    // std::cout << "AForm default constructor called" << std::endl;
    if (_sGrade < 1) {
        throw GradeTooHighException();
    }
    else if (_sGrade > 150) {
        throw GradeTooLowException();
    }
    if (_eGrade < 1) {
        throw GradeTooHighException();
    }
    else if (_eGrade > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm &other) : name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade), isSigned(other.isSigned) {
    // std::cout << "AForm copy constructor called" << std::endl;
    if (other.signGrade < 1) {
        throw GradeTooHighException();
    }
    else if (other.signGrade > 150) {
        throw GradeTooLowException();
    }
    if (other.executeGrade < 1) {
        throw GradeTooHighException();
    }
    else if (other.executeGrade > 150) {
        throw GradeTooLowException();
    }
}

AForm &AForm::operator=(const AForm &other) {
    // std::cout << "AForm copy assignment called" << std::endl;
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

AForm::~AForm() {
    // std::cout << "AForm destructore called" << std::endl;
}

std::string AForm::getName() const {
    return (name);
}

int AForm::getSignGrade() const {
    return (signGrade);
}

int AForm::getExecuteGrade() const {
    return (executeGrade);
}

bool AForm::getIsSigned() const {
    return (isSigned);
}

void AForm::beSigned(Bureaucrat &b) {
    int temp = b.getGrade();

    if (temp <= signGrade) {
        isSigned = true;
    }
    else {
        isSigned = false;
    }
    if (temp < 1) {
        throw GradeTooHighException();
    }
    if (temp > 150 || isSigned == false) {
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, AForm &b) {
    os << b.getName()
        << ", AForm signGrade "
        << b.getSignGrade()
        << ", AForm executeGrade "
        << b.getExecuteGrade()
        << ", is AForm signed ";
    if (b.getIsSigned() == 0)
        os << "\033[31mFalse\033[0m\n";
    else
        os << "\033[32mTrue\033[0m\n";
    return (os);
}
