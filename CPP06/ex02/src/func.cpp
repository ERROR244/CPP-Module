/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:35:50 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/04 21:22:20 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.hpp"

Base * generate(void) {
    int choice;

    choice = rand() % 3;
    switch(choice) {
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
    }
    return (NULL);
}

void identify(Base* p) {
    std::cout << "the type of the object pointed to is ";
    if (dynamic_cast<A*>(p)) {
        std::cout << "A." << std::endl;
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "B." << std::endl;
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "C." << std::endl;
    }
    else {
        std::cout << "Valid!" << std::endl;
    }
}   

void identify(Base& p) {
    std::cout << "the type of the object pointed to is ";
	try {  
		(void)dynamic_cast<A&>(p);
		std::cout << "A." << std::endl;
	}   
    catch (std::exception&) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B." << std::endl;
		}
        catch (std::exception&) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C." << std::endl;
			}
            catch (std::exception&) {
				std::cout << "Valid!" << std::endl;
            }
		}
	}
}
