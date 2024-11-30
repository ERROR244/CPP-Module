/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:17:57 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/30 19:06:33 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
    
}

Serializer::Serializer(const Serializer& other) {
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    if (this != &other) {}
    return (*this);
}

Serializer::~Serializer() {

}

uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t memoryAddress = reinterpret_cast<uintptr_t>(ptr);
    return (memoryAddress);
}


Data* Serializer::deserialize(uintptr_t raw) {
    Data* dataPtr = reinterpret_cast<Data*>(raw);
    return (dataPtr);
}
