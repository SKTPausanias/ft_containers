/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:26:31 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/16 18:27:15 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "reverseIterator.hpp"
namespace ft
{

template<typename T>
struct  _List_Node
{
    _List_Node* prev;
    _List_Node* next;

    _List_Node(_List_Node *prev_, _List_Node *next_)
				: prev(prev_), next(next_) {}
    T el;
};

template <class T>
class ListIterator
{
public:      
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef std::ptrdiff_t difference_type;
protected:
    typedef ListIterator<T> _Self;
    typedef _List_Node<T> _node;
    _node* _p;
public:
    ListIterator(): _p(nullptr) { }
    ListIterator(_node* p): _p(p) { }
    ListIterator(const ListIterator &x): _p(x._p) { }
    virtual ~ListIterator() {};
    ListIterator &operator=(const ListIterator &x) { this->_p = x._p; return *this; }
    
    reference operator*() const { return _p->el; }
    pointer operator->() const { return &_p->el; }
    const_reference operator*() { return _p->el; }
    const_pointer operator->() { return &_p->el; }
    
    _Self& operator++() {
        _p = _p->next;
        return *this;
    }
    
    _Self operator++(int) { 
        _Self tmp = *this;
        _p = _p->next;
        return tmp;
    }
    
    _Self& operator--() {
        _p = _p->prev;
        return *this;
    }
    
    _Self operator--(int) {
        _Self tmp = *this;
        _p = _p->prev;
        return *this;
    }
    
    template <typename _T>
	friend bool operator==(const ListIterator<T> &lx, const ListIterator<T> &y);  
};

template<typename T>
bool &operator==(const ListIterator<T> &x, const ListIterator<T>& y){
    return (x._p->el == y._p->el && x._p->next == y._p->next && x._p->prev == y._p->prev);
}

template<typename T>
bool &operator!=(const ListIterator<T> &x, const ListIterator<T> &y){
    return (!(x == y));
}

template <class T>
class List
{
public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef ListIterator<value_type> iterator;
    typedef ListIterator<const value_type> const_iterator;
    typedef reverseIterator<iterator>  reverse_iterator;
    typedef reverseIterator<const_iterator> const_reverse_iterator; 
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;
private:
    typedef List<T> _Self;
    _List_Node<T> *_head;
    _List_Node<T> *_tail;
    size_type _n;
public:
    List() : _n(0), _head(nullptr), _tail(nullptr) { }
    List(size_type n, const value_type& val = value_type()): _n(n) {
        
    } 
};

}

#endif