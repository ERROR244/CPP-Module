/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:19:41 by ksohail           #+#    #+#             */
/*   Updated: 2024/11/29 11:28:53 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>

int main() {
    try {
        Bureaucrat b1("bob", 1);
        Bureaucrat b2("bob", 10);
        Form f1("1337", 5, 1);
        Form f2("1337", 5, 1);

        std::cout << b1;
        std::cout << b2;
        std::cout << f1;
        std::cout << f2;

        std::cout << "\n\n";
        
        b1.signForm(f1);
        b2.signForm(f2);
        
        std::cout << "\n\n";

        std::cout << b1;
        std::cout << b2;
        std::cout << f1;
        std::cout << f2;
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
    return 0;
}

// int main(int ac, char **av) {
//     if (ac == 3)
//     {
//         try {
//             Bureaucrat b("bob", atoi(av[2]));
//             Form f("1337", atoi(av[1]), 1);

//             std::cout << b;
//             std::cout << f;

//             std::cout << "\n\n";
            
//             b.signForm(f);
            
//             std::cout << "\n\n";

//             std::cout << b;
//             std::cout << f;
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
