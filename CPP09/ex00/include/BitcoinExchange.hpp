/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:04:12 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/05 16:46:49 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream> 
#include <sstream> 
#include <map>
#include <cstdlib>

struct TowValue {
    int date;
    float exchange_rate;
    TowValue() : date(0), exchange_rate(0.0f) {}  
    TowValue(int v1, float v2) : date(v1), exchange_rate(v2) {}
};

class myMap : public std::map<std::string, TowValue> {
    public:
        myMap();
        myMap(const myMap& other);
        myMap& operator=(const myMap& other);
        ~myMap();

        void addKeyExchange(const std::string& key, const float exchange_rate);
        void addBufferExchange(std::ifstream& file);
};

int convertToInt(std::string str);
float convertToFloat(std::string& str);
void addBufferValue(std::ifstream& file, const myMap& map);
long checkValue(const std::string& key, const float value);

#endif