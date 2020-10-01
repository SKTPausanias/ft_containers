/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:30:57 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/01 17:08:15 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
template<class T>
class VectorIterator
{
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
	typedef std::ptrdiff_t difference_type;
protected:
    pointer _ptr;
public:
    VectorIterator(): _ptr(nullptr) { }
    VectorIterator(const pointer &ptr): _ptr(ptr) { }
    VectorIterator(const VectorIterator &c): _ptr(c._ptr) { }
    virtual ~VectorIterator() {};
    VectorIterator &operator=(const VectorIterator &c) {this->_ptr = c._ptr; return *this;}
    
    reference operator*() const {return *_ptr;}
    pointer operator->() const {return _ptr;}
	reference operator[] (const difference_type& _n) const { return _ptr[_n]; }
    VectorIterator& operator++() {
        ++_ptr;
        return *this;
    }
    
    VectorIterator operator++(int) { return VectorIterator(_ptr++); }
    
    VectorIterator& operator--() {
        --_ptr;
        return *this;
    }
    
    VectorIterator operator--(int) { return VectorIterator(_ptr--); }
    
    VectorIterator operator+=(difference_type _n) { _ptr += _n; return *this; }

    VectorIterator operator+(difference_type _n) { return VectorIterator(_ptr + _n); }

    VectorIterator operator-=(difference_type _n) { _ptr -= _n; return *this; }

    VectorIterator operator-(difference_type _n) { return VectorIterator(_ptr - _n); }

    bool operator==(const VectorIterator &c) { return (this->_ptr == c._ptr); }
    bool operator!=(const VectorIterator &c) { return (this->_ptr != c._ptr); }
    bool operator<(const VectorIterator &c) { return (this->_ptr < c._ptr); }
    bool operator<=(const VectorIterator &c) { return (this->_ptr <= c._ptr); }
    bool operator>(const VectorIterator &c) { return (this->_ptr > c._ptr); }
    bool operator>=(const VectorIterator &c) { return (this->_ptr >= c._ptr); }
};

template<class T>
class Vector
{
public:
	typedef T value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef VectorIterator<value_type> iterator;
	typedef VectorIterator<value_type> reverse_iterator;
	typedef std::ptrdiff_t difference_type;
	typedef unsigned int size_type;
private:
	pointer _ptr;
	size_type _len;
	size_type _capacity;
public:
	iterator begin()
	{
		
	}
};

#endif