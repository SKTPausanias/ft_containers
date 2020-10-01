/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <mlaplana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:38:45 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/01 13:00:58 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

template<class T>
class reverseIterator
{
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef std::ptrdiff_t difference;
protected:
    pointer _ptr;
public:
    reverseIterator(): _ptr(nullptr) { }
    reverseIterator(pointer ptr): _ptr(ptr) { }
    reverseIterator(const reverseIterator &c): _ptr(c._ptr) { }
    virtual ~reverseIterator() { }
    
    reverseIterator &operator=(const reverseIterator &c) { _ptr = c._ptr; return *this; }
    
    reference operator*() { 
        pointer tmp(_ptr);
        return *--tmp;
    }

    
};

#endif