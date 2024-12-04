/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.pp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksohail- <ksohail-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:17:38 by ksohail-          #+#    #+#             */
/*   Updated: 2024/12/03 17:26:52 by ksohail-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    Array<int> I(5);
    Array<char> C(5);
    Array<const char *> P(5);
    Array<std::string> S(5);
    Array<bool> B(5);
    Array<float> F(5);
    Array<double> D(5);


    try
    {
        for (int i = 0; i < 5; ++i) {
            std::cout << "'" << I[i] << "'" << ", the size is = " << I.size() << " | ";
            std::cout << "'" << C[i] << "'" << ", the size is = " << C.size() << " | ";
            // std::cout << "'" << P[i] << "'" << ", the size is = " << P.size() << " | ";
            std::cout << "'" << S[i] << "'" << ", the size is = " << S.size() << " | ";
            std::cout << "'" << B[i] << "'" << ", the size is = " << B.size() << " | ";
            std::cout << "'" << F[i] << "'" << ", the size is = " << F.size() << " | ";
            std::cout << "'" << D[i] << "'" << ", the size is = " << D.size();
            std::cout << "\n";
        }
        std::string str = "khalil sohail";
        for (int i = 0; i < 5; ++i) {
            I[i] = 1;
            C[i] = 'c';
            P[i] = str.c_str();
            S[i] = "khalil";
            B[i] = true;
            F[i] = 42.42f;
            D[i] = 42.42;
        }

        for (int i = 0; i < 5; ++i) {
            std::cout << "'" << I[i] << "'" << ", the size is = " << I.size() << " | ";
            std::cout << "'" << C[i] << "'" << ", the size is = " << C.size() << " | ";
            std::cout << "'" << P[i] << "'" << ", the size is = " << P.size() << " | ";
            std::cout << "'" << S[i] << "'" << ", the size is = " << S.size() << " | ";
            std::cout << "'" << B[i] << "'" << ", the size is = " << B.size() << " | ";
            std::cout << "'" << F[i] << "'" << ", the size is = " << F.size() << " | ";
            std::cout << "'" << D[i] << "'" << ", the size is = " << D.size();
            std::cout << "\n";
        }
        std::cout << I[10] << std::endl;
        // std::cout << C[10] << std::endl;
        // std::cout << P[10] << std::endl;
        // std::cout << S[10] << std::endl;
        // std::cout << B[10] << std::endl;
        // std::cout << F[10] << std::endl;
        // std::cout << D[10] << std::endl;
        std::cout << "Hello\n" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "ERROR\n" << std::endl;
    }
}