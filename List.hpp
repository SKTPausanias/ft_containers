/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:26:31 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/13 00:29:43 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

namespace ft
{

template <class T>
class ListIterator
{
public:      
    typedef List_iterator<T>		_Self;
    typedef List_node<T>			_Node;
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef std::ptrdiff_t difference_type;
protected:
    pointer _ptr;
public:
    ListIterator(): _ptr(nullptr) { }
    ListIterator(const pointer &ptr): _ptr(ptr) { }
    ListIterator(const ListIterator &c): _ptr(c._ptr) { }
    virtual ~ListIterator() {};
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
    
    ListIterator operator+=(difference_type _n) { _ptr += _n; return *this; }

    ListIterator operator+(difference_type _n) { return ListIterator(_ptr + _n); }

    ListIterator operator-=(difference_type _n) { _ptr -= _n; return *this; }

    ListIterator operator-(difference_type _n) { return ListIterator(_ptr - _n); }

    bool operator==(const ListIterator &c) { return (this->_ptr == c._ptr); }
    bool operator!=(const ListIterator &c) { return (this->_ptr != c._ptr); }
    bool operator<(const ListIterator &c) { return (this->_ptr < c._ptr); }
    bool operator<=(const ListIterator &c) { return (this->_ptr <= c._ptr); }
    bool operator>(const ListIterator &c) { return (this->_ptr > c._ptr); }
    bool operator>=(const ListIterator &c) { return (this->_ptr >= c._ptr); }
};

template <class T>
class List
{
};

}

#endif