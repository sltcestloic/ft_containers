#ifndef CONTAINERS_ITERATOR_HPP
#define CONTAINERS_ITERATOR_HPP

namespace ft {

	template <class Iterator>
	class iterator_traits {
		public:
			typedef typename 	Iterator::difference_type 	difference_type;
			typedef typename 	Iterator::value_type 		value_type;
			typedef typename 	Iterator::pointer			pointer;
			typedef typename 	Iterator::reference		 	reference;
			typedef typename 	Iterator::category 			category;
	};

	template <class T>
	class iterator_traits<T*> {
		public:
			typedef		T									value_type;
			typedef		std::random_access_iterator_tag		category;
			typedef		std::ptrdiff_t						difference_type;
			typedef		value_type							*pointer;
			typedef		value_type							&reference;
	};

	template <class T>
	class iterator_traits<const T*> {
		public:
			typedef		T									value_type;
			typedef		std::random_access_iterator_tag		category;
			typedef		std::ptrdiff_t						difference_type;
			typedef		const value_type					*pointer;
			typedef		const value_type					&reference;
	};

	template <class Iterator>
	class vector_iterator {

		public:
			typedef				Iterator 											iterator_type;
			typedef typename 	iterator_traits<iterator_type>::difference_type 	difference_type;
			typedef typename 	iterator_traits<iterator_type>::value_type 			value_type;
			typedef typename 	iterator_traits<iterator_type>::pointer 			pointer;
			typedef typename 	iterator_traits<iterator_type>::reference 			reference;
			typedef typename 	iterator_traits<iterator_type>::category 			category;

		protected:
			Iterator			_p;

		public:
			vector_iterator() : _p(nullptr) {};
			vector_iterator(pointer ptr) : _p(ptr) {};
			vector_iterator(vector_iterator const &ref) : _p(ref._p) {};
			virtual ~vector_iterator() {};

			Iterator 	base() const { return _p; }

			reference 	operator*() { return *_p; }

			reference	operator[](int index) {
				return *(this->_p + index);
			}

			difference_type operator+(const vector_iterator &rhs) const {
				difference_type res = this->_p + rhs._p;
				return (res);
			}

			vector_iterator operator+(difference_type n) const {
           		vector_iterator res = this->_p + n;
           		return (res);
      		}

			difference_type operator-(const vector_iterator &rhs) const {
				difference_type res = this->_p - rhs._p;
				return (res);
			}

			vector_iterator operator-(difference_type n) const
			{
				vector_iterator res = this->_p - n;
				return (res);
			}

			vector_iterator &operator+=(difference_type n) {
				this->_p += n;
				return *this;
			}

			vector_iterator &operator-=(difference_type n) {
				this->_p -= n;
				return *this;
			}

			bool operator==(const vector_iterator &other) const
			{
				bool b = this->_p == other._p;
				return (b);
			}

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
        return (vector_iterator<Iterator>(it.get_ptr() + n));
    }

    template <typename Iterator>
    vector_iterator<Iterator> operator-(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator> &it)
    {
        return (vector_iterator<Iterator>(it.get_ptr() - n));
    }

    template <typename it1, typename it2>
    bool operator==(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
    {
        bool res = a.get_ptr() == b.get_ptr();
        return (res);
    }

    template <typename it1, typename it2>
    bool operator!=(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
    {
        bool res = a.get_ptr() != b.get_ptr();
        return (res);
    }

    template <typename it1, typename it2>
    bool operator<(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
    {
        bool res = a.get_ptr() < b.get_ptr();
        return (res);
    }

    template <typename it1, typename it2>
    bool operator<=(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
    {
        bool res = a.get_ptr() <= b.get_ptr();
        return (res);
    }

    template <typename it1, typename it2>
    bool operator>(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
    {
        bool res = a.get_ptr() > b.get_ptr();
        return (res);
    }

    template <typename it1, typename it2>
    bool operator>=(const vector_iterator<it1> &a, const vector_iterator<it2> &b)
    {
        bool res = a.get_ptr() >= b.get_ptr();
        return (res);
    }

    template <class T>
    std::ostream &operator<<(std::ostream &o, vector_iterator<T> &rhs)
    {
        o << rhs.get_ptr();
        return o;
    }
}

#endif