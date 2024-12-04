/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:21:25 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/03 17:35:50 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T> class Array {
    private:
        T* data;
        unsigned int arraySize;
    public:
        Array() : data(NULL), arraySize(0) {}
        Array(unsigned int n) : arraySize(n)  { data = new T[n](); }

        Array(const Array& other) : arraySize(other.arraySize)  {
            if (arraySize > 0) {
                data = new T[arraySize]();
                for (unsigned int i = 0; i < arraySize; ++i) { data[i] = other.data[i]; }
            }
            else { data = NULL; }
        }

        Array& operator=(const Array& other)  {
            if (this != &other) {
                delete data;
                arraySize = other.arraySize;
                if (arraySize > 0) {
                    data = new T[arraySize]();
                    for (unsigned int i = 0; i < arraySize; ++i) { data[i] = other.data[i]; }
                }
                else {
                    data = other.data;
                }
            }
            return (*this);
        }

        T& operator[](unsigned int index) const {
            if (index >= arraySize) {
                throw std::out_of_range("Index out of bounds");
            }
            return (data[index]);
        }
        ~Array() { delete[] data; }
        unsigned int size() const { return (arraySize); }
};

#endif
