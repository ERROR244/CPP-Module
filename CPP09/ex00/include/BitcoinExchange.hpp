/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:04:12 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/05 15:51:09 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream> 
#include <sstream> 
#include <map>

class myMap : public std::map<std::string, float> {
    public:
        myMap();
        myMap(const myMap& other);
        myMap& operator=(const myMap& other);
        ~myMap();

        void addKeyExchange(const std::string& key, const float exchange_rate);
        void addBufferExchange(std::ifstream& file);
};

int convertToInt(std::string& str);
float convertToFloat(std::string& str);
void addBufferValue(std::ifstream& file, const myMap& map);
void addKeyValue(const std::string& key, const float value);

#endif