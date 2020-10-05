/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <mlaplana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:30:57 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/05 11:53:28 by mlaplana         ###   ########.fr       */
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
    
    size_type max_size() const {}
    void resize(size_type n, value_type val = value_type()) {}
    size_type capacity() const;
    bool empty() const { return (this->_size == 0); }
    void reserve(size_type n) {}

    reference operator[](size_type n) {}
    const_reference operator[](size_type n) const {}
    reference at (size_type n) {}
    const_reference at (size_type n) const {}
    reference front() {}
    const_reference front() const {}
    reference back() {}
    const_reference back() const {}

    void assign(size_type size, const_reference val);
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