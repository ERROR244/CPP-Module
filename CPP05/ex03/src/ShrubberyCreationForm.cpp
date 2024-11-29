/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:09:48 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/29 14:12:56 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("unnamed") {
    // std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target) : Form("ShrubberyCreationForm", 145, 137), target(_target) {
    // std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form("ShrubberyCreationForm", 145, 137) {
    // std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    this->target = other.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    // std::cout << "ShrubberyCreationForm copy assignment called" << std::endl;
    if (this != &other) {
        this->target = other.target;
    }
    return (*this);
}


ShrubberyCreationForm::~ShrubberyCreationForm() {
    // std::cout << "ShrubberyCreationForm destructore called" << std::endl;
    
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (getIsSigned() == false)
        throw NotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();

    std::ofstream outFile((target + "_shrubbery").c_str());
    if (!outFile) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }

    outFile << "                     .        +          .      .          .\n"
            << "          .              _        .                    .\n"
            << "       ,                /;-._,-.____        ,-----.__\n"
            << "    ((        .       (_:#::_.:::. `-._   /:, /-._, `._,\n"
            << "     `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
            << "                        ,    `./  \\:. `.   )==-'  .\n"
            << "       .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
            << "  .           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
            << "         .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
            << "    .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
            << "     `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
            << "                \\:  `  X` _| _,\\/\'   .-'\n"
            << "  .               \":._:`\\____  /:'  /      .           .\n"
            << "                      \\::.  :\\/:'  /              +\n"
            << "     .                 `.:.  /:'  }      .\n"
            << "             .           ):_(:;   \\           .\n"
            << "                        /:. _/ ,  |\n"
            << "                     . (|::.     ,`                  .\n"
            << "       .                |::.    {\\\n"
            << "                        |::.:  \\ `.\n"
            << "                        |:::(\\    |\n"
            << "                O       |:::/{ }  |                  (o\n"
            << "                 )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
            << "            ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n";

    outFile.close();
}