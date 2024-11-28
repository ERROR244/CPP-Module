/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:19:41 by ksohail           #+#    #+#             */
/*   Updated: 2024/11/28 12:02:09 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>

// int main() {

//     return 0;
// }

int main(int ac, char **av)
{
    if (ac == 6)
    {
        try {
            Bureaucrat b("bob", atoi(av[1]));
            Form f(av[2], atoi(av[3]), atoi(av[4]), atoi(av[5]));

            std::cout << b;
            std::cout << f;
            f.beSigned(b);
            b.signForm();
        }
        catch (const Form::GradeTooHighException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        catch (const Form::GradeTooLowException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

    }

    return (0);
}
