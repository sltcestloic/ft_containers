#ifndef CONTAINERS_ITERATOR_HPP
#define CONTAINERS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T& >
	struct iterator {
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category category;
	};

	template <class T>
	class reverse_iterator : public iterator<typename iterator_traits<T>::iterator_category, typename iterator_traits<T>::value_type,
            typename iterator_traits<T>::difference_type,
            typename iterator_traits<T>::pointer,
            typename iterator_traits<T>::reference> {


		protected:
			T								_p;
			typedef		iterator_traits<T>	traits;

		public:
			typedef				T	 						iterator_type;
			typedef typename 	traits::difference_type 	difference_type;
			typedef typename 	traits::pointer 			pointer;
			typedef typename 	traits::reference 			reference;

		public:
			reverse_iterator() : _p() {};
			explicit reverse_iterator(iterator_type ptr) : _p(ptr) {};
			template <typename _Iter>
			reverse_iterator(const reverse_iterator<_Iter> &ref) : _p(ref.base()) {};
			virtual ~reverse_iterator() {};

			iterator_type 		base() const { return _p; }

			reference 			operator*() const {
				T tmp = _p;
				return *--tmp;
			}

			reverse_iterator 	operator+ (difference_type n) const { return reverse_iterator(_p - n); }

			reverse_iterator 	operator- (difference_type n) const { return reverse_iterator(_p + n); }

			reverse_iterator	&operator+= (difference_type n) {
				this->_p -= n;
				return *this;
			}

			reverse_iterator	&operator-=(difference_type n) {
				this->_p += n;
				return *this;
			}

			pointer operator->() const {
				return &(operator*());
			}


			// Pre increment
			reverse_iterator &operator++()
			{
				this->_p--;
				return *this;
			}

			// Post decrement
			reverse_iterator operator++(int)
			{
				reverse_iterator it = *this;
				this->_p--;
				return it;
			}

			// Pre decrement
			reverse_iterator &operator--()
			{
				this->_p++;
				return *this;
			}

			// Post decrement
			reverse_iterator operator--(int)
			{
				reverse_iterator it = *this;
				this->_p++;
				return it;
			}


			reference			operator[](int index) { return *(this->_p + index); }
	};

	template <typename Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &it)
    {
        return (reverse_iterator<Iterator>(it.base() - n));
    }

    template <typename it1, typename it2>
    bool operator==(const reverse_iterator<it1> &a, const reverse_iterator<it2> &b) { return (a.base() == b.base()); }

    template <typename it1, typename it2>
    bool operator!=(const reverse_iterator<it1> &a, const reverse_iterator<it2> &b) { return (a.base() != b.base()); }

    template <typename it1, typename it2>
    bool operator<(const reverse_iterator<it1> &a, const reverse_iterator<it2> &b) { return (a.base() > b.base()); }

    template <typename it1, typename it2>
    bool operator<=(const reverse_iterator<it1> &a, const reverse_iterator<it2> &b) { return (a.base() >= b.base()); }

    template <typename it1, typename it2>
    bool operator>(const reverse_iterator<it1> &a, const reverse_iterator<it2> &b) { return (a.base() < b.base()); }

    template <typename it1, typename it2>
    bool operator>=(const reverse_iterator<it1> &a, const reverse_iterator<it2> &b) { return (a.base() <= b.base()); }

    template <class T>
    std::ostream &operator<<(std::ostream &o, reverse_iterator<T> &rhs)
    {
        o << rhs.base();
        return o;
    }
}

#endif