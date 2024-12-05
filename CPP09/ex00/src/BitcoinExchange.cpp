/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:04:10 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/05 13:08:12 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

myMap::myMap() : std::map<std::string, float>() {}

myMap::myMap(const myMap& other) : std::map<std::string, float>(other) {}

myMap& myMap::operator=(const myMap& other) {
    if (this != &other) {
        std::map<std::string, float>::operator=(other);
    }
    return (*this);
}

myMap::~myMap() {}

int myMap::convertToInt(std::string& str) {
    std::istringstream iss(str);
    int value = 0;

    iss >> value;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("invalid argument");
    }
    return (value);
}

float myMap::convertToFloat(std::string& str) {
    std::istringstream iss(str);
    float value = 0.0f;

    iss >> value;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("can't convert dates to float");
    }
    return (value);
}

void myMap::addKeyValue(const std::string& key, const float value) {
    size_t C1 = key.find('-');
    size_t C2 = key.find('-', C1 + 1);
    size_t C3 = key.find('-', C2 + 1);

    if (C1 == std::string::npos || C2 == std::string::npos || C3 != std::string::npos) {
        throw std::invalid_argument("Key must be in the format YYYY-MM-DD.");
    }

    std::string year = key.substr(0, C1);
    std::string month = key.substr(C1 + 1, C2 - C1 - 1);
    std::string day = key.substr(C2 + 1);

    // std::cout << "Year: " << year << ", Month: " << month << ", Day: " << day << std::endl;

    int yearInt = convertToInt(year);
    int monthInt = convertToInt(month);
    int dayInt = convertToInt(day);

    if (yearInt <= 0) {
        throw std::invalid_argument("Year must be a positive number.");
    }
    if (monthInt < 1 || monthInt > 12) {
        throw std::invalid_argument("Month must be between 1 and 12.");
    }
    if (dayInt < 1 || dayInt > 31) {
        throw std::invalid_argument("Day must be between 1 and 31.");
    }
    if (value < 0) {
        throw std::invalid_argument("Value must be a non-negative number.");
    }
    (*this)[key] = value;
}


void myMap::addbuffer(std::ifstream& file) {
    std::string line;

    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);
        if (firstComma == std::string::npos || firstComma == 0) {
            throw std::invalid_argument("invalid exchange_rate or data");
        }
        else if (secondComma != std::string::npos) {
            throw std::invalid_argument("line hase more than one \",\"");
        }
        std::string key = line.substr(0, firstComma);
        std::string valueStr = line.substr(firstComma + 1);
        addKeyValue(key, convertToFloat(valueStr));  
    } 
}