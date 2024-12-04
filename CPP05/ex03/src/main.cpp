/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:19:41 by ksohail           #+#    #+#             */
/*   Updated: 2024/11/29 16:04:53 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>

int main() {
    try {
        Bureaucrat b("bob", 5);
        Intern someRandomIntern;

        Form* f1 = someRandomIntern.makeForm("PresidentialPardonForm", "bob");
        Form* f2 = someRandomIntern.makeForm("ShrubberyCreationForm", "bob");
        Form* f3 = someRandomIntern.makeForm("RobotomyRequestForm", "bob");
        Form* f4 = someRandomIntern.makeForm("Ba33", "bob");

        std::cout << b  << std::endl;
        std::cout << *f1 << std::endl;
        std::cout << *f2 << std::endl;
        std::cout << *f3 << std::endl;

        std::cout << "\n\n";
        
        b.signForm(*f1);
        b.executeForm(*f1);
        std::cout << "\n\n";

        b.signForm(*f2);
        b.executeForm(*f2);
        std::cout << "\n\n";

        b.signForm(*f3);
        b.executeForm(*f3);
        std::cout << "\n\n";

        std::cout << b  << std::endl;
        std::cout << *f1 << std::endl;
        std::cout << *f2 << std::endl;
        std::cout << *f3 << std::endl;

        delete f1;
        delete f2;
        delete f3;
    }
    catch (const Form::NotSignedException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooHighException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return (0);
}

// int main(int ac, char **av) {
//     if (ac == 2)
//     {
//         try {
//             Bureaucrat b("bob", atoi(av[1]));
//             ShrubberyCreationForm f1("home");
//             RobotomyRequestForm f2("roboto");
//             PresidentialPardonForm f3("someone");

//             std::cout << b << std::endl;
//             std::cout << f1 << std::endl;
//             std::cout << f2 << std::endl;
//             std::cout << f3 << std::endl;

//             std::cout << "\n\n";
            
//             b.signForm(f1);
//             b.executeForm(f1);
//             std::cout << "\n\n";

//             b.signForm(f2);
//             b.executeForm(f2);
//             std::cout << "\n\n";

//             b.signForm(f3);
//             b.executeForm(f3);
//             std::cout << "\n\n";


//             std::cout << b << std::endl;
//             std::cout << f1 << std::endl;
//             std::cout << f2 << std::endl;
//             std::cout << f3 << std::endl;
//         }
//         catch (const Form::NotSignedException& e) {
//             std::cout << "Caught exception: " << e.what() << std::endl;
//         }
//         catch (const Form::GradeTooHighException& e) {
//             std::cout << "Caught exception: " << e.what() << std::endl;
//         }
//         catch (const Form::GradeTooLowException& e) {
//             std::cout << "Caught exception: " << e.what() << std::endl;
//         }
//         catch (const Bureaucrat::GradeTooHighException& e) {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//         }
//         catch (const Bureaucrat::GradeTooLowException& e) {
//             std::cout << "Caught exception: " << e.what() << std::endl;
//         }
//     }

//     return (0);
// }
