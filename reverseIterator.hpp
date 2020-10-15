/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:38:45 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/15 13:35:19 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include <iostream>

namespace ft
{
template<class It>
class reverseIterator : public It
{
public:
    using typename It::value_type;
    using typename It::pointer;
    using typename It::const_pointer;
    using typename It::reference;
    using typename It::const_reference;
    using typename It::difference_type;
private:
    It _base;
    reverseIterator();
public:
    reverseIterator(It base): _base(base) { }
    reverseIterator(const reverseIterator &x): _base(x._base) { }
    virtual ~reverseIterator() { }
    reverseIterator &operator=(const reverseIterator &x) { this->_base = x._base; return *this; }
	
    reference operator*() const {
		It tmp(_base);
		return (*--tmp);
	}
    
	const_reference operator*() {
		It tmp(_base);
		return (*--tmp);
	}

    pointer operator->() {
        It tmp(_base);
        return &*--tmp;
    }

    const_pointer operator->() const {
        It tmp(_base);
        return &*--tmp;
    }

    reverseIterator &operator++() {
        --_base;
        return *this;
    }

    reverseIterator operator++(int) {
        reverseIterator tmp(_base--);
        return tmp;
    }

    reverseIterator &operator--() {
        ++_base;
        return *this;
    }

    reverseIterator operator--(int) {
        reverseIterator tmp(_base++);
        return tmp;
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