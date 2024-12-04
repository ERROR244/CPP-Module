/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:42:03 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/04 13:11:31 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {
    if (N == 0) {
        throw std::invalid_argument("Span size must be greater than zero");
    }
}

Span::Span(const Span& other) {
    if (other.maxSize == 0) {
        throw std::invalid_argument("Span size must be greater than zero");
    }
    this->maxSize = other.maxSize;
    this->numbers = other.numbers;
}
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        if (other.maxSize == 0) {
            throw std::invalid_argument("Span size must be greater than zero");
        }
        this->maxSize = other.maxSize;
        this->numbers = other.numbers;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(const int& nbr) {
    if (numbers.size() >= maxSize) {
        throw std::invalid_argument("Span size must be greater than zero");
    }
    numbers.push_back(nbr);
}

std::vector<int> Span::getNumbers() {
    return (numbers);
}

int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough elements to calculate span");
    }
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        minSpan = std::min(minSpan, sorted[i] - sorted[i-1]);
        if (minSpan == 0) return (0);
    }
    return (minSpan);
}

int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough elements to calculate span");
    }
    
    int max = *std::max_element(numbers.begin(), numbers.end());
    int min = *std::min_element(numbers.begin(), numbers.end());
    return (max - min);
}

void	Span::fillRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int>::iterator it;

    it = begin;
    while (it != end)
    {
        addNumber(*it);
        it++;
    }
}
