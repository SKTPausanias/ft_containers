/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:30:57 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/08 13:52:45 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "reverseIterator.hpp"
#include <limits>

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

        difference_type operator-(VectorIterator const &other) const {
            return (this->_ptr - other._ptr);
        }
    };

    template<typename T>
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
    	void copy_construct(size_type idx, const_reference val) {
		    new(&this->_ptr[idx]) value_type(val);
	    }
    public:
        Vector(): _ptr(nullptr), _size(0), _capacity(0) {}
        
        /*Vector(size_type n, const value_type& val = value_type()):
            _ptr(nullptr), _size(0), _capacity(0) {
            printf("f\n");
            this->assign(n, val);
        }*/
        
        Vector(size_type n, const_reference val=value_type()):
            _ptr(nullptr), _size(0), _capacity(0) {
            printf("f\n");
            this->assign(n, val);
        }
        
        Vector(iterator first, iterator last):
            _ptr(nullptr), _size(0), _capacity(0) {
            insert(begin(), first, last);        
        }
        
        Vector(const Vector& x):
            _ptr(nullptr), _size(0), _capacity(0) {
            insert(begin(), x.begin(), x.end());
        }

        virtual ~Vector() {
            this->clear();
            if (this->_ptr)
                delete _ptr;
        }
        
        Vector &operator=(const Vector &x) {
            this->clear();
            insert(begin(), x.begin(), x.end());
            return *this;
        }

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
            return std::numeric_limits<difference_type>::max() / sizeof(value_type);
        }
        
        void resize(size_type n, value_type val = value_type()) {
            if (n < _size)
                erase(begin() + n, end());
            if (n > _capacity)
                reserve(n);
            if (n > _size)
                insert(end(), n - _size, val);    
        }
        
        size_type capacity() const {
            return this->_capacity;
        }
        
        bool empty() const {
            return (this->_size == 0);
        }
        
        /*void reserve(size_type n) {
            printf("reserve\n");
            if (n > max_size())
                throw std::length_error("Vector::resize");
            if (_capacity == 0)
            {
                this->_ptr = new value_type[n];
                this->_capacity = n;
            }
            else if (n > _capacity)
            {
                printf("yeso\n");
                pointer tmp = static_cast<pointer>(::operator new(sizeof(value_type) * n));
                if (this->_ptr)
                {
                    for (size_t i = 0; i < this->_size; i++)
                        new (&tmp[i]) value_type(this->_ptr[i]);
                    delete(this->_ptr);
                }
                this->_capacity = n;
                this->_ptr = tmp;   
            }
        }*/
        
        /*void reserve(size_type new_cap)
		{
			if (new_cap <= _capacity) // no reallocation when not needed
				return;

			if (!new_cap) // no empty allocation
				return;

			std::allocator<T> alloc;
			T *new_arr = alloc.allocate(new_cap);
			for (size_type i = 0; i < _size; i++)
			{
				//alloc.construct(&new_arr[i], _ptr[i]); // call copy constructor
				//alloc.destroy(&_ptr[i]);			   // call destructor
			}

			//alloc.deallocate(_ptr, _capacity);
			_ptr = new_arr;
			_capacity = new_cap;
		}*/

        void reserve(size_type size) {
            if (this->_capacity == 0) {
                size = (size > 128) ? size : 128;
                printf("mama\n");
                this->_ptr = static_cast<value_type*>(::operator new(sizeof(value_type) * size));
                this->_capacity = size;
            } else if (size > this->_capacity) {
                size = (size > this->_capacity * 2) ? size : this->_capacity * 2;
                value_type *tmp = static_cast<value_type*>(::operator new(sizeof(value_type) * size));
                if (this->_ptr) {
                    //std::memmove(static_cast<void*>(tmp), static_cast<void*>(this->container), this->m_size * sizeof(value_type));
                    for (size_t i = 0; i < this->_size; ++i)
                        new(&tmp[i]) value_type(this->_ptr[i]);
                    ::operator delete(this->_ptr);
                }
                this->_ptr = tmp;
                this->_capacity = size;
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

        /*void assign(size_type size, const_reference val) {
            clear();
            //printf("hola¿\n");
            //insert(begin(), size, val);
        }*/

        void assign(size_type size, const_reference val) {
            printf("assign\n");
            if (size > this->_capacity)
                this->reserve(size);
            size_t i = 0;
            while (i < size) {
                if (i >= this->_size)
                    this->copy_construct(i, val);
                else
                    this->_ptr[i] = val;
                ++i;
            }
            while (i < this->_size)
                this->_ptr[i++].value_type::~value_type();
            this->_size = size;
        }

        /*void assign(iterator first, iterator last) {
            clear();
            printf("no puede ser\n");
            insert(begin(), first, last);
        }

        void assign(const_iterator first, const_iterator last) {
            clear();
            printf("no puede ser\n");
            insert(begin(), first, last);
        }*/

        void push_back(const value_type& val) {
            insert(end(), val);
        }
        
        void pop_back() {
            erase(end() - 1);
        }
        
        iterator insert(iterator position, const value_type& val) {
            size_type init = 1;
            insert(position, init, val);
            return position;
        }
        
        void insert(iterator position, size_type n, const value_type& val) {
            iterator it = this->begin();
            size_type index = 0;
            while (it != position) {
                ++it;
                ++index;
            }
            if (!n)
                return ;
            printf("hola\n");
            if (_size + n >= _capacity)
               reserve(_size + n);
            for (size_t j = _size; j >= 1 && j >= index; j--)
                new(&_ptr[j + n]) value_type(_ptr[j]);
            for (size_t i = index; i < index + n; i++)
                new(&_ptr[i]) value_type(val);
            printf("%d\n", val);
            _size += n;
        }

        template<class InputIt>
        void insert(iterator position, InputIt first, InputIt last) {
            iterator it = this->begin();
            size_type n = last - first;
            size_type index = 0;
            while (it != position) {
                ++it;
                ++index;
            }
            if (!n)
                return ;
            if (_size + n > _capacity)
                reserve(_size + n);
            for (size_t j = _size - 1; j >= index; j--)
                new(&_ptr[j + n]) value_type(_ptr[j]);
            for (size_t i = index; i < index + n; i++)
                new(&_ptr[i]) value_type(*first++); 
            _size += n;    
        }
        
        iterator erase(iterator position) {
            return erase(position, position + 1);
        }
        
        iterator erase(iterator first, iterator last) {
            iterator it = this->begin();
            size_type n = last - first;
            size_type index = 0;
            while (it != first) {
                ++it;
                ++index;
            }
            if (n <= 0)
                return last;
            for (size_t i = index; i < index + n; i++)
                delete &_ptr[index];
            for (size_t i = index + n; i < _size; i++)
            {
                new (&_ptr[i - n]) value_type(_ptr[i]);
                delete &_ptr[i];
            }
            _size -= n;
            return first;
        }
        
        void swap(Vector& x) {
            std::swap(this->_ptr, x._ptr);
            std::swap(this->_size, x._size);
            std::swap(this->_capacity, x._capacity); 
        }
        
        void clear() {
            erase(begin(), end());
        }
    };

    template<typename T>
    bool operator==(Vector<T> const &lhs, Vector<T> const &rhs) {
        return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<typename T>
    bool operator!=(Vector<T> const &lhs, Vector<T> const &rhs) {
        return (!(lhs = rhs));
    }

    template<typename T>
    bool operator<(Vector<T> const &lhs, Vector<T> const &rhs) {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<typename T>
    bool operator<=(Vector<T> const &lhs, Vector<T> const &rhs) {
        return (!(rhs < lhs));
    }

    template<typename T>
    bool operator>(Vector<T> const &lhs, Vector<T> const &rhs) {
        return (rhs < lhs);
    }

    template<typename T>
    bool operator>=(Vector<T> const &lhs, Vector<T> const &rhs) {
        return (!(lhs < rhs));
    }

    template<typename T>
    void swap(Vector<T> &x, Vector<T> &y) {
        x.swap(y);
    }

}

#endif