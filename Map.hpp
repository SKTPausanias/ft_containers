/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:30:50 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/28 21:01:30 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "reverseIterator.hpp"
#include <algorithm>

namespace ft
{

template<typename key, typename T>
struct  pair
{
    typedef key first_type;
    typedef T second_type;

    first_type key_value;
    second_type mapped_value;
    
    pair* prev;
    pair* next;

    pair(pair *prev_, pair *next_)
                                : key_value(), mapped_value(), prev(prev_), next(next_) {}
    
    void insert_before(pair *node) {
		if (this->prev) {
			node->prev = this->prev;
			this->prev->next = node;
		}
		node->next = this;
		this->prev = node;
	}
};

template <typename key, typename T>
class MapIterator
{
public:      
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef std::ptrdiff_t difference_type;
protected:
    typedef MapIterator<key, T> _Self;
    typedef pair<key, T> pair;
    pair* _p;
public:
    MapIterator(): _p(nullptr) { }
    MapIterator(pair* p): _p(p) { }
    MapIterator(const MapIterator &x): _p(x._p) { }
    virtual ~MapIterator() {};
    MapIterator &operator=(const MapIterator &x) { this->_p = x._p; return *this; }

    pair* base() const {
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

	bool operator==(MapIterator const &other) const {
		return (this->_p == other._p);
	}
	bool operator!=(MapIterator const &other) const {
		return (this->_p != other._p);
	}
	bool operator<(MapIterator const &other) const {
		return (this->_p < other._p);
	}
	bool operator<=(MapIterator const &other) const {
		return (this->_p <= other._p);
	}
	bool operator>(MapIterator const &other) const {
		return (this->_p > other._p);
	}
	bool operator>=(MapIterator const &other) const {
		return (this->_p >= other._p);
	}
};
 
template <class Key, class T, class Compare = std::less<Key>>
class Map
{
public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef MapIterator<key_type, mapped_type> iterator;
    typedef MapIterator<const key_type, const mapped_type> const_iterator;
    typedef reverseIterator<iterator>  reverse_iterator;
    typedef reverseIterator<const_iterator> const_reverse_iterator; 
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

    class value_compare
    {
    friend class Map;
    protected:
        Compare comp;
        value_compare (Compare c) : comp(c) {}
    public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        bool operator() (const value_type& x, const value_type& y) const
        {
            return comp(x.first, y.first);
        }
    };

private:
    typedef Map<Key, T, Compare> _Self;
    pair<Key, T> *_head;
    pair<Key, T> *_tail;
    key_compare comp;
    size_type _n;
public:
    Map(const key_compare& comp = key_compare()): _n(0) {
        _head = new pair<Key, T>(NULL, NULL);
        _tail = _head;
        //insert(begin(), n, val);
    }

    Map(iterator first, iterator last) {
        _head = new pair<Key, T>(NULL, NULL);
        _tail = _head;
        insert(begin(), first, last);
    }

    Map(const Map& x) {
        _head = new pair<Key, T>(NULL, NULL);
        _tail = _head;
        insert(begin(), x.begin(), x.end());
    }
    
    virtual ~Map() {
        this->clear();
        delete _tail;
    }
    
    Map &operator=(const Map& x) {
        this->clear();
        insert(begin(), x.begin(), x.end());
        return *this;
    }

    iterator begin() {
        return iterator(_head);
    }
    
    const_iterator begin() const {
        typedef pair<const Key, const T> const_pair;
		return const_iterator(reinterpret_cast<const_pair *>(_head));
    }
    
    iterator end() {
        return iterator(_tail);
    }

    const_iterator end() const {
        typedef pair<const Key, const T> const_pair;
		return const_iterator(reinterpret_cast<const_pair *>(_tail));
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

    mapped_type& operator[] (const key_type& k) {
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
        {
            if (it.base()->key_value == k)
                return it.base()->mapped_value;
        }
        const value_type val = pair<k, ()>;
        insert(val);
    }

    iterator insert (iterator position, const value_type& val) {
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
        {
            if (it.base()->key_value == val->key_value)
                return iterator(it.base());
        } 
        if (position == this->begin())
        {
            pair<Key, T>* pair = new pair<Key, T>(nullptr, nullptr);
            pair->key_value = val->key_value;
            pair->mapped_value = val->key_value;
            this->_head->insert_before(pair);
            this->_head = pair;
            _n++;
            return iterator(this->begin());
        }
        else if (position == this->end())
        {
            pair<Key, T>* pair = new pair<Key, T>(nullptr, nullptr);
            pair->key_value = val->key_value;
            pair->mapped_value = val->key_value;
            this->_tail->insert_before(pair);
            _n++;
            return iterator(this->end());
        }
        else
        {
            pair<Key, T>* pair = new pair<Key, T>(nullptr, nullptr);
            pair->key_value = val->key_value;
            pair->mapped_value = val->key_value;
            position.base()->insert_before(pair);
            _n++;
            return iterator(pair);
        }
    }
    
    pair<iterator,bool> insert (const value_type& val) {
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
        {
            if (it.base()->key_value == val->key_value)
                return pair<iterator(it.base()), false>;
        }
        return pair<insert(lower_bound(val->key_value), val), true>;
    }
    
   void insert (iterator position, const_iterator first, const_iterator last) {
        while (first != last)
            this->insert(position, *first++);
    }

    void insert (iterator position, iterator first, iterator last) {
        while (first != last)
            this->insert(position, *first++);
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
                pair<Key, T> *tmp = this->_head->next;
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
                pair<Key, T> *tmp = this->_tail->prev;
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
            pair<Key, T>* node_right = position.base()->next;
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
        return (first);
    }
    
    void swap (Map& x) {
        std::swap(_head, x._head);
        std::swap(_tail, x._tail);
        std::swap(_n, x._n);
    }
    
    void clear() {
        erase(begin(), end());
        //_head = new pair<Key, T>(NULL, NULL);
        //_tail = _head;
    }

    key_compare key_comp() const {
        return comp;
    }

    value_compare value_comp() const {
        return value_compare(comp);
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
        size_type sum = 0;
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
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
        for (it; it != ite; it++)
        {
            if (cmp(k, it.base()->key_value) == false)
                break;
        }
        //if size >1 ?
        it--;
        return iterator(it.base());
    }
    
    const_iterator lower_bound (const key_type& k) const {
        key_compare cmp = key_comp();
        iterator ite = this->end();
        iterator it = this->begin();
        for (it; it != ite; it++)
        {
            if (cmp(k, it.base()->key_value) == false)
                break;
        }
        it--;
        return const_iterator(it.base());
    }

    iterator upper_bound (const key_type& k) {
        key_compare cmp = key_comp();
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
        {
            if (cmp(k, it.base()->key_value) == false)
                break;
        }
        return iterator(it.base());
    }

    const_iterator upper_bound (const key_type& k) const {
        key_compare cmp = key_comp();
        iterator ite = this->end();
        for (iterator it = this->begin(); it != ite; it++)
        {
            if (cmp(k, it.base()->key_value) == false)
                break;
        }
        return const_iterator(it.base());
    }

    pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
        return pair(lower_bound(k), upper_bound(k));
    }
    
    pair<iterator,iterator>             equal_range (const key_type& k) {
        return pair(lower_bound(k), upper_bound(k));
    }
};

}

#endif
