/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:15:13 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/01 15:34:18 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data* ptr = new Data;

    ptr->nI = 2;
    ptr->nF = 2.2f;
    ptr->nD = 2.2;
    ptr->name = "khalil sohail";


    std::cout << "Reconstructed Pointer: " << ptr << std::endl;
    std::cout << "Reconstructed name: " << ptr->name << std::endl;
    std::cout << "Reconstructed nI: " << ptr->nI << std::endl;
    std::cout << "Reconstructed nF: " << ptr->nF << std::endl;
    std::cout << "Reconstructed nD: " << ptr->nD << std::endl;

    uintptr_t memoryAddress = Serializer::serialize(ptr);
    
    std::cout << "\n\nOriginal Struct Pointer: " << ptr << std::endl;
    std::cout << "Converted to uintptr_t: " << memoryAddress << std::endl;

    Data* dataPtr = Serializer::deserialize(memoryAddress);

    std::cout << "\n\nReconstructed Pointer: " << dataPtr << std::endl;
    std::cout << "Reconstructed name: " << dataPtr->name << std::endl;
    std::cout << "Reconstructed nI: " << dataPtr->nI << std::endl;
    std::cout << "Reconstructed nF: " << dataPtr->nF << std::endl;
    std::cout << "Reconstructed nD: " << dataPtr->nD << std::endl;

    delete ptr;
    return (0);
}