/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:54:17 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/01 15:31:21 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {}
    return (*this);
}

ScalarConverter::~ScalarConverter() {}


int ScalarConverter::convertToInt(std::string& str) {
    std::istringstream iss(str);
    int value = 0;

    iss >> value;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("invalid argument");
    }
    return (value);
}

float ScalarConverter::convertToFloat(std::string& str, std::string& floatEnd, std::string& doubleEnd) {
    std::istringstream iss(str);
    float value = 0.0f;
    int n = 0;

    iss >> value;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("invalid argument");
    }
    size_t idx = str.find(".");
    if (idx == std::string::npos) {
        return (value);
    }
    idx++;
    while (idx < str.size()) {
        if (str[idx] == '0') {
            idx++;
            n++;
        } else { break; }
    }
    if (idx != str.size() && (((n == 4) && (str[idx] >= '6' || (idx + 1 < str.size() && str[idx + 1] > '1'))) || (n < 4))) {
        floatEnd = "f";
        doubleEnd = "";
    }
    return (value);
}

double ScalarConverter::convertToDouble(std::string& str, std::string& floatEnd, std::string& doubleEnd) {
    std::istringstream iss(str);
    double value = 0.0;
    int n = 0;

    iss >> value;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("invalid argument");
    }
    size_t idx = str.find(".");
    if (idx == std::string::npos) {
        return (value);
    }
    idx++;
    while (idx < str.size()) {
        if (str[idx] == '0') {
            idx++;
            n++;
        } else { break; }
    }
    if (idx != str.size() && (((n == 4) && str[idx] >= '5') || (n < 4))) {
        floatEnd = "f";
        doubleEnd = "";
    }
    return (value);
}

void ScalarConverter::convert(std::string str) {
    std::string floatEnd = ".0f";
    std::string doubleEnd = ".0";
    if (str.compare("nan") == 0 || str.compare("nanf") == 0
		|| str.compare("inf") == 0 || str.compare("inff") == 0
		|| str.compare("+inf") == 0 || str.compare("+inff") == 0
		|| str.compare("-inf") == 0 || str.compare("-inff") == 0) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << str << std::endl;
			std::cout << "double: " << str << std::endl;
			return;
	}
    else if (str.length() == 1 && str[0] != '-' && str[0] != '+') {
        try {
            char c = static_cast<char>(str[0]);
            std::cout << "char: " << (std::isprint(c) ? ("'" + std::string(1, c) + "'") : "Non displayable") << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << floatEnd << std::endl;
            std::cout << "double: " << static_cast<double>(c) << doubleEnd << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    else if (str.find_first_not_of("0123456789-") == std::string::npos) {
        try {
            int nbr = convertToInt(str);
            std::cout << "char: " << (std::isprint(static_cast<char>(nbr)) ? ("'" + std::string(1, static_cast<char>(nbr)) + "'") : "Non displayable") << std::endl;
            std::cout << "int: " << nbr << std::endl;
            std::cout << "float: " << static_cast<float>(nbr) << floatEnd << std::endl;
            std::cout << "double: " << static_cast<double>(nbr) << doubleEnd << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    else if (str.find("f") != std::string::npos) {
        str.erase(str.size() - 1);
        try {
            float nbr = convertToFloat(str, floatEnd, doubleEnd);
            std::cout << "char: " << (std::isprint(static_cast<char>(nbr)) ? ("'" + std::string(1, static_cast<char>(nbr)) + "'") : "Non displayable") << std::endl;
            std::cout << "int: " << static_cast<int>(nbr) << std::endl;
            std::cout << "float: " << nbr << floatEnd << std::endl;
            std::cout << "double: " << static_cast<double>(nbr) << doubleEnd << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    else {
        try {
            double nbr = convertToDouble(str, floatEnd, doubleEnd);
            std::cout << "char: " << (std::isprint(static_cast<char>(nbr)) ? ("'" + std::string(1, static_cast<char>(nbr)) + "'") : "Non displayable") << std::endl;
            std::cout << "int: " << static_cast<int>(nbr) << std::endl;
            std::cout << "float: " << static_cast<float>(nbr) << floatEnd << std::endl;
            std::cout << "double: " << nbr << doubleEnd << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}