/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:09:48 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/29 15:00:45 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Bureaucrat.hpp"

struct FormArray {
    std::string name;
    Form* (*creator)(const std::string& target);
};

class Intern {
    private:
        FormArray formArray[3];
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();
        
        Form *makeForm(std::string formName, std::string target);
};
Form* createPresidentialPardonForm(const std::string& target);
Form* createRobotomyRequestForm(const std::string& target);
Form* createShrubberyCreationForm(const std::string& target);

#endif