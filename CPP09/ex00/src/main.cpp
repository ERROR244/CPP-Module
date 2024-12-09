/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:04:07 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/05 21:26:45 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    try {
        if (ac != 2) {
            throw std::invalid_argument("the program need 1 arg");
        }
        myMap mapDataBase;
        std::ifstream dataBase("data.csv");

        if (!dataBase.is_open()) {
            throw std::invalid_argument("Could not open file " + (std::string)av[1]);
        }
        mapDataBase.addBufferExchange(dataBase);
        dataBase.close();
        std::ifstream inputFile(av[1]);
        if (!inputFile.is_open()) {
            throw std::invalid_argument("Could not open file " + (std::string)av[1]);
        }
        addBufferValue(inputFile, mapDataBase);
        inputFile.close();

    }
    catch (const std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
    return (0);
}
