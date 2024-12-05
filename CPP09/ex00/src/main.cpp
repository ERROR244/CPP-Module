/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:04:07 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/05 12:40:52 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    try {
        if (ac != 2) {
            throw std::invalid_argument("the program need 1 arg");
        }
        myMap mp;
        std::ifstream fileStream(av[1]);

        if (!fileStream.is_open()) {
            throw std::invalid_argument("Could not open file " + (std::string)av[1]);
        }
        mp.addbuffer(fileStream);
        myMap::reverse_iterator it = mp.rbegin();

        while (it != mp.rend()) {
            std::cout << it->first << "," << it->second << std::endl;
            ++it;
        }
    }
    catch (const std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
    return (0);
}
