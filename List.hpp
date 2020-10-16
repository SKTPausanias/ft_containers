/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:26:31 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/16 13:59:53 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

namespace ft
{
template<class T>
struct  _List_Node
{
    _List_Node* prev;
    _List_Node* next;
    T el;

    bool operator==(_List_Node x, _List_Node y)
    {
        
    }
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
    
    bool operator==(const _Self& x, const _Self& y){ return x._p == y._p; }
    bool operator!=(const _Self& x, const _Self& y){ return x._p != y._p; }
};

template <class T>
class List
{
};

}

#endif