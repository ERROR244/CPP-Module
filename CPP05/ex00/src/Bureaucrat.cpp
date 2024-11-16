/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail <ksohail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:19:39 by ksohail           #+#    #+#             */
/*   Updated: 2024/11/16 02:43:29 by ksohail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, const int _grade) : name(_name), grade(_grade) {
    // std::cout << "Bureaucrat default constructor called" << std::endl;
    if (_grade < 1) {
        throw GradeTooHighException();
    }
    if (_grade > 150) {
        throw GradeTooLowException();
    }
    this->grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) {
    // std::cout << "Bureaucrat copy constructor called" << std::endl;
    if (other.grade < 1) {
        throw GradeTooHighException();
    }
    if (other.grade > 150) {
        throw GradeTooLowException();
    }
    this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    // std::cout << "Bureaucrat copy assignment called" << std::endl;
    if (this != &other) {
        if (other.grade < 1) {
            throw GradeTooHighException();
        }
        if (other.grade > 150) {
            throw GradeTooLowException();
        }
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    // std::cout << "Bureaucrat destructore called" << std::endl;
}


std::string Bureaucrat::getName() {
    return (name);
}

int Bureaucrat::getGrade() {
    return (grade);
}

void Bureaucrat::increment() {
    if (grade -1 < 1) {
        throw GradeTooHighException();
    }
    if (grade -1 > 150) {
        throw GradeTooLowException();
    }
    --this->grade;
}

void Bureaucrat::decrement() {
    if (grade +1 < 1) {
        throw GradeTooHighException();
    }
    if (grade +1 > 150) {
        throw GradeTooLowException();
    }
    ++this->grade;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (os);
}
