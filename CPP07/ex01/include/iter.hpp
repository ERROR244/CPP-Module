/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:07:15 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/03 14:35:55 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T1, typename T2, typename T3>
    void iter(T1 x, T2 y, T3 z) {
        for (int i =0; i < y; i++) { z(x[i]); }
}


#endif