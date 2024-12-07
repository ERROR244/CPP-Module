/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:41:24 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/07 11:38:34 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char* av[]) {
    PmergeMe sorter;
    
    if (sorter.parseInput(ac, av) == false) {
        return 1;
    }
    

    std::cout << "Before: ";
    sorter.print(0);
    std::cout << "\n";

    sorter.sortAndPrintResults();

    return 0;
}
