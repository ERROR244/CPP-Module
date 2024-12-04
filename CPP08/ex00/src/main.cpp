/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:07:17 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/04 11:39:25 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void ) {
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    std::deque<int> gquiz;
    gquiz.push_back(1);
    gquiz.push_front(2);
    gquiz.push_back(3);
    gquiz.push_front(4);
    gquiz.push_back(5);

    try
    {
        std::list<int>::iterator it1 = easyfind(lst, 3);
        std::cout << "-> " << *it1 << std::endl;
        std::list<int>::iterator it2 = easyfind(lst, 9);
        std::cout << "-> " << *it2 << std::endl;
    }
    catch(const char* c) { std::cerr << c << std::endl; }

    try
    {
        std::vector<int>::iterator it1 = easyfind(vec, 3);
        std::cout << "-> " << *it1 << std::endl;
        std::vector<int>::iterator it2 = easyfind(vec, 9);
        std::cout << "-> " << *it2 << std::endl;
    }
    catch(const char* c) { std::cerr << c << std::endl; }

    try
    {
        std::deque<int>::iterator it1 = easyfind(gquiz, 3);
        std::cout << "-> " << *it1 << std::endl;
        std::deque<int>::iterator it2 = easyfind(gquiz, 9);
        std::cout << "-> " << *it2 << std::endl;
    }
    catch(const char* c) { std::cerr << c << std::endl; }
    
    
    return (0);
}
