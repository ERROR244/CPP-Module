/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:41:27 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/07 14:50:25 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        (void)other;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::print(int type) {
    if (type == 0) {
        for (size_t i = 0; i < v.size(); i++) {
            std::cout << v[i] << " ";
        }
    }
    else {
        for (size_t i = 0; i < d.size(); i++) {
            std::cout << v[i] << " ";
        }
    }
}

bool PmergeMe::validateInput(const std::string& input) {
    std::istringstream iss(input);
    long long num;
    
    while (iss >> num) {
        if (num <= 0 || num > std::numeric_limits<int>::max()) {
            return (false);
        }
    }
    return (true);
}

bool PmergeMe::parseInput(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: no input" << std::endl;
        return (false);
    }
    for (int i = 1; i < ac; ++i) {
        if (!validateInput(av[i])) {
            std::cerr << "Error: Invalid input" << std::endl;
            return (false);
        }
    }
    for (int i = 1; i < ac; ++i) {
        std::istringstream iss(av[i]);
        int num;
        while (iss >> num) {
            v.push_back(num);
            d.push_back(num);
        }
    }
    return (true);
}

void PmergeMe::mergeSortVector(std::vector<long long>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSortVector(arr, left, mid);
    mergeSortVector(arr, mid + 1, right);
    mergeVector(arr, left, mid, right);
}

void PmergeMe::mergeVector(std::vector<long long>& arr, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    std::vector<long long> arr1(size1), arr2(size2);
    for (int i = 0; i < size1; ++i) {
        arr1[i] = arr[left + i];
    }
    for (int i = 0; i < size2; ++i) {
        arr2[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
        }
        else {
            arr[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        arr[k++] = arr1[i++];
    }
    while (j < size2) {
        arr[k++] = arr2[j++];
    }
}


void PmergeMe::mergeSortDeque(std::deque<long long>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSortDeque(arr, left, mid);
    mergeSortDeque(arr, mid + 1, right);
    mergeDeque(arr, left, mid, right);
}

void PmergeMe::mergeDeque(std::deque<long long>& arr, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    std::deque<long long> arr1(size1), arr2(size2);
    for (int i = 0; i < size1; ++i) {
        arr1[i] = arr[left + i];
    }
    for (int i = 0; i < size2; ++i) {
        arr2[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
        }
        else {
            arr[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        arr[k++] = arr1[i++];
    }
    while (j < size2) {
        arr[k++] = arr2[j++];
    }
}

void PmergeMe::sortAndPrintResults() {
    std::clock_t start1 = std::clock();
    mergeSortVector(v, 0, v.size() - 1);
    std::clock_t end1 = std::clock();
    
    std::clock_t start2 = std::clock();
    mergeSortDeque(d, 0, d.size() - 1);
    std::clock_t end2 = std::clock();
    
    double vectorTime = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1e6;
    double dequeTime = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1e6;;
    
    std::cout << "Vector after: ";
    print(0);
    std::cout << "\n";
    // std::cout << "Deque after: ";
    // print(1);
    // std::cout << "\n";
    std::cout << "Time to process a range of 5 elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of 5 elements with std::deque : " << dequeTime << " us" << std::endl;
}
