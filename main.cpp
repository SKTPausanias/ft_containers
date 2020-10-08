/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:19:01 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/08 13:53:50 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include <vector>
//#include <list>
#include "Vector.hpp"

int main()
{
    ft::Vector<int> first;
    ft::Vector<int> second(4,100);
    //first.insert(first.begin(), 10);
    printf("que paso\n");

    //ft::Vector<int> third (second.begin(),second.end());
    /*ft::Vector<int> fourth (third);
    ft::Vector<int> bar (0,5);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";*/
    /*printf("llegamos\n");
    for (ft::Vector<int>::iterator it = second.begin(); it != second.end(); it++)

        std::cout << *it << " ";
    //bar = second;
    printf("no comprendo\n");*/
    return 0;
}
