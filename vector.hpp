#ifndef CONTAINERS_VECTOR_HPP
#define CONTAINERS_VECTOR_HPP

#include <memory>
#include "iterator.hpp"

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef				T							value_type;
			typedef				Alloc						allocator_type;
			typedef				std::size_t					size_type;
			typedef				std::ptrdiff_t				difference_type;
			typedef typename	Alloc::reference			reference;
			typedef	typename	Alloc::pointer				pointer;

		private:
			T*				_data;
			size_t			_size;
			size_t			_capacity;
			allocator_type	_alloc;

		

		public:

			explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _begin(nullptr), _end(nullptr) {};

			explicit vector (size_type n, const value_type& val = value_type(), 
				const allocator_type& alloc = allocator_type()) : _capacity(n) {
					_alloc.allocate(n);
					for (size_type i = 0; i < n; i++)
						
					//construct les trucs
				}

			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
				 
			}

			vector (const vector& x) {
				assign(x._begin, x._end);
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last) {
				if (_capacity < last - first) {
					clear();
					_alloc.deallocate(_data, _capacity);
				}
				_alloc.allocate(last - first);
				while (first != last) {
					_alloc.construct(_data + _size, *first);
					first++;
				}
			}


			void assign (size_type n, const value_type& val);

			void clear() {
				for (size_t i = 0; i < _size; i++)
					_alloc.deconstruct(_data[i]);
				_size = 0;
			}

			// vector		&operator=(vector &ref) {
			// 	this->_data = ref._data; 
			// }

	};
}

#endif