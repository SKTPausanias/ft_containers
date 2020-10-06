/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:19:01 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/06 18:49:33 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include <vector>
//#include <list>
#include "List.hpp"
#include "Vector.hpp"

int main()
{
    Vector<int> first;
    Vector<int> second (4,100);
    Vector<int> third (second.begin(),second.end());
    Vector<int> fourth (third);
    Vector<int> bar (0,5);

    for (Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";    
    for (Vector<int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << *it << " ";
    bar = second;
    return 0;
}
