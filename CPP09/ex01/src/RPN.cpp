/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:18:33 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/07 10:34:01 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<double> RPN::operandStack;

calcArray RPN::calc[4] = {
    {'+', RPN::calcP},
    {'-', RPN::calcM},
    {'*', RPN::calcMT},
    {'/', RPN::calcD}
};

RPN::RPN() {
}

RPN::RPN(const RPN& other) {
    (void)other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        (void)other;
    }
    return (*this);
}

RPN::~RPN() {}

double RPN::calcP(double x, double y) {
    return (x + y);
}

double RPN::calcM(double x, double y) {
    return (x - y);
}

double RPN::calcMT(double x, double y) {
    return (x * y);
}

double RPN::calcD(double x, double y) {
    if (y == 0) throw std::runtime_error("Division by zero");
    return (x / y);
}

void RPN::performOperation(char op) {
    if (operandStack.size() < 2) {
        throw std::runtime_error("Insufficient operands");
    }

    int y = operandStack.top();
    operandStack.pop();
    int x = operandStack.top();
    operandStack.pop();

    for (int i = 0; i < 4; ++i) {
        if (calc[i].c == op) {
            operandStack.push(calc[i].calcFunc(x, y));
        }
    }
}

double RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (!operandStack.empty()) {
        operandStack.pop();
    }
    while (iss >> token) {
        if (token != "+" && token != "-" && token != "*" && token != "/") {
            if (token.length() != 1 || !isdigit(token[0])) {
                throw std::runtime_error("Invalid token: " + token);
            }
            operandStack.push(token[0] - '0');
        }
        else {
            performOperation(token[0]);
        }
    }
    if (operandStack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }
    return (operandStack.top());
}
