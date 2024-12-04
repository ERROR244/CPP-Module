/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:25:17 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/29 11:41:51 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string name;
        const int signGrade;
        const int executeGrade;
        bool isSigned;
    public:
        Form();
        Form(const std::string _name, const int _sGrade, const int _eGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        virtual ~Form();

        std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getIsSigned() const;
        
        void beSigned(Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw() {
                return "Grade is too high!";
            }
        };
        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw() {
                return "Grade is too low!";
            }
        };
        class NotSignedException : public std::exception {
        public:
            const char* what() const throw() {
                return "Form not signed!";
            }
        };
};

std::ostream &operator<<(std::ostream &os, Form &b);

#endif