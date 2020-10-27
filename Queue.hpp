/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:57:23 by mlaplana          #+#    #+#             */
/*   Updated: 2020/10/27 13:47:31 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"

namespace ft
{
    template <class T, class Container = List<T>>
    class Queue
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;
    private:
        container_type _ctnr;
    public:
        Queue(const container_type& ctnr = container_type()): _ctnr(ctnr) { }
        Queue(const Queue &x): _ctnr(x._ctnr) { }
        virtual ~Queue() { }

        Queue &operator=(const Queue &x) { _ctnr = x._ctnr; return *this; }

        bool empty() const {
            return _ctnr.empty();
        }

        size_type size() const {
            return _ctnr.size();
        }

        value_type& front() {
            return _ctnr.front();
        }

        const value_type& front() const {
            return _ctnr.front();
        }

		value_type &back()
		{
			return _ctnr.back();
		}

		const value_type &back() const
		{
			return _ctnr.back();
		}
        
		void push(const value_type &val)
		{
			return _ctnr.push_back(val);
		}

		void pop()
		{
			_ctnr.pop_front();
		}

        template<typename queue_type, typename container_type>
        friend bool operator==(const Queue<queue_type, container_type> &lhs, const Queue<queue_type, container_type> &rhs) {
            return (lhs.container == rhs.container);
        }

        template<typename queue_type, typename container_type>
        friend bool operator!=(const Queue<queue_type, container_type> &lhs, const Queue<queue_type, container_type> &rhs) {
            return (lhs.container != rhs.container);
        }

        template<typename queue_type, typename container_type>
        friend bool operator<(const Queue<queue_type, container_type> &lhs, const Queue<queue_type, container_type> &rhs) {
            return (lhs.container < rhs.container);
        }

        template<typename queue_type, typename container_type>
        friend bool operator<=(const Queue<queue_type, container_type> &lhs, const Queue<queue_type, container_type> &rhs) {
            return (lhs.container <= rhs.container);
        }

        template<typename queue_type, typename container_type>
        friend bool operator>(const Queue<queue_type, container_type> &lhs, const Queue<queue_type, container_type> &rhs) {
            return (lhs.container > rhs.container);
        }

        template<typename queue_type, typename container_type>
        friend bool operator>=(const Queue<queue_type, container_type> &lhs, const Queue<queue_type, container_type> &rhs) {
            return (lhs.container >= rhs.container);
        }
    };
}

#endif