/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:07:17 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/04 13:18:05 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void ) {
    try {
        int size = 10000;
        std::vector<int> tmp;
        Span sp = Span(size);

        srand(time(NULL));
		for (int i = 1; i <= size; i++)
			tmp.push_back(i);
			tmp.push_back(rand());
        sp.fillRange(tmp.begin(), tmp.end());
        for (int i = 1; i < size; i++)
            std::cout << sp.getNumbers().at(i) << " ";

        std::cout << "\nshortestSpan-> " << sp.shortestSpan() << std::endl;
        std::cout << "\nlongestSpan--> " << sp.longestSpan() << std::endl;    
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
