/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:19:01 by mlaplana          #+#    #+#             */
/*   Updated: 2020/11/01 19:53:03 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"
#include "List.hpp"
#include "Queue.hpp"
#include "Map.hpp"
#include "Stack.hpp"

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
}

bool single_digit (const int& value) { return (value<10); }


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

    ft::List<int>::reverse_iterator it = third.rbegin(); 
    ft::List<int>::reverse_iterator ite = third.rend();
    std::cout << "reverse: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        it++;
    }
    
    std::cout << "\nsize: ";

    std::cout << third.size() << "\nmax_size: ";
    std::cout << third.max_size() << "\nthird empty?: ";

    if (third.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";

    std::cout << "third.front(): " << third.front() << "\n";
    std::cout << "third.back(): " << third.back() << "\n";

    std::cout << "assign first: ";
    first.assign(2, 4);
    for (ft::List<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\nerase begin: ";
    first.erase(first.begin());
    for (ft::List<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
        
    third.push_front(6);
    third.push_back(6);

    std::cout << "\nthird, push_front(6) and push_back(6): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    third.pop_front();
    third.pop_back();
    
    std::cout << "\nthird, pop_front() and pop_back(): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    first.swap(third);

    std::cout << "\n first.swap(third): ";
    for (ft::List<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    
    first.swap(third);
    third.resize(2);
    third.resize(8,100);
    std::cout << "\nthird.resize(2); \n third.resize(8,100): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    first.push_front(1);
    first.push_front(2);
    third.splice(third.end(), first);
    std::cout << "\nthird.splice(third.end(), first); : ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    third.splice(third.end(), first, first.end());
    
    std::cout << "\nthird.splice(third.end(), first, first.end()); : ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    third.splice(third.end(), first, first.begin(), first.end());

    std::cout << "\nthird.splice(third.end(), first, first.begin(), first.end()); : ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    third.clear();

    third.push_front(42);
    third.push_front(10);
    third.push_front(3);
    third.push_front(2);
    third.push_front(1);
    std::cout << "\nnew list :";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    third.remove(4);
    std::cout << "\nremove(4): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    third.remove(2);
    std::cout << "\nremove(2): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    third.remove_if(single_digit);
    std::cout << "\nremove_if(single_digit): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    third.push_front(3);
    third.push_front(3);
    third.push_front(3);
    third.push_front(2);
    third.push_front(2);
    third.push_front(1);
    std::cout << "\nnew list :";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    third.unique();
    std::cout << "\nthird.unique() :";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    first.clear();
    first.push_front(6);
    first.push_front(5);
    first.push_front(4);
    
    third.merge(first);
    std::cout << "\nfirst = 4,5,6 third.merge(first) :";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    std::cout << "\nfirst size: " << first.size();
    
    third.push_front(12);
    third.push_front(7);
    third.push_front(22);
    
    std::cout << "\nthird unsortered :";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    third.sort();
    std::cout << "\nthird sortered :";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    third.reverse();
    std::cout << "\nthird reversed :";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
}

void test_queue()
{
    ft::List<int> mylist (2,200);         // list with 2 elements

    ft::Queue<int> first;                 // empty Queue
    ft::Queue<int,ft::List<int> > second; // empty Queue with list as underlying container
    ft::Queue<int,ft::List<int> > third (mylist);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';

    std::cout << "second empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";
  
    std::cout << "third empty?: ";
    if (third.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";

    third.push(10);
    third.push(7);
    std::cout << "third.push(10)\n";
    std::cout << "third.push(7)\n"; 
    std::cout << "third.front() is now " << third.front() << '\n';
    std::cout << "third.back() is now " << third.back() << '\n';
    third.pop();
    third.pop();
    std::cout << "third.pop()\n";
    std::cout << "third.pop()\n";
    std::cout << "third.front() is now " << third.front() << '\n';
}

void test_stack()
{
    ft::Vector<int> myvector (2,200);         // list with 2 elements

    ft::Stack<int> first;                 // empty Stack
    ft::Stack<int,ft::Vector<int> > second; // empty Stack with list as underlying container
    ft::Stack<int,ft::Vector<int> > third (myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';

    std::cout << "second empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";
  
    std::cout << "third empty?: ";
    if (third.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";

    third.push(10);
    third.push(7);
    std::cout << "third.push(10)\n";
    std::cout << "third.push(7)\n"; 
    std::cout << "third.top() is now " << third.top() << '\n';
    third.pop();
    third.pop();
    std::cout << "third.pop()\n";
    std::cout << "third.pop()\n";
    std::cout << "third.front() is now " << third.top() << '\n';
}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void test_map()
{
    ft::Map<char,int> first;

    first['a']=10;
    //ft::Map<char,int>::iterator it = first.begin();
    //std::cout << it.base()->mapped_value << "\n";
    first['b']=30;
    first['c']=50;
    first['d']=70;

    ft::Map<char,int> second (first.begin(),first.end());

    ft::Map<char,int> third (second);
    
    ft::Map<char,int> fourth = third;

    std::cout << "first:\n";
    for (ft::Map<char,int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "second:\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "third:\n";
    for (ft::Map<char,int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";
    
    std::cout << "fourth:\n";
    for (ft::Map<char,int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "second empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
        
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "max_size: " << second.max_size() << "\n";

    std::cout << "second['a'] is " << second['a'] << '\n';
    std::cout << "second['a'] is " << second['c'] << '\n';

    second.insert(ft::_pair<const char, int>('e', 42));
    std::cout << "second.insert(_pair<const char, int>('e', 42)):\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";
    
    second.erase('a');
    std::cout << "second.erase('a'):\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    third.swap(second);
    std::cout << "third.swap('second'):\n";
    std::cout << "third: \n";
    for (ft::Map<char,int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    ft::Map<char,int>::key_compare mycomp = third.key_comp();
    ft::Map<char,int>::iterator it = third.begin();
    ft::Map<char,int>::iterator it2 = third.begin();
    it2++;
    if (mycomp(it.base()->key_value, it2.base()->key_value) == true)
        std::cout << "my comp == less\n";
    if (third.value_comp()(ft::_pair<const char, int>('c', 42), ft::_pair<const char, int>('d', 44)) == true)
        std::cout << "value_comp == less\n";

    std::cout << "third.find('b'): \n";
    std::cout << "b => " << third.find('b').base()->mapped_value << '\n';

    std::cout << "third.count('b'): \n";
    std::cout << third.count('b') << "\n";

    ft::Map<char,int>::iterator it3 = third.lower_bound('b');
    std::cout << "third.lower_bound ('b'):\n";
    std::cout << it3.base()->key_value << " " << it3.base()->mapped_value << "\n";
    
    ft::Map<char,int>::iterator it4 = third.upper_bound('b');
    std::cout << "third.upper_bound ('b'):\n";
    std::cout << it4.base()->key_value << " " << it4.base()->mapped_value << "\n";

    ft::_pair<ft::Map<char,int>::iterator,ft::Map<char,int>::iterator> ret = third.equal_range('c');

    std::cout << "lower bound points to: ";
    std::cout << ret.key_value.base()->key_value << " => " << ret.key_value.base()->mapped_value << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.mapped_value.base()->key_value << " => " << ret.mapped_value.base()->mapped_value << '\n';
}

int main()
{
    //test_vector();
    //test_list();
    //test_queue();
    //test_stack();
    test_map();
    return 0;
}
