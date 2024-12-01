/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:24:06 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/01 13:15:38 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.hpp"

int main() {
    Base* base;

    std::srand(std::time(0));
    for (int i = 0; i < 10; ++i) {
        base = generate();
        identify(*base);
        identify(base);
        std::cout << "\n\n";
        delete base;
    }
    return (0);
}
