/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:54:17 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/29 18:58:16 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& str) {
    if (str.length() == 1 && str[0] != '-' && str[0] != '+') {
        
    }
    else if (str.find_first_not_of("0123456789-") == std::string::npos) {
        
    }
    else if (str.find("f") != std::string::npos) {

    }
    else {
        
    }
}