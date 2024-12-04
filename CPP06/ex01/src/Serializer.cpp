/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:17:57 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/01 15:34:01 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    if (this != &other) {}
    return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}


Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}
