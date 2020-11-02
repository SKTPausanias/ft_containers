/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:30:50 by mlaplana          #+#    #+#             */
/*   Updated: 2020/11/02 15:10:48 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include "reverseIterator.hpp"
#include <algorithm>

namespace ft
{

template<typename T>
struct _node
{
    T key_value;
    
    _node* prev;
    _node* next;

    _node(T t1): key_value(t1) {}
    
    _node(T t1, _node *prev_, _node *next_): key_value(t1), prev(prev_), next(next_) {}
    
    
    void insert_before(_node *node) {
		if (this->prev) {
			node->prev = this->prev;
			this->prev->next = node;
		}
		node->next = this;
		this->prev = node;
	}
};

template <typename T>
class SetIterator
{
public:      
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef std::ptrdiff_t difference_type;
protected:
    typedef SetIterator<T> _Self;
    typedef _node<T> node;
    node* _p;
public:
    SetIterator(): _p(nullptr) { }
    SetIterator(node* p): _p(p) { }
    SetIterator(const SetIterator &x): _p(x._p) { }
    virtual ~SetIterator() {};
    SetIterator &operator=(const SetIterator &x) { this->_p = x._p; return *this; }

    node* base() const {
        return _p;
    }
    
    reference operator*() const { return _p->key_value; }
    pointer operator->() const { return &_p->key_value; }
    const_reference operator*() { return _p->key_value; }
    const_pointer operator->() { return &_p->key_value; }
    
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

	bool operator==(SetIterator const &other) const {
		return (this->_p == other._p);
	}
	bool operator!=(SetIterator const &other) const {
		return (this->_p != other._p);
	}
	bool operator<(SetIterator const &other) const {
		return (this->_p < other._p);
	}
	bool operator<=(SetIterator const &other) const {
		return (this->_p <= other._p);
	}
	bool operator>(SetIterator const &other) const {
		return (this->_p > other._p);
	}
	bool operator>=(SetIterator const &other) const {
		return (this->_p >= other._p);
	}
};
 
template <class T, class Compare = std::less<T>>
class Set
{
public:
    typedef T key_type;
    typedef T value_type;
    typedef Compare key_compare;
    typedef Compare value_compare;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef SetIterator<value_type> iterator;
    typedef SetIterator<const value_type> const_iterator;
    typedef reverseIterator<iterator>  reverse_iterator;
    typedef reverseIterator<const_iterator> const_reverse_iterator; 
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

private:
    typedef Set<T, Compare> _Self;
    _node<T> *_head;
    _node<T> *_tail;
    key_compare comp;
    size_type _n;
public:
    Set(const key_compare& comp = key_compare()): comp(comp), _n(0) {
        _head = new _node<T>(0, NULL, NULL);
        _tail = _head;
    }

    template <class InputIterator>
    Set(InputIterator first, InputIterator last): _n(0) {
        _head = new _node<T>(0, NULL, NULL);
        _tail = _head;
        insert(first, last);
    }

    Set(const Set& x): _n(0) {
        _head = new _node<T>(0, NULL, NULL);
        _tail = _head;
        insert(x.begin(), x.end());
    }
    
    virtual ~Set() {
        this->clear();
        delete _tail;
    }
    
    Set &operator=(const Set& x) {
        this->clear();
        insert(x.begin(), x.end());
        return *this;
    }

    iterator begin() {
        return iterator(_head);
    }
    
    const_iterator begin() const {
        typedef _node<const T> const_node;
		return const_iterator(reinterpret_cast<const_node *>(_head));
    }
    
    iterator end() {
        return iterator(_tail);
    }

    const_iterator end() const {
        typedef _node<const T> const_node;
		return const_iterator(reinterpret_cast<const_node *>(_tail));
    }

    reverse_iterator rbegin() {
        return reverse_iterator(_tail);
    }
    
    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(_tail);
    }
    
    reverse_iterator rend() {
        return reverse_iterator(_head);
    }
    const_reverse_iterator rend() const {
        return const_reverse_iterator(_head);
    }
    
    bool empty() const {
        return (_n == 0);
    }
    
    size_type size() const {
        return _n;
    }
    
    size_type max_size() const {
        return std::numeric_limits<difference_type>::max() / sizeof(value_type);
    }

    iterator insert (iterator position, const value_type& val) {
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
        {
            if (it.base()->key_value == val)
                return iterator(it.base());
        }
        if (position == this->begin())
        {
            _node<T>* node = new _node<T>(val, nullptr, nullptr);
            this->_head->insert_before(node);
            this->_head = node;
            _n++;
            return iterator(this->begin());
        }
        else if (position == this->end())
        {
            _node<T>* node = new _node<T>(val, nullptr, nullptr);
            this->_tail->insert_before(node);
            _n++;
            return iterator(this->end());
        }
        else
        {
            _node<T>* node = new _node<T>(val, nullptr, nullptr);
            position.base()->insert_before(node);
            _n++;
            return iterator(node);
        }
    }
    
    _pair<iterator,bool> insert (const value_type& val) {
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
        {
            if (it.base()->key_value == val)
                return (_pair<iterator, bool>(it.base(), false));
        }
        iterator it1 = insert(lower_bound(val), val);
        return _pair<iterator, bool>(it1, true);
    }

    template <class InputIterator>
    void insert (InputIterator first, InputIterator last) {
        while (first != last)
            this->insert(*first++);
    }
  
    void erase (iterator position)
    {
        if (position == this->begin()) {
            if (_n == 1)
            {
                delete this->_head;
                this->_head = this->_tail;
                this->_tail->prev = nullptr;
            }
            else if (_n >= 1)
            {
                _node<T> *tmp = this->_head->next;
                if (_head->prev)
                    _head->prev->next = _head->next;
                if (_head->next)
                    _head->next->prev = _head->prev;
                delete this->_head;
                this->_head = tmp;
            }
            --_n;
        } 
        else if (position == this->end()) {
            if (_n == 1)
                erase(this->begin());
            else if (_n >= 1)
            {
                _node<T> *tmp = this->_tail->prev;
                if (_tail->prev->prev)
                    _tail->prev->prev->next = _tail->prev->next;
                if (_tail->prev->next)
                    _tail->prev->next->prev = _tail->prev->prev;
                delete tmp;
                --_n;
            }
        }
        else
        {
            position.base()->next->prev = position.base()->prev;
            position.base()->prev->next = position.base()->next;
            delete position.base();
            _n--;
        }
    }

    size_type erase (const key_type& k) {
        size_type ret = 0;
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
        {
            if (it.base()->key_value == k)
            {
                erase(it);
                ret++;
            }
        }
        return ret;
    }
    
    void erase (iterator first, iterator last) {
        while (first != last)
            erase(first++);
    }
    
    void swap (Set& x) {
        std::swap(_head, x._head);
        std::swap(_tail, x._tail);
        std::swap(_n, x._n);
    }
    
    void clear() {
        erase(begin(), end());
    }

    key_compare key_comp() const {
        return comp;
    }

    value_compare value_comp() const {
        return comp;
    }
    
    iterator find (const key_type& k) {
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
        {
            if (it.base()->key_value == k)
                return iterator(it.base());
        }
        return iterator(this->end());
    }
    
    const_iterator find (const key_type& k) const {
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
        {
            if (it.base()->key_value == k)
                return const_iterator(it.base());
        }
        return const_iterator(this->end());
    }
    
    size_type count (const key_type& k) const {
        const_iterator ite = this->end();
        size_type sum = 0;
        for (const_iterator it = this->begin(); it != ite; it++)
        {
            if (it.base()->key_value == k)
                sum++;
        }
        return sum;
    }

    iterator lower_bound (const key_type& k) {
        key_compare cmp = key_comp();
        iterator ite = this->end();
        iterator it = this->begin();
        while(it != ite)
        {
            if (cmp(it.base()->key_value, k) == false)
                return iterator(it.base());
            it++;
        }
        return iterator(this->end());
    }
    
    const_iterator lower_bound (const key_type& k) const {
        key_compare cmp = key_comp();
        iterator ite = this->end();
        iterator it = this->begin();
        while(it != ite)
        {
            if (cmp(it.base()->key_value, k) == false)
                return iterator(it.base());
            it++;
        }
        return const_iterator(this->end());
    }

    iterator upper_bound (const key_type& k) {
        iterator it = lower_bound(k);
        if (it.base()->next)
            it++;
        return it;
    }

    const_iterator upper_bound (const key_type& k) const {
        iterator it = lower_bound(k);
        if (it.base()->next)
            it++;
        return it;
    }

    _pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
        return _pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
    }
    
    _pair<iterator,iterator>             equal_range (const key_type& k) {
        return _pair<iterator, iterator>(lower_bound(k), upper_bound(k));
    }
};

}

#endif
