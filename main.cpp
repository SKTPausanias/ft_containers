/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:19:01 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/23 15:17:43 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
//#include <vector>
#include "Vector.hpp"
#include "List.hpp"

void test_vector()
{
    ft::Vector<int> first;
    ft::Vector<int> second(4, 100);
    ft::Vector<int> third(second.begin(), --second.end());
    ft::Vector<int> fourth(third);
    ft::Vector<int> fifth(5, 0);

    fifth = third;

    for (ft::Vector<int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << *it << " ";
    std::cout << "\nthird: ";

    for (ft::Vector<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    std::cout << "\nfourth: ";

    for (ft::Vector<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << *it << " ";
    std::cout << "\nfifth: ";

    for (ft::Vector<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    first.insert(first.begin(), 1, 1);
    first.insert(first.end(), 1, 2);
    first.insert(first.end(), 1, 3);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    first.insert(first.begin(), 2, 2);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    ft::Vector<int> anothervector(2, 400);
    first.insert(first.begin(), anothervector.begin(), anothervector.end());
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    ft::Vector<int> vec(2, 2);
    vec.insert(vec.begin(), 2, 3);
    std::cout << "normal vector : ";
    for (ft::Vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    
    ft::Vector<int>::reverse_iterator it = vec.rbegin(); 
    ft::Vector<int>::reverse_iterator ite = vec.rend();
    std::cout << "reverse: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
    
    std::cout << first.size() << "\n";
    std::cout << first.max_size() << "\n";
    first.resize(9, 6);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << first.capacity() << "\n";
    if (first.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";
    first.reserve(10);
    std::cout << first.capacity() << "\n";
    std::cout << first[1] << "\n";
    std::cout << first.at(2) << "\n";
    std::cout << first.front() << "\n";
    std::cout << first.back() << "\n";

    first.assign(10, 5);
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    first.push_back(3);
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    first.pop_back();
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    first.insert(first.begin(), 2, 2);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    first.erase(first.begin());
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    first.swap(second);
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    first.clear();
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
}

void test_list()
{
    ft::List<int> first;                                // empty list of ints
    ft::List<int> second(4,100);                       // four ints with value 100
    
    first.insert(first.begin(), 4);
    first.insert(first.begin(), 3);
    first.insert(first.begin(), 2);
    first.insert(first.begin(), 1);
    
    ft::List<int> third (first.begin(),first.end());
    ft::List<int> fourth (third);
    
    std::cout << "first: ";
    for (ft::List<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";   
    std::cout << "\nsecond: ";
    for (ft::List<int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << *it << " ";
    std::cout << "\nthird: ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    std::cout << "\nfourth: ";
    for (ft::List<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
}

int main()
{
    //test_vector();
    test_list();
    return 0;
}
