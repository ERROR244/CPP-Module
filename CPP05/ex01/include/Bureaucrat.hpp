/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:19:38 by ksohail           #+#    #+#             */
/*   Updated: 2024/11/28 11:57:21 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        std::string signMsg;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string _name, const int _grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName();
        std::string getSignMsg();
        void setSignMsg(std::string msg);
        int getGrade();
        void increment();
        void decrement();

        void signForm();

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
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &b);

#endif