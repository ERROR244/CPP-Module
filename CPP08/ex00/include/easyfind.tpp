/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:24:39 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/04 11:40:15 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename C>
typename C::iterator easyfind(C& container, int target) {
    typename C::iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end()) {
        throw "Element not found in the container";
    }
    return (it);
}

#endif
