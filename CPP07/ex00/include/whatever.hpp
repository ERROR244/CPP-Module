/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:07:15 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/03 14:36:11 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> void swap(T& x, T& y) {
    T temp;

    temp = x;
    x = y;
    y = temp;
}

template <typename T> T min(T x, T y) { return (x < y) ? x : y; }

template <typename T> T max(T x, T y) { return (x > y) ? x : y; }

#endif