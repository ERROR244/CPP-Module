/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail <ksohail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:19:41 by ksohail           #+#    #+#             */
/*   Updated: 2024/11/16 02:33:34 by ksohail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>

int main() {
    try {
        Bureaucrat bob("Bob", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 151);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat charlie("Charlie", 50);
        charlie.decrement();
        std::cout << charlie.getName() << "'s grade: " << charlie.getGrade() << std::endl;
        charlie.increment();
        std::cout << charlie.getName() << " was promoted successfully!" << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}

// int main(int ac, char **av)
// {
//     if (ac == 3)
//     {
//         try {
//             Bureaucrat b(av[1], atoi(av[2]));

//             std::cout << b;
//             b.increment();
//             std::cout << b;
//             b.decrement();
//             std::cout << b;
//         }
//         catch (const Bureaucrat::GradeTooHighException& e) {
//             std::cout << "Caught exception: " << e.what() << std::endl;
//         }
//         catch (const Bureaucrat::GradeTooLowException& e) {
//             std::cout << "Caught exception: " << e.what() << std::endl;
//         }

//     }

//     return (0);
// }