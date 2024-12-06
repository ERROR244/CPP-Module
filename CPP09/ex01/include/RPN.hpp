/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:18:35 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/06 12:51:19 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>

struct calcArray {
    char c;
    double (*calcFunc)(double x, double y);
};


class RPN {
private:
    static std::stack<int> operandStack;
    static calcArray calc[4];

    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    static double calcP(double x, double y);
    static double calcM(double x, double y);
    static double calcMT(double x, double y);
    static double calcD(double x, double y);

    static void performOperation(char op);
    
public:
    static int calculate(const std::string& expression);
};

#endif