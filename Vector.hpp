/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <mlaplana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:30:57 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/05 13:03:24 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "reverseIterator.hpp"

namespace ft
{

template<class T>
class VectorIterator
{
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
	typedef std::ptrdiff_t difference_type;
protected:
    pointer _ptr;
public:
    VectorIterator(): _ptr(nullptr) { }
    VectorIterator(const pointer &ptr): _ptr(ptr) { }
    VectorIterator(const VectorIterator &c): _ptr(c._ptr) { }
    virtual ~VectorIterator() {};
    VectorIterator &operator=(const VectorIterator &c) {this->_ptr = c._ptr; return *this;}
    
    reference operator*() const { return *_ptr; }
    const_reference operator*() { return *_ptr; }
    pointer operator->() const { return _ptr; }
    const_pointer operator->() { return _ptr; }
	reference operator[] (const difference_type& _n) const { return _ptr[_n]; }
    const_reference operator[] (const difference_type& _n) { return _ptr[_n]; }
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
    typedef size_t size_type;
	typedef T value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef VectorIterator<value_type> iterator;
	typedef VectorIterator<value_type const> const_iterator;
    typedef reverseIterator<iterator> reverse_iterator;
    typedef reverseIterator<const_iterator> const_reverse_iterator;
	typedef std::ptrdiff_t difference_type;
private:
	pointer _ptr;
	size_type _size;
	size_type _capacity;
public:
    Vector(): _ptr(nullptr), _size(0), _capacity(0) {}
    Vector(size_type n, const value_type& val = value_type()) {}
    Vector(iterator first, iterator last) {}
    Vector(const Vector& x) {}
    virtual ~Vector() {}
    Vector &operator=(const Vector &x) {}

    //iterators
    iterator begin() {
        return iterator(this->_ptr);
    }

    const_iterator begin() const {
        return const_iterator(this->_ptr);
    }

    iterator end() {
        return iterator(this->_ptr + this->_size);
    }

    const_iterator end() const {
        return const_iterator(this->_ptr + this->_size);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(this->end());
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(this->end());
    }

    reverse_iterator rend() {
        return reverse_iterator(this->begin());
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(this->begin());
    }

    //capacity

    size_type size() const {
        return this->_size;
    }
    
    size_type max_size() const {
        return (ft::min(std::numeric_limits<difference_type>::max(),
        std::numeric_limits<size_type>::max() / sizeof(value_type)));
    }
    void resize(size_type n, value_type val = value_type()) {
        if (n > _capacity)
            
    }
    size_type capacity() const {
        return this->_capacity;
    }
    
    bool empty() const {
        return (this->_size == 0);
    }
    
    void reserve(size_type n) {
        if (n > _capacity)
        {
            
        }
    }

    //element access

    reference operator[](size_type n) {
        return this->_ptr[n];
    }

    const_reference operator[](size_type n) const {
        return this->_ptr[n];        
    }

    reference at (size_type n) {
        if (n >= _size)
            throw std::out_of_range("Vector index out of range");
        return this->_ptr[n];
    }

    const_reference at (size_type n) const {
        if (n >= _size)
            throw std::out_of_range("Vector index out of range");
        return this->_ptr[n];    
    }
    
    reference front() {
        return this->_ptr[0];
    }
    const_reference front() const {
        return this->_ptr[0];
    }
    reference back() {
        return this->_ptr[_size - 1];
    }
    const_reference back() const {
        return this->_ptr[_size - 1];
    }

    //modifiers

    void assign(size_type size, const_reference val) {
        
        for (int i = 0; i < size; i++)
            _ptr[i] = val;
    }

    void assign(iterator first, iterator last);
    void assign(const_iterator first, const_iterator last);
    void push_back(const value_type& val);
    void pop_back();
    iterator insert(iterator position, const value_type& val);
    void insert(iterator position, size_type n, const value_type& val);
    void insert(iterator position, iterator first, iterator last);
    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    void swap(Vector& x);
    void clear();
};

template<class T>
bool operator!=(Vector<T> const &lhs, Vector<T> const &rhs) {
}

template<class T>
bool operator<(Vector<T> const &lhs, Vector<T> const &rhs) {
}

template<class T>
bool operator<=(Vector<T> const &lhs, Vector<T> const &rhs) {
}

template<class T>
bool operator>(Vector<T> const &lhs, Vector<T> const &rhs) {
}

template<class T>
bool operator>=(Vector<T> const &lhs, Vector<T> const &rhs) {
}

template<class T>
void swap(Vector<T> &x, Vector<T> &y) {
    x.swap(y);
}

}

#endif