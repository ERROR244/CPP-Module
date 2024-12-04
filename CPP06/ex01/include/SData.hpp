/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SData.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:19:10 by ksohail-          #+#    #+#             */
/*   Updated: 2024/11/30 19:20:24 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDATA_HPP
#define SDATA_HPP

#include "Serializer.hpp"

typedef struct SData
{
    std::string name;
    double nD;
    float nF;
    int nI;
}   Data;

#endif
