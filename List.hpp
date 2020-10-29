/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:26:31 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/28 21:19:36 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "reverseIterator.hpp"
#include <algorithm>

namespace ft
{

template<typename T>
struct  _List_Node
{
    _List_Node* prev;
    _List_Node* next;
    T el;

    _List_Node(_List_Node *prev_, _List_Node *next_)
                                : prev(prev_), next(next_) {}
    
    void insert_before(_List_Node *node) {
		if (this->prev) {
			node->prev = this->prev;
			this->prev->next = node;
		}
		node->next = this;
		this->prev = node;
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

    _node* base() const {
        return _p;
    }
    
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

	bool operator==(ListIterator const &other) const {
		return (this->_p == other._p);
	}
	bool operator!=(ListIterator const &other) const {
		return (this->_p != other._p);
	}
	bool operator<(ListIterator const &other) const {
		return (this->_p < other._p);
	}
	bool operator<=(ListIterator const &other) const {
		return (this->_p <= other._p);
	}
	bool operator>(ListIterator const &other) const {
		return (this->_p > other._p);
	}
	bool operator>=(ListIterator const &other) const {
		return (this->_p >= other._p);
	}
};

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
    List() : _n(0) {
        _head = new _List_Node<T>(NULL, NULL);
        _tail = _head;
    }
    
    List(size_type n, const value_type& val = value_type()): _n(0) {
        _head = new _List_Node<T>(NULL, NULL);
        _tail = _head;
        insert(begin(), n, val);
    }

    List(iterator first, iterator last): _n(0) {
        _head = new _List_Node<T>(NULL, NULL);
        _tail = _head;
        insert(begin(), first, last);
    }

    List(const List& x): _n(0) {
        _head = new _List_Node<T>(NULL, NULL);
        _tail = _head;
        insert(begin(), x.begin(), x.end());
    }
    
    virtual ~List() {
        this->clear();
        delete _tail;
    }
    
    List &operator=(const List& x) {
        this->clear();
        insert(begin(), x.begin(), x.end());
        return *this;
    }

    iterator begin() {
        return iterator(_head);
    }
    
    const_iterator begin() const {
        typedef _List_Node<const T> const_node;
		return const_iterator(reinterpret_cast<const_node *>(_head));
    }
    
    iterator end() {
        return iterator(_tail);
    }

    const_iterator end() const {
        typedef _List_Node<const T> const_node;
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
    
    reference front() {
        return _head->el;
    }
    
    const_reference front() const {
        return _head->el;
    }
    
    reference back() {
        return _tail->prev->el;
    }
    
    const_reference back() const {
        return _tail->prev->el;
    }
    
    void assign (iterator first, iterator last) {
        clear();
        insert(begin(), first, last);
    }

    void assign (const_iterator first, const_iterator last) {
        clear();
        insert(begin(), first, last);
    }
    
    void assign (size_type n, const value_type& val) {
        clear();
        insert(begin(), n, val);
    }
    
    void push_front (const value_type& val) {
        insert(begin(), val);
    }

    void pop_front() {
        erase(begin());
    }
    
    void push_back (const value_type& val) {
        insert(end(), val);
    }
    
    void pop_back() {
        erase(end());
    }

    iterator insert (iterator position, const value_type& val) {
        if (position == this->begin())
        {
            _List_Node<T>* node = new _List_Node<T>(nullptr, nullptr);
            node->el = val;
            this->_head->insert_before(node);
            this->_head = node;
            _n++;
            return iterator(this->begin());
        }
        else if (position == this->end())
        {
            _List_Node<T>* node = new _List_Node<T>(nullptr, nullptr);
            node->el = val;
            this->_tail->insert_before(node);
            _n++;
            return iterator(this->end());
        }
        else
        {
            _List_Node<T>* node = new _List_Node<T>(nullptr, nullptr);
            node->el = val;
            position.base()->insert_before(node);
            _n++;
            return iterator(node);
        }
    }
    
    void insert (iterator position, size_type n, const value_type& val) {
        for (size_type i = 0; i < n; i++)
            this->insert(position, val);
    }
    
   void insert (iterator position, const_iterator first, const_iterator last) {
        while (first != last)
            this->insert(position, *first++);
    }

    void insert (iterator position, iterator first, iterator last) {
        while (first != last)
            this->insert(position, *first++);
    }
    
    iterator erase (iterator position)
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
                _List_Node<T> *tmp = this->_head->next;
                if (_head->prev)
                    _head->prev->next = _head->next;
                if (_head->next)
                    _head->next->prev = _head->prev;
                delete this->_head;
                this->_head = tmp;
            }
            --_n;
            return (this->begin());
        } 
        else if (position == this->end()) {
            if (_n == 1)
                return erase(this->begin());
            else if (_n >= 1)
            {
                _List_Node<T> *tmp = this->_tail->prev;
                if (_tail->prev->prev)
                    _tail->prev->prev->next = _tail->prev->next;
                if (_tail->prev->next)
                    _tail->prev->next->prev = _tail->prev->prev;
                delete tmp;
                --_n;
            }
            return (this->end());
        }
        else
        {
            _List_Node<T>* node_right = position.base()->next;
            position.base()->next->prev = position.base()->prev;
            position.base()->prev->next = position.base()->next;
            delete position.base();
            _n--;
            return iterator(node_right);
        }
    }
    
    iterator erase (iterator first, iterator last) {
        while (first != last)
            erase(first++);
        return (first);
    }
    
    void swap (List& x) {
        std::swap(_head, x._head);
        std::swap(_tail, x._tail);
        std::swap(_n, x._n);
    }
    
    void resize (size_type n, value_type val = value_type()) 
    {
        if (n < _n)
        {
            while (_n > n)
                this->pop_back();            
        }
        else if (n > _n)
            this->insert(this->end(), n - _n, val);
    }
    
    void clear() {
        erase(begin(), end());
        //_head = new _List_Node<T>(NULL, NULL);
        //_tail = _head;
    }
    
    void splice (iterator position, List& x) {
        for (iterator it = x.begin(); it != x.end(); it++)
            splice(position, x, it);   
    }
    
    void splice (iterator position, List& x, iterator i) {
        iterator it = x.begin();
        while (it != i)
            it++;
        insert(position, *it);
        x._n--;
    }
    
    void splice (iterator position, List& x, iterator first, iterator last) {
        while (first != last)
            splice(position, x, first++);
    }
    
    void remove (const value_type& val) {
        iterator ite = this->end();
        iterator it = this->begin();
        while (it != ite)
        {
            if (val == it.base()->el) // *it ?
                it = erase(it);
            else
                it++;
        }
    }
    
    template <class Predicate>
    void remove_if (Predicate pred) {
        iterator ite = this->end();
        iterator it = this->begin();
        while (it != ite)
        {
            if (pred(it.base()->el)) // *it ?
                it = erase(it);
            else
                it++;
        }        
    }
    
	void unique()
	{
		this->unique(&equal<value_type>);
	}

	template <typename BinaryPredicate>
	void unique(BinaryPredicate binary_pred)
    {
        iterator prev = this->begin();
        iterator next = prev;
        iterator last = this->end();
        while (next != last)
        {
            ++next;
            if (binary_pred(*prev, *next))
            {
                erase(next);
                next = prev;
            }
            else
                prev = next;
        }
    }   
    
    void merge (List& x) {
        return merge(x, std::less<T>());
    }
    
    template <class Compare>
    void merge (List& x, Compare comp) {
        if (&x == this)
            return;
        iterator ite = this->begin();
        for (iterator it = x.begin(); it != x.end(); it++)
        {
            while(ite != this->end() && comp(*ite, *it))
                ite++;
            insert(ite, *it);
        }
        x.clear();
        x._n = 0;
        delete x._head;
    }
    
    void sort() {
        sort(std::greater<T>());
    }
    
    template <class Compare>
    void sort (Compare comp) {
        if (this->_n <= 1)
            return;
        iterator first = this->begin();
        iterator last = this->end();
        iterator tmp; 
        while (first != last)
        {
            iterator next = first;
            while(++next != last)
            {
                if (comp(*first, *next))
                {
                    T tmp;
                    tmp = first.base()->el;
                    first.base()->el = next.base()->el;
                    next.base()->el = tmp;
                }
            }
            ++first;
        }
    }
    
    void reverse() {
        if (this->_n <= 1)
            return;
	    iterator first = this->begin();
	    iterator last = --this->end();

        size_type limit = this->_n / 2;
        for (size_t i = 0; i < limit; i++)
        {
            T tmp;
            tmp = first.base()->el;
            first.base()->el = last.base()->el;
            last.base()->el = tmp;
            ++first;
            --last;
        }
    }
};

template <typename T>
bool operator==(const List<T>& lhs, const List<T>& rhs) {
    if (lhs.size() != rhs.size())
        return false;
    return equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T>
bool operator!=(const List<T> &lhs, const List<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const List<T> &lhs, const List<T> &rhs) {
    return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T>
bool operator<=(const List<T> &lhs, const List<T> &rhs) {
    return !(lhs > rhs);
}

template <typename T>
bool operator>(const List<T> &lhs, const List<T> &rhs) {
    return rhs < lhs;
}

template <typename T>
bool operator>=(const List<T> &lhs, const List<T> &rhs) {
    return !(lhs < rhs);
}

template <typename T>
void swap(List<T> &x, List<T> &y) {
    x.swap(y);
}

}

#endif