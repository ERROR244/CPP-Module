/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:35:50 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/01 13:16:33 by ksohail-         ###   ########.fr       */
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
    if (dynamic_cast<A*>(p)) {
        std::cout << "the type of the object pointed to is A.\n";
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "the type of the object pointed to is B.\n";
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "the type of the object pointed to is C.\n";
    }
    else {
        std::cout << "Unknown type!\n";
    }
}

void identify(Base& p) {
    try {
        try { A& a = dynamic_cast<A&>(p); (void)a;}
        catch (...) { throw BadTypeCastException(); }
        std::cout << "the type of the object pointed to is A.\n";
        return;
    }
    catch (const BadTypeCastException&) { }
    try {
        try { B& b = dynamic_cast<B&>(p); (void)b;}
        catch (...) { throw BadTypeCastException(); }
        std::cout << "the type of the object pointed to is B.\n";
        return;
    }
    catch (const BadTypeCastException&) { }
    try {
        try { C& c = dynamic_cast<C&>(p); (void)c;}
        catch (...) { throw BadTypeCastException(); }
        std::cout << "the type of the object pointed to is C.\n";
        return;
    }
    catch (const BadTypeCastException&) { }
    std::cout << "Unknown type!\n";
}

