/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:38:45 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/12 23:43:52 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include <iostream>
template<class T>
class reverseIterator : public T
{
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::ptrdiff_t difference;
protected:
    pointer _ptr;
public:
    reverseIterator(): _ptr(nullptr) { }
    reverseIterator(pointer const &ptr): _ptr(ptr) { }
    reverseIterator(const reverseIterator &c): _ptr(c._ptr) { }
    virtual ~reverseIterator() { }
    
    reverseIterator &operator=(const reverseIterator &c) { _ptr = c._ptr; return *this; }

    reference operator*() { 
        pointer tmp(_ptr);
        return *--tmp;
    }

    const_reference operator*() const {
        pointer tmp(_ptr);
        return *--tmp;
    }

    pointer operator->() {
        pointer tmp(_ptr);
        return --tmp;
    }

    const_pointer operator->() const {
        pointer tmp(_ptr);
        return --tmp;
    }

    reverseIterator operator++() {
        --_ptr;
        return *this;
    }

    reverseIterator operator++(int) {
        reverseIterator tmp = *this;
        --_ptr;
        return tmp;
    }

    reverseIterator operator--() {
        ++_ptr;
        return *this;
    }

    reverseIterator operator--(int) {
        reverseIterator tmp = *this;
        ++_ptr;
        return tmp;
    }

    reverseIterator operator+(int __n) const {
        return reverseIterator(_ptr - __n); 
    }
    
    reverseIterator operator+=(int __n) {
	    _ptr -= __n;
	    return *this;
    }

    reverseIterator operator-(int __n) const {
        return reverseIterator(_ptr + __n); 
    }
    
    reverseIterator operator-=(int __n) {
	    _ptr += __n;
	    return *this;
    }

    bool operator==(const reverseIterator &c) { return this->_ptr == c._ptr; }
    bool operator!=(const reverseIterator &c) { return (this->_ptr != c._ptr); }
    bool operator<(const reverseIterator &c) { return (this->_ptr > c._ptr); }
    bool operator<=(const reverseIterator &c) { return (this->_ptr >= c._ptr); }
    bool operator>(const reverseIterator &c) { return (this->_ptr < c._ptr); }
    bool operator>=(const reverseIterator &c) { return (this->_ptr <= c._ptr); }
};

#endif