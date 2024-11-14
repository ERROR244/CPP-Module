/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail <ksohail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:19:41 by ksohail           #+#    #+#             */
/*   Updated: 2024/11/14 20:27:08 by ksohail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        Bureaucrat b(av[1], atoi(av[2]));

        std::cout << "\n\n";
        std::cout << b;
        b.decrement();
        std::cout << b;
        b.increment();
        std::cout << b;
        std::cout << "\n\n";
    }

    return (0);
}