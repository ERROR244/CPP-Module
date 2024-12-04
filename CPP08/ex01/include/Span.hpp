/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:24:48 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/04 13:11:21 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <limits>

class Span {
    private:
        unsigned int maxSize;
        std::vector<int> numbers;
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(const int& nbr);
        std::vector<int> getNumbers();
        int shortestSpan();
        int longestSpan();
        void fillRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};


#endif
