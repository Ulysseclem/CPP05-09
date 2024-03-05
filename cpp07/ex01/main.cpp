/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulysse <ulysse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:23:19 by uclement          #+#    #+#             */
/*   Updated: 2024/03/04 17:17:38 by ulysse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <cstring>


int main()
{
    {
        const char *test = "Bonjour";
        size_t len = std::strlen(test);
        iter(test, len, increPrint);
    }
    {
        int * test = new int[5];
        for (int i = 0; i < 5; ++i) {
            test[i] = i; }
        iter(test, 5, increPrint);
        delete test;
    }
}
