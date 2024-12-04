/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:33:33 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/01 13:03:52 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_HPP
#define FUNC_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class BadTypeCastException {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
