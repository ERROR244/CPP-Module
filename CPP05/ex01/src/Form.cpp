/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:34:53 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/28 12:02:29 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("bob"), signGrade(150), executeGrade(150), isSigned(false) {
    // std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string _name, const int _sGrade, const int _eGrade, const bool _isSigned) : name(_name), signGrade(_sGrade), executeGrade(_eGrade), isSigned(_isSigned) {
    // std::cout << "Form default constructor called" << std::endl;
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

Form::Form(const Form &other) : name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade), isSigned(other.isSigned) {
    // std::cout << "Form copy constructor called" << std::endl;
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

Form &Form::operator=(const Form &other) {
    // std::cout << "Form copy assignment called" << std::endl;
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

Form::~Form() {
    // std::cout << "Form destructore called" << std::endl;
}

std::string Form::getName() {
    return (name);
}

int Form::getSignGrade() {
    return (signGrade);
}

int Form::getExecuteGrade() {
    return (executeGrade);
}

bool Form::getIsSigned() {
    return (isSigned);
}

void Form::beSigned(Bureaucrat &b) {
    int temp = b.getGrade();

    if (temp < 1) {
        throw GradeTooHighException();
    }
    if (temp > 150) {
        throw GradeTooLowException();
    }
    if (temp <= signGrade) {
        isSigned = true;
        b.setSignMsg(b.getName() + " signed " + name);
    }
    else {
        isSigned = false;
        b.setSignMsg(b.getName() + " couldn’t sign " + name + " because the grade is less than the requirement");
    }
}

std::ostream &operator<<(std::ostream &os, Form &b) {
    os << b.getName()
        << ", Form signGrade "
        << b.getSignGrade()
        << ", Form executeGrade "
        << b.getExecuteGrade()
        << ", is Form signed ";
    if (b.getIsSigned() == 0)
        os << "\033[31mFalse\033[0m\n";
    else
        os << "\033[32mTrue\033[0m\n";
    return (os);
}
