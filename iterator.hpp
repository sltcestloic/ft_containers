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


	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T& >
	struct iterator {
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category category;
	};

	template <class T>
	class reverse_iterator : public iterator<typename iterator_traits<T>::category, typename iterator_traits<T>::value_type,
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

    template <class Iterator>
  	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		  (void)lhs;
		  (void)rhs;
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