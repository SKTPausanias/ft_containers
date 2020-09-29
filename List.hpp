/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:26:31 by mlaplana          #+#    #+#             */
/*   Updated: 2020/09/29 02:13:12 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

namespace ft
{

template <class Category, class T, class Distance = std::ptrdiff_t,
            class Pointer = T*, class Reference = T&>
class ListIterator
{
public:
    typedef Category iterator_category;
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
protected:
    typedef ListIterator::pointer Tptr;
    Tptr _ptr;
public:
    ListIterator(): _ptr(nullptr) { }
    ListIterator(const Tptr &ptr): _ptr(ptr) { }
    ListIterator(const ListIterator &c): _ptr(c._ptr) { }
    ~ListIterator() {};
    ListIterator &operator=(const ListIterator &c) {this->_ptr = c._ptr; return *this;}
    
    reference operator*() const {return *_ptr;}
    pointer operator->() const {return _ptr;}
    ListIterator& operator++() {
        ++_ptr;
        return *this;
    }
    
    ListIterator operator++(int) { return ListIterator(_ptr++); }
    
    ListIterator& operator--() {
        --_ptr;
        return *this;
    }
    
    ListIterator operator--(int) { return ListIterator(_ptr--); }

};

template <class T>
class List
{  
};

}

#endif