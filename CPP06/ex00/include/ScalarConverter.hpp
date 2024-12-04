/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:41:07 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/01 15:31:32 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <sstream>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        static int convertToInt(std::string& str);
        static float convertToFloat(std::string& str, std::string& floatEnd, std::string& doubleEnd);
        static double convertToDouble(std::string& str, std::string& floatEnd, std::string& doubleEnd);
    public:
        static void convert(std::string str);
};


#endif