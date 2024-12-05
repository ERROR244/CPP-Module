/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:04:10 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/05 15:59:56 by ksohail-         ###   ########.fr       */
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

int convertToInt(std::string& str) {
    std::istringstream iss(str);
    int value = 0;

    iss >> value;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("invalid argument");
    }
    return (value);
}

float convertToFloat(std::string& str) {
    std::istringstream iss(str);
    float value = 0.0f;

    iss >> value;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("can't convert dates to float");
    }
    return (value);
}

void myMap::addKeyExchange(const std::string& key, const float exchange_rate) {
    size_t C1 = key.find('-');
    size_t C2 = key.find('-', C1 + 1);
    size_t C3 = key.find('-', C2 + 1);

    if (C1 == std::string::npos || C2 == std::string::npos || C3 != std::string::npos) {
        throw std::invalid_argument("Key must be in the format YYYY-MM-DD.");
    }

    std::string year = key.substr(0, C1);
    std::string month = key.substr(C1 + 1, C2 - C1 - 1);
    std::string day = key.substr(C2 + 1);

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
    if (exchange_rate < 0) {
        throw std::invalid_argument("exchange_rate must be between 1 and 1000.");
    }
    (*this)[key] = exchange_rate;
}


void myMap::addBufferExchange(std::ifstream& file) {
    std::string line;

    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t C1 = line.find(',');
        size_t C2 = line.find(',', C1 + 1);
        if (line.empty())
            continue;
        if (C1 == std::string::npos || C1 == 0) {
            throw std::invalid_argument("invalid exchange_rate or data");
        }
        else if (C2 != std::string::npos) {
            throw std::invalid_argument("line hase more than one \",\"");
        }
        std::string key = line.substr(0, C1);
        std::string exchange_rate = line.substr(C1 + 1);
        addKeyExchange(key, convertToFloat(exchange_rate));  
    } 
}

void addKeyValue(const std::string& key, const float value) {
    size_t C1 = key.find('-');
    size_t C2 = key.find('-', C1 + 1);
    size_t C3 = key.find('-', C2 + 1);

    if (C1 == std::string::npos || C2 == std::string::npos || C3 != std::string::npos) {
        throw std::invalid_argument("Key must be in the format YYYY-MM-DD.");
    }

    std::string year = key.substr(0, C1);
    std::string month = key.substr(C1 + 1, C2 - C1 - 1);
    std::string day = key.substr(C2 + 1);

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
    if (value < 0 || value > 1000) {
        throw std::invalid_argument("value must be between 1 and 1000.");
    }
}

myMap::const_iterator findClosestDate(const myMap& rates, const std::string& date) {
    myMap::const_iterator it = rates.lower_bound(date);
    if (it == rates.end() || it->first != date) {
        if (it == rates.begin()) {
            throw std::invalid_argument("Error: no exchange rate available for " + date);
        }
        --it;
    }
    return (it);
}

void addBufferValue(std::ifstream& file, const myMap& map) {
    std::string line;
    float fValue;

    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t C1 = line.find('|');
        size_t C2 = line.find('|', C1 + 1);
        try
        {
                if (line.empty())
                    continue;
                if (C1 == std::string::npos || C1 == 0) {
                    throw std::invalid_argument("invalid value or data");
                }
                else if (C2 != std::string::npos) {
                    throw std::invalid_argument("line hase more than one \",\"");
                }
                std::string key = line.substr(0, C1);
                std::string value = line.substr(C1 + 1);

                key.erase(0, key.find_first_not_of(" "));
                key.erase(key.find_last_not_of(" ") + 1);
                value.erase(value.find_last_not_of(" ") + 1);
                value.erase(0, value.find_first_not_of(" "));

                fValue = convertToFloat(value);
                addKeyValue(key, fValue);
                myMap::const_iterator closestDate = findClosestDate(map, key);
                float rate = closestDate->second;
                float result = fValue * rate;

                std::cout << closestDate->second << " => " << value << " = " << result << std::endl;
        }
        catch(const std::exception& e) {
            std::cout << "ERROR: " << e.what() << std::endl;
        }
    } 
}
