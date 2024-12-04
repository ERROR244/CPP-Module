/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:07:17 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/03 14:14:15 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


void inc( int& x )
{
  x++;
  return;
}

void print( int& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 9, 19, 29, 39, 49 };

  iter( tab, 5, inc );
  iter( tab, 5, print );

  return 0;
}
