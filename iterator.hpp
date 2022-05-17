#ifndef CONTAINERS_ITERATOR_HPP
#define CONTAINERS_ITERATOR_HPP

namespace ft {

	template<typename T>
	class vector_iterator {

		public:
			typedef		T									value_type;
			typedef		std::random_access_iterator_tag		category;
			typedef		std::ptrdiff_t						distance;
			typedef		value_type							*pointer;
			typedef		value_type							&reference;

		protected:
			value_type		*_p;

		public:
			vector_iterator() : _p(nullptr) {};
			vector_iterator(pointer ptr) : _p(ptr) {};
			vector_iterator(T const &ref) : _p(ref._p) {};
			virtual ~vector_iterator() {};

			
	};
}

#endif