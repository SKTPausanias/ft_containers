/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:38:45 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/13 19:28:06 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include <iostream>

namespace ft
{
template<class T>
class reverseIterator : public T
{
public:
    using typename T::value_type;
    using typename T::pointer;
    using typename T::const_pointer;
    using typename T::reference;
    using typename T::const_reference;
    using typename T::difference_type;
protected:
    T _base;
public:
    reverseIterator(): T() { }
    reverseIterator(T const &base): T(base) { }
    reverseIterator(const reverseIterator &other): T(other._base) { }
    virtual ~reverseIterator() { }
    reverseIterator &operator=(const reverseIterator &c) { _base = c._base; return *this; }

	reference operator*() {
		T tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const {
		T tmp(*this);
		return (*--tmp);
	}

    pointer operator->() {
        T tmp(_base);
        return &*--tmp;
    }

    const_pointer operator->() const {
        T tmp(_base);
        return &*--tmp;
    }

    reverseIterator operator++() {
        --_base;
        return *this;
    }

    reverseIterator operator++(int) {
        reverseIterator tmp(*this);
        --_base;
        return tmp;
    }

    reverseIterator operator--() {
        ++_base;
        return *this;
    }

    reverseIterator operator--(int) {
        reverseIterator tmp(*this);
        ++_base;
        return tmp;
    }

    reverseIterator operator+(int __n) const {
        return reverseIterator(_base - __n); 
    }
    
    reverseIterator operator+=(int __n) {
	    _base -= __n;
	    return *this;
    }

    reverseIterator operator-(int __n) const {
        return reverseIterator(_base + __n); 
    }
    
    reverseIterator operator-=(int __n) {
	    _base += __n;
	    return *this;
    }

    bool operator==(const reverseIterator &c) { return this->_base == c._base; }
    bool operator!=(const reverseIterator &c) { return (this->_base != c._base); }
    bool operator<(const reverseIterator &c) { return (this->_base > c._base); }
    bool operator<=(const reverseIterator &c) { return (this->_base >= c._base); }
    bool operator>(const reverseIterator &c) { return (this->_base < c._base); }
    bool operator>=(const reverseIterator &c) { return (this->_base <= c._base); }
};

}

#endif