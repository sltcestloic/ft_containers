#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

template <class Iterator>
class iterator_traits {
	public:
		typedef typename 	Iterator::difference_type 		difference_type;
		typedef typename 	Iterator::value_type 			value_type;
		typedef typename 	Iterator::pointer				pointer;
		typedef typename 	Iterator::reference		 		reference;
		typedef typename 	Iterator::iterator_category 	iterator_category;
};

template <class T>
class iterator_traits<T*> {
	public:
		typedef		T									value_type;
		typedef		std::random_access_iterator_tag		iterator_category;
		typedef		std::ptrdiff_t						difference_type;
		typedef		value_type							*pointer;
		typedef		value_type							&reference;
};

template <class T>
class iterator_traits<const T*> {
	public:
		typedef		T									value_type;
		typedef		std::random_access_iterator_tag		iterator_category;
		typedef		std::ptrdiff_t						difference_type;
		typedef		const value_type					*pointer;
		typedef		const value_type					&reference;
};

#endif