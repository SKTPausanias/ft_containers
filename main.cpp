/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:19:01 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/11 14:15:59 by mlaplana         ###   ########.fr       */
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
    ft::Vector<int> third (second.begin(), --second.end());
    ft::Vector<int> fourth (third);
    
    for (ft::Vector<int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    for (ft::Vector<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    /*for (ft::Vector<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n"; */   
    
    first.insert(first.begin(), 5, 1);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    
    first.insert(first.begin(), 2, 2);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    
    ft::Vector<int> anothervector (2,400);
    first.insert (first.begin() ,anothervector.begin(),anothervector.end());
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    first.erase(first.begin());
    
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    
    return 0;
}
