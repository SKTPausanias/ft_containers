/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:19:01 by mlaplana          #+#    #+#             */
/*   Updated: 2020/11/03 14:48:20 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"
#include "List.hpp"
#include "Queue.hpp"
#include "Map.hpp"
#include "Multimap.hpp"
#include "Stack.hpp"
#include "Set.hpp"
#include "MultiSet.hpp"
#include <set>

void test_vector()
{
    std::cout << "| VECTOR TEST |\n\n";
    ft::Vector<int> first;
    ft::Vector<int> second(4, 100);
    ft::Vector<int> third(second.begin(), --second.end());
    ft::Vector<int> fourth(third);
    ft::Vector<int> fifth(5, 0);

    fifth = third;

    std::cout << "ft::Vector<int> second(4, 100):\n";
    for (ft::Vector<int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << *it << " ";
    
    std::cout << "\n\nft::Vector<int> third(second.begin(), --second.end()):\n";
    for (ft::Vector<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    std::cout << "\n\nft::Vector<int> fourth(third):\n";
    for (ft::Vector<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << *it << " ";
    
    std::cout << "\n\nft::Vector<int> fifth(5, 0); \nfifth = third;\n";
    for (ft::Vector<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
        std::cout << *it << " ";

    std::cout << "\n\nft::Vector<int> first; \n";
    std::cout << "first.insert(first.begin(), 1, 1);\n";
    std::cout << "first.insert(first.end(), 1, 2);\n";
    std::cout << "first.insert(first.end(), 1, 3);\n";

    first.insert(first.begin(), 1, 1);
    first.insert(first.end(), 1, 2);
    first.insert(first.end(), 1, 3);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nfirst.insert(first.begin(), 2, 2);\n";
    first.insert(first.begin(), 2, 2);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nft::Vector<int> anothervector(2, 400);\n";
    std::cout << "first.insert(first.begin(), anothervector.begin(), anothervector.end());\n";    
    ft::Vector<int> anothervector(2, 400);
    first.insert(first.begin(), anothervector.begin(), anothervector.end());
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    ft::Vector<int> vec(2, 2);
    vec.insert(vec.begin(), 2, 3);
    std::cout << "\nft::Vector<int> vec(2, 2);";
    std::cout << "\nvec.insert(vec.begin(), 2, 3);\n";
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

    std::cout << "\nfirst.size(): ";
    std::cout << first.size() << "\n";
    std::cout << "first.max_size(): ";
    std::cout << first.max_size() << "\n";

    std::cout << "\nfirst.resize(9, 6): \n";
    first.resize(9, 6);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nfirst.capacity(): ";
    std::cout << first.capacity() << "\n";
    
    std::cout << "\nfirst is empty?\n";
    if (first.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";

    std::cout << "\nfirst.reserve(10); "<< "\n";     
    first.reserve(10);

    std::cout << "first.capacity(): ";
    std::cout << first.capacity() << "\n";
    std::cout << "\nfirst[1]: ";
    std::cout << first[1] << "\n";
    std::cout << "\nfirst.at(2): ";
    std::cout << first.at(2) << "\n";
    std::cout << "\nfirst.front(): ";
    std::cout << first.front() << "\n";
    std::cout << "\nfirst.back(): ";
    std::cout << first.back() << "\n";

    std::cout << "\nfirst.assign(10, 5):\n";
    first.assign(10, 5);
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.push_back(3):\n";
    first.push_back(3);
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.pop_back(3):\n";
    first.pop_back();
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.insert(first.begin(), 2, 2):\n";
    first.insert(first.begin(), 2, 2);

    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfirst.erase(first.begin()): \n";
    first.erase(first.begin());
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "\nfirst.swap(second): \n";
    first.swap(second);
    for (ft::Vector<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
}

bool single_digit (const int& value) { return (value<10); }


void test_list()
{
    std::cout << "| LIST TEST |\n\n";

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
    std::cout << "\n\nsecond: ";
    for (ft::List<int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nthird: ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nfourth: ";
    for (ft::List<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    ft::List<int>::reverse_iterator it = third.rbegin(); 
    ft::List<int>::reverse_iterator ite = third.rend();
    std::cout << "\nreverse: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        it++;
    }

    
    std::cout << "\n\nthird.size(): ";

    std::cout << third.size() << "\nmax_size: ";
    std::cout << third.max_size() << "\n\nthird empty?: ";

    if (third.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";

    std::cout << "\nthird.front(): " << third.front() << "\n";
    std::cout << "third.back(): " << third.back() << "\n";

    std::cout << "\nassign first: ";
    first.assign(2, 4);
    for (ft::List<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n\nerase begin: ";
    first.erase(first.begin());
    for (ft::List<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
        
    third.push_front(6);
    third.push_back(6);

    std::cout << "\n\nthird, push_front(6) and push_back(6): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    third.pop_front();
    third.pop_back();
    
    std::cout << "\n\nthird, pop_front() and pop_back(): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    first.swap(third);

    std::cout << "\n\n first.swap(third): ";
    for (ft::List<int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << *it << " ";
    
    first.swap(third);
    third.resize(2);
    third.resize(8,100);
    std::cout << "\n\nthird.resize(2); \n third.resize(8,100): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    first.push_front(1);
    first.push_front(2);
    third.splice(third.end(), first);
    std::cout << "\n\nthird.splice(third.end(), first); : ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    third.splice(third.end(), first, first.end());
    
    std::cout << "\n\nthird.splice(third.end(), first, first.end()); : ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    third.splice(third.end(), first, first.begin(), first.end());

    std::cout << "\n\nthird.splice(third.end(), first, first.begin(), first.end()); : ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    third.clear();

    third.push_front(42);
    third.push_front(10);
    third.push_front(3);
    third.push_front(2);
    third.push_front(1);
    std::cout << "\n\nnew list: ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    third.remove(4);
    std::cout << "\n\nremove(4): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    third.remove(2);
    std::cout << "\n\nremove(2): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    third.remove_if(single_digit);
    std::cout << "\n\nremove_if(single_digit): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    third.push_front(3);
    third.push_front(3);
    third.push_front(3);
    third.push_front(2);
    third.push_front(2);
    third.push_front(1);
    std::cout << "\n\nnew list: ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";

    third.unique();
    std::cout << "\n\nthird.unique(): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    first.clear();
    first.push_front(6);
    first.push_front(5);
    first.push_front(4);
    
    third.merge(first);
    std::cout << "\n\nfirst = 4,5,6 third.merge(first): ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    std::cout << "\n\nfirst size: " << first.size();
    
    third.push_front(12);
    third.push_front(7);
    third.push_front(22);
    
    std::cout << "\n\nthird unsortered: ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    third.sort();
    std::cout << "\n\nthird sortered: ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
    
    third.reverse();
    std::cout << "\n\nthird reversed: ";
    for (ft::List<int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << *it << " ";
}

void test_queue()
{
    std::cout << "| QUEUE TEST |\n\n";
    ft::List<int> mylist (2,200);         // list with 2 elements

    ft::Queue<int> first;                 // empty Queue
    ft::Queue<int,ft::List<int> > second; // empty Queue with list as underlying container
    ft::Queue<int,ft::List<int> > third (mylist);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << "\n\n";

    std::cout << "second empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";
  
    std::cout << "third empty?: ";
    if (third.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n\n";

    third.push(10);
    third.push(7);
    std::cout << "third.push(10)\n";
    std::cout << "third.push(7)\n\n"; 
    std::cout << "third.front() is now " << third.front() << "\n";
    std::cout << "third.back() is now " << third.back() << "\n\n";
    third.pop();
    third.pop();
    std::cout << "third.pop()\n";
    std::cout << "third.pop()\n";
    std::cout << "third.front() is now " << third.front() << '\n';
}

void test_stack()
{
    std::cout << "| STACK TEST |\n\n";

    ft::Vector<int> myvector (2,200);         // list with 2 elements

    ft::Stack<int> first;                 // empty Stack
    ft::Stack<int,ft::Vector<int> > second; // empty Stack with list as underlying container
    ft::Stack<int,ft::Vector<int> > third (myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << "\n\n";

    std::cout << "second empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
    else
        std::cout << "empty\n";
  
    std::cout << "third empty?: ";
    if (third.empty() == false)
        std::cout << "not empty\n\n";
    else
        std::cout << "empty\n\n";

    third.push(10);
    third.push(7);
    std::cout << "third.push(10)\n";
    std::cout << "third.push(7)\n\n"; 
    std::cout << "third.top() is now " << third.top() << "\n\n";
    third.pop();
    third.pop();
    std::cout << "third.pop()\n";
    std::cout << "third.pop()\n";
    std::cout << "third.front() is now " << third.top() << '\n';
    std::cout << "\n";
}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void test_map()
{
    std::cout << "| MAP TEST |\n\n";

    ft::Map<char,int> first;

    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['f']=70;

    ft::Map<char,int> second (first.begin(),first.end());

    ft::Map<char,int> third (second);
    
    ft::Map<char,int> fourth = third;

    std::cout << "first:\n";
    for (ft::Map<char,int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "\nsecond:\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "\nthird:\n";
    for (ft::Map<char,int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";
    
    std::cout << "\nfourth:\n";
    for (ft::Map<char,int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "\nsecond empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
        
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "max_size: " << second.max_size() << "\n";

    std::cout << "\nsecond['a'] is " << second['a'] << '\n';
    std::cout << "second['a'] is " << second['c'] << '\n';

    second.insert(ft::_pair<const char, int>('e', 42));
    std::cout << "\nsecond.insert(_pair<const char, int>('e', 42)):\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    second.insert(ft::_pair<const char, int>('e', 42));
    std::cout << "\nsecond.insert(_pair<const char, int>('e', 42)):\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";
            
    second.erase('a');
    std::cout << "\nsecond.erase('a'):\n";
    for (ft::Map<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    third.swap(second);
    std::cout << "\nthird.swap('second'):\n";
    std::cout << "third: \n";
    for (ft::Map<char,int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    ft::Map<char,int>::key_compare mycomp = third.key_comp();
    ft::Map<char,int>::iterator it = third.begin();
    ft::Map<char,int>::iterator it2 = third.begin();
    it2++;
    if (mycomp(it.base()->key_value, it2.base()->key_value) == true)
        std::cout << "\nmy comp == less\n";
    if (third.value_comp()(ft::_pair<const char, int>('c', 42), ft::_pair<const char, int>('d', 44)) == true)
        std::cout << "value_comp == less\n";

    std::cout << "\nthird.find('b'): \n";
    std::cout << "b => " << third.find('b').base()->mapped_value << '\n';

    std::cout << "third.count('b'): \n";
    std::cout << third.count('b') << "\n";

    ft::Map<char,int>::iterator it3 = third.lower_bound('b');
    std::cout << "\nthird.lower_bound ('b'):\n";
    std::cout << it3.base()->key_value << " " << it3.base()->mapped_value << "\n";
    
    ft::Map<char,int>::iterator it4 = third.upper_bound('b');
    std::cout << "third.upper_bound ('b'):\n";
    std::cout << it4.base()->key_value << " " << it4.base()->mapped_value << "\n";

    ft::_pair<ft::Map<char,int>::iterator,ft::Map<char,int>::iterator> ret = third.equal_range('c');

    std::cout << "\n";
    std::cout << "lower bound points to: ";
    std::cout << ret.key_value.base()->key_value << " => " << ret.key_value.base()->mapped_value << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.mapped_value.base()->key_value << " => " << ret.mapped_value.base()->mapped_value << '\n';
    
}

void test_multimap()
{
    std::cout << "| MULTIMAP TEST |\n\n";

    ft::MultiMap<char,int> first;

    first.insert(ft::_pair<const char, int>('a', 10));
    first.insert(ft::_pair<const char, int>('b', 30));
    first.insert(ft::_pair<const char, int>('c', 50));
    first.insert(ft::_pair<const char, int>('f', 70));

    std::cout << "lol\n";

    ft::MultiMap<char,int> second(first.begin(),first.end());

    std::cout << "lol\n";

    ft::MultiMap<char,int> third(second);
    
    ft::MultiMap<char,int> fourth = third;

    std::cout << "first:\n";
    for (ft::MultiMap<char,int>::iterator it = first.begin(); it != first.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "\nsecond:\n";
    for (ft::MultiMap<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "\nthird:\n";
    for (ft::MultiMap<char,int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";
    
    std::cout << "\nfourth:\n";
    for (ft::MultiMap<char,int>::iterator it = fourth.begin(); it != fourth.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    std::cout << "\nsecond empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
        
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "max_size: " << second.max_size() << "\n";

    second.insert(ft::_pair<const char, int>('e', 42));
    std::cout << "\nsecond.insert(_pair<const char, int>('e', 42)):\n";
    for (ft::MultiMap<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    second.insert(ft::_pair<const char, int>('e', 42));
    std::cout << "\nsecond.insert(_pair<const char, int>('e', 42)):\n";
    for (ft::MultiMap<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";
            
    second.erase('a');
    std::cout << "\nsecond.erase('a'):\n";
    for (ft::MultiMap<char,int>::iterator it = second.begin(); it != second.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    third.swap(second);
    std::cout << "\nthird.swap('second'):\n";
    std::cout << "third: \n";
    for (ft::MultiMap<char,int>::iterator it = third.begin(); it != third.end(); it++)
        std::cout << it.base()->key_value << " " << it.base()->mapped_value << "\n";

    ft::MultiMap<char,int>::key_compare mycomp = third.key_comp();
    ft::MultiMap<char,int>::iterator it = third.begin();
    ft::MultiMap<char,int>::iterator it2 = third.begin();
    it2++;
    if (mycomp(it.base()->key_value, it2.base()->key_value) == true)
        std::cout << "\nmy comp == less\n";
    if (third.value_comp()(ft::_pair<const char, int>('c', 42), ft::_pair<const char, int>('d', 44)) == true)
        std::cout << "value_comp == less\n";

    std::cout << "\nthird.find('b'): \n";
    std::cout << "b => " << third.find('b').base()->mapped_value << '\n';

    std::cout << "third.count('b'): \n";
    std::cout << third.count('b') << "\n";

    ft::MultiMap<char,int>::iterator it3 = third.lower_bound('b');
    std::cout << "\nthird.lower_bound ('b'):\n";
    std::cout << it3.base()->key_value << " " << it3.base()->mapped_value << "\n";
    
    ft::MultiMap<char,int>::iterator it4 = third.upper_bound('b');
    std::cout << "third.upper_bound ('b'):\n";
    std::cout << it4.base()->key_value << " " << it4.base()->mapped_value << "\n";

    ft::_pair<ft::MultiMap<char,int>::iterator,ft::MultiMap<char,int>::iterator> ret = third.equal_range('c');

    std::cout << "\n";
    std::cout << "lower bound points to: ";
    std::cout << ret.key_value.base()->key_value << " => " << ret.key_value.base()->mapped_value << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.mapped_value.base()->key_value << " => " << ret.mapped_value.base()->mapped_value << '\n';
}

void test_set()
{
    std::cout << "| SET TEST |\n\n";

    ft::Set<int> first;                           // empty Set of ints

    int myints[]= {10,20,30,40,50};
    ft::Set<int> second (myints,myints+5);        // range

    ft::Set<int> third (second);

    ft::Set<int> fourth = second;


    std::cout << "second:\n";
    for (ft::Set<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << "\n\nthird:\n";
    for (ft::Set<int>::iterator it=third.begin(); it!=third.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << "\n\nfourth:\n";
    for (ft::Set<int>::iterator it=fourth.begin(); it!=fourth.end(); ++it)
        std::cout << ' ' << *it;

    std::cout << "\n\nsecond empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
        
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "max_size: " << second.max_size() << "\n";
    
    second.insert(25);
    std::cout << "\nsecond.insert(25):\n";
    for (ft::Set<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;

    second.insert(25);
    std::cout << "\n\nsecond.insert(25):\n";
    for (ft::Set<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;
    
    second.erase(40);
    std::cout << "\n\nsecond.erase(40):\n";
    for (ft::Set<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;
    
    third.swap(second);
    std::cout << "\n\nthird.swap('second'):\n";
    std::cout << "third: \n";
    for (ft::Set<int>::iterator it=third.begin(); it!=third.end(); ++it)
        std::cout << ' ' << *it;
    
    std::cout << "\n";

    ft::Set<int>::iterator it = third.begin();
    ft::Set<int>::iterator it2 = third.begin();
    it2++;
    if (third.key_comp()(it.base()->key_value, it2.base()->key_value) == true)
        std::cout << "\nmy comp == less\n";
    if (third.value_comp()(it.base()->key_value, it2.base()->key_value) == true)
        std::cout << "value_comp == less\n";
    
    std::cout << "\nthird.find(20): \n";
    std::cout << "b => " << third.find(20).base()->key_value << '\n';

    std::cout << "third.count(20): \n";
    std::cout << third.count(20) << "\n";

    ft::Set<int>::iterator it3 = third.lower_bound(20);
    std::cout << "\nthird.lower_bound (20):\n";
    std::cout << it3.base()->key_value << "\n";
    
    ft::Set<int>::iterator it4 = third.upper_bound(20);
    std::cout << "third.upper_bound (20):\n";
    std::cout << it4.base()->key_value << "\n";

    ft::_pair<ft::Set<int>::iterator,ft::Set<int>::iterator> ret = third.equal_range(20);

    std::cout << "\nlower bound points to: ";
    std::cout << ret.key_value.base()->key_value << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.mapped_value.base()->key_value << '\n';
}

void test_multiset()
{
    std::cout << "| MULTISET TEST |\n\n";

    ft::MultiSet<int> first;                           // empty MultiSet of ints

    int myints[]= {10,20,30,40,50};
    ft::MultiSet<int> second (myints,myints+5);        // range

    ft::MultiSet<int> third (second);

    ft::MultiSet<int> fourth = second;


    std::cout << "second:\n";
    for (ft::MultiSet<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << "\n\nthird:\n";
    for (ft::MultiSet<int>::iterator it=third.begin(); it!=third.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << "\n\nfourth:\n";
    for (ft::MultiSet<int>::iterator it=fourth.begin(); it!=fourth.end(); ++it)
        std::cout << ' ' << *it;

    std::cout << "\n\nsecond empty?: ";
    if (second.empty() == false)
        std::cout << "not empty\n";
        
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "max_size: " << second.max_size() << "\n";
    
    second.insert(25);
    std::cout << "\nsecond.insert(25):\n";
    for (ft::MultiSet<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;

    second.insert(25);
    std::cout << "\n\nsecond.insert(25):\n";
    for (ft::MultiSet<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;
    
    second.erase(40);
    std::cout << "\n\nsecond.erase(40):\n";
    for (ft::MultiSet<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;
    
    third.swap(second);
    std::cout << "\n\nthird.swap('second'):\n";
    std::cout << "third: \n";
    for (ft::MultiSet<int>::iterator it=third.begin(); it!=third.end(); ++it)
        std::cout << ' ' << *it;
    
    std::cout << "\n";

    ft::MultiSet<int>::iterator it = third.begin();
    ft::MultiSet<int>::iterator it2 = third.begin();
    it2++;
    if (third.key_comp()(it.base()->key_value, it2.base()->key_value) == true)
        std::cout << "\nmy comp == less\n";
    if (third.value_comp()(it.base()->key_value, it2.base()->key_value) == true)
        std::cout << "value_comp == less\n";
    
    std::cout << "\nthird.find(20): \n";
    std::cout << "b => " << third.find(20).base()->key_value << '\n';

    std::cout << "third.count(20): \n";
    std::cout << third.count(20) << "\n";

    ft::MultiSet<int>::iterator it3 = third.lower_bound(20);
    std::cout << "\nthird.lower_bound (20):\n";
    std::cout << it3.base()->key_value << "\n";
    
    ft::MultiSet<int>::iterator it4 = third.upper_bound(20);
    std::cout << "third.upper_bound (20):\n";
    std::cout << it4.base()->key_value << "\n";

    ft::_pair<ft::MultiSet<int>::iterator,ft::MultiSet<int>::iterator> ret = third.equal_range(20);

    std::cout << "\nlower bound points to: ";
    std::cout << ret.key_value.base()->key_value << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.mapped_value.base()->key_value << '\n';
}

int main(int argc, char **av)
{
    if (argc == 2)
    {
        if (strcmp(av[1], "bonus") == 0)
        {   
            test_set();
            test_multiset();
            test_multimap();
        }
    }
    else
    {
        test_vector();
        test_list();
        test_queue();
        test_stack();
        test_map();
    }
    return 0;
}
