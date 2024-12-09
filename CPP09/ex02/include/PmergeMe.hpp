/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:41:22 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/07 12:09:19 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits>
#include <stdexcept>
#include <string>
#include <ctime>

class PmergeMe {
    private:
        std::vector<long long> v;
        std::deque<long long> d;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void print(int i);

        bool validateInput(const std::string& input);
        bool parseInput(int ac, char **av);
        void sortAndPrintResults();
        
        void mergeSortVector(std::vector<long long>& arr, int left, int right);
        void mergeVector(std::vector<long long>& arr, int left, int mid, int right);

        void mergeSortDeque(std::deque<long long>& arr, int left, int right);
        void mergeDeque(std::deque<long long>& arr, int left, int mid, int right);
};

#endif