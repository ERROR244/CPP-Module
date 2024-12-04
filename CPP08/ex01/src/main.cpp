/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:07:17 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/04 18:12:01 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void ) {
    try {
        int size = 10;
        std::vector<int> tmp;
        Span sp = Span(size);

        srand(time(NULL));
		for (int i = 1; i <= size; i++) {
			tmp.push_back(i);
			// tmp.push_back(rand());
        }
        sp.fillRange(tmp.begin(), tmp.end());
        for (int i = 1; i < size; i++)
            std::cout << sp.getNumbers().at(i) << " ";

        std::cout << "\n\nshortestSpan-> " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan--> " << sp.longestSpan() << std::endl;    
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
