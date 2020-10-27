/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:30:54 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/27 12:59:24 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft
{  
    template <class T, class Container = Vector<T>>
    class Stack 
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;
    private:
        container_type _ctnr;
    public:
        Stack(const container_type& ctnr = container_type()): _ctnr(ctnr) { }
        Stack(const Stack &x): _ctnr(x._ctnr) { }
        virtual ~Stack() { }

        Stack &operator=(const Stack &x) { _ctnr = x._ctnr; return *this; }

        bool empty() const {
            return _ctnr.empty();
        }

        size_type size() const {
            return _ctnr.size();
        }

        value_type& top() {
            return _ctnr.back();
        }

        const value_type& top() const {
            return _ctnr.back();
        }

        void push (const value_type& val) {
            _ctnr.push_back(val);
        }

        void pop() {
            _ctnr.pop_back();
        }
        
        template <typename stack_type, typename container_type>
        friend bool operator==(const Stack<stack_type,container_type>& lhs, const Stack<stack_type,container_type>& rhs) {
            return (lhs._ctnr == rhs._ctnr);
        }
        	
        template <typename stack_type, typename container_type>
        friend bool operator!=(const Stack<stack_type,container_type>& lhs, const Stack<stack_type,container_type>& rhs) {
            return (lhs._ctnr != rhs._ctnr);
        }
        
        template <typename stack_type, typename container_type>
        friend bool operator<(const Stack<stack_type,container_type>& lhs, const Stack<stack_type,container_type>& rhs) {
            return (lhs._ctnr < rhs._ctnr);
        }

        template <typename stack_type, typename container_type>
        friend bool operator<=(const Stack<stack_type,container_type>& lhs, const Stack<stack_type,container_type>& rhs) {
            return (lhs._ctnr <= rhs._ctnr);
        }
        
        template <typename stack_type, typename container_type>
        friend bool operator>(const Stack<stack_type,container_type>& lhs, const Stack<stack_type,container_type>& rhs) {
            return (lhs._ctnr > rhs._ctnr);
        }
        
        template <typename stack_type, typename container_type>
        friend bool operator>=(const Stack<stack_type,container_type>& lhs, const Stack<stack_type,container_type>& rhs) {
            return (lhs._ctnr >= rhs._ctnr);
        }
    };
}

#endif