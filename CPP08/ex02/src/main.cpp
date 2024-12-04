/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:07:17 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/04 18:05:36 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


int	main(int ac, char **av)
{
    (void)av;
    if (ac == 1) {
        std::cout << "MutantStack test: " << std::endl;
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "top = " << mstack.top() << std::endl;
        std::cout << "size = " << mstack.size() << std::endl;
        mstack.pop();
        std::cout << "size = " << mstack.size() << std::endl;


        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(72);
        mstack.push(-12);
        mstack.push(0);
        mstack.push(1);
        std::cout << "top = " << mstack.top() << std::endl;

        MutantStack<int>::iterator	it = mstack.begin();
        MutantStack<int>::iterator	ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack <int> s(mstack);
    }
    else {
        std::cout << "Vector test: " << std::endl;
        std::vector<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);

        std::cout << "top = " << *(mstack.end() - 1) << std::endl;
        std::cout << "size = " << mstack.size() << std::endl;
        mstack.pop_back();
        std::cout << "size = " << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(72);
        mstack.push_back(-12);
        mstack.push_back(0);
        mstack.push_back(1);
        std::cout << "top = " << *(mstack.end() - 1) << std::endl;

        std::vector<int>::iterator	it = mstack.begin();
        std::vector<int>::iterator	ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }	
    }
	return (0);
}