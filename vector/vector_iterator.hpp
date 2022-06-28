#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "../iterator_traits.hpp"

namespace ft {	
	template <class Iterator>
	class vector_iterator {

		public:
			typedef				Iterator 												iterator_type;
			typedef typename 	iterator_traits<iterator_type>::difference_type 		difference_type;
			typedef typename 	iterator_traits<iterator_type>::value_type 				value_type;
			typedef typename 	iterator_traits<iterator_type>::pointer 				pointer;
			typedef typename 	iterator_traits<iterator_type>::reference 				reference;
			typedef typename 	iterator_traits<iterator_type>::iterator_category 		iterator_category;

		protected:
			Iterator			_p;

		public:
			vector_iterator() : _p(nullptr) {};
			vector_iterator(pointer ptr) : _p(ptr) {};
			template <typename _Iter>
			vector_iterator(const vector_iterator<_Iter> &ref) : _p(ref.base()) {};
			virtual ~vector_iterator() {};

			Iterator 	base() const { return _p; }

			reference 	operator*() { return *_p; }

			reference	operator[](int index) { return *(this->_p + index); }

			//difference_type operator+(const vector_iterator &rhs) const { return (this->_p + rhs._p); }

			vector_iterator operator+(difference_type n) const { return (this->_p + n); }

			difference_type operator-(const vector_iterator &rhs) const { return (this->_p - rhs._p); }

			vector_iterator operator-(difference_type n) const { return (this->_p - n); }

			vector_iterator &operator+=(difference_type n) {
				this->_p += n;
				return *this;
			}

			vector_iterator &operator-=(difference_type n) {
				this->_p -= n;
				return *this;
			}

			bool operator==(const vector_iterator &other) const { return this->_p == other._p; }

			bool operator!=(const vector_iterator &other) const { return this->_p != other._p; }

			// Pre increment
			vector_iterator &operator++()
			{
				this->_p++;
				return *this;
			}

			// Post decrement
			vector_iterator operator++(int)
			{
				vector_iterator it = *this;
				this->_p++;
				return it;
			}

			// Pre decrement
			vector_iterator &operator--()
			{
				this->_p--;
				return *this;
			}

			// Post decrement
			vector_iterator operator--(int)
			{
				vector_iterator it = *this;
				this->_p--;
				return it;
			}

			

	};

	template <typename Iterator>
    vector_iterator<Iterator> operator+(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator> &it)
    {
        return (vector_iterator<Iterator>(it.base() + n));
    }

	template <typename Iterator>
    vector_iterator<Iterator> operator-(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator> &it)
    {
        return (vector_iterator<Iterator>(it.base() - n));
    }

    template <typename it1, typename it2>
    bool operator==(const vector_iterator<it1> &a, const vector_iterator<it2> &b) { return (a.base() == b.base()); }

    template <typename it1, typename it2>
    bool operator!=(const vector_iterator<it1> &a, const vector_iterator<it2> &b) { return (a.base() != b.base()); }

    template <typename it1, typename it2>
    bool operator<(const vector_iterator<it1> &a, const vector_iterator<it2> &b) { return (a.base() < b.base()); }

    template <typename it1, typename it2>
    bool operator<=(const vector_iterator<it1> &a, const vector_iterator<it2> &b) { return (a.base() <= b.base()); }

    template <typename it1, typename it2>
    bool operator>(const vector_iterator<it1> &a, const vector_iterator<it2> &b) { return (a.base() > b.base()); }

    template <typename it1, typename it2>
    bool operator>=(const vector_iterator<it1> &a, const vector_iterator<it2> &b) { return (a.base() >= b.base()); }

    template <class T>
    std::ostream &operator<<(std::ostream &o, vector_iterator<T> &rhs)
    {
        o << rhs.base();
        return o;
    }
}

#endif // VECTOR_ITERATOR_HPP